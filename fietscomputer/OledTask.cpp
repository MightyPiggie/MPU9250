#include "oledTask.hpp"

OledTask::OledTask(hwlib::i2c_bus& bus):
	task(1, "Oled Task"),
	oledChannel(this, "OledChannel"),
	display(bus, 0x3c),
	speedPart(display, hwlib::xy(0,0), hwlib::xy(32, 16)),
	distancePart(display, hwlib::xy(0, 32), hwlib::xy(64, 48)),
	temperaturePart(display, hwlib::xy(64, 0), hwlib::xy(96, 16)),
	speedTerminal(speedPart, font),
	distanceTerminal(distancePart, font),
	temperatureTerminal(temperaturePart, font)
{ 
	display.clear(); 
}

void OledTask::main() {
	while(true){
		wait(oledChannel);
		auto data = oledChannel.read(); //Read the queue of oledChannel
		switch (data.type) {
			case DisplayType::speed:
				speedTerminal << "\f" << data.value << hwlib::flush; //If the type is speed it will write the value to the speedTerminal
				break;
			case DisplayType::distance:
				distanceTerminal << "\f" << data.value << hwlib::flush; //If the type is dinstance it will write the value to the dinstanceTerminal
				break;
			case DisplayType::temperature:
				hwlib::cout << data.value << hwlib::endl;
				temperatureTerminal << "\f" << data.value << hwlib::flush; //If the type is temperature it will write the value to the temperatureTerminal
				break;
		}
	}
}

void OledTask::setDisplayData(DisplayType type, int value) {
	oledChannel.write({type, value});
}