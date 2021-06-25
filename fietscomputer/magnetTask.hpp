#ifndef MAGNETTASK_H_
#define MAGNETTASK_H_

#include "hwlib.hpp"
#include "rtos.hpp"

#include "fietscomputerTask.hpp"
#include "MPU9250.hpp"

class MagnetTask : public rtos::task<> {
private:
	MPU9250 ak;
	FietscomputerTask& fietsTask;
	rtos::clock clock;

public:
	MagnetTask(hwlib::i2c_bus& bus, FietscomputerTask& fietsTask);
	void main() override;
};

#endif