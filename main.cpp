#include <iostream>
#include <string>

#include "server.cpp"
#include "utils.cpp"
#include "conn.cpp"

#include "transaction_generated.h"
#include "flatbuffers/flatbuffers.h"

#define SERVER_ADDRESS INADDR_ANY
#define SERVER_PORT 5220

uint32_t current_transaction = 0;

void request_handler(sockaddr_in* client_address, int conn_socket) {
    print_client_address(client_address);

    flatbuffers::uoffset_t struct_size;
    read(conn_socket, &struct_size, sizeof(flatbuffers::uoffset_t));

    void* command = malloc(struct_size);
    read(conn_socket, command, struct_size);

    const char* command_type = flatbuffers::GetBufferIdentifier(command, false);
    
    if (strncmp(command_type, "WOPP", 4) == 0) {
        const scheduler::Write* myobj = flatbuffers::GetRoot<scheduler::Write>(command);
        std::cout << myobj->key()->str() << std::endl;
    } else if (strncmp(command_type, "RMSG", 4) == 0) {
        std::cout << "Received RMSG" << std::endl;
    } else if (strncmp(command_type, "META", 4) == 0) {
        uint32_t to_send = htons(current_transaction);
        current_transaction += 1;
        write(conn_socket, &to_send, sizeof(uint32_t));
    }

    free(command);
    command = nullptr;
}

int main(int argc, char** argv) {
    // allocate and set server address on stack
    sockaddr_in server_address;

    std::memset((void*) &server_address, 0, sizeof(sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(SERVER_ADDRESS);
    server_address.sin_port = htons(SERVER_PORT);

    StreamServer server = StreamServer(&server_address, &request_handler);

    server.serve_forever();
}
