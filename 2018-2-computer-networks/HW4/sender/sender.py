from socket import *
import threading
import time
from sys import getsizeof

import os
import sys

port = 10080
bufferSize = 1400
headerSize = 48


def getfile(filename, type):
    try:
        fptr = open(os.path.join(sys.path[0], filename), type)
        return fptr
    except:
        return 0


def addheader(pktnum, data):
    header = (str(pktnum)).encode()
    while getsizeof(header) < headerSize:
        header = header + b'\0'
    return header + data


def logfilewrite(flogptr, pkt, num, timediff, state):
    content = f'{timediff:0.3f}' + "\t" + pkt + ": " + str(num) + "\t| " + state + "\n"
    flogptr.write(content)


def filetransfer(fileName, ip, timeout, cwnd):
    senderSocket = socket(AF_INET, SOCK_DGRAM)
    senderSocket.bind(('', 0))

    fptr = getfile(fileName, 'rb')
    if fptr == 0:
        exit(1)

    flogptr = getfile(fileName + '_sending_log.txt', 'wt')

    fstore = []
    fsize = 0

    fdata = fptr.read(bufferSize - headerSize)
    while fdata:
        fstore.append(addheader(fsize, fdata))
        fsize += 1
        fdata = fptr.read(bufferSize - headerSize)

    recentAck = -1
    recvAck = -1
    recvAckBuffer = []
    duplicateAck = -1

    senderSocket.sendto(fileName.encode(), (ip,port))
    startTime = time.time()

    while recentAck < fsize - 1:
        senderSocket.settimeout(timeout)
        nowTime = time.time()

        for i in range(1, cwnd+1):
            expectAck = i + recentAck
            if expectAck < fsize:
                senderSocket.sendto(fstore[expectAck], (ip, port))
                logfilewrite(flogptr, 'pkt', expectAck, time.time() - startTime, 'sent')
            else:
                expectAck -= 1
                break

        while expectAck != recentAck:
            try:
                recvbyte,recvaddr = senderSocket.recvfrom(headerSize)
                recvAck = recvbyte.decode()

            except:
                logfilewrite(flogptr,'pkt', recentAck + 1, time.time() - startTime,
                             "Timeout since {0}".format(round(nowTime - startTime, 3)))
                senderSocket.settimeout(timeout)
                nowTime = time.time()

                while True:
                    logfilewrite(flogptr, 'pkt', recentAck + 1, time.time() - startTime, "retransmitted")
                    senderSocket.sendto(fstore[recentAck + 1], (ip, port))
                    try:
                        recvbyte, recvaddr = senderSocket.recvfrom(headerSize)
                        recvAck = recvbyte.decode()
                        recvAck = int(recvAck.split('\0')[0])
                        logfilewrite(flogptr, 'ack', recvAck, time.time() - startTime, 'received')

                    except:
                        senderSocket.settimeout(timeout)
                        logfilewrite(flogptr, 'pkt', recentAck + 1, time.time() - startTime,
                                     "Timeout since {0}".format(round(nowTime - startTime, 3)))
                        nowTime = time.time()
                        continue

                    if recvAck >= recentAck + 1:
                        break

                recentAck = recvAck
                duplicateAck = 0
                break

            recvAck = int(recvAck.split('\0')[0])
            logfilewrite(flogptr, 'ack', recvAck, time.time() - startTime, 'received')

            if recvAck != recentAck:
                duplicateAck = 0

            else:
                duplicateAck += 1
                if duplicateAck == 3:
                    logfilewrite(flogptr, 'pkt', recvAck, time.time() - startTime, '3 duplicate ACKs')
                    recentAck = recvAck
                    duplicateAck = 0

                    senderSocket.settimeout(timeout)
                    while True:
                        try:
                            recvbyte, recvaddr = senderSocket.recvfrom(headerSize)
                        except:
                            break
                    break

            if recentAck < recvAck:
                recentAck = recvAck

    senderSocket.sendto(b'end',(ip, port))
    time.sleep(0.0001)
    endTime = time.time()
    throughput = round(fsize / (endTime - startTime),3)
    flogptr.write("\nFile transfer is finished.\n")
    flogptr.write("Throughput : " + str(throughput) + "pkts / sec")

    flogptr.close()
    fptr.close()
    senderSocket.close()


if __name__ == "__main__":
    print("Receiver IP address: ", end ="")
    ip = input()
    print("Timeout : ", end ="")
    timeoutVal = float(input())
    print("Window size : ",  end ="")
    windowSize = int(input())

    while True:
        print("Filename : ",  end ="")
        fileName = input()
        th = threading.Thread(target=filetransfer, args=(fileName, ip, timeoutVal, windowSize))
        th.start()
