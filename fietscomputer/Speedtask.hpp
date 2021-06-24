#ifndef SPEEDTASK_H_
#define SPEEDTASK_H_

#include "hwlib.hpp"
#include "rtos.hpp"

#include "fietscomputer.hpp"

class SpeedTask : public rtos::task<> {
private:
	rtos::timer wait_time;	
	fietscomputer fiets;	
	hwlib::target::pin_oc scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
	hwlib::target::pin_oc sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
	hwlib::i2c_bus_bit_banged_scl_sda i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
	hwlib::glcd_oled display = hwlib::glcd_oled(i2c_bus, 0x3c);
	hwlib::window_part_t speed = hwlib::part(display, hwlib::xy(0,0), hwlib::xy(64, 32));
	hwlib::font_default_16x16 speed_font = hwlib::font_default_16x16();
	hwlib::terminal_from speed_terminal = hwlib::terminal_from(speed, speed_font);

public:
SpeedTask(fietscomputer fiets);

void main() override;
};

#endif	