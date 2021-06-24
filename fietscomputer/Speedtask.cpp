#include "Speedtask.hpp"


	
	
	
SpeedTask::SpeedTask(fietscomputer fiets):
wait_time(this, "wait_time"),
fiets(fiets)
{}

void SpeedTask::main() {
	hwlib::cout << "KM/Uur: " << int(fiets.calc_speed()*3.6) << hwlib::endl;
	
	wait_time.set(5000);
	wait(wait_time);
	
}