# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.13)

# Pull in the Pico SDK
include(pico_sdk_import.cmake)

# Set the name of the project
project(pico_blink)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Create the library target
add_library(pico_blink INTERFACE)

# Specify the source files for the library
target_sources(pico_blink INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/blink.c
)

# Specify the include directories for the library
target_include_directories(pico_blink INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/include
)

# Link the necessary libraries
target_link_libraries(pico_blink INTERFACE
    pico_stdlib
)
