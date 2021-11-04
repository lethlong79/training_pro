#include "../include/Server.h"
#include "./socket_mock.cpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

TEST (Server, InvalidParam) { 
    MockSocket _mockSocket;
    Server _server;

    EXPECT_CALL(_mockSocket, connect(_, _, _ ))
        .Times(AtLeast(2));
    _server.waitForConnection();
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}