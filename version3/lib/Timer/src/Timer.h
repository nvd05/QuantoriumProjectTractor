#pragma once

#include <Arduino.h>

class Timer final
{
private:
	long _microseconds;

public:
	void set_microseconds(long microseconds = micros());
	long get_elapsed_time(bool update_time);
	Timer();
};
