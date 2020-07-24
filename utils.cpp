#include "utils.hpp"

void print_client_address(sockaddr_in* client_address) {
    char* address_array = (char*) &(client_address->sin_addr.s_addr);

    std::cout << "client address: ";
    std::cout << (int)(address_array[0]) << ".";
    std::cout << (int)(address_array[1]) << ".";
    std::cout << (int) (address_array[2]) << ".";
    std::cout << (int) (address_array[3]) << std::endl;

    std::cout  << std::endl;

    std::cout << "client port: ";
    std::cout << ntohs(client_address->sin_port) << std::endl;

    std::cout  << std::endl;
}