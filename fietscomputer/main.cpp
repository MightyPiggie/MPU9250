#include "hwlib.hpp"
#include "MPU9250.hpp"
#include "fietscomputer.hpp"

unsigned int circumference = 2268;

//void write_data_to_terminal(hwlib::terminal& terminal, int data ) {
//	terminal << "\f" << data << hwlib::flush;
//}
int main(void){
	hwlib::wait_ms(100);
	auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
	auto display = hwlib::glcd_oled(i2c_bus, 0x3c);
	auto mpu = MPU9250(i2c_bus, 0x68, 0x0c);	
	auto fiets = fietscomputer(circumference);
	
	auto speed = hwlib::part(display, hwlib::xy(0,0), hwlib::xy(64, 32));
	auto speed_font = hwlib::font_default_16x16();
	auto speed_terminal = hwlib::terminal_from(speed, speed_font);
	hwlib::wait_ms(2000);
	bool triggered = false;
	hwlib::cout << mpu.self_test() << hwlib::endl;
	
	while(true){
		int16_t z = mpu.get_z_mag();
//		hwlib::cout << z << hwlib::endl;
		hwlib::wait_ms(10);
		if((z >= 5000 || z <=-5000) && triggered == false) {
			triggered = true;
			fiets.add_rotation();
//			hwlib::cout << "KM/Uur: " << int(fiets.calc_speed()*3.6) << hwlib::endl;
//			write_data_to_terminal(speed_terminal, int(fiets.calc_speed()*3.6));
		}
		else if(z < 5000 && z > -5000 && triggered == true) {
			triggered = false;
		}
		hwlib::wait_ms(10);
//		hwlib::cout << mpu.get_accel_data().x << hwlib::endl;
	}
}