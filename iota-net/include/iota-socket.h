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
                Socket(protocol proto, address_fmt addr_fmt = IPV4);
        };
    }
}

#endif // __IOTA_SOCKET_H__
