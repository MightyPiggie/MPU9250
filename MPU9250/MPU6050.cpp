#include "MPU6050.hpp"

#include "MPU9250_defines.hpp"



MPU6050::MPU6050(hwlib::i2c_bus& bus, uint8_t adress):
	I2C_device(bus, adress)
{}

uint8_t MPU6050::get_temperature() {
	uint16_t temp = read_2_bytes(REG_TEMP_OUT_L, REG_TEMP_OUT_H);
	return (temp / 333.87) + 17;
		}
		
int16_t MPU6050::get_x_accel() {
	return read_2_bytes(REG_ACCEL_XOUT_L, REG_ACCEL_XOUT_H);
	}
int16_t MPU6050::get_y_accel() {
	return read_2_bytes(REG_ACCEL_YOUT_L, REG_ACCEL_YOUT_H);
	}
int16_t MPU6050::get_z_accel() {
	return read_2_bytes(REG_ACCEL_ZOUT_L, REG_ACCEL_ZOUT_H);
	}
	
int16_t MPU6050::get_x_gyro() {
	return read_2_bytes(REG_GYRO_XOUT_L, REG_GYRO_XOUT_H);
	}
int16_t MPU6050::get_y_gyro() {
	return read_2_bytes(REG_GYRO_YOUT_L, REG_GYRO_YOUT_H);
	}
int16_t MPU6050::get_z_gyro() {
	return read_2_bytes(REG_GYRO_ZOUT_L, REG_GYRO_ZOUT_H);
	}	
						
xyz MPU6050::get_accel_data(){
	return {get_x_accel(), get_y_accel(), get_z_accel()};
		}	
		
xyz MPU6050::get_gyro_data(){
	return {get_x_gyro(), get_y_gyro(), get_z_gyro()};
		}
bool MPU6050::init(){
	if(check_if_sensor_present()) {
		write(REG_INT_PIN_CFG, 0x2);
		return true;
	}
	return false;
}
bool MPU6050::check_if_sensor_present(){
	if(read(REG_WHO_AM_I) != 0x71) {
		hwlib::cout << read(REG_WHO_AM_I) << hwlib::endl;
		hwlib::cout << "MPU6050 has not been detected. Check if the cables are wired correctly.";
		return false;
	}
	hwlib::cout << read(REG_WHO_AM_I) << hwlib::endl;
	return true;
}		