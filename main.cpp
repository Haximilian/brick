#include <iostream>

#include "server.cpp"

#include <arpa/inet.h>

// consider using cstdio

void myhandler() {
    std::cout << "HELLO WORLD" << std::endl;
}

int main(int argc, char** argv) {
    StreamServer server = StreamServer(htonl(INADDR_ANY), htons(5220), &myhandler);
    server.serve_forever();
}