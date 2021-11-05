#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Server.cpp"
#include "./socket_mock.cpp"
#include <string>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

extern int sock_rval;
extern int sock_rcv;

//Check initial values of Server
//2 clients Fd must be 0
TEST (Server, CheckInitialClientFd) {
    Server* _server = new Server();

    EXPECT_EQ(0, _server->getClientFd(0));
    EXPECT_EQ(0, _server->getClientFd(1));
}

//Listen socket is created successfully when it is bigger 0
TEST (Server, CheckInitialServerListenFd) {
    Server* _server = new Server();

    EXPECT_NE(0, _server->getListenFd());
}

//Server wait for 2 clients
TEST (Server, ConnectSuccessful) {
    Server _server;

    sock_rval = 1;
    bool isConnectSuccessful = _server.waitForConnection();
    EXPECT_TRUE(isConnectSuccessful);

    sock_rval = 3;
    isConnectSuccessful = _server.waitForConnection();
    EXPECT_TRUE(isConnectSuccessful);

    sock_rval = 13;
    isConnectSuccessful = _server.waitForConnection();
    EXPECT_TRUE(isConnectSuccessful);
}

TEST (Server, ConnectFail) {
    Server _server;

    sock_rval = -1;
    bool isConnectSuccessful = _server.waitForConnection();
    EXPECT_FALSE(isConnectSuccessful);

    sock_rval = -3;
    isConnectSuccessful = _server.waitForConnection();
    EXPECT_FALSE(isConnectSuccessful);

    sock_rval = 0;
    isConnectSuccessful = _server.waitForConnection();
    EXPECT_FALSE(isConnectSuccessful);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}