#include "oledTask.hpp"

OledTask::OledTask(hwlib::i2c_bus& bus):
	task(1, "Oled Task"),
	oledChannel(this, "OledChannel"),
	display(bus, 0x3c),
	speedPart(display, hwlib::xy(0,0), hwlib::xy(64, 32)),
	distancePart(display, hwlib::xy(0, 32), hwlib::xy(64, 64)),
	temperaturePart(display, hwlib::xy(64, 0), hwlib::xy(128, 32)),
	speedTerminal(speedPart, font),
	distanceTerminal(distancePart, font),
	temperatureTerminal(temperaturePart, font)
{}

void OledTask::main() {
	while(true){
		wait(oledChannel);
		auto data = oledChannel.read();
		switch (data.type) {
			case DisplayType::speed:
				speedTerminal << "\f" << data.value << hwlib::flush;
				break;
			case DisplayType::distance:
				distanceTerminal << "\f" << data.value << hwlib::flush;
				break;
			case DisplayType::temperature:
				temperatureTerminal << "\f" << data.value << hwlib::flush;
				break;
		}
	}
}

void OledTask::setDisplayData(DisplayType type, int value) {
	oledChannel.write({type, value});
}