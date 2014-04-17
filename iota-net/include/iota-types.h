#ifndef __IOTA_TYPES_H__
#define __IOTA_TYPES_H__

#include "iota-platform.h"

namespace iota
{
    namespace net
    {
        // Generic protocol signifier. 
        enum protocol { TCP, UDP };

        // Address format
        enum address_fmt { IPV4, IPV6 };

    }
}

#endif // __IOTA_TYPES_H__

