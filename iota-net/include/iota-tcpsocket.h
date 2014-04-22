#ifndef __IOTA_TCPSOCKET_H__
#define __IOTA_TCPSOCKET_H__

#include "iota-socket.h"

namespace iota
{
    namespace net
    {
        class TcpSocket : public Socket
        {
            public:
                TcpSocket(host_t host, port_t port);
        };
    }
}

#endif // __IOTA_TCPSOCKET_H__
