#include "ActuatorMotor.h"
#include <Arduino.h>

void ActuatorMotor::configuration(long pin_enable, long pin_input_a, long pin_input_b)
{
	_pinEnable = pin_enable;
	_pinInputA = pin_input_a;
	_pinInputB = pin_input_b;

	pinMode(_pinEnable, OUTPUT);
	pinMode(_pinInputA, OUTPUT);
	pinMode(_pinInputB, OUTPUT);

	ActuatorAssistant::configuration(0, -1, 1);
};

void ActuatorMotor::set_expected(long position)
{
	// normalize value
	set_current(position);

	digitalWrite(_pinInputA, get_current() + 2 == HIGH);
	digitalWrite(_pinInputB, get_current() + 0 == HIGH);
};

void ActuatorMotor::set_enable(long enable)
{
	digitalWrite(_pinEnable, enable == HIGH);
};
