#include <iostream>
#include <string>
#include <map>

#include "server.cpp"
#include "utils.cpp"
#include "connection.cpp"
#include "router.cpp"

#include "transaction_generated.h"
#include "flatbuffers/flatbuffers.h"

#define SERVER_ADDRESS INADDR_ANY
#define SERVER_PORT 5220

int main(int argc, char** argv) {
    // allocate and set server address on stack
    sockaddr_in server_address;

    std::memset((void*) &server_address, 0, sizeof(sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(SERVER_ADDRESS);
    server_address.sin_port = htons(SERVER_PORT);

    StreamServer server = StreamServer(&server_address, &router);

    server.serve_forever();
}
