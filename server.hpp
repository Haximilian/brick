#include <sys/socket.h>
#include <netinet/in.h>

class StreamServer {
    public:
        StreamServer(
            struct sockaddr_in* server_address, 
            void (*request_handler)(struct sockaddr_in* client_address));

        void serve_forever();

    private:
        struct sockaddr_in* server_address;
        
        int receive_socket;

        void bind_server();

        void activate_server();

        int accept_request(struct sockaddr* client_address, socklen_t* address_length);

        void (*request_handler)(struct sockaddr_in* client_address);

        void close_request(int connection);
};
