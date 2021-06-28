#ifndef FIETSCOMPUTERTASK_H_
#define	FIETSCOMPUTERTASK_H_

#include "hwlib.hpp"
#include "rtos.hpp"

#include "oledTask.hpp"
#include "fietscomputer.hpp"

class FietscomputerTask : public rtos::task<> {
private:
	OledTask& oledTask;
	Fietscomputer fc;
	rtos::clock clock;

public:
	FietscomputerTask(OledTask& oledTask);
	void main() override;
	
	void addRotation();
};

#endif