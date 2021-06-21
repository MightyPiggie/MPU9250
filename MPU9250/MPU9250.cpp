#include "MPU9250.hpp"

#include "MPU9250_defines.hpp"



MPU9250::MPU9250(uint8_t adress_6050, uint8_t adress_mag, hwlib::i2c_bus& bus):
	adress_6050(adress_6050),
	adress_mag(adress_mag),
	bus(bus)
		{}
		
void MPU9250::write(uint8_t adress, uint8_t reg, uint8_t data) {
	auto trans = bus.write(adress);
	trans.write(reg);
	trans.write(data);	
}
			
uint8_t MPU9250::read(uint8_t adress, uint8_t reg) {
	bus.write(adress).write(reg);
	return bus.read(adress).read_byte();
}
		
int16_t MPU9250::read_2_bytes(uint8_t adress, uint8_t LSB, uint8_t MSB) {
	combine.half_bits[0] = read(adress, LSB);
	combine.half_bits[1] = read(adress, MSB);
	return combine.full_bits;
			}
			
uint8_t MPU9250::get_temperature() {
	uint16_t temp = read_2_bytes(adress_6050, REG_TEMP_OUT_L, REG_TEMP_OUT_H);
	return (temp / 333.87) + 17;
		}
		
int16_t MPU9250::get_x_accel() {
	return read_2_bytes(adress_6050, REG_ACCEL_XOUT_L, REG_ACCEL_XOUT_H);
	}
int16_t MPU9250::get_y_accel() {
	return read_2_bytes(adress_6050, REG_ACCEL_YOUT_L, REG_ACCEL_YOUT_H);
	}
int16_t MPU9250::get_z_accel() {
	return read_2_bytes(adress_6050, REG_ACCEL_ZOUT_L, REG_ACCEL_ZOUT_H);
	}
	
int16_t MPU9250::get_x_gyro() {
	return read_2_bytes(adress_6050, REG_GYRO_XOUT_L, REG_GYRO_XOUT_H);
	}
int16_t MPU9250::get_y_gyro() {
	return read_2_bytes(adress_6050, REG_GYRO_YOUT_L, REG_GYRO_YOUT_H);
	}
int16_t MPU9250::get_z_gyro() {
	return read_2_bytes(adress_6050, REG_GYRO_ZOUT_L, REG_GYRO_ZOUT_H);
	}	
MPU9250::cal_mag MPU9250::get_cal_mag() {
	write(adress_mag, REG_MAG_CONTROL1, 0x00);
	hwlib::wait_ms(10);
	write(adress_mag, REG_MAG_CONTROL1, 0x0F);
	hwlib::wait_ms(10);
	MPU9250::cal_mag cal_mag;
	cal_mag.x = ((read(adress_mag, 0x10)-128)/256+1);
	cal_mag.y = ((read(adress_mag, 0x11)-128)/256+1);
	cal_mag.z = ((read(adress_mag, 0x12)-128)/256+1);
	return cal_mag;
}
int16_t MPU9250::get_x_mag() {
	auto temp =  read_2_bytes(adress_mag, REG_MAG_XOUT_L, REG_MAG_XOUT_H) * calibrated_mag.x;
	read(adress_mag, REG_MAG_STATUS2);
	return temp;
	}
int16_t MPU9250::get_y_mag() {
	auto temp = read_2_bytes(adress_mag, REG_MAG_YOUT_L, REG_MAG_YOUT_H) * calibrated_mag.y;
	read(adress_mag, REG_MAG_STATUS2);
	return temp;
	}
int16_t MPU9250::get_z_mag() {
	auto temp = read_2_bytes(adress_mag, REG_MAG_ZOUT_L, REG_MAG_ZOUT_H) * calibrated_mag.z;
	read(adress_mag, REG_MAG_STATUS2);
	return temp;
	}
						
MPU9250::xyz MPU9250::get_accel_data(){
	return {get_x_accel(), get_y_accel(), get_z_accel()};
		}	
		
MPU9250::xyz MPU9250::get_gyro_data(){
	return {get_x_gyro(), get_y_gyro(), get_z_gyro()};
		}
void MPU9250::check_if_sensor_present(){
	if(read(adress_6050, REG_WHO_AM_I) != MPU9250_ADDRESS) {
		hwlib::cout << "MPU9250 has not been detected. Check if the cables are wired correctly.";
	}
}		
void MPU9250::init_mag(){
	check_if_sensor_present();
	write(adress_6050, REG_INT_PIN_CFG, 0x2);
	calibrated_mag = get_cal_mag();
	write(adress_mag, REG_MAG_CONTROL1, 0x00);
	write(adress_mag, REG_MAG_CONTROL1,0x16);
}