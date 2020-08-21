#include "unistd.h"

#include "conn.hpp"

Connection::Connection(int conn_socket, flatbuffers::FlatBufferBuilder* builder) {
    this->conn_socket = conn_socket;
    this->builder = builder;
}

void Connection::start() {
    // clear buffer builder
    builder->Clear();
    // create flatbuffer
    auto c = scheduler::CreateMetaCommand(*builder, scheduler::Action::Action_Start);
    builder->Finish(c, "META");

    flatbuffers::uoffset_t struct_size = builder->GetSize();
    flatbuffers::uoffset_t send_size = htons(struct_size);
    write(conn_socket, &send_size, sizeof(flatbuffers::uoffset_t));

    write(conn_socket, builder->GetBufferPointer(), struct_size);

    // define transaction identifier type
    uint32_t receive;
    read(conn_socket, &receive, sizeof(uint32_t));
    transaction = ntohs(receive);
}

scheduler::ReadResult* Connection::read_value(std::string key) {
    // assert that transaction number has been set...
    
    builder->Clear();

    auto k = builder->CreateString(key);
    auto r = scheduler::CreateRead(*builder, k, transaction);
    builder->Finish(r, "RMSG");
    
    flatbuffers::uoffset_t struct_size = builder->GetSize();
    // htons
    write(conn_socket, &struct_size, sizeof(flatbuffers::uoffset_t));

    write(conn_socket, builder->GetBufferPointer(), struct_size);

    return nullptr;
}

scheduler::WriteStatus* Connection::write_value(std::string key, std::string value) {
    return nullptr;
}
