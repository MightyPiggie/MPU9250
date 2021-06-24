#ifndef OLEDTASK_H_
#define OLEDTASK_H_

#include "hwlib.hpp"
#include "rtos.hpp"

#include "fietscomputer.hpp"

class OledTask : public rtos::task<> {
private:
	rtos::channel<int, 5> oledChannel;
	struct displayData {
		int data = 0;
		hwlib::terminal_from terminal;
		displayData(int data, hwlib::terminal_from terminal):
		data(data),
		terminal(terminal)
		{}
	};

public:
OledTask();
	void main() override;
	void setDisplay(int data, hwlib::terminal_from terminal );
};
#endif