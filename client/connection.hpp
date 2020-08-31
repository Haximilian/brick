#include "transaction_generated.h"

class Connection {
    public:
        Connection(
            int conn_socket,
            flatbuffers::FlatBufferBuilder* builder);

        void start_transaction();

        scheduler::ReadResult* read_value(std::string key);

        scheduler::WriteStatus* write_value(std::string key, std::string value);

        void commit_transaction(int transaction);
        
    private:
        int conn_socket;

        int32_t transaction;
        
        flatbuffers::FlatBufferBuilder* builder;
};
