#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>

#include <unistd.h>
#include <iostream>

#include "transaction_generated.h"
#include "rpc.hpp"

#define SERVER_ADDRESS "localhost"
#define SERVER_PORT 5220

int main(int argc, char** argv) {
    int conn_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, (void*) &server_addr.sin_addr);

    connect(conn_socket, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in));

    flatbuffers::FlatBufferBuilder builder;
    auto mykey = builder.CreateString("Maximilian");
    auto myvalue = builder.CreateString("1 + 1 = 3");
    auto keymsg = scheduler::CreateWrite(builder, mykey, myvalue);

    builder.Finish(keymsg);

    uint32_t struct_size = htonl((uint32_t) builder.GetSize());
    write(conn_socket, &struct_size, sizeof(flatbuffers::uoffset_t));

    uint32_t command_type = htonl(rpc::write_value);
    write(conn_socket, &struct_size, sizeof(flatbuffers::uoffset_t));

    write(conn_socket, builder.GetBufferPointer(), struct_size);
    
    return EXIT_SUCCESS;
}
