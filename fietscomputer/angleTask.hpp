#ifndef HELLINGTASK_H_
#define HELLINGTASK_H_

#include "hwlib.hpp"
#include "rtos.hpp"

#include "oledTask.hpp"
#include "MPU9250.hpp"

class AngleTask : public rtos::task<> {
private:
	MPU9250& mpu;
	OledTask& oledTask;
	rtos::clock clock;

public:
	AngleTask(MPU9250& mpu, OledTask& oledTask);
	void main() override;
};

#endif