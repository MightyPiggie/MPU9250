#include "AK8963.hpp"

#include "MPU9250_defines.hpp"



AK8963::AK8963(hwlib::i2c_bus& bus, uint8_t adress):
	I2C_device(bus, adress)
{
	init();
}

AK8963::CalMag AK8963::getCalMag() {
	write(REG_MAG_CONTROL1, 0x00);
	hwlib::wait_ms(10);
	write(REG_MAG_CONTROL1, 0x0F);
	hwlib::wait_ms(10);
	AK8963::CalMag Calmag;
	Calmag.x = ((read(0x10)-128)/256+1);
	Calmag.y = ((read(0x11)-128)/256+1);
	Calmag.z = ((read(0x12)-128)/256+1);
	return Calmag;
}

int16_t AK8963::getXMag() {
	auto temp =  read2Bytes(REG_MAG_XOUT_L, REG_MAG_XOUT_H) * Calibrated_mag.x;
	read(REG_MAG_STATUS2);
	return temp;
}

int16_t AK8963::getYMag() {
	auto temp = read2Bytes(REG_MAG_YOUT_L, REG_MAG_YOUT_H) * Calibrated_mag.y;
	read(REG_MAG_STATUS2);
	return temp;
}

int16_t AK8963::getZMag() {
	auto temp = read2Bytes(REG_MAG_ZOUT_L, REG_MAG_ZOUT_H) * Calibrated_mag.z;
	read(REG_MAG_STATUS2);
	return temp;
}

XYZ AK8963::getMagData() {
	return {getXMag(), getYMag(), getZMag()};
}

bool AK8963::init(){
	Calibrated_mag = getCalMag();
	write(REG_MAG_CONTROL1, 0x00);
	write(REG_MAG_CONTROL1,0x16);
	return true;
}