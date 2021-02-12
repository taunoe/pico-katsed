cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(adc_console_project)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(adc_console
  adc_console.cpp
  )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(adc_console pico_stdlib hardware_adc)

# enable usb output, disable uart output
pico_enable_stdio_usb(adc_console 1)
pico_enable_stdio_uart(adc_console 0)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(adc_console)