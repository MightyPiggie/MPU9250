#ifndef OLEDTASK_H_
#define OLEDTASK_H_

#include "hwlib.hpp"
#include "rtos.hpp"

class OledTask : public rtos::task<> {
public:
	enum class DisplayType {
		speed, temperature, distance, angle
	};
	
	struct DisplayData {
		DisplayType type;
		int value;
	};

private:
	rtos::channel<DisplayData, 5> oledChannel;
	hwlib::glcd_oled display;
	
	hwlib::font_default_16x16 font;
	hwlib::window_part_t speedPart;
	hwlib::window_part_t distancePart;
	hwlib::window_part_t temperaturePart;
	hwlib::window_part_t anglePart;
	hwlib::terminal_from speedTerminal;
	hwlib::terminal_from distanceTerminal;
	hwlib::terminal_from temperatureTerminal;
	hwlib::terminal_from angleTerminal;

public:
	OledTask(hwlib::i2c_bus& bus);
	void main() override;
	
	void setDisplayData(DisplayType type, int value);
};

#endif