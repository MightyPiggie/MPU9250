#include "fietscomputerTask.hpp"

unsigned int CIRCUMFERENCE = 2268;

FietscomputerTask::FietscomputerTask(OledTask& oledTask):
	task(2, "Fietscomputer Task"),
	oledTask(oledTask),
	fc(CIRCUMFERENCE),
	clock(this, 1000 * 1000)
{}

void FietscomputerTask::main() {
	while(true) {
		wait(clock);
		oledTask.setDisplayData(OledTask::DisplayType::speed, fc.calc_speed() * 3.6);
		oledTask.setDisplayData(OledTask::DisplayType::distance, fc.get_distance());
	}
}

void FietscomputerTask::addRotation() {
	fc.add_rotation();
}