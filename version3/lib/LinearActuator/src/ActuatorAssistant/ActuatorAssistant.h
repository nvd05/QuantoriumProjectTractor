#pragma once

class ActuatorAssistant
{
private:
	long _maximumPosition;
	long _currentPosition;
	long _minimumPosition;

public:
	virtual void set_expected(long position);

	void configuration(long current, long minimum, long maximum);

	void set_current(long position);
	void add_current(long position);

	long get_maximum();
	long get_current();
	long get_minimum();
};
