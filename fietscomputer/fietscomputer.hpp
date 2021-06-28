#ifndef FIETSCOMPUTER_H_
#define FIETSCOMPUTER_H_
#include "hwlib.hpp"

class Fietscomputer {
private:
	uint64_t timestamps[50] = {0};
	unsigned int rotations = 0;
	unsigned int circumference;
public:	
Fietscomputer(unsigned int circumference);

void add_rotation();

void clear_timestamps();

uint8_t count_timestamps();

float calc_speed();

unsigned int get_distance();
};

#endif	