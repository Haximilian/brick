#include "transaction_generated.h"
#include "flatbuffers/flatbuffers.h"

// consider creating a transaction class

class Connection {
    public:
        Connection(
            int conn_socket,
            flatbuffers::FlatBufferBuilder builder);

        int start();

        char* read(int transaction);

        bool write(int transaction, char* to_write, flatbuffers::uoffset_t size);

        void commit(int transaction);
        
    private:
        int conn_socket;
        
        flatbuffers:FlatBufferBuilder builder;
};
