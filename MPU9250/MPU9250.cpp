#include "MPU9250.hpp"

#include "MPU9250_defines.hpp"



MPU9250::MPU9250(uint8_t adress, hwlib::i2c_bus& bus):
	adress(adress),
	bus(bus)
		{}
void MPU9250::write(uint8_t reg, uint8_t data) {
	auto trans = bus.write(adress);
	trans.write(reg);
	trans.write(data);	
		}
			
uint8_t MPU9250::read(uint8_t reg) {
	bus.write(adress).write(reg);
	return bus.read(adress).read_byte();
		}
		
int16_t MPU9250::read_2_bytes(uint8_t LSB, uint8_t MSB) {
	combine.half_bits[0] = read(LSB);
	combine.half_bits[1] = read(MSB);
	return combine.full_bits;
			}
			
uint8_t MPU9250::get_temperature() {
	uint16_t temp = read_2_bytes(REG_TEMP_OUT_L, REG_TEMP_OUT_H);
	return (temp / 333.87) + 17;
		}
		
int16_t MPU9250::get_x_accel() {
	return read_2_bytes(REG_ACCEL_XOUT_L, REG_ACCEL_XOUT_H);
	}
int16_t MPU9250::get_y_accel() {
	return read_2_bytes(REG_ACCEL_YOUT_L, REG_ACCEL_YOUT_H);
	}
int16_t MPU9250::get_z_accel() {
	return read_2_bytes(REG_ACCEL_ZOUT_L, REG_ACCEL_ZOUT_H);
	}
MPU9250::cal_mag MPU9250::get_cal_mag(MPU9250 mag) {
	mag.write(0xA, 0x00);
	hwlib::wait_ms(10);
	mag.write(0xA, 0x0F);
	hwlib::wait_ms(10);
	MPU9250::cal_mag cal_mag;
	cal_mag.x = ((mag.read(0x10)-128)/256+1);
	cal_mag.y = ((mag.read(0x11)-128)/256+1);
	cal_mag.z = ((mag.read(0x12)-128)/256+1);
	return cal_mag;
}
int16_t MPU9250::get_x_mag() {
	return read_2_bytes(REG_MAG_XOUT_L, REG_MAG_XOUT_H);
	}
int16_t MPU9250::get_y_mag() {
	return read_2_bytes(REG_MAG_YOUT_L, REG_MAG_YOUT_H);
	}
int16_t MPU9250::get_z_mag() {
	return read_2_bytes(REG_MAG_ZOUT_L, REG_MAG_ZOUT_H);
	}
						
MPU9250::xyz MPU9250::get_accel_data(){
	MPU9250::xyz accel_data;
	accel_data.x = get_x_accel();
	accel_data.y = get_y_accel();
	accel_data.z = get_z_accel();
	return accel_data;
		}	