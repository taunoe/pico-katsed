cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(adc_hello_project)

pico_sdk_init()

add_executable(adc_hello
adc_hello.cpp
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(adc_hello pico_stdlib hardware_adc)

# enable usb output, disable uart output
pico_enable_stdio_usb(adc_hello 1)
pico_enable_stdio_uart(adc_hello 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(adc_hello)
