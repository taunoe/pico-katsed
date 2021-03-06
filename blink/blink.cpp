/*
 * Blinks LEDs on GP15 and GP16
 * Copyright 2021 Tauno Erik
 */
#include <stdio.h>
#include "pico/stdlib.h"  // umbrella headers: hardware/gpio.h, pico/time.h
// #include "hardware/gpio.h"
#include "pico/binary_info.h"

#define LOW 0
#define HIGH 1

const uint LED_PIN_15 = 15;
const uint LED_PIN_16 = 16;
// On board LED: 25

int main() {
  bi_decl(bi_program_name("Blink."));
  bi_decl(bi_program_description("This is a blink test."));
  bi_decl(bi_program_version_string("0.1"));
  bi_decl(bi_program_url("https://github.com/taunoe/pico-katsed"));
  bi_decl(bi_1pin_with_name(LED_PIN_15, "Left LED"));
  bi_decl(bi_1pin_with_name(LED_PIN_16, "Right LED"));


stdio_init_all();
  gpio_init(LED_PIN_15);
  gpio_init(LED_PIN_16);
  gpio_set_dir(LED_PIN_15, GPIO_OUT);
  gpio_set_dir(LED_PIN_16, GPIO_OUT);

  while (true) {
    gpio_put(LED_PIN_15, LOW);
    gpio_put(LED_PIN_16, HIGH);
    sleep_ms(500);

    gpio_put(LED_PIN_15, HIGH);
    gpio_put(LED_PIN_16, LOW);
    sleep_ms(500);

    // Serial print:
    // minicom -b 115200 -o -D /dev/ttyACM0
    puts("Hello World\n");
  }
}
