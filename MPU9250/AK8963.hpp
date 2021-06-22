#ifndef AK8963_H_
#define AK8963_H_
#include "hwlib.hpp"
#include "XYZ.hpp"
#include "I2C_device.hpp"

class AK8963 : public I2C_device {
private:
	struct cal_mag {
		float x;
		float y;
		float z;
	};
	cal_mag calibrated_mag;
public:
	AK8963(hwlib::i2c_bus& bus, uint8_t adress);
	
	cal_mag get_cal_mag();
	int16_t get_x_mag();
	int16_t get_y_mag();
	int16_t get_z_mag();
	xyz get_mag_data();
	void init();
};

#endif	