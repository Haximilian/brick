#include <sys/socket.h>
#include <netinet/in.h>

class StreamServer {
    public:
        StreamServer(
            sockaddr_in* server_address, 
            void (*request_handler)(sockaddr_in* client_address));

        void serve_forever();

    private:
        sockaddr_in* server_address;
        
        int receive_socket;

        void bind_server();

        void activate_server();

        int accept_request(sockaddr* client_address, socklen_t* address_length);

        void (*request_handler)(sockaddr_in* client_address);

        void close_request(int connection);
};
