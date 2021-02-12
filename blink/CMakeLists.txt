cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(blink_project)

pico_sdk_init()

add_executable(blink
  blink.cpp
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(blink pico_stdlib)

pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink)
# ELF file (executable linkable format)

# add url via pico_set_program_url
#auto_set_url(blink)