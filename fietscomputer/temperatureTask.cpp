#include "temperatureTask.hpp"

TemperatureTask::TemperatureTask(MPU9250& mpu, OledTask& oledTask):
	task(3, "Temperature Task"),
	mpu(mpu),
	oledTask(oledTask),
	clock(this, 60000 * 1000)
{}

void TemperatureTask::main() {
	while(true) {
		oledTask.setDisplayData(OledTask::DisplayType::temperature, (int)mpu.get_temperature());
		wait(clock);
	}
}