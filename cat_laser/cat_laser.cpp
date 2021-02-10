/*
 * Original code: https://www.youtube.com/watch?v=il4bgA76E1M&ab_channel=BenHeckHacks
 * 
 * Copyright 2021 Tauno Erik
 */

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"

uint8_t x_pos = 90;
uint8_t y_pos = 90;
int slice_num;
uint16_t count = 0;

void set_servo(int slice_num, uint16_t angle_x, uint16_t angle_y) {
  angle_x = angle_x * 10.85;
  angle_x = angle_x + 1953;

  angle_y = angle_y * 10.85;
  angle_y = angle_y + 1954;

  pwm_set_chan_level(slice_num, PWM_CHAN_A, angle_x);
  pwm_set_chan_level(slice_num, PWM_CHAN_B, angle_y);
}

uint16_t get_random(uint16_t range) {
  return rand() % range;
}

void laser_flash(int a) {
  a &= 0x01;
  gpio_put(14, a);
  gpio_put(15, !a);
  sleep_ms(100);
}

void target(uint8_t x_t, uint8_t y_t) {
  uint16_t speed = get_random(2) + 5;

  while(true) {
    if (x_pos > x_t) {
      x_pos--;
    }
    if (x_pos < x_t) {
      x_pos++;
    }
    if (y_pos > y_t) {
      y_pos--;
    }
    if (y_pos < y_t) {
      y_pos++;
    }

    set_servo(slice_num, x_pos, y_pos);

    if (x_pos == x_t && y_pos == y_t) {
      break;
    }
    sleep_ms(speed);
  }
}

int main() {
  gpio_init(14);
  gpio_init(15);
  gpio_set_dir(14, GPIO_OUT);
  gpio_set_dir(15, GPIO_OUT);

  gpio_set_function(16, GPIO_FUNC_PWM);
  gpio_set_function(17, GPIO_FUNC_PWM);

  slice_num = pwm_gpio_to_slice_num(16);
  pwm_set_clkdiv(slice_num, 64);
  pwm_set_wrap(slice_num, 39060);
  pwm_set_enabled(slice_num, true);

  adc_init();
  adc_select_input(0);

  set_servo(slice_num, 90, 90);

  while (true) {
    target(get_random(100) + 40, get_random(60) +120 );

    for (int g = 0, g < (get_random(4) + 4); g++) {
      laser_flash(g);
    }

    gpio_put(14, 1);
    gpio_put(15, 1);

    sleep_ms(1000 + get_random(3000));

    for (int g = 0; g < (get_random(4) + 4); g++) {
      laser_flash(g);
    }
  }
}
