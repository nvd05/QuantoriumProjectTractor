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
	double percent = (double) get_current() / (double) get_expected();

	// Если ожидаемое и текущее положения совпадают на больше чем 90%, тогда не нужно двигать
	if (percent > 0.9 && percent < 1.1)
	{
		_motor.set_expected(0);
		return;
	}

	_motor.set_expected(_expectedPosition - get_current());
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
	return percent < 0.9 || percent > 1.1;
};
