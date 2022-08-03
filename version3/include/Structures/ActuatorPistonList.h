#pragma once

#include "ActuatorPiston/ActuatorPiston.h"
#include "Memory/VariableList.h"

struct ActuatorPistonList final
{
	ActuatorPiston gearbox; // Коробка передач
	ActuatorPiston clutch;  // Сцепление
	ActuatorPiston rudder;  // Руль
	ActuatorPiston brake;   // Тормоз
};
