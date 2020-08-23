#include <arpa/inet.h>
#include <unistd.h>

#include "connection.hpp"
#include "rpc.hpp"
#include "transaction_generated.h"

Connection::Connection(int conn_socket, flatbuffers::FlatBufferBuilder* builder) 
{
    this->conn_socket = conn_socket;
    this->builder = builder;
}

void Connection::start_transaction() 
{
    uint32_t struct_size = 0;

    uint32_t struct_size_send_to = htonl(struct_size);
    write(conn_socket, &struct_size_send_to, sizeof(uint32_t));

    uint32_t command_type = htonl(rpc::start_transaction);
    write(conn_socket, &command_type, sizeof(uint32_t));

    uint32_t received_value;
    read(conn_socket, &received_value, sizeof(uint32_t));

    transaction = ntohl(received_value);

    std::cout << transaction << std::endl;
}

scheduler::ReadResult* Connection::read_value(std::string key) 
{
    builder->Clear();

    auto serial_key = builder->CreateString(key);
    auto message = scheduler::CreateRead(*builder, serial_key, transaction);

    builder->Finish(message);

    uint32_t struct_size = (uint32_t) builder->GetSize();

    uint32_t struct_size_send_to = htonl(struct_size);
    write(conn_socket, &struct_size_send_to, sizeof(uint32_t));

    uint32_t command_type = htonl(rpc::read_value);
    write(conn_socket, &command_type, sizeof(uint32_t));

    write(conn_socket, builder->GetBufferPointer(), struct_size);

    return nullptr;
}

scheduler::WriteStatus* Connection::write_value(std::string key, std::string value) 
{
    builder->Clear();

    auto serial_key = builder->CreateString(key);
    auto serial_value = builder->CreateString(value);
    auto message = scheduler::CreateWrite(*builder, serial_key, serial_value, transaction);

    builder->Finish(message);

    uint32_t struct_size = (uint32_t) builder->GetSize();

    uint32_t struct_size_send_to = htonl(struct_size);
    write(conn_socket, &struct_size_send_to, sizeof(uint32_t));

    uint32_t command_type = htonl(rpc::write_value);
    write(conn_socket, &command_type, sizeof(uint32_t));

    write(conn_socket, builder->GetBufferPointer(), struct_size);

    return nullptr;
}