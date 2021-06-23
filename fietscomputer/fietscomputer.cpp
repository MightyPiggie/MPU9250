#include "fietscomputer.hpp"

fietscomputer::fietscomputer(unsigned int circumference):
	circumference(circumference)
{}

void fietscomputer::add_rotation() {
	rotations++;
	for(int i = 0; i < 50; i++) {
		if(timestamps[i] == 0) {
			timestamps[i] = hwlib::now_us() + (10 * 1000 * 1000);
			return;
		}
	}
}

void fietscomputer::clear_timestamps() {
	uint64_t now = hwlib::now_us();
	for(int i = 0; i < 50; i++) {
		if(timestamps[i] < now) {
			timestamps[i] = 0;
		}
	}
}

uint8_t fietscomputer::count_timestamps() {
	uint8_t count = 0;
	for(int i = 0; i < 50; i++) {
		if(timestamps[i] != 0) count++;
	}
	return count;
}

float fietscomputer::calc_speed() {
	clear_timestamps();
	auto count = count_timestamps();
	return (count / 10.0) * (circumference / 1000.0);
}