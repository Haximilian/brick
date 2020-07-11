#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <string.h>

// 192.168.0.11
// 0xC0A8000B
#define SERVER_ADDRESS "192.168.0.11"


#define SERVER_PORT 5220

int main(int argc, char** argv) {
    int conn_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, (void*) &server_addr.sin_addr);

    connect(conn_socket, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in));
    
    return EXIT_SUCCESS;
}
