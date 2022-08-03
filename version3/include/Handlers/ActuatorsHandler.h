#pragma once

#include "Configuration/PWMValues.h"
#include "Configuration/PinList.h"
#include "Memory/VariableList.h"

void configuration_actuators_handler()
{
	actuator_motor_list.gearbox.configuration(PIN_DRIVER_GEARBOX_ENABLE, PIN_DRIVER_GEARBOX_INPUT_A, PIN_DRIVER_GEARBOX_INPUT_B);
	actuator_motor_list.clutch .configuration(PIN_DRIVER_CLUTCH_ENABLE,  PIN_DRIVER_CLUTCH_INPUT_A,  PIN_DRIVER_CLUTCH_INPUT_B);
	actuator_motor_list.rudder .configuration(PIN_DRIVER_RUDDER_ENABLE,  PIN_DRIVER_RUDDER_INPUT_A,  PIN_DRIVER_RUDDER_INPUT_B);
	actuator_motor_list.brake  .configuration(PIN_DRIVER_BRAKE_ENABLE,   PIN_DRIVER_BRAKE_INPUT_A,   PIN_DRIVER_BRAKE_INPUT_B);

	actuator_piston_list.gearbox.configuration(actuator_motor_list.gearbox, 0, 0, (long) 1000000); // Коробка передач
	actuator_piston_list.clutch .configuration(actuator_motor_list.clutch,  0, 0, (long) 1000000); // Сцепление
	actuator_piston_list.rudder .configuration(actuator_motor_list.rudder,  0, 0, (long) 1000000); // Руль
	actuator_piston_list.brake  .configuration(actuator_motor_list.brake,   0, 0, (long) 1000000); // Тормоз

	// Serial.begin(9600);
	// Serial.println("running");
}

void listener_actuators_handler()
{
	// Коробка передач
	actuator_piston_list.gearbox.update_direction();
	actuator_piston_list.gearbox.update_position();

	// Сцепление
	actuator_piston_list.clutch.update_direction();
	actuator_piston_list.clutch.update_position();

	// Руль
	actuator_piston_list.rudder.update_direction();
	actuator_piston_list.rudder.update_position();
	actuator_piston_list.rudder.set_expected_map(remote_values.right_stick_width, PWM_REMOTE_MINIMUM, PWM_REMOTE_MAXIMUM);

	// Тормоз
	actuator_piston_list.brake.update_direction();
	actuator_piston_list.brake.update_position();
	actuator_piston_list.brake.set_expected_map(remote_values.left_stick_height, 1450, 0);

	// Serial.println(actuator_piston_list.gearbox.get_current());
	// Serial.println(actuator_piston_list.gearbox.get_expected());
	// Serial.println();
}
