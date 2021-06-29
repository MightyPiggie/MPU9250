#ifndef I2C_DEVICE_H_
#define I2C_DEVICE_H_

#include "hwlib.hpp"
#include "rtos.hpp"

class I2C_device {
private:
	hwlib::i2c_bus& bus;
	uint8_t adress;
	rtos::mutex busMutex;
	
	union {
		int16_t full_bits;
		uint8_t half_bits[2];
	} combine;
	
protected:
	/**
	 * @brief This function creates an I2C device with the bus and adress of the chip
	 * 
	 * @param bus This is the hwlib bus created with the pins from the chip
	 * 
	 * @param adress This is the adress from the chip
	 */
	I2C_device(hwlib::i2c_bus& bus, 	uint8_t adress);
	
	/**
	 * @brief This function writes data to the chip
	 * 
	 * @param reg This is the register adress to which the function will write
	 * 
	 * @param data This is the data that the function will write to the register adress
	 */
	void write(uint8_t reg, uint8_t data);
	
	/**
	 * @brief This function reads data from the registers
	 * 
	 * @param reg This is the register adress from which the function will read from
	 * 
	 * @return The data that has been read from the register adress
	 */
	int8_t read(uint8_t reg);
	
	/**
	 * @brief This function will read 2 bytes from 2 registers and combine them to one uint16_t "byte"
	 * 
	 * @param LSB This is the register adress of the least significant bits
	 * 
	 * @param MSB This is the register adress of the most significant bits
	 * 
	 * @return The data that has been read from the least and most significant bits combined to one uint16_t byte.
	 */
	int16_t read2Bytes(uint8_t LSB, uint8_t MSB);
	
	/**
	 * @brief This function will read a register an x amount of times and makes an average out of it
	 * 
	 * @param reg This is the register adress that the function will read from
	 * 
	 * @param amount This is the amount you want the function to read the register
	 * 
	 * @return An average from the data that was read from the register x times.
	 */
	int8_t readAverage(uint8_t reg, int amount);
	
	/**
	 * @brief This function will read two registers an x amount of times and combines them to one uint16_t "byte" and then it makes an average from it.
	 * 
	 * @param LSB This is the register adress of the least significant bits
	 * 
	 * @param MSB This is the register adress of the least significant bits
	 * 
	 * @param amount This is the amount you want the function to read the registers
	 * 
	 * @return The averga data that the function has read from the 2 registers.
	 */
	int16_t read2BytesAverage(uint8_t LSB, uint8_t MSB, int amount);
};

#endif