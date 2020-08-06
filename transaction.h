#include "transaction_generated.h"
#include "flatbuffers/flatbuffers.h"

// you may want this to be part of a connection class

// clear builder
// make sure socket is blocking and waits for response
int start(int socket, flatbuffers::FlatBufferBuilder builder);

void commit(int socket, flatbuffers::FlatBufferBuilder builder, int transaction);