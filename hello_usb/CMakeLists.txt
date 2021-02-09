cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(hello_usb_project)

pico_sdk_init()

add_executable(hello_usb
  hello_usb.cpp
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(hello_usb pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(hello_usb 1)
pico_enable_stdio_uart(hello_usb 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(hello_usb)
# ELF file (executable linkable format)

# add url via pico_set_program_url
# example_auto_set_url(hello_usb) # Error: Unknown CMake command "example_auto_set_url".