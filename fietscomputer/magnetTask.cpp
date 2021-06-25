#include "magnetTask.hpp"

MagnetTask::MagnetTask(hwlib::i2c_bus& bus, FietscomputerTask& fietsTask):
	task(0, "Magnet Task"),
	ak(bus, 0x68, 0x0C),
	fietsTask(fietsTask),
	clock(this, 10 * 1000)
{}

void MagnetTask::main() {
	bool triggered = false;
	while(true) {
		int z = ak.get_z_mag();
		if((z >= 5000 || z <=-5000) && triggered == false) {
			hwlib::cout << z << hwlib::endl;
			triggered = true;
			fietsTask.addRotation();
		}
		else if(z < 5000 && z > -5000 && triggered == true) {
			triggered = false;
		}
		wait(clock);
	}
}