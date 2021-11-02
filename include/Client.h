#ifndef CLIENT_H
#define CLIENT_H
#include "./SocDef.h"
#include <stdio.h>
#include <unistd.h>

class Client : public SockDef {
    char recvBuffer[SIZE_OF_BUFFER];
    char sendBuffer[SIZE_OF_BUFFER];
    int connFd;
public:
    Client(): SockDef::SockDef() {
        memset(recvBuffer, '0', SIZE_OF_BUFFER); 
        memset(sendBuffer, '0', SIZE_OF_BUFFER); 
        connFd = socket(AF_INET, SOCK_STREAM, 0);

        if(connect(connFd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            printf("Cannot connet to Server\n");
            close(connFd);
        }
    }

    void sendDataFromKeyboard ();

    void showDataFromServer ();
};

#endif