#include <Arduino.h>
#include "Timer.h"

void Timer::set_microseconds(long microseconds)
{
	_microseconds = microseconds;
};

long Timer::get_elapsed_time(bool update_time)
{
	long current_time = micros();
	long elapsed_time = current_time - _microseconds;

	if (update_time)
	{
		set_microseconds(current_time);
	}

	return elapsed_time;
};

Timer::Timer() : _microseconds(micros())
{
};
