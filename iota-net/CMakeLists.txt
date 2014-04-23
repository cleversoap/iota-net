include_directories(include)

file(GLOB_RECURSE SRC_FILES src/*)

add_library(
    ${LIBRARY_NAME}
    SHARED
    ${SRC_FILES}
    )

