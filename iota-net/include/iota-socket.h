#ifndef __IOTA_SOCKET_H__
#define __IOTA_SOCKET_H__

#include "iota-platform.h"
#include "iota-types.h"

namespace iota
{
    namespace net
    {
        class Socket
        {
            public:
                Socket(host_t host, port_t port, proto_t protocol);
                Socket(const socket_config &config);
                /*
                virtual void connect();
                virtual void bind();
                virtual void listen();
                virtual void close();
                */

            protected:
                virtual void init(const socket_config &config);
                IOTA_PLATFORM_SOCKET _socket;
            
            private:
                static unsigned short socket_count;
        };
    }
}

#endif // __IOTA_SOCKET_H__
