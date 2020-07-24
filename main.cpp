#include <iostream>
#include <string>

#include "server.cpp"
#include "utils.cpp"
#include "transaction_generated.h"
#include "flatbuffers/flatbuffers.h"

#define SERVER_ADDRESS INADDR_ANY
#define SERVER_PORT 5220

void request_parser(sockaddr_in* client_address, int conn_socket) {
    print_client_address(client_address);

    flatbuffers::FlatBufferBuilder builder;

    u_int32_t struct_size;
    read(conn_socket, &struct_size, sizeof(u_int32_t));

    // flushes on newline
    std::cout << struct_size << std::endl;

    void* serialized_obj = malloc(struct_size);
    read(conn_socket, serialized_obj, struct_size);

    // return object identifier
    const char* identifier = flatbuffers::GetBufferIdentifier(serialized_obj, false);

    std::cout << identifier << std::endl;
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