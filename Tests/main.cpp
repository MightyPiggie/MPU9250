#include "hwlib.hpp"
#include "MPU9250.hpp"


void testAccel(MPU9250& mpu) {
	hwlib::cout << "Lay the chip flat to test the accelorometer." << hwlib::endl << "The x-axis should be arround 0 +- 1000" << hwlib::endl << "The y-axis should be arround 0 +- 1000" << hwlib::endl << "The z-axis should be arround -16000 +- -1000" << hwlib::endl;
	hwlib::wait_ms(5000);
	for(int i = 0; i < 20; i++) {
		hwlib::cout << "x: "<< mpu.getXAccel() << " y: "  << mpu.getYAccel() << " z: " << mpu.getZAccel() << hwlib::endl;
		hwlib::wait_ms(500);
	}
}

void testGyro(MPU9250& mpu) {
	hwlib::cout << "Hold the chip still to test the gyroscope" << hwlib::endl << "The x-axis should be arround 0 +- 1000" << hwlib::endl << "The y-axis should be arround 0 +- 1000" << hwlib::endl << "The z-axis should be arround 0 +- 1000" << hwlib::endl;
	hwlib::wait_ms(5000);
	for(int i = 0; i < 20; i++) {
		hwlib::cout << "x: "<< mpu.getXGyro() << " y: "  << mpu.getYGyro() << " z: " << mpu.getZGyro() << hwlib::endl;
		hwlib::wait_ms(500);
	}
}

void testMag(MPU9250& mpu) {
	hwlib::cout << "Hold the chip still to test the magnetometer" << hwlib::endl << "The x-axis should be between 250 and 650 +- 100" << hwlib::endl << "The y-axis should be between 250 and 650 +- 100" << hwlib::endl << "The z-axis should be between 250 and 650 +- 100" << hwlib::endl;
	hwlib::wait_ms(5000);
	for(int i = 0; i < 20; i++) {
		hwlib::cout << "x: "<< mpu.getXMag() << " y: "  << mpu.getYMag() << " z: " << mpu.getZMag() << hwlib::endl;
		hwlib::wait_ms(500);
	}
}

void clearTerminal() {
	for(int i = 0; i < 100; i++) {
		hwlib::cout << "\n\n\n\n\n\n\n\n\n\n";
		 
		}
	hwlib::cout << hwlib::endl;
}

void testAllSensors(MPU9250& mpu) {
	clearTerminal();
	testAccel(mpu);
	clearTerminal();
	testGyro(mpu);
	clearTerminal();
	testMag(mpu);
	clearTerminal();
	hwlib::cout << "All sensors has been tested" << hwlib::endl;
}

int main(void){	
	auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
	auto mpu = MPU9250(i2c_bus, 0x68, 0x0c);	
	hwlib::wait_ms(2000);
	testAllSensors(mpu);
	if(mpu.selfTest() == true) {
		hwlib::cout << "The selftest was successful" << hwlib::endl;
	}
	else {
		hwlib::cout << "The selftest was unsuccessful" << hwlib::endl;
	}
}