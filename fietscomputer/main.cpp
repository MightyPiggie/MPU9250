#include "hwlib.hpp"
#include "fietscomputer.hpp"
#include "magnetTask.hpp"
#include "oledTask.hpp"
#include "fietscomputerTask.hpp"

int main(void){
	hwlib::wait_ms(2000);
	auto scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
	auto sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
	
	auto scl2 = hwlib::target::pin_oc(hwlib::target::pins::d19);
	auto sda2 = hwlib::target::pin_oc(hwlib::target::pins::d18);
	auto i2c_bus2 = hwlib::i2c_bus_bit_banged_scl_sda(scl2, sda2);
	
	auto oledTask = OledTask(i2c_bus2);
	auto fietsTask = FietscomputerTask(oledTask);
	auto magnetTask = MagnetTask(i2c_bus, fietsTask);
	
	rtos::print(hwlib::cout);
	rtos::run();
}