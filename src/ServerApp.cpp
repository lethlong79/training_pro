#include "../include/Server.h"
#include <thread>

using namespace std;

int main() {

    Server * s = new Server();

    thread socketThread(&Server::handleMsg, s);
    thread connectThread(&Server::waitForConnection, s);

    socketThread.join();
    connectThread.join();

    return 0;
}