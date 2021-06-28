#include "hwlib.hpp"
#include "MPU9250.hpp"


void test_accel(MPU9250& mpu) {
	hwlib::cout << "Lay the chip flat to test the accelorometer." << hwlib::endl << "The x-axis should be arround 0 +- 1000" << hwlib::endl << "The y-axis should be arround 0 +- 1000" << hwlib::endl << "The z-axis should be arround -16000 +- -1000" << hwlib::endl;
	hwlib::wait_ms(2500);
	while(true) {
		hwlib::cout << "x: "<< mpu.get_x_accel() << " y: "  << mpu.get_y_accel() << " z: " << mpu.get_z_accel() << hwlib::endl;
		hwlib::wait_ms(500);
	}
}

void test_gyro(MPU9250& mpu) {
	hwlib::cout << "Hold the chip still to test the gyroscope" << hwlib::endl << "The x-axis should be arround 0 +- 1000" << hwlib::endl << "The y-axis should be arround 0 +- 1000" << hwlib::endl << "The z-axis should be arround 0 +- 1000" << hwlib::endl;
	hwlib::wait_ms(2500);
	while(true) {
		hwlib::cout << "x: "<< mpu.get_x_gyro() << " y: "  << mpu.get_y_gyro() << " z: " << mpu.get_z_gyro() << hwlib::endl;
		hwlib::wait_ms(500);
	}
}

void test_mag(MPU9250& mpu) {
	hwlib::cout << "Hold the chip still to test the magnetometer" << hwlib::endl << "The x-axis should be arround 0 +- 1000" << hwlib::endl << "The y-axis should be arround 0 +- 1000" << hwlib::endl << "The z-axis should be arround 0 +- 1000" << hwlib::endl;
	hwlib::wait_ms(2500);
	while(true) {
		hwlib::cout << "x: "<< mpu.get_x_mag() << " y: "  << mpu.get_y_mag() << " z: " << mpu.get_z_mag() << hwlib::endl;
		hwlib::wait_ms(500);
	}
}

int main(void){	
	auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
	auto mpu = MPU9250(i2c_bus, 0x68, 0x0c);	
	hwlib::wait_ms(2000);
	test_mag(mpu);
	if(mpu.self_test() == true) {
		hwlib::cout << "The selftest was successful" << hwlib::endl;
	}
	else {
		hwlib::cout << "The selftest was unsuccessful" << hwlib::endl;
	}
}