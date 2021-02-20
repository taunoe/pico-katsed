cmake_minimum_required(VERSION 3.13)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
#set(PICO_SDK_PATH "../../../pico-sdk")

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(i2c_scanner C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(lcd_1602_i2c
        lcd_1602_i2c.cpp
        )

pico_set_program_name(lcd_1602_i2c "lcd_1602_i2c")
pico_set_program_version(lcd_1602_i2c "0.1")
        
# enable usb output, disable uart output
pico_enable_stdio_usb(lcd_1602_i2c 1)
pico_enable_stdio_uart(lcd_1602_i2c 0)

# Pull in our (to be renamed) simple get you started dependencies
target_link_libraries(lcd_1602_i2c pico_stdlib hardware_i2c)

# create map/bin/hex file etc.
pico_add_extra_outputs(lcd_1602_i2c)

