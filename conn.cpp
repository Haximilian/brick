#include "unistd.h"

#include "conn.hpp"

Connection::Connection(int conn_socket, flatbuffers::FlatBufferBuilder* builder) {
    this->conn_socket = conn_socket;
    this->builder = builder;
}

int start() {
    // clear buffer builder
    // create flatbuffer
    // send flatbuffer
    // fcntl, poll, epoll on socket
    // deserialize
    // return transaction number
    return 0;
}

scheduler::ReadResult* Connection::read(int transaction, std::string key) {
    auto k = builder->CreateString(key);
    auto r = scheduler::CreateRead(*builder, k, transaction);
    builder->Finish(r, "RMSG");
    
    flatbuffers::uoffset_t struct_size = builder->GetSize();
    // htons
    write(conn_socket, &struct_size, sizeof(flatbuffers::uoffset_t));

    write(conn_socket, builder->GetBufferPointer(), struct_size);

    return nullptr;
}
