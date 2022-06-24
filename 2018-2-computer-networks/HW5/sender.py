from socket import *
from threading import Thread
import time
from sys import getsizeof
from os import _exit

import os
import sys

port = 10080
bufferSize = 1400
headerSize = 48
SR_G_AV = [0, 0, 0]


# opens file with file name and type, and returns 0 when file open is failed
def getfile(filename, type):
    try:
        fptr = open(os.path.join(sys.path[0], filename), type)
        return fptr
    except:
        return 0


# Add the header to the data with the given packet number
def addheader(pktnum, data):
    header = (str(pktnum)).encode()
    while getsizeof(header) < headerSize:
        header = header + b'\0'
    return header + data


# Writes the contents to the log file
def logfilewrite(flogptr, starttime):
    while True:
        time.sleep(2.0)
        timediff = time.time() - starttime
        content = f'{timediff:0.3f}' + "\t|\t" + f'{SR_G_AV[2]:0.3f}' + "\t|\t" + str(SR_G_AV[0] / 2) + "pkts/sec" \
                + "\t|\t" + str(SR_G_AV[1] / 2) + "pkts/sec" + "\n"
        flogptr.write(content)
        flogptr.flush()
        SR_G_AV[0] = 0
        SR_G_AV[1] = 0


# Sender module : sends the packets to Receiver module
def SEM(Socket, ip, wndSize):

    # Measure the sample RTT
    sampstart = time.time()
    Socket.sendto(b'sample', (ip, port))
    recvmsg,_addr = Socket.recvfrom(headerSize)
    if recvmsg == b'sampleOK':
        sampleRTT = time.time() - sampstart
    else:
        print('something went wrong')
        exit(1)

    print('samplertt : ' + str(sampleRTT))

    # Set the values of timeout, avgRTT and devRTT
    SR_G_AV[2] = sampleRTT
    devRTT = 0.01
    timeoutVal = SR_G_AV[2] + 4 * devRTT

    # Variables for receiving packet
    recentAck = -1
    recvAck = -1
    duplicateAck = -1
    window = []
    is_first_pkt = 1
    is_first_pkt_sent = 0

    while True:
        # If window has the left space to sent
        while len(window) < wndSize:
            # When window is empty
            if len(window) == 0:
                expectAck = recentAck + 1

            # When window is not empty
            else:
                expectAck = window[len(window) - 1] + 1

            # Sends the generated packet
            Socket.sendto(addheader(expectAck, genpacket), (ip, port))
            if is_first_pkt_sent == 0 and is_first_pkt == 1:
                Socket.settimeout(timeoutVal)
                nowTime = time.time()
                is_first_pkt_sent = 1
                sampleAck = expectAck
            window.append(expectAck)
            SR_G_AV[0] += 1                                # Increases the sending rate

        # After sending
        while True:
            # Receive ack from the receiver
            try:
                recvbyte, recvaddr = Socket.recvfrom(headerSize)

            # When timeout occurs, set the timeout again
            except:
                # If the timeout is occurred after the ack receive
                window = []
                wndSize = 1
                is_first_pkt = 1
                is_first_pkt_sent = 0
                break

            recvAck = int(recvbyte.decode())
            SR_G_AV[1] += 1  # Increases the goodput

            # First Ack before the timeout occurs
            if is_first_pkt == 1 and recvAck == sampleAck:
                # Calculate the timeout using the RTT
                sampleRTT = time.time() - nowTime
                devRTT = 0.75 * devRTT + 0.25 * abs(sampleRTT - SR_G_AV[2])
                SR_G_AV[2] = 0.875 * SR_G_AV[2] + 0.125 * sampleRTT
                timeoutVal = SR_G_AV[2] + 4 * devRTT
                is_first_pkt = 0

            if time.time() - nowTime > timeoutVal:
                wndSize += 1
                is_first_pkt = 1
                is_first_pkt_sent = 0

            elif wndSize <= 4:
                wndSize *= 2


            if window == []:
                break

            # If the received ack is the right order
            if recvAck == window[0]:
                duplicateAck = 0
                recentAck = recvAck
                window.pop(0)
                break

            # If the received ack is larger than the expected ack
            elif recvAck > window[0]:
                duplicateAck = 0
                recentAck = recvAck

                # pops the elements in the window while the right one is found or window becomes empty
                while len(window) != 0 and recvAck == window[0]:
                    window.pop(0)
                break

            # If Ack is duplicated
            elif recvAck == recentAck:
                duplicateAck += 1

                # For 3 duplicate Ack
                if duplicateAck >= 3:
                    if wndSize != 1:
                        wndSize //= 2               # Reduce the window size as its half
                    window = []
                    duplicateAck = 0

                    Socket.settimeout(timeoutVal / 2)
                    try:
                        while True:
                            recvbyte, recvaddr = Socket.recvfrom(headerSize)
                            SR_G_AV[1] += 1
                    except:
                        is_first_pkt = 1
                        is_first_pkt_sent = 0
                        break

            # If Ack is smaller than recently recevied packet, just ignore it



if __name__ == "__main__":
    # Generates the packet only exists for null
    genpacket = b'\0'
    while getsizeof(genpacket) < bufferSize:
        genpacket += genpacket
    genpacket = genpacket[:bufferSize - headerSize]

    # Gets the ip address and initial window size
    print("Receiver IP address: ", end ="")
    ip = input()
    print("start initial window size : ", end ="")
    wndSize = int(input())

    # Bind the socket and send the starting message
    print("Sending Start")
    senderSocket = socket(AF_INET, SOCK_DGRAM)
    senderSocket.bind(('', 0))
    senderSocket.sendto(b'send', (ip, port))

    # Open the log file corresponding to port number
    portnum = senderSocket.getsockname()
    portnum = str(portnum[1])
    print(portnum)
    flogptr = getfile(portnum + '_log.txt', 'wt')

    startTime = time.time()

    # Runs the log file writing thread
    Thread(target=logfilewrite, args=(flogptr, startTime)).start()

    # Runs the sender module to send the packet
    Thread(target=SEM, args=(senderSocket, ip, wndSize)).start()

    # When user enters stop, exit the program
    while True:
        state = input()
        if state == 'stop':
            senderSocket.sendto(b'end', (ip, port))
            flogptr.close()
            senderSocket.close()
            _exit(0)
