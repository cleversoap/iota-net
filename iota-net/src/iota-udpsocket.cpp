#include "iota-udpsocket.h"

iota::net::UdpSocket::UdpSocket(iota::net::host_t host, iota::net::port_t port) : iota::net::Socket(host, port, iota::net::UDP)
{
}
