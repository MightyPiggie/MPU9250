# MPU9250
This is a library with a bycicle computer example I created for a project from school that uses the MPU9250 chip

The library communicates through a software I2C implementation from [HWLIB](https://github.com/wovo/hwlib "HWLIB").

It also uses the [RTOS library](https://github.com/wovo/rtos "RTOS").

### Requirements
* A working enviroment with HWLIB
* A working enviroment with RTOS
* A 0.96" Oled with a SSD1301 driver chip
* An Arduino Due

### How to use
To use the bycicle computer add a magnet to the wheel of the bycicle as close as possible to the middle. Attach the sensor to the frame in a location where the magnet will come across.

Once you've done that start the project and you should now be able to read the data on the oled screen.

### Using the MPU6050
To make development easier, the MPU9250 is split into 2 classes: MPU6050 and AK8963 corosponding with the 2 chips inside the MPU9250.  
There are however some minor differences between the internal MPU6050 and a standalone MPU6050, which means some features might not work correctly and more research is needed to make this work.
