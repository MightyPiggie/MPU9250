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
	MPU9250 mpu = MPU9250(0x68, 0x0C, i2c_bus);

	mpu.write(0x68, 0x37, 0x2 );
	auto test = mpu.get_cal_mag();
	//hwlib::cout << test_data << hwlib::endl;
	
	mpu.write(0x0C, 0x0A, 0x00);
	mpu.write(0x0C, 0x0A,0x16);
	bool triggered = false;
	while(true){
//		hwlib::cout << mpu.get_temperature() << hwlib::endl;
//		hwlib::cout << mpu.get_x_accel() << "--" << mpu.get_y_accel() << "--" << mpu.get_z_accel()  << hwlib::endl;
	//			hwlib::cout << mpu.read(0x3B) << "                     " << mpu.read(0x3F) << hwlib::endl;
		
		
		
	
		
		
		int16_t z = mpu.get_z_mag()*test.z;
		mpu.read(0x0C, 0x09);
		if((z >= 5000 || z <=-5000) && triggered == false) {
//			hwlib::cout << z << hwlib::endl;
			triggered = true;
			add_rotation();
			hwlib::cout << "KM/Uur: " << int(calc_speed()*3.6) << hwlib::endl;
		}
		else if(z < 5000 && z > -5000 && triggered == true) {
			triggered = false;
		}
		}
		 /*
		 while(true){
			 auto x_mag = mpu.read_2_bytes(0x03h, 0x4h);
			 hwlib::cout << x_mag << hwlib::endl;
			 
		 }
		  */
  //hwlib::wait_ms(10);
}