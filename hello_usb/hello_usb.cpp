/*
 *  USB Seril print
 * 
 *  minicom -b 115200 -o -D /dev/ttyACM0

 *  Copyright 2021 Tauno Erik
 */


#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"

int nr = 0;

int main() {
  bi_decl(bi_program_name("Hello world."));
  bi_decl(bi_program_description("Hello world: USB."));
  bi_decl(bi_program_version_string("0.1"));
  bi_decl(bi_program_url("https://github.com/taunoe/pico-katsed"));

  stdio_init_all();
  printf("Hello, world!\n");

  while (true) {
    nr++;
    printf("%i\n", nr);
    sleep_ms(1000);
  }
  // return 0;
}
