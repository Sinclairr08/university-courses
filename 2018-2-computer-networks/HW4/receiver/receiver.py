from socket import *
import threading
import random
import time
from sys import getsizeof

import os
import sys

bufferSize = 1400
headerSize = 48
lossp = 0.0
port = 10080
shrdque = []


def getfile(filename, type):
    try:
        fptr = open(os.path.join(sys.path[0], filename), type)
        return fptr
    except:
        return 0


def makeheader(pktnum):
    header = str(pktnum).encode()
    while getsizeof(header) < headerSize:
        header = header + b'\0'
    return header


def logfilewrite(flogptr, pkt, num, timediff, state):
    content = f'{timediff:0.3f}' + "\t" + pkt + ": " + str(num) + "\t| " + state + '\n'
    flogptr.write(content)


def filereceive(socket, fileName, addr):
    fptr = getfile(fileName, 'wb')

    if fptr == 0:
        exit(1)

    recvAckBuffer = []
    recentAck = -1

    flogptr = getfile(fileName + '_receiving_log.txt', 'wt')

    startTime = time.time()

    while True:
        Tag = 0
        while Tag == 0:
            for recvtuple in shrdque:
                if recvtuple[1] == addr:
                    data = recvtuple[0]
                    shrdque.remove(recvtuple)
                    Tag = 1
                    break

        if data == b'end':
            break

        bytenum = getsizeof(b'')
        headercnt = headerSize - bytenum
        seqnum = data[0:headercnt]
        fdata = data[headercnt:]
        seqnum = int((seqnum.split(b'\0')[0]).decode())

        logfilewrite(flogptr, 'pkt', seqnum, time.time() - startTime, 'received')

        rand = random.random()
        if rand < lossp:
            logfilewrite(flogptr, 'pkt', seqnum, time.time() - startTime, 'dropped')
            continue

        if recentAck == seqnum -1:
            fptr.write(fdata)
            recentAck += 1
            while len(recvAckBuffer) != 0 and recentAck == recvAckBuffer[0][0] - 1:
                recentAck += 1
                fptr.write((recvAckBuffer.pop(0))[1])
            socket.sendto(makeheader(recentAck), addr)
            logfilewrite(flogptr, 'ack', recentAck, time.time() - startTime, 'sent')

        else:
            socket.sendto(makeheader(recentAck), addr)
            logfilewrite(flogptr, 'ack', recentAck, time.time() - startTime, 'sent')

            if recentAck < seqnum - 1:
                recvAckBuffer.append((seqnum, fdata))

    print("transfer done")
    time.sleep(0.0001)
    endTime = time.time()
    throughput = round((recentAck + 1) / (endTime - startTime),3)
    flogptr.write("\nFile transfer is finished.\n")
    flogptr.write("Throughtput" + str(throughput) + "pkts / sec")

    flogptr.close()
    fptr.close()


if __name__ == "__main__":
    print("packet loss probabillity :", end = "")
    lossp = float(input())

    if lossp > 1 or lossp < 0:
        print("Wrong probabillity!")
        exit(1)

    receiverSocket = socket(AF_INET, SOCK_DGRAM)
    receiverSocket.bind(('', port))
    socketBufferSize = receiverSocket.getsockopt(SOL_SOCKET,SO_RCVBUF)

    print("socket recv buffer size : {0}".format(socketBufferSize))

    if socketBufferSize < 1000000:
        receiverSocket.setsockopt(SOL_SOCKET,SO_RCVBUF, 1000000)

    print("socket recv buffer size updated : 10000000")

    addrque = []

    while True:
        recvbyte, recvaddr = receiverSocket.recvfrom(bufferSize)

        if addrque.count(recvaddr) == 0:
            addrque.append(recvaddr)
            recvFileName = recvbyte.decode()
            if recvFileName != '':
                print(recvFileName)
                th = threading.Thread(target=filereceive, args=(receiverSocket, recvFileName, recvaddr))
                th.start()
        else:
            shrdque.append((recvbyte, recvaddr))
