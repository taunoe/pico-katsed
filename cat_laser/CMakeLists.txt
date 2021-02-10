cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
project(cat_laser_project)

# Initialize the SDK
pico_sdk_init()

add_executable(cat_laser
cat_laser.cpp
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(cat_laser pico_stdlib hardware_pwm hardware_adc)

# enable usb output, disable uart output
pico_enable_stdio_usb(cat_laser 1)
pico_enable_stdio_uart(cat_laser 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink)
# ELF file (executable linkable format)
