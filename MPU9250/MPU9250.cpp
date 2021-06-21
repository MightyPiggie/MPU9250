#include "MPU9250.hpp"
#include "MPU9250_defines.hpp"


MPU9250::MPU9250(hwlib::i2c_bus& bus, uint8_t adress_6050, uint8_t adress_AK8963):
	MPU6050(bus, adress_6050),
	AK8963(bus, adress_AK8963)
{
	AK8963::init();
	MPU6050::init();
}