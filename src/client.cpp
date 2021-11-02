#include "../include/Client.h"
#include <thread>
#include <stdlib.h>
// #include <string.h>

using namespace std;

void Client::sendDataFromKeyboard () {
    int sentByte;
    while(true) {
        memset(sendBuffer, '0', SIZE_OF_BUFFER);

        //Treat spacewhite as a character
        fgets(sendBuffer, SIZE_OF_BUFFER, stdin);

        //Dont send the enter: length - 1
        sentByte = send(connFd , sendBuffer , strlen(sendBuffer) - 1, 0 ); 
    }
}

void Client::showDataFromServer () {
    //Wait for incomming msg
    memset(recvBuffer, '0', SIZE_OF_BUFFER);
    while(true) {
        int msgLen = recv(connFd, recvBuffer, strlen(recvBuffer), 0);
        if (msgLen > 0) {
            printf("Other side: %.*s\n", msgLen, recvBuffer);
        }
        sleep(1);
    }
}

int main() {
    Client* c = new Client();

    thread typingThread(&Client::sendDataFromKeyboard, c);
    thread showingThread(&Client::showDataFromServer, c);

    typingThread.join();
    showingThread.join();
    return 0;
}
