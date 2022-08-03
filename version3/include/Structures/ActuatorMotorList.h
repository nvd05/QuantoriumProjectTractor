#pragma once

#include "ActuatorMotor/ActuatorMotor.h"

struct ActuatorMotorList final
{
	ActuatorMotor gearbox; // Коробка передач
	ActuatorMotor clutch;  // Сцепление
	ActuatorMotor rudder;  // Руль
	ActuatorMotor brake;   // Тормоз
};
