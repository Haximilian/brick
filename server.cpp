#include <cstring>

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "server.hpp"

#define BACKLOG 8

StreamServer::StreamServer(
    sockaddr_in* server_address, 
    void (*request_handler)(sockaddr_in* client_address, int conn_socket)) 
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
        sockaddr_in client_address;
        socklen_t address_length = sizeof(sockaddr_in);
        int connection = accept_request((sockaddr*) &client_address, &address_length);
        
        request_handler(&client_address, connection);

        close_request(connection);
    }
}

void StreamServer::bind_server() {
    bind(this->receive_socket, (sockaddr*) server_address, sizeof(sockaddr_in));
}

void StreamServer::activate_server() {
    listen(this->receive_socket, BACKLOG);
}

int StreamServer::accept_request(sockaddr* client_address, socklen_t* address_length) {
    return accept(this->receive_socket, client_address, address_length);
}

void StreamServer::close_request(int connection) {
    close(connection);
}
