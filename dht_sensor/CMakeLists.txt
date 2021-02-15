cmake_minimum_required(VERSION 3.13)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
#set(PICO_SDK_PATH "../../../pico-sdk")

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(dht_sensor_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(dht_sensor
        dht_sensor.cpp
        )

pico_set_program_name(dht_sensor "dht_sensor")
pico_set_program_version(dht_sensor "0.1")

# enable usb output, disable uart output
pico_enable_stdio_usb(dht_sensor 1)
pico_enable_stdio_uart(dht_sensor 0)

target_link_libraries(dht_sensor pico_stdlib)

pico_add_extra_outputs(dht_sensor)

# add url via pico_set_program_url
#example_auto_set_url(dht_sensor)
