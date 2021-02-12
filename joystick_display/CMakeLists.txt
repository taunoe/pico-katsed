cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(joystick_display_project)

pico_sdk_init()

add_executable(joystick_display
        joystick_display.cpp
        )

target_link_libraries(joystick_display pico_stdlib hardware_adc)

# enable usb output, disable uart output
pico_enable_stdio_usb(joystick_display 1)
pico_enable_stdio_uart(joystick_display 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(joystick_display)

# add url via pico_set_program_url
#example_auto_set_url(joystick_display)
