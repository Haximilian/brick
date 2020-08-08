#include "transaction_generated.h"

// consider creating a transaction class

class Connection {
    public:
        Connection(
            int conn_socket,
            flatbuffers::FlatBufferBuilder* builder);

        int start();

        scheduler::ReadResult* read(int transaction, std::string key);

        bool store(int transaction, char* to_write, flatbuffers::uoffset_t size);

        void commit(int transaction);
        
    private:
        int conn_socket;
        
        flatbuffers::FlatBufferBuilder* builder;
};
