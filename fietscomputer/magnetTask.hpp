#ifndef MAGNETTASK_H_
#define MAGNETTASK_H_

#include "hwlib.hpp"
#include "rtos.hpp"

#include "fietscomputerTask.hpp"
#include "MPU9250.hpp"

class MagnetTask : public rtos::task<> {
private:
	MPU9250& mpu;
	FietscomputerTask& fietsTask;
	rtos::clock clock;

public:
	MagnetTask(MPU9250& mpu, FietscomputerTask& fietsTask);
	void main() override;
};

#endif