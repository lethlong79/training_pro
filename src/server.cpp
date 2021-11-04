#include "../include/Server.h"
#include <stdio.h>
#include <sys/socket.h>
#include <thread>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

void Server::handleMsg() {
    int byteOfRead1 = 0;
    int byteOfRead2 = 0;

    while ((sockFd[0] == 0) || (sockFd[1] == 0)) {};

    while (true) {
        memset(dataBuffer, '0', SIZE_OF_BUFFER);

        byteOfRead1 = recv(sockFd[0], dataBuffer, strlen(dataBuffer), MSG_DONTWAIT);
        byteOfRead2 = recv(sockFd[1], dataBuffer, strlen(dataBuffer), MSG_DONTWAIT);
        if (byteOfRead1 > 0) {
            //Có msg ở trong buffer => gửi vào newSocket
            send(sockFd[1] , dataBuffer , byteOfRead1 , 0 );
            byteOfRead1 = 0;
            memset(dataBuffer, '0', SIZE_OF_BUFFER);
        } else if (byteOfRead2 > 0) {
            send(sockFd[0] , dataBuffer , byteOfRead2 , 0 );
            byteOfRead2 = 0;
            memset(dataBuffer, '0', SIZE_OF_BUFFER);
        }
        sleep(1);
    }
}

// void Server::waitForConnection() {

//     printf("Waiting for new connection\n");
//     for (int i = 0; i < NUM_OF_CLIENTS; i++) {
//         sockFd[i] = accept(listenFd, (struct sockaddr *)&serverAddr, 
//                         (socklen_t*)&serverAddr);
//         printf("%d client connected\n", i + 1);
//     }
   
// }
void Server::waitForConnection() {

    printf("Waiting for new connection\n");
   
}

// int main() {

//     Server * s = new Server();

//     thread socketThread(&Server::handleMsg, s);
//     thread connectThread(&Server::waitForConnection, s);

//     socketThread.join();
//     connectThread.join();

//     return 0;
// }