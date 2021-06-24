#include "OledTask.hpp"

OledTask::OledTask():
oledChannel(this, "oledChannel")
{}
void OledTask::main() {
	while(true){
		wait(oledChannel);
		
	}
	
}

void OledTask::setDisplay(int data, hwlib::terminal_from terminal) {
	displayData data1 = displayData(data, terminal);
	oledChannel.write(data1);
}