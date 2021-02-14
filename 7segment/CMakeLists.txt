cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(joystick_display_project)

pico_sdk_init()

add_executable(7segment
        7segment.cpp
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(7segment pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(7segment 1)
pico_enable_stdio_uart(7segment 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(7segment)

# add url via pico_set_program_url
#example_auto_set_url(7segment)