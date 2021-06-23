#include "I2C_device.hpp"

I2C_device::I2C_device(hwlib::i2c_bus& bus, uint8_t adress):
	bus(bus),
	adress(adress)
{}

void I2C_device::write(uint8_t reg, uint8_t data) {
	auto trans = bus.write(adress);
	trans.write(reg);
	trans.write(data);	
}

int8_t I2C_device::read(uint8_t reg) {
	bus.write(adress).write(reg);
	return bus.read(adress).read_byte();
}

int16_t I2C_device::read_2_bytes(uint8_t LSB, uint8_t MSB) {
	combine.half_bits[0] = read(LSB);
	combine.half_bits[1] = read(MSB);
	return combine.full_bits;
}

int8_t I2C_device::read_average(uint8_t reg, int amount) {
	int64_t totaal = 0;
	for(int i = 0; i < amount; i++) {
		totaal += read(reg);
	}
	return totaal / amount;
}

int16_t I2C_device::read_2_bytes_average(uint8_t LSB, uint8_t MSB, int amount) {
	int64_t totaal = 0;
	for(int i = 0; i < amount; i++) {
		totaal += read_2_bytes(LSB, MSB);
	}
	return totaal / amount;
}