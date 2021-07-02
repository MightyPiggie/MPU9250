#include "angleTask.hpp"

AngleTask::AngleTask(MPU9250& mpu, OledTask& oledTask):
	task(4, "Angle Task"),
	mpu(mpu),
	oledTask(oledTask),
	clock(this, 10000 * 1000)
{}

void AngleTask::main() {
	while(true) {
		hwlib::wait_ms(100); // Wait a short moment to be sure there is no interference on the bus
		int pitch = (mpu.getPitch());
		int angle = ((90.f - pitch)/90.f)*100.f;
		oledTask.setDisplayData(OledTask::DisplayType::angle, angle);
		wait(clock);
	}
}