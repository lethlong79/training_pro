#include <gtest/gtest.h>
#include <gmock/gmock.h>
// #include "../include/Server.h"
#include <sys/socket.h>
#include <string>

using namespace std;

int sock_rval;
int sock_rcv;

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
        printf("Hello\n");
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

int accept(int, struct sockaddr * __restrict, socklen_t * __restrict) {
    printf("Calling mock socket (accept)\n");
    return sock_rval;
}


ssize_t recv(int, void *, size_t, int) {
    printf("Calling from mock socket (recv)\n");
    return sock_rcv;
}
