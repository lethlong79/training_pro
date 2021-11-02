#ifndef SERVER_H
#define SERVER_H
#include "./SocDef.h"
#include <sys/select.h>
#include <sys/time.h>

#define BACKLOG 10
#define NUM_OF_CLIENTS 2

class Server : public SockDef {
    int listenFd;
    int maxSd;
    int sockFd[NUM_OF_CLIENTS];
    char dataBuffer[SIZE_OF_BUFFER];
public:
    Server() : SockDef::SockDef() {
        sockFd[0] = 0;
        sockFd[1] = 0;
        
        //Create socket
        listenFd = socket(AF_INET, SOCK_STREAM, 0);

        //Assign server address to socket
        bind(listenFd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

        listen(listenFd, BACKLOG);
    }

    // ~Server();
    void waitForConnection();

    void handleMsg();
};

#endif