#include <iostream>

#include "server.cpp"

#include <arpa/inet.h>

// consider using cstdio

#define SERVER_ADDRESS INADDR_ANY
#define SERVER_PORT 5220

void request_parser(sockaddr_in* client_address) {
    std::cout << "HELLO WORLD" << std::endl;
}

int main(int argc, char** argv) {
    // allocate and set server address on stack
    sockaddr_in server_address;

    std::memset((void*) &server_address, 0, sizeof(sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(SERVER_ADDRESS);
    server_address.sin_port = htons(SERVER_PORT);

    StreamServer server = StreamServer(&server_address, &request_parser);

    server.serve_forever();
}