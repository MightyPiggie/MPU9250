# MPU9250
This is a library with a bycicle computer example I created for a project from school that uses the MPU9250 chip

The library communicates through a software I2C implementation from [HWLIB](https://github.com/wovo/hwlib "HWLIB").

It also uses the [RTOS library](https://github.com/wovo/rtos "RTOS")  and the [MATH library]("MATH").

### Requirements
* A working enviroment with HWLIB
* A working enviroment with RTOS
* A 0.95" Oled
* An Arduino Due

### How to use
To use the bycicle computer add a magnet to the wheel of the bycicle as close as possible to the middle. Attach the sensor to the frame in a location where the magnet will come across.

Once you've done that start the project and you should now be able to read the data on the oled screen.

