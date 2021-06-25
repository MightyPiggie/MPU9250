#include "fietscomputer.hpp"

fietscomputer::fietscomputer(unsigned int circumference):
	circumference(circumference)
{}

void fietscomputer::add_rotation() {
	rotations++; //Add a rotation to the total rotations
	for(int i = 0; i < 50; i++) {
		if(timestamps[i] == 0) { //Cycle trough the array and find the first timestamp that is 0
			timestamps[i] = hwlib::now_us() + (10 * 1000 * 1000); //Make the first timestamp that is 0 the current time + 10 seconds
			return;
		}
	}
}

void fietscomputer::clear_timestamps() {
	uint64_t now = hwlib::now_us();
	for(int i = 0; i < 50; i++) {
		if(timestamps[i] < now) { //Cycle trough the array and make all timestamps that are older than now (so 10 seconds old) 0
			timestamps[i] = 0;
		}
	}
}

uint8_t fietscomputer::count_timestamps() {
	uint8_t count = 0;
	for(int i = 0; i < 50; i++) {
		if(timestamps[i] != 0) count++; //Count all timestamps currently in the array
	}
	return count;
}

float fietscomputer::calc_speed() {
	clear_timestamps();
	auto count = count_timestamps();
	return (count / 10.0) * (circumference / 1000.0); //Calculate the speed with the rotations (count) devided by 10 so you get the rotations per second.
} 														//After that multiply the rotations per second by the circumference of the tire in mm. And devide with 1000 so you get speed in meter/second.

unsigned int fietscomputer::get_distance() {
	return rotations * (circumference / 1000.0); //Calculate the total distance with the total rotations multiplied by the circumference in mm devided by 1000, so you will get the total dinstance in meter.
}