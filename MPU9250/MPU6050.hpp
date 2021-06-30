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
	uint8_t getTemperature();
	
	/**
	 * @brief Get the current x axis accelerometer data 
	 * 
	 * @return The current x axis accelorometer data as a signed 16 bit integer
	 */
	int16_t getXAccel();
	
	/**
	 * @brief Get the current y axis accelerometer data 
	 * 
	 * @return The current y axis accelorometer data as a signed 16 bit integer
	 */
	int16_t getYAccel();
	
	/**
	 * @brief Get the current z axis accelerometer data 
	 * 
	 * @return The current z axis accelorometer data as a signed 16 bit integer
	 */
	int16_t getZAccel();
	
	/**
	 * @brief Get the currect accelorometer data 
	 * 
	 * @return The currect accelorometer data from all axis in a XYZ struct 
	 */
	XYZ getAccelData(); 
	
	/**
	 * @brief Get the current x axis gyroscope data 
	 * 
	 * @return The current x axis gyroscope data as a signed 16 bit integer
	 */
	int16_t getXGyro();
	
	/**
	 * @brief Get the current y axis gyroscope data 
	 * 
	 * @return The current y axis gyroscope data as a signed 16 bit integer
	 */
	int16_t getYGyro();
	
	/**
	 * @brief Get the current z axis gyroscope data 
	 * 
	 * @return The current z axis gyroscope data as a signed 16 bit integer
	 */
	int16_t getZGyro();
	
	/**
	 * @brief Get the currect gyroscope data 
	 * 
	 * @return The currect gyroscope data from all axis in a XYZ struct 
	 */
	XYZ getGyroData();
	
	/**
	 * @brief Initialize the MPU6050 sensor
	 * 
	 * @return A true (1) if the initialization is succesful.
	 */
	bool init();
	
	/**
	 * @brief Check if the sensor is working
	 * 
	 * @return A true (1) if the sensor is working
	 */
	bool checkIfSensorPresent();
	
	/**
	 * @brief Perform a selftest on the sensors
	 * 
	 * @return A true (1) if the selftest passed all tests
	 */
	bool selfTest();
};

#endif	

