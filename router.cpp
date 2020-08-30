#include <netinet/in.h>

#include "transaction_generated.h"

#include "rpc.hpp"
#include "utils.hpp"

#include "brick.cpp"

void router(sockaddr_in* client_address, int conn_socket) {
    print_client_address(client_address);

    // sruct_size
    uint32_t struct_size;
    read(conn_socket, &struct_size, sizeof(uint32_t));
    struct_size = ntohl(struct_size);

    // command_type
    uint32_t command_type;
    read(conn_socket, &command_type, sizeof(uint32_t));
    command_type = ntohl(command_type);

    void* command = malloc(struct_size);
    read(conn_socket, command, struct_size);

    switch (command_type)
    {
        case rpc::start_transaction: {
            std::cout << "server | start received" << std::endl;
            uint32_t default_transaction = htonl(Brick::start_transaction());
            write(conn_socket, &default_transaction, sizeof(default_transaction));
            break;
        }
        case rpc::read_value: {
            std::cout << "server | read received" << std::endl;
            const scheduler::Read* read_obj = flatbuffers::GetRoot<scheduler::Read>(command);
            std::cout << read_obj->key()->str() << std::endl;
            break;
        }
        case rpc::write_value: {
            std::cout << "server | write received" << std::endl;
            const scheduler::Write* write_obj = flatbuffers::GetRoot<scheduler::Write>(command);
            std::cout << write_obj->key()->str() << std::endl;
            break;
        }
        case rpc::commit_transaction: {
            std::cout << "server | commit received" << std::endl;
            break;
        }
        default: {
            std::cout << "server | unknown command received" << std::endl;
            break;
        }
    }

    // unknown or start may cause free nullptr...
    free(command);
    command = nullptr;
}