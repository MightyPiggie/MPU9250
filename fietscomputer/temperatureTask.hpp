#ifndef TEMPERATURETASK_H_
#define TEMPERATURETASK_H_

#include "hwlib.hpp"
#include "rtos.hpp"

#include "oledTask.hpp"
#include "MPU9250.hpp"

class TemperatureTask : public rtos::task<> {
private:
	MPU9250& mpu;
	OledTask& oledTask;
	rtos::clock clock;

public:
	TemperatureTask(MPU9250& mpu, OledTask& oledTask);
	void main() override;
};

#endif