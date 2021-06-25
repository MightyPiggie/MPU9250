#include "magnetTask.hpp"

MagnetTask::MagnetTask(MPU9250& mpu, FietscomputerTask& fietsTask):
	task(0, "Magnet Task"),
	mpu(mpu),
	fietsTask(fietsTask),
	clock(this, 10 * 1000)
{}

void MagnetTask::main() {
	bool triggered = false; //Set triggered standard as false.
	while(true) {
		int z = mpu.get_z_mag();
		if((z >= 5000 || z <=-5000) && triggered == false) {
			hwlib::cout << z << hwlib::endl;
			triggered = true; //Set triggered true so the magnet will not be detected multiple times
			fietsTask.addRotation();
		}
		else if(z < 5000 && z > -5000 && triggered == true) {
			triggered = false; // Set triggered false once the magnet is not being detected anymore
		}
		wait(clock);
	}
}