#include "hwlib.hpp"
#include "MPU9250.hpp"

uint64_t timestamps[50] = {0};
unsigned int rotations = 0;
unsigned int circumference = 2268;
void add_rotation() {
	rotations++;
	for(int i = 0; i < 50; i++) {
		if(timestamps[i] == 0) {
			timestamps[i] = hwlib::now_us() + (10 * 1000 * 1000);
			return;
		}
	}
}
void clear_timestamps() {
	uint64_t now = hwlib::now_us();
	for(int i = 0; i < 50; i++) {
		if(timestamps[i] < now) {
			timestamps[i] = 0;
		}
	}
}

uint8_t count_timestamps() {
	uint8_t count = 0;
	for(int i = 0; i < 50; i++) {
		if(timestamps[i] != 0) count++;
	}
	return count;
}

float calc_speed() {
	clear_timestamps();
	auto count = count_timestamps();
	return (count / 10.0) * (circumference / 1000.0);
}

int main(void){
	hwlib::wait_ms(100);
	auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
	MPU9250 mpu = MPU9250(0x68, 0x0C, i2c_bus );	
	mpu.init_mag();
	bool triggered = false;
	while(true){
		int16_t z = mpu.get_z_mag();
//		hwlib::cout << z << hwlib::endl;
		if((z >= 5000 || z <=-5000) && triggered == false) {
			triggered = true;
			add_rotation();
			hwlib::cout << "KM/Uur: " << int(calc_speed()*3.6) << hwlib::endl;
		}
		else if(z < 5000 && z > -5000 && triggered == true) {
			triggered = false;
		}
		hwlib::wait_ms(10);
//		hwlib::cout << mpu.get_accel_data().x << hwlib::endl;
	}
}