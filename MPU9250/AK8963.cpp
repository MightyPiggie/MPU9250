#include "AK8963.hpp"

#include "MPU9250_defines.hpp"



AK8963::AK8963(hwlib::i2c_bus& bus, uint8_t adress):
	I2C_device(bus, adress)
{}

AK8963::cal_mag AK8963::get_cal_mag() {
	write(REG_MAG_CONTROL1, 0x00);
	hwlib::wait_ms(10);
	write(REG_MAG_CONTROL1, 0x0F);
	hwlib::wait_ms(10);
	AK8963::cal_mag cal_mag;
	cal_mag.x = ((read(0x10)-128)/256+1);
	cal_mag.y = ((read(0x11)-128)/256+1);
	cal_mag.z = ((read(0x12)-128)/256+1);
	return cal_mag;
}

int16_t AK8963::get_x_mag() {
	auto temp =  read_2_bytes(REG_MAG_XOUT_L, REG_MAG_XOUT_H) * calibrated_mag.x;
	read(REG_MAG_STATUS2);
	return temp;
}

int16_t AK8963::get_y_mag() {
	auto temp = read_2_bytes(REG_MAG_YOUT_L, REG_MAG_YOUT_H) * calibrated_mag.y;
	read(REG_MAG_STATUS2);
	return temp;
}

int16_t AK8963::get_z_mag() {
	auto temp = read_2_bytes(REG_MAG_ZOUT_L, REG_MAG_ZOUT_H) * calibrated_mag.z;
	read(REG_MAG_STATUS2);
	return temp;
}

xyz AK8963::get_mag_data(){
	return {get_x_mag(), get_y_mag(), get_z_mag()};
}

void AK8963::init(){
	calibrated_mag = get_cal_mag();
	write(REG_MAG_CONTROL1, 0x00);
	write(REG_MAG_CONTROL1,0x16);
}