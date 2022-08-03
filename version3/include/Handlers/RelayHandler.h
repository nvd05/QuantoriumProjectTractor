#pragma once

#include "Configuration/PWMValues.h"
#include "Configuration/PinList.h"
#include <Arduino.h>

void configuration_relay_handler()
{
	pinMode(PIN_RELAY_IGNITION, OUTPUT); // Зажигание
}

void listener_relay_handler()
{
	// Условия не сокращяю в if (...) {return; }, потому что еслт нужно будет еще что-то добавить,
	// Тогда будет проще пойти по полным условиям.

	// Зажигание
	// Зажигание и Глушение не может одновременно работать.
	if (remote_values.two_position_toggle_switch < PWM_SERVO_MUTE_MINIMUM)
	{
		/*
		*       sticks
		 *   left   right
		 * +-----+ +-----+
		 * |     | |     |
		 * |    *| |*    |
		 * +-----+ +-----+
		 */
		bool ignition_right_width = remote_values.right_stick_width < PWM_RELAY_IGNITION_HEIGHT_MAXIMUM;
		bool ignition_left_height = remote_values.left_stick_height < PWM_RELAY_IGNITION_HEIGHT_MAXIMUM;
		bool ignition_left_width  = remote_values.left_stick_width  > PWM_RELAY_IGNITION_WIDTH_MINIMUM;
		bool ignition_status = ignition_right_width && ignition_left_height && ignition_left_width;
		digitalWrite(PIN_RELAY_IGNITION, ignition_status ? HIGH : LOW);
	}

	// code...
}
