# All examples will include the main iota-net headers
include_directories(../iota-net/include)

file(GLOB EXAMPLES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./*)

foreach(example ${EXAMPLES})

    if( IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${example} )

        # Name of the example to use
        string(SUBSTRING ${example} 2 -1 EXAMPLE_NAME)

        # Add the subdirectory
        add_subdirectory(${example})

        # Add the test
        add_test(${EXAMPLE_NAME} ${example}/${EXAMPLE_NAME})

    endif()

endforeach()

