#include <iota-net.h>

int main (int argc, char** argv)
{
    iota::net::TcpSocket* sock = new iota::net::TcpSocket(IOTA_NET_ANY, 4242);

    return 0;
}
