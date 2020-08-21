#include "transaction_generated.h"

// consider creating a transaction class

class Connection {
    public:
        Connection(
            int conn_socket,
            flatbuffers::FlatBufferBuilder* builder,
            int transaction);

        int start();

        scheduler::ReadResult* read(std::string key);

        scheduler::WriteStatus* store(std::string key, std::string value);

        void commit(int transaction);
        
    private:
        int conn_socket;
        
        flatbuffers::FlatBufferBuilder* builder;

        int transaction;
};
