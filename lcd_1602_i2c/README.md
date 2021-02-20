# LCD 1602A I2C

16x2 LCD panel with I2C bridge chip (e.g. PCF8574).
Use [i2c scanner](../i2c_scanner/) to find LCD I2C address. 

Usually the  address is 0x27. On one of mine it is 0x3f.

Most of these displays are 5v type. Whilst a 5v display will just about work at 3.3v, the display will be dim. If you power a 5v to display you will need to use level shifters on the SDA and SCL lines to convert from the 3.3V used by the RP2040.


## Build:

```Bash
$ mkdir build && cd build
$ cmake ..
$ make
```

Results over minicom:

```Bash
$ minicom -b 115200 -o -D /dev/ttyACM0
```

![minicom](i2c.png)

 ___

Copyright 2021 Tauno Erik https://taunoerik.art