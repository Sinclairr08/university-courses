from socket import *
from sys import getsizeof
import threading
from datetime import *

import os
import sys

BUFFERSIZE = 1024
serverPort = 10080
CRLF = '\r\n'

def serverConnect(socket):
    requestMessage = ''
    responseMessage = ''
    while True:
        data = socket.recv(BUFFERSIZE)
        requestMessage += data.decode()

        if not data or getsizeof(data) < BUFFERSIZE:
            break

    getMessage = requestMessage.split(CRLF)
    print(requestMessage)

    if getMessage[0] == '':
        socket.close()
        return 1

    method, fileName = getMessage[0].split(' ')[0:2]
    if method == 'GET' or method == 'Post':
        fileName = fileName[1:len(fileName)]

        if fileName == '':
            fileName = 'index.html'

        elif fileName == 'secret.html':
            Tag = 0
            for msg in getMessage:
                header = msg.split(' ')[0]
                if header == 'Referer:':
                    Tag = 1
                    break

            if Tag == 0:
                responseMessage += 'HTTP/1.1 403 Forbidden' + CRLF + CRLF
                print(responseMessage)
                socket.sendall(responseMessage.encode())
                socket.close()
                return 1

        try:
            fptr = open(os.path.join(sys.path[0], fileName), 'rb')
        except:
            responseMessage += 'HTTP/1.1 404 Not Found' + CRLF + CRLF
            socket.sendall(responseMessage.encode())
            print(responseMessage)
            socket.close()
            return 1


        responseMessage += 'HTTP/1.1 200 OK' + CRLF + CRLF

        """
        responseMessage += 'Connection: Keep-Alive' + CRLF
        responseMessage += 'Keep-Alive: timeout=30, max=99' + CRLF
        responseMessage += 'Set-Cookie: id=1234; Expires='
    

        nowtime = datetime.now()
        expiretime = nowtime + timedelta(seconds=30)
        expirestring = expiretime.strftime("%a, %d %h %Y %H:%M:%S") + " GMT"

        responseMessage += expirestring + CRLF + CRLF
        """

        socket.sendall(responseMessage.encode())

        print(responseMessage)

        fdata = fptr.read(BUFFERSIZE)
        while fdata:
            socket.sendall(fdata)
            fdata = fptr.read(BUFFERSIZE)

    else:
        responseMessage += 'HTTP/1.1 400 Bad Request' + CRLF + CRLF
        socket.sendall(responseMessage.encode())

    socket.close()
    return 0

if __name__ == "__main__":
    serverSocket = socket(AF_INET, SOCK_STREAM)
    serverSocket.bind(('', serverPort))
    serverSocket.listen(10)
    print("The server is ready to recieve")
    while True:
        connectionSocket, addr = serverSocket.accept()
        th = threading.Thread(target = serverConnect, args=(connectionSocket, ))
        th.start()