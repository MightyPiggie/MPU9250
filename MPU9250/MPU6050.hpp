#ifndef MPU6050_H_
#define MPU6050_H_

#include "hwlib.hpp"
#include "I2C_device.hpp"
#include "XYZ.hpp"

class MPU6050 : public I2C_device {
public:
	MPU6050(hwlib::i2c_bus& bus, uint8_t adress);
	
	 /**
	  * @brief Get the current temperature
	  * 
	  * @return The current temperature in degrees Celsius
	  */
	uint8_t get_temperature();
	int16_t get_x_accel();
	int16_t get_y_accel();
	int16_t get_z_accel();
	xyz get_accel_data(); 
	int16_t get_x_gyro();
	int16_t get_y_gyro();
	int16_t get_z_gyro();
	xyz get_gyro_data();
	bool init();
	bool check_if_sensor_present();
};

#endif	