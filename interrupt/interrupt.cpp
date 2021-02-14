/**
 * Copyright 2021 Tauno Erik
 *
 * 14.02.2021
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int PIN = 2;

static char event_str[128];

static const char *gpio_irq_str[] = {
        "LEVEL_LOW",   // 0x1
        "LEVEL_HIGH",  // 0x2
        "EDGE_FALL",   // 0x4
        "EDGE_RISE"    // 0x8
};

void gpio_event_string(char *buf, uint32_t events) {
    for (unsigned int i = 0; i < 4; i++) {
        unsigned int mask = (1 << i);
        if (events & mask) {
            // Copy this event string into the user string
            const char *event_str = gpio_irq_str[i];
            while (*event_str != '\0') {
                *buf++ = *event_str++;
            }
            events &= ~mask;

            // If more events add ", "
            if (events) {
                *buf++ = ',';
                *buf++ = ' ';
            }
        }
    }
    *buf++ = '\0';
}

void gpio_callback(unsigned int gpio, uint32_t events) {
    // Put the GPIO event(s) that just happened into event_str
    // so we can print it
    gpio_event_string(event_str, events);
    printf("GPIO %d %s\n", gpio, event_str);
}

int main() {
    stdio_init_all();

    printf("Hello GPIO IRQ\n");

    // Enable interrupts for specified GPIO pin.
    gpio_set_irq_enabled_with_callback(
        PIN,  // GPIO
        GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL,  // Which events will cause an interrupt
        // GPIO_IRQ_LEVEL_LOW, GPIO_IRQ_LEVEL_HIGH, GPIO_IRQ_EDGE_FALL, GPIO_IRQ_EDGE_RISE
        true,  // Enable or disable flag
        &gpio_callback);  // user function to call on GPIO irq.

    // Wait forever
    while (true) {
        //
    }

    return 0;
}
