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
	
	/**
	 * @brief Get the calibration data from the registers 
	 * 
	 * @return The calibration data in a struct with 3 floats called x, y and z.
	 */
	cal_mag get_cal_mag();
	
	/**
	 * @brief Get the current x axis magnetometer data 
	 * 
	 * @return The current x axis magnetometer data as a signed 16 bit integer. The returned data is calibrated
	 */
	int16_t get_x_mag();
	
	/**
	 * @brief Get the current y axis magnetometer data 
	 * 
	 * @return The current y axis magnetometer data as a signed 16 bit integer. The returned data is calibrated
	 */
	int16_t get_y_mag();
	
	/**
	 * @brief Get the current z axis magnetometer data 
	 * 
	 * @return The current z axis magnetometer data as a signed 16 bit integer. The returned data is calibrated
	 */
	int16_t get_z_mag();
	
	/**
	 * @brief Get the currect magnetometer data 
	 * 
	 * @return The currect magnetometer data from all axis in a xyz struct. The returned data is calibrated
	 */
	xyz get_mag_data();
	
	/**
	 * @brief Initialize the AK8963 sensor
	 * 
	 * @return A true (1) if the initialization is succesful.
	 */
	bool init();
};

#endif	