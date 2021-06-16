#ifndef MPU9250_H_
#define MPU9520_H_
#include "hwlib.hpp"

class MPU9250 {
private:
	uint8_t adress_6050;
	uint8_t adress_mag;
	hwlib::i2c_bus& bus;
	union {
		int16_t full_bits;
		uint8_t half_bits[2];
			} combine;
							
	struct xyz {
		int16_t x;
		int16_t y;
		int16_t z;
			};
	struct cal_mag {
		float x;
		float y;
		float z;
	};
	
												
	int16_t read_2_bytes(uint8_t adress, uint8_t LSB, uint8_t MSB);
		
public:
	MPU9250(uint8_t adress_6050, uint8_t adress_mag, hwlib::i2c_bus& bus);
	
	void write(uint8_t adress, uint8_t reg, uint8_t data);
	
	uint8_t read(uint8_t adress, uint8_t reg);
		
	/**
		 * @brief Get the current temperature
		 * 	 * 
	 * @return The current temperature in degrees Celsius
	 * 	 */
	uint8_t get_temperature();
	int16_t get_x_accel();
	int16_t get_y_accel();
	int16_t get_z_accel();
	xyz get_accel_data(); 
	cal_mag get_cal_mag();
	int16_t get_x_mag();
	int16_t get_y_mag();
	int16_t get_z_mag();
	
	};
								

#endif	