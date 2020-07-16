#include <iostream>
#include <string>

#include "server.cpp"
// #include "transaction_generated.h"

#include <arpa/inet.h>

// consider using cstdio

#define SERVER_ADDRESS INADDR_ANY
#define SERVER_PORT 5220

void request_parser(sockaddr_in* client_address, int conn_socket) {
    char* address_array = (char*) &(client_address->sin_addr.s_addr);

    std::cout << "client address: ";
    std::cout << (int)(address_array[0]) << ".";
    std::cout << (int)(address_array[1]) << ".";
    std::cout << (int) (address_array[2]) << ".";
    std::cout << (int) (address_array[3]) << std::endl;

    std::cout  << std::endl;

    std::cout << "client port: ";
    std::cout << ntohs(client_address->sin_port) << std::endl;

    std::cout  << std::endl;

    std::cout << "sleeping for 3 seconds..." << std::endl;

    char* sample_string = "Hello from Maximilian!\n";
    write(conn_socket, (void*) sample_string, 23);
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