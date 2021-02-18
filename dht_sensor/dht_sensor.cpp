/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 **/

#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const unsigned int LED_PIN = PICO_DEFAULT_LED_PIN;  // 25
const unsigned int DHT_PIN = 15;
const unsigned int MAX_TIMINGS = 85;

typedef struct {
    float humidity;
    float temp_celsius;
} dht_reading;


void read_from_dht(dht_reading *result) {
  int data[5] = {0, 0, 0, 0, 0};
  unsigned int last = 1;
  unsigned int j = 0;

  gpio_set_dir(DHT_PIN, GPIO_OUT);
  gpio_put(DHT_PIN, 0);
  sleep_ms(20);
  gpio_set_dir(DHT_PIN, GPIO_IN);

  gpio_put(LED_PIN, 1);

    for (int i = 0; i < MAX_TIMINGS; i++) {
      unsigned int count = 0;

      while (gpio_get(DHT_PIN) == last) {
        count++;
        sleep_us(1);
        if (count == 255) {
          break;
        }
      }

      last = gpio_get(DHT_PIN);
      if (count == 255) {
        break;
      }

      if ((i >= 4) && (i % 2 == 0)) {
        data[j / 8] <<= 1;
        if (count > 16) data[j / 8] |= 1;
        j++;
      }
    }
    gpio_put(LED_PIN, 0);

    if ((j >= 40) &&
    (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF))) {

      result->humidity = static_cast <float> ((data[0] << 8) + data[1]) / 10;

      if (result->humidity > 100) {
        result->humidity = data[0];
      }

      result->temp_celsius = static_cast <float> (((data[2] & 0x7F) << 8) + data[3]) / 10;

      if (result->temp_celsius > 125) {
        result->temp_celsius = data[2];
      }

      if (data[2] & 0x80) {
        result->temp_celsius = -result->temp_celsius;
      }

    } else {
        printf("Bad data\n");
    }
}

int main() {
  stdio_init_all();
  gpio_init(LED_PIN);
  gpio_init(DHT_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  while (true) {
    //
    dht_reading reading;
    read_from_dht(&reading);

    float fahrenheit = (reading.temp_celsius * 9 / 5) + 32;

    printf("Humidity = %.1f%%, Temperature = %.1fC (%.1fF)\n",
            reading.humidity, reading.temp_celsius, fahrenheit);

    sleep_ms(2000);
  }

}