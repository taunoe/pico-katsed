cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(interrupt_project)

pico_sdk_init()

add_executable(interrupt
interrupt.cpp
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(interrupt pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(interrupt 1)
pico_enable_stdio_uart(interrupt 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(interrupt)

# add url via pico_set_program_url
#example_auto_set_url(interrupt)
