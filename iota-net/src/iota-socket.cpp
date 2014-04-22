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
    // Determine if the socket is ipv4 or ipv6
    struct addrinfo* ai;

    if (getaddrinfo(config.host, NULL, NULL, &ai) != 0) {
        fprintf(stderr, "Could not use getaddrinfo on %s\n", config.host);
    }

    char hostname[NI_MAXHOST] = "";
    if (getnameinfo(ai->ai_addr, ai->ai_addrlen, hostname, NI_MAXHOST, NULL, 0, 0) != 0) {
        fprintf(stderr, "Could not use getnameinfo\n");
    }

    if (*hostname != '\0') {
        printf("hostname: %s\n", hostname);
    }

    if (ai->ai_family == AF_INET)
        printf("IPV4\n");
    else if (ai->ai_family == AF_INET6) {
        printf("IPV6\n");
    }

    freeaddrinfo(ai);

    // Address family type
    // Port
    // protocol
}
