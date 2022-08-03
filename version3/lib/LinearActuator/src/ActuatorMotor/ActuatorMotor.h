#pragma once

#include "ActuatorAssistant/ActuatorAssistant.h"

class ActuatorMotor final : public ActuatorAssistant
{
private:
	long _pinEnable;
	long _pinInputA;
	long _pinInputB;

public:
	void configuration(long pin_enable, long pin_input_a, long pin_input_b);
	void set_expected(long position) override;
	void set_enable(long enable);
};
