#pragma once

#include "ActuatorAssistant/ActuatorAssistant.h"
#include "ActuatorMotor/ActuatorMotor.h"
#include "Timer.h"

class ActuatorPiston final : public ActuatorAssistant
{
private:
	long _expectedPosition = 0;
	long _previousPosition = 0;
	bool _block;

	ActuatorMotor _motor;
	Timer         _timer;

public:
	void configuration(ActuatorMotor motor, long current, long minimum, long maximum);

	void update_direction();
	void update_position();

	void set_expected(long position) override;
	void set_expected_map(long position, long minimum, long maximum);
	void set_block(bool block);

	long get_expected();
	long get_previous();

	bool is_move();
};
