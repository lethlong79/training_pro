#ifndef SOCDEF_H
#define SOCDEF_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 5000
#define SIZE_OF_BUFFER 1024
#define SERVER_ADDRESS "127.0.0.1"

class SockDef {
protected:
    struct sockaddr_in serverAddr;
public:
    SockDef() {
        memset(&serverAddr, '0', sizeof(serverAddr));

        //Server addressa
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
        serverAddr.sin_port = htons(PORT); 
    }

    // ~SockDef();
};

#endif