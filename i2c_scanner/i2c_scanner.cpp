/**
 * Copyright 2021 Tauno Erik
 *
 */

// Sweep through all 7-bit I2C addresses, to see if any slaves are present on
// the I2C bus. Print out a table that looks like this:
//
// I2C Bus Scan
//   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
// 0
// 1       @
// 2
// 3             @
// 4
// 5
// 6
// 7
//
// E.g. if slave addresses 0x12 and 0x34 were acknowledged.

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

const int SDA_PIN = 4;
const int SCL_PIN = 5;
int counter{};

// I2C reserves some addresses for special purposes.
// We exclude these from the scan.
// These are any addresses of the form 000 0xxx or 111 1xxx
bool reserved_addr(uint8_t addr) {
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}

void tauno_i2c_init(int sda_pin, int scl_pin) {
    // This example will use I2C0 on GPIO4 (SDA) and GPIO5 (SCL)
    i2c_init(i2c0, 100 * 1000);
    gpio_set_function(sda_pin, GPIO_FUNC_I2C);
    gpio_set_function(scl_pin, GPIO_FUNC_I2C);
    gpio_pull_up(sda_pin);
    gpio_pull_up(scl_pin);
}

void tauno_i2c_scanner() {
    // printf("\nI2C Scan\n");
    printf("   0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");

    for (int addr = 0; addr < (1 << 7); ++addr) {
        if (addr % 16 == 0) {
            printf("%02x ", addr);
        }

        // Perform a 1-byte dummy read from the probe address. If a slave
        // acknowledges this address, the function returns the number of bytes
        // transferred. If the address byte is ignored, the function returns
        // -1.

        // Skip over any reserved addresses.
        int ret;
        uint8_t rxdata;
        if (reserved_addr(addr))
            ret = PICO_ERROR_GENERIC;
        else
            ret = i2c_read_blocking(i2c0, addr, &rxdata, 1, false);

        printf(ret < 0 ? "." : "@");
        printf(addr % 16 == 15 ? "\n" : "  ");
    }
    // printf("Done.\n");
}

int main() {
    // Enable UART so we can print status output
    stdio_init_all();
    tauno_i2c_init(SDA_PIN, SCL_PIN);

    while (true) {
        printf("\nI2C Scan: %i\n", counter);
        tauno_i2c_scanner();
        counter++;

        printf("Sleep 10s.\n");
        sleep_ms(10000);
    }
    return 0;
}
