#include "hwlib.hpp"
#include "MPU9250.hpp"


int main(void){
	auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
	auto mpu = MPU9250(i2c_bus, 0x68, 0x0c);	
	
	hwlib::wait_ms(2000);
	if(mpu.self_test() == true) {
		hwlib::cout << "The selftest was successful" << hwlib::endl;
	}
	else {
		hwlib::cout << "The selftest was unsuccessful" << hwlib::endl;
	}
}