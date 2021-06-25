#ifndef FIETSCOMPUTER_H_
#define FIETSCOMPUTER_H_
#include "hwlib.hpp"

class fietscomputer {
private:
	uint64_t timestamps[50] = {0};
	unsigned int rotations = 0;
	unsigned int circumference;
public:	
fietscomputer(unsigned int circumference);

void add_rotation();

void clear_timestamps();

uint8_t count_timestamps();

float calc_speed();

unsigned int get_distance();
};

#endif	