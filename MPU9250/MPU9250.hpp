#ifndef MPU9250_H_
#define MPU9520_H_

#pragma once

#include "hwlib.hpp"
#include "MPU6050.hpp"
#include "AK8963.hpp"


class MPU9250 : public MPU6050, public AK8963 {
public:
	MPU9250(hwlib::i2c_bus& bus, uint8_t adress_6050, uint8_t adress_AK8963);
	
	/**
	 * @brief Calculate the pitch from the accelerometer data 
	 * 
	 * @return The pitch value as a float
	 */
	float getPitch
	
	/**
	 * @brief Calculate the roll from the accelerometer data 
	 * 
	 * @return The roll value as a float
	 */
	float getRoll();
};

#endif	