# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.13)

# Set the name of the project
project(blink_led)

# Add your source files here
add_executable(${PROJECT_NAME}
    main.c
)

# Link the necessary libraries
target_link_libraries(${PROJECT_NAME} PRIVATE pico_blink)

# Generate additional output files
pico_add_extra_outputs(${PROJECT_NAME})
