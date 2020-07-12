#include <cstring>

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "server.hpp"

#define BACKLOG 8

StreamServer::StreamServer(
    struct sockaddr_in* server_address, 
    void (*request_handler)(struct sockaddr_in* client_address)) 
{
    receive_socket = socket(AF_INET, SOCK_STREAM, 0);

    this->request_handler = request_handler;
    this->server_address = server_address;

    bind_server();
    activate_server();
}

void StreamServer::serve_forever() {
    while (true) {
        // allocate on stack
        // address_length: value-result argument
        struct sockaddr_in client_address;
        socklen_t address_length = sizeof(struct sockaddr_in);
        int connection = accept_request((sockaddr*) &client_address, &address_length);
        
        request_handler(&client_address);

        close_request(connection);
    }
}

void StreamServer::bind_server() {
    bind(this->receive_socket, (struct sockaddr*) server_address, sizeof(struct sockaddr_in));
}

void StreamServer::activate_server() {
    listen(this->receive_socket, BACKLOG);
}

int StreamServer::accept_request(struct sockaddr* client_address, socklen_t* address_length) {
    return accept(this->receive_socket, client_address, address_length);
}

void StreamServer::close_request(int connection) {
    close(connection);
}
