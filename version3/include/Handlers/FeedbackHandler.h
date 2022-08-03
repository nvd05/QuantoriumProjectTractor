#pragma once

#include "Configuration/PinList.h"
#include "Memory/VariableList.h"
#include <Arduino.h>

void configuration_feedback_handler()
{
	pinMode(PIN_FEEDBACK_POTENTIOMETER_RUDDER, INPUT); // Руль
	pinMode(PIN_FEEDBACK_POTENTIOMETER_WHEEL,  INPUT); // Колеса
	pinMode(PIN_FEEDBACK_BUTTON_GEARBOX,       INPUT); // Коробка передач
}

void listener_feedback_handler()
{
	feedback_values.gearbox = digitalRead(PIN_FEEDBACK_BUTTON_GEARBOX);      // Коробка передач
	feedback_values.rudder  = analogRead(PIN_FEEDBACK_POTENTIOMETER_RUDDER); // Руль
	feedback_values.wheel   = analogRead(PIN_FEEDBACK_POTENTIOMETER_WHEEL);  // Колеса
}
