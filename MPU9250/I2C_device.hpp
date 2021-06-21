#ifndef I2C_DEVICE_H_
#define I2C_DEVICE_H_

#include "hwlib.hpp"

class I2C_device {
private:
	hwlib::i2c_bus& bus;
	uint8_t adress;
	
	union {
		int16_t full_bits;
		uint8_t half_bits[2];
	} combine;
	
protected:
	I2C_device(hwlib::i2c_bus& bus, 	uint8_t adress);
	void write(uint8_t reg, uint8_t data);
	uint8_t read(uint8_t reg);
	int16_t read_2_bytes(uint8_t LSB, uint8_t MSB);
};

#endif