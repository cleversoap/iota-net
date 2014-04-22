#include "iota-tcpsocket.h"

iota::net::TcpSocket::TcpSocket(iota::net::host_t host, iota::net::port_t port) : iota::net::Socket(host, port, iota::net::TCP)
{
}
