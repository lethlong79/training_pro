#include "../include/Server.h"
#include <string>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;

// Abstract SocketInterface class
class SocketInterface {
public:
    virtual void Write(const string& buffer) = 0;
    virtual int connect(int sockfd, const struct sockaddr *addr,
                   socklen_t addrlen) = 0;
    ~SocketInterface() = default;
};

// The Socket class implements the SocketInterface's Write() method
class Socket : public SocketInterface {
public:
    Socket() {};
    void Write(const std::string& buffer) override {};

    int connect(int sockfd, const struct sockaddr *addr,
                   socklen_t addrlen) override 
    {
        return 0;
    };
    ~Socket() = default;
};

// The MockSocket class implements the SocketInterface's Write() method
// But this time using GMock's Method Macro
class MockSocket : public Socket {
public:
    MOCK_METHOD(void, Write, (const string& buffer), (override));
    MOCK_METHOD(int, connect, (int sockfd, const struct sockaddr *addr,
                   socklen_t addrlen), (override));
    ~MockSocket() = default;
};

// int connect(int sockfd, const struct sockaddr *addr,
//                    int addrlen) 
//     {
//         printf("Hello\n");
//         return 0;
//     };