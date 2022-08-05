#include "ActuatorPiston.h"
#include <Arduino.h>
#include "Timer.h"

void ActuatorPiston::configuration(ActuatorMotor motor, long current, long minimum, long maximum)
{
	ActuatorAssistant::configuration(current, minimum, maximum);
	_motor = motor;
};

// ===== ===== ===== ===== =====

void ActuatorPiston::update_direction()
{
	_motor.set_expected(is_move() ? _expectedPosition - get_current() : 0);
};

void ActuatorPiston::update_position()
{
	add_current(_motor.get_current() * (_timer.get_elapsed_time(true) / 10));
};

// ===== ===== ===== ===== =====

void ActuatorPiston::set_expected(long position)
{
	if (_block)
	{
		return;
	}

	_expectedPosition = constrain(position, get_minimum(), get_maximum());
};

void ActuatorPiston::set_expected_map(long position, long minimum, long maximum)
{
	long value = map(position, minimum, maximum, get_minimum(), get_maximum());
	set_expected(value);
};

void ActuatorPiston::set_block(bool block)
{
	_block = block;
};

long ActuatorPiston::get_expected()
{
	return _expectedPosition;
};

long ActuatorPiston::get_previous()
{
	return _previousPosition;
};

bool ActuatorPiston::is_move()
{
	double percent = (double) get_current() / (double) get_expected();
	return percent < 0.8 || percent > 1.2;
};
