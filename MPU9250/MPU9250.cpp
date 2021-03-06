#include "MPU9250.hpp"
#include "MPU9250_defines.hpp"
#include <math.h>

MPU9250::MPU9250(hwlib::i2c_bus& bus, uint8_t adress_6050, uint8_t adress_AK8963):
	MPU6050(bus, adress_6050),
	AK8963(bus, adress_AK8963)
{}
// I have used this as a reference on how to calculate Pitch and Roll since its above my knowledge on how to calculate it. 
// https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing
float MPU9250::getPitch() {
	XYZ accel_data = getAccelData();
	return atan2(-accel_data.x , (sqrt(accel_data.y * accel_data.y + accel_data.z * accel_data.z))) * 57.3;
}

float MPU9250::getRoll() {
	XYZ accel_data = getAccelData();
	return (atan2(accel_data.y , accel_data.z)) * 57.3;
}
