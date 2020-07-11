#include <sys/socket.h>
#include <netinet/in.h>

class StreamServer {
    public:
        StreamServer(in_addr_t address, in_port_t port, void (*request_handler)(void));

        void serve_forever();

    private:
        struct sockaddr_in server_address;
        
        int receive_socket;

        void bind_server();

        void activate_server();

        int accept_request(sockaddr* client_address, socklen_t* address_length);

        void (*request_handler)(void);

        void close_request(int connection);
};
