#include "ActuatorAssistant.h"
#include <Arduino.h>

void ActuatorAssistant::configuration(long current, long minimum, long maximum)
{
	_maximumPosition = maximum;
	_currentPosition = current;
	_minimumPosition = minimum;
};

// ===== ===== ===== ===== =====

void ActuatorAssistant::set_current(long position)
{
	_currentPosition = constrain(position, _minimumPosition, _maximumPosition);
};

void ActuatorAssistant::add_current(long position)
{
	set_current(_currentPosition + position);
};

// ===== ===== ===== ===== =====

long ActuatorAssistant::get_maximum()
{
	return _maximumPosition;
};

long ActuatorAssistant::get_current()
{
	return _currentPosition;
};

long ActuatorAssistant::get_minimum()
{
	return _minimumPosition;
};
