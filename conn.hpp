#include "transaction_generated.h"

// consider creating a transaction class

class Connection {
    public:
        uint32_t transaction;

        Connection(
            int conn_socket,
            flatbuffers::FlatBufferBuilder* builder);

        void start();

        scheduler::ReadResult* read_value(std::string key);

        scheduler::WriteStatus* write_value(std::string key, std::string value);

        void commit(int transaction);
        
    private:
        int conn_socket;
        
        flatbuffers::FlatBufferBuilder* builder;
};
