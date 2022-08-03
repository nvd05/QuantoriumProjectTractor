#pragma once

#include "Configuration/PWMValues.h"
#include "Configuration/PinList.h"
#include "Memory/VariableList.h"

void configuration_servo_handler()
{
	servo_list.mute.attach(PIN_SERVO_MUTE); // Глушение
	servo_list.gas.attach(PIN_SERVO_GAS);   // Газ
}

void listener_servo_handler()
{
	// Глушение
	servo_list.mute.write(remote_values.two_position_toggle_switch > PWM_SERVO_MUTE_MINIMUM ? 180 : 0);

	// Газ
	servo_list.gas.write(map(remote_values.left_stick_height, PWM_SERVO_GAS_MINIMUM, PWM_REMOTE_MAXIMUM, 0, 180));
}
