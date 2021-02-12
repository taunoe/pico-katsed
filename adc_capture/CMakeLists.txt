cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(adc_capture_project C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(adc_capture
        adc_capture.cpp
        )

pico_generate_pio_header(adc_capture ${CMAKE_CURRENT_LIST_DIR}/resistor_dac.pio)

target_link_libraries(adc_capture
		pico_stdlib
		hardware_adc
		hardware_dma
		# For the dummy output:
		hardware_pio
		pico_multicore
		)

# create map/bin/hex file etc.
pico_add_extra_outputs(adc_capture)

# enable usb output, disable uart output
#pico_enable_stdio_usb(hello_usb 1)
#pico_enable_stdio_uart(hello_usb 0)

# add url via pico_set_program_url
#example_auto_set_url(adc_dma_capture)
