cmake_minimum_required (VERSION 2.6)
project (iota-net)

set (iota-net_VERSION_MAJOR 0)
set (iota-net_VERSION_MINOR 1)

# Platform defines
if ( ${CMAKE_SYSTEM_NAME} MATCHES "Windows" )

    # Generic windows define
    add_definitions(-D__IOTA_WIN__)

    # 64bit Windows
    if ( ${CMAKE_SIZEOF_VOID_P} EQUAL 8 )
        add_definitions(-D__IOTA_WIN64__)
    endif ()

else ()

    add_definitions(-D__IOTA_UNIX__)

endif()

# Library
set (LIBRARY_NAME iota-net)

include_directories (iota-net/include)
file (GLOB_RECURSE SRC_FILES iota-net/src/*)
file (GLOB_RECURSE INCLUDE_FILES iota-net/include/*)

add_library(
    ${LIBRARY_NAME}
    SHARED
    ${SRC_FILES}
    ${INCLUDE_FILES}
    )

# Examples
