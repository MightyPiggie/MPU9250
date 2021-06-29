#include "angleTask.hpp"

AngleTask::AngleTask(MPU9250& mpu, OledTask& oledTask):
	task(4, "Angle Task"),
	mpu(mpu),
	oledTask(oledTask),
	clock(this, 2500 * 1000)
{}

void AngleTask::main() {
	while(true) {
		hwlib::wait_ms(100); // Wait a short moment to be sure there is no interference on the bus
		int pitch = (mpu.getPitch());
		hwlib::cout << int(pitch) << hwlib::endl;
		int angle = ((90.f - pitch)/90.f)*100.f;
		hwlib::cout << angle << hwlib::endl;
		oledTask.setDisplayData(OledTask::DisplayType::angle, angle);
		wait(clock);
	}
}