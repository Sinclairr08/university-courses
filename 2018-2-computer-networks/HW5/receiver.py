from socket import *
from threading import Thread
import time

import os
import sys

bufferSize = 1400
headerSize = 48
port = 10080
nemque = []
avgque = []
shrddic = {}
IN_FO = [0,0]


def avgquecal(quesize):
    while True:
        avgque.append(len(nemque) / quesize)
        time.sleep(0.1)


# opens file with file name and type, and returns 0 when file open is failed
def getfile(filename, type):
    try:
        fptr = open(os.path.join(sys.path[0], filename), type)
        return fptr
    except:
        return 0


# Sends from NEM to RM as the rate of BLR
def NEMque(BLRhz):
    while True:
        # If queue is not empty
        if len(nemque) != 0:
            recvtuple = nemque.pop(0)
            try:
                shrddic[recvtuple[1]].append(recvtuple[0])
            except:
                pass
            IN_FO[1] += 1                   # Increase the forwarding rate
            time.sleep(BLRhz)


# Calculating jain fairness index
def jfindex(list):
    sumsq = 0.0
    sqsum = 0.0
    cnt = len(list)
    for val in list:
        sumsq += val
        sqsum += val * val
    sumsq *= sumsq

    # If list is empty or everything in list is zero, returns 'NA'
    if sqsum == 0:
        return 'NA'
    else:
        return str(sumsq / (cnt * sqsum))


# Writes the content of RM to the log file
def logfilewriteRM(flogptr, starttime):
    while True:
        time.sleep(2.0)
        timediff = time.time() - starttime
        content1 = f'{timediff:0.3f}' + "\t|\t"
        content2 = ''
        rate = []
        for addr in shrddic.keys():
            content2 += '\t\t' + str(addr[0]) + ':' + str(addr[1]) + "\t|\t" \
                       + str(shrddic[addr][0] / 2) + "\n"
            rate.append(shrddic[addr][0] / 2)
            shrddic[addr][0] = 0

        content1 += jfindex(rate) + '\n'
        flogptr.write(content1 + content2)
        flogptr.flush()


# Writes the content of NEM to the log file
def logfilewriteNEM(flogptr, starttime):
    while True:
        time.sleep(2.0)
        timediff = time.time() - starttime
        avg = sum(avgque) / len(avgque)
        content = f'{timediff:0.3f}' + "\t|\t" + str(IN_FO[0] / 2) + "\t|\t" + str(IN_FO[1] / 2) + "\t|\t" + str(avg) +"\n"
        flogptr.write(content)
        flogptr.flush()
        IN_FO[0] = 0
        IN_FO[1] = 0


# Receiver module which gets the packet from the NEM, thread exist for each sender
def RM(socket, addr):
    recvAckBuffer = []
    recentAck = -1

    while True:
        # Gets the input from the shared dictionary
        while True:
            if len(shrddic[addr]) != 1:
                data = (shrddic[addr]).pop(1)
                break

        # If the received packet is end signal, just quit this content
        if data == b'end':
            del shrddic[addr]
            return

        # If the received packet is sample signal
        if data == b'sample':
            socket.sendto(b'sampleOK', addr)
            continue

        seqnum = int(data.decode())

        # If given pkt number is the next of recently sent ack
        if recentAck == seqnum - 1:
            recentAck += 1

            # Search and send the buffered ack
            while len(recvAckBuffer) != 0 and recentAck == recvAckBuffer[0] - 1:
                recentAck += 1
            socket.sendto(str(recentAck).encode(), addr)
            shrddic[addr][0] += 1                           # Adds the number of received pkts

        # If given pkt number is the out of order
        else:
            socket.sendto(str(recentAck).encode(), addr)
            shrddic[addr][0] += 1                           # Adds the number of received pkts

            if recentAck < seqnum - 1:
                recvAckBuffer.append(seqnum)


if __name__ == "__main__":
    # Gets the BLR and queue size
    print("BLR : ", end = "")
    BLR = float(input())
    print("queue_size : ", end="")
    queSize = int(input())

    # Bind the socket and update the socket buffer size
    receiverSocket = socket(AF_INET, SOCK_DGRAM)
    receiverSocket.bind(('', port))
    socketBufferSize = receiverSocket.getsockopt(SOL_SOCKET,SO_RCVBUF)

    if socketBufferSize < 1000000:
        receiverSocket.setsockopt(SOL_SOCKET,SO_RCVBUF, 1000000)
    print("socket recv buffer size updated : 10000000")

    # Runs the thread for sending NEM to RM by the rate as BLR
    Thread(target=NEMque, args=(1 / BLR, )).start()
    Thread(target = avgquecal, args=(queSize, )).start()

    # Runs the log file writing thread for NEM and RM
    flogptrRM = getfile('RM_log.txt', 'wt')
    flogptrNEM = getfile('NEM_log.txt', 'wt')

    startTime = time.time()
    Thread(target=logfilewriteRM, args=(flogptrRM, startTime,)).start()
    Thread(target=logfilewriteNEM, args=(flogptrNEM, startTime,)).start()

    # The queue for saving address of the sender
    addrque = []

    # NEM part
    while True:
        # Receives from the sender
        try:
            recvbyte, recvaddr = receiverSocket.recvfrom(bufferSize)
        except:
            continue
        recvbyte = recvbyte.split(b'\0')[0]

        # If the sender sends the start signal
        if recvbyte == b'send':
            addrque.append(recvaddr)
            shrddic[recvaddr] = [0]
            Thread(target=RM, args=(receiverSocket, recvaddr)).start()

        # If the sender sends the quit signal
        elif recvbyte == b'end':
            addrque.remove(recvaddr)
            shrddic[recvaddr].insert(1,recvbyte)

        # Packet is arrived
        else:
            IN_FO[0] += 1                      # Increase the incoming rate
            # Use tail drop method for the filed queue
            if len(nemque) < queSize:
                nemque.append((recvbyte, recvaddr))