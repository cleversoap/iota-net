#ifndef __IOTA_UDPSOCKET_H__
#define __IOTA_UDPSOCKET_H__

#include "iota-socket.h"

namespace iota
{
    namespace net
    {
        class UdpSocket : public Socket
        {
            public:
                UdpSocket(host_t host, port_t port);
        };
    }
}

#endif // __IOTA_UDPSOCKET_H__
