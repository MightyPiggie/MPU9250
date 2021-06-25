#include "fietscomputerTask.hpp"

unsigned int CIRCUMFERENCE = 2268;

FietscomputerTask::FietscomputerTask(OledTask& oledTask):
	task(2, "Fietscomputer Task"),
	oledTask(oledTask),
	fc(CIRCUMFERENCE),
	clock(this, 10000 * 1000)
{}

void FietscomputerTask::main() {
	while(true) {
		oledTask.setDisplayData(OledTask::DisplayType::speed, fc.calc_speed() * 3.6); //Write the speed data to the oled Task
		oledTask.setDisplayData(OledTask::DisplayType::distance, fc.get_distance()); //Write the distance data to the oled Task
		wait(clock);
	}
}

void FietscomputerTask::addRotation() {
	fc.add_rotation();
}