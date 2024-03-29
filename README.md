# Katsed Raspberry Pi Pico'ga kasutades C/C++ SDKd.

- Laealla **pico-sdk**
  
  ```Bash
  cd~
  mkdir pico
  cd pico
  git clone -b master https://github.com/raspberrypi/pico-sdk.git
  cd pico-sdk
  git submodule update --init
  cd ..
  git clone -b master https://github.com/raspberrypi/pico-examples.git
  ```

- Paigalda vajalikud tööriistad (_toolchain_)

  ```Bash
  sudo apt update
  sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential
  ```

- Paigalda Visual Studio Code ja pluginad

  ```Bash
  code --install-extension marus25.cortex-debug
  code --install-extension ms-vscode.cmake-tools
  code --install-extension ms-vscode.cpptools
  ```

- PICO_SDK_PATH

~/.profile faili lisada tee failidee SDK juurde. Näiteks:

```Bash
export PICO_SDK_PATH="/home/taunoerik/pico/pico-sdk"
```

- VSCode käivitamisel

Valida "Yes" to configure the project. Ja valida **GCC for arm-none-eabi**

## Oma projekti ehitamine

Tee kataloog pico-sdk kõrvale.
Failid projektinimi.c või projektinimi.cpp ja CMakeLists.txt fail.
Then copy the pico_sdk_import.cmake file from the external folder in your pico-sdk installation to your test project folder.

  ```Bash
  mkdir build
  cd build
  cmake ..
  make
  ```

Faili **.uf2** saab tirida otse Picole, programmi käivitamiseks.

## minicom

Paigalda:

    sudo apt install minicom

Kasuta (USB kaudu):

    minicom -b 115200 -o -D /dev/ttyACM0

minicomis väljumine: CTRL+A ja X

## Resett nupp

![Pico resett button](./img/pico_resett.png)

## Katsed

Originaal kood: https://github.com/raspberrypi/pico-examples

Kompilaator: GCC for arm-none-eabi 9.2.1

Rakendus|Kompileerub
---|---
[blink](blink/) | Jah
[hello_usb](hello_usb/) | Jah
[cat_laser](cat_laser/) | Not tested
[adc_hello](adc_hello/) | Jah
[adc_capture](adc_capture/) | Ei
[adc_console](adc_console/) | Ei
[joystick_display](joystick_display/) | Jah
[7-segment LED display](7segment/) | Jah
[Pin interrupt](interrupt/) | Jah
[DHT sensor](dht_sensor/) | Jah, aga "Bad data"
[i2c scanner](i2c_scanner/) | Jah
[LCD 16*2 1602 I2C](lcd_1602_i2c/) | Jah

## Juhendid

- [Getting started with Raspberry Pi Pico](https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf) C/C++ development with Raspberry Pi Pico and other RP2040-based microcontroller boards.
- [Raspberry Pi Pico C/C++ SDK](https://datasheets.raspberrypi.org/pico/raspberry-pi-pico-c-sdk.pdf) Libraries and tools for C/C++ development on RP2040 microcontrollers
- https://www.youtube.com/watch?v=7h6mTR0oNcg
 ___

Copyright 2021 Tauno Erik https://taunoerik.art
