#ifndef __IOTA_PLATFORM_H__
#define __IOTA_PLATFORM_H__

// Platform independent headers.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// If on Windows then handle using the winsock library.
#ifdef __IOTA_WIN__

// x64 Windows uses a newer version of the winsock library.
#ifdef __IOTA_WIN64__
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <winsock.h>
typedef int socklet_t;
#endif  // __IOTA_WIN64__

#else // __IOTA_UNIX__

// Use regular BSD sockets and types
#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netdb.h>

#endif // __IOTA_WIN__

#endif // __IOTA_PLATFORM_H__
