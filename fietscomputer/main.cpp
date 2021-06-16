#include "hwlib.hpp"
#include "MPU9250.hpp"

int main(void){
	hwlib::wait_ms(100);
	auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
	MPU9250 mpu = MPU9250(0x68, i2c_bus);
	
	
	mpu.write(0x37, 0x2 );
	
	MPU9250 mag = MPU9250(0x0C, i2c_bus);
	auto test = mag.get_cal_mag(MPU9250(0x0C, i2c_bus));
	//hwlib::cout << test_data << hwlib::endl;
	hwlib::wait_ms(10);
	mag.write(0x0A, 0x00);
	hwlib::wait_ms(10);
	mag.write(0x0A,0x11);
	hwlib::wait_ms(10);
	
	while(true){
//		hwlib::cout << mpu.get_temperature() << hwlib::endl;
//		hwlib::cout << mpu.get_x_accel() << "--" << mpu.get_y_accel() << "--" << mpu.get_z_accel()  << hwlib::endl;
	//			hwlib::cout << mpu.read(0x3B) << "                     " << mpu.read(0x3F) << hwlib::endl;
		
		
		
		hwlib::wait_ms(50);
		mag.write(0x0A, 0x00);
		mag.write(0x0A,0x11);
		hwlib::wait_ms(10);
		hwlib::cout << "X: " << int((mag.get_x_mag()*test.x)) << hwlib::endl;
		hwlib::cout << "Y: " << int((mag.get_y_mag()*test.y)) << hwlib::endl;
		hwlib::cout << "Z: " << int((mag.get_z_mag()*test.z)) << hwlib::endl;
		
		}
		 /*
		 while(true){
			 auto x_mag = mpu.read_2_bytes(0x03h, 0x4h);
			 hwlib::cout << x_mag << hwlib::endl;
			 
		 }
		  */
  //hwlib::wait_ms(10);
}