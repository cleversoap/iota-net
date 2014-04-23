#include "iota-socket.h"

unsigned short iota::net::Socket::socket_count = 0;

iota::net::Socket::Socket(iota::net::host_t host, iota::net::port_t port, iota::net::proto_t protocol)
{
    iota::net::socket_config config = {host, port, protocol};
    this->init(config);
}

iota::net::Socket::Socket(const iota::net::socket_config &config)
{
    this->init(config);
}

void iota::net::Socket::init(const iota::net::socket_config &config)
{
    #ifdef __IOTA_WIN__
    if (iota::net::Socket::socket_count == 0) {
        WSADATA wsaData;
        if (WSAStartup(__IOTA_WIN_MAKEWORD__, &wsaData) != 0) {
            fprintf(stderr, "iota-net failed to initialise winsock\n");
        }
    }
    #endif

    // Determine if the socket is ipv4 or ipv6
    struct addrinfo* ai;

    // Define some parameters to later use in socket construction
    struct addrinfo hints;

    // Protocol specific implementations
    switch (config.protocol)
    {
        case iota::net::TCP:
            hints.ai_socktype = SOCK_STREAM;
            hints.ai_protocol = IPPROTO_TCP;
            break;

        case iota::net::UDP:
            hints.ai_socktype = SOCK_DGRAM;
            hints.ai_protocol = IPPROTO_UDP;
            break;

        default:
            fprintf(stderr, "Could not use the protocol provided\n");
    }

    // Convert the port value to the correct type
    char port[5];
    snprintf(port, sizeof(port), "%d", config.port); 

    // Get as much info as possible for the socket
    if (getaddrinfo(config.host, port, NULL, &ai) != 0) {

        fprintf(stderr, "Could not use getaddrinfo on %s:%s\n", config.host, port);

    } else {

        // Initialise the socket member
        this->_socket = socket(ai->ai_family, hints.ai_socktype, hints.ai_protocol);

        // Check it is valid
        if (this->_socket == IOTA_INVALID_SOCKET) {
            fprintf(stderr, "Invalid iota-socket was created.\n");
        } else {
            iota::net::Socket::socket_count++;
        }
    }

    // Clean up
    // freeaddrinfo(ai);
}

bool iota::net::Socket::connect()
{
    return true;
}

bool iota::net::Socket::listen()
{
    return true;
}

bool iota::net::Socket::close()
{
    return true;
}

