#pragma once

#include "Configuration/PWMValues.h"
#include "Memory/VariableList.h"

long gearbox_get_direction()
{
	// Переключение коробки передач в положение -1 (трактор двигается назад)
	if (remote_values.three_position_toggle_switch < 1250)
	{
		return 0;
	}

	// Переключение коробки в передачу 1 (трактор двигается вперед)
	if (remote_values.three_position_toggle_switch > 1750)
	{
		return 1000000;
	}

	// Нейстральная скорость
	return 500000;
}

// список функций
void gearbox_task_1()
{
	long gearbox = gearbox_get_direction();

	if (gearbox == gearbox_back)
	{
		return;
	}

	// Установить руль в центральное положение и заблокировать изменение положения
	actuator_piston_list.rudder.set_expected(0);
	actuator_piston_list.rudder.set_block(true);

	// Зажать тормоз и заблокировать изменение положения
	actuator_piston_list.brake.set_expected(actuator_piston_list.brake.get_maximum());
	actuator_piston_list.brake.set_block(true);

	// Зажать сцепление
	actuator_piston_list.clutch.set_expected(actuator_piston_list.clutch.get_maximum());

	gearbox_back   = gearbox;
	gearbox_status = 1;
}

void gearbox_task_2()
{
	// Ожидаю пока сцепление закончить двигаться
	if (actuator_piston_list.clutch.is_move())
	{
		return;
	}

	// Переключаю коробку передач в нужное положение
	actuator_piston_list.gearbox.set_expected(gearbox_back);

	gearbox_status = 2;
}

void gearbox_task_3()
{
	if (actuator_piston_list.gearbox.is_move())
	{
		return;
	}

	// Отдать сцепление
	actuator_piston_list.clutch.set_expected(actuator_piston_list.clutch.get_minimum());

	gearbox_status = 3;
}

void gearbox_task_4()
{
	// Ожидание пока сцепление отожмется
	if (actuator_piston_list.clutch.is_move())
	{
		return;
	}

	// Убираю блокировку на руле и тормозе
	// В нужные положения их автоматический выставит пульт
	actuator_piston_list.rudder.set_block(false);
	actuator_piston_list.brake.set_block(false);

	gearbox_status = 0;
}

void listener_gearbox_handler()
{
	switch (gearbox_status)
	{
		case 0: gearbox_task_1(); break;
		case 1: gearbox_task_2(); break;
		case 2: gearbox_task_3(); break;
		case 3: gearbox_task_4(); break;
	}
}
