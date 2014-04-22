#ifndef __IOTA_TYPES_H__
#define __IOTA_TYPES_H__

#include "iota-platform.h"

namespace iota
{
    namespace net
    {
        // Generic protocol signifier. 
        enum proto_t { TCP, UDP };

        // Port type
        typedef unsigned short port_t;

        // Host type
        typedef const char* host_t;

        // Socket Config Info
        typedef struct {
            host_t host;
            port_t port; 
            proto_t protocol;
        } socket_config;

#define IOTA_NET_ANY "0.0.0.0"

#ifdef __IOTA_WIN__
#define IOTA_INVALID_SOCKET INVALID_SOCKET
        typedef SOCKET IOTA_SOCKET;
#else
#define IOTA_INVALID_SOCKET -1
        typedef int IOTA_SOCKET;
#endif
    }
}

#endif // __IOTA_TYPES_H__

