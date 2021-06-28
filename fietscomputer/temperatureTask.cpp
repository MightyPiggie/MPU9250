#include "temperatureTask.hpp"

TemperatureTask::TemperatureTask(MPU9250& mpu, OledTask& oledTask):
	task(3, "Temperature Task"),
	mpu(mpu),
	oledTask(oledTask),
	clock(this, 59000 * 1000)
{}

void TemperatureTask::main() {
	while(true) {
		hwlib::wait_ms(1000); // Wait a short moment to be sure there is no interference on the bus
		oledTask.setDisplayData(OledTask::DisplayType::temperature, mpu.getTemperature());
		wait(clock);
	}
}