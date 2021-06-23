#include "MPU6050.hpp"
#include <math.h>
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
						
XYZ MPU6050::get_accel_data(){
	return {get_x_accel(), get_y_accel(), get_z_accel()};
		}	
		
XYZ MPU6050::get_gyro_data(){
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

int ST_OTP(uint8_t self_test) {
	return 2620 * pow(1.01, self_test-1);
}

bool MPU6050::self_test() {
	write(REG_CONFIG, 0x02);
	write(REG_ACCEL_CONFIG2, 0x02);
	write(REG_GYRO_CONFIG, 0x00);
	write(REG_ACCEL_CONFIG, 0x00);
	
	int16_t GX_OS = read_2_bytes_average(REG_GYRO_XOUT_L, REG_GYRO_XOUT_H, 200);
	int16_t GY_OS = read_2_bytes_average(REG_GYRO_YOUT_L, REG_GYRO_YOUT_H, 200);
	int16_t GZ_OS = read_2_bytes_average(REG_GYRO_ZOUT_L, REG_GYRO_ZOUT_H, 200);
	int16_t AX_OS = read_2_bytes_average(REG_ACCEL_XOUT_L, REG_ACCEL_XOUT_H, 200);
	int16_t AY_OS = read_2_bytes_average(REG_ACCEL_YOUT_L, REG_ACCEL_YOUT_H, 200);
	int16_t AZ_OS = read_2_bytes_average(REG_ACCEL_ZOUT_L, REG_ACCEL_ZOUT_H, 200);

	write(REG_GYRO_CONFIG, 0xE0);
	write(REG_ACCEL_CONFIG, 0xE0);
	
	hwlib::wait_ms(30);
	
	int16_t GX_ST_OS = read_2_bytes_average(REG_GYRO_XOUT_L, REG_GYRO_XOUT_H, 200);
	int16_t GY_ST_OS = read_2_bytes_average(REG_GYRO_YOUT_L, REG_GYRO_YOUT_H, 200);
	int16_t GZ_ST_OS = read_2_bytes_average(REG_GYRO_ZOUT_L, REG_GYRO_ZOUT_H, 200);
	int16_t AX_ST_OS = read_2_bytes_average(REG_ACCEL_XOUT_L, REG_ACCEL_XOUT_H, 200);
	int16_t AY_ST_OS = read_2_bytes_average(REG_ACCEL_YOUT_L, REG_ACCEL_YOUT_H, 200);
	int16_t AZ_ST_OS = read_2_bytes_average(REG_ACCEL_ZOUT_L, REG_ACCEL_ZOUT_H, 200);

	int ST[6] = {
		GX_ST_OS - GX_OS,
		GY_ST_OS - GY_OS,
		GZ_ST_OS - GZ_OS,
		AX_ST_OS - AX_OS,
		AY_ST_OS - AY_OS,
		AZ_ST_OS - AZ_OS
	};

	write(REG_GYRO_CONFIG, 0x00);
	write(REG_ACCEL_CONFIG, 0x00);
	
	hwlib::wait_ms(30);
	
	uint8_t X_gyro = read(REG_SELF_TEST_X_GYRO);
	uint8_t Y_gyro = read(REG_SELF_TEST_Y_GYRO);
	uint8_t Z_gyro = read(REG_SELF_TEST_Z_GYRO);
	uint8_t X_accel = read(REG_SELF_TEST_X_ACCEL);
	uint8_t Y_accel = read(REG_SELF_TEST_Y_ACCEL);
	uint8_t Z_accel = read(REG_SELF_TEST_Z_ACCEL);

	int gyro_OTP[3] = {ST_OTP(X_gyro), ST_OTP(Y_gyro), ST_OTP(Z_gyro)};
	int accel_OTP[3] = {ST_OTP(X_accel), ST_OTP(Y_accel), ST_OTP(Z_accel)};
	
	bool success = true;
	for(int i = 0; i < 3; i++) {
		success = success && ((float)ST[i] / gyro_OTP[i]) > 0.5;
	}
	for(int i = 0; i < 3; i++) {
		success = success && ((float)ST[i+3] / accel_OTP[i]) > 0.5 && ((float)ST[i+3] / accel_OTP[i]) < 1.5;
	}
	return success;
}