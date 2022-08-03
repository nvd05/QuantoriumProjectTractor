#pragma once

#include "Memory/VariableList.h"
#include <Arduino.h>

/* displaying functions */

void display_page_1()
{
	// channel 1
	lcd_display.setCursor(0, 0);
	lcd_display.print("ch1: " + String(remote_values.right_stick_width));

	// channel 2
	lcd_display.setCursor(9, 0);
	lcd_display.print(", ch2: " + String(remote_values.right_stick_height));

	// channel 3
	lcd_display.setCursor(0, 1);
	lcd_display.print("ch3: " + String(remote_values.left_stick_height));

	// channel 4
	lcd_display.setCursor(9, 1);
	lcd_display.print(", ch4: " + String(remote_values.left_stick_width));

	// channel 5
	lcd_display.setCursor(0, 2);
	lcd_display.print("ch5: " + String(remote_values.three_position_toggle_switch));

	// channel 6
	lcd_display.setCursor(9, 2);
	lcd_display.print(", ch6: " + String(remote_values.two_position_toggle_switch));

	// working hours
	long _second = millis() / 1000;
	long _minute = _second  / 60;
	long _hour   = _minute  / 60;
	lcd_display.setCursor(0, 3);
	lcd_display.print(String(_hour) + ":" + String(_minute % 60) + ":" + String(_second % 60));
}

void display_page_2()
{
	// Коробка передач => Название
	lcd_display.setCursor(0, 0);
	lcd_display.print("gearbox");

	// Коробка передач => Значение мотора
	lcd_display.setCursor(8, 0);
	lcd_display.print(actuator_motor_list.gearbox.get_current());

	// Коробка передач => Значение поршня
	lcd_display.setCursor(10, 0);
	lcd_display.print(actuator_piston_list.gearbox.get_current());

	// Коробка передач => Концевик
	lcd_display.setCursor(17, 0);
	lcd_display.print(feedback_values.gearbox);

	lcd_display.setCursor(19, 0);
	lcd_display.print(gearbox_status);

	// ====== ===== ===== ===== =====

	// Сцепление => Название
	lcd_display.setCursor(0, 1);
	lcd_display.print("clutch");

	// Сцепление => Значение мотора
	lcd_display.setCursor(8, 1);
	lcd_display.print(actuator_motor_list.clutch.get_current());

	// Сцепление => Значение поршная
	lcd_display.setCursor(10, 1);
	lcd_display.print(actuator_piston_list.clutch.get_current());

	// ====== ===== ===== ===== =====

	// Руль => Название
	lcd_display.setCursor(0, 2);
	lcd_display.print("rudder");

	// Руль => Значение мотора
	lcd_display.setCursor(8, 2);
	lcd_display.print(actuator_motor_list.rudder.get_current());

	// Руль => Значение поршня
	lcd_display.setCursor(10, 2);
	lcd_display.print(actuator_piston_list.rudder.get_current());

	// Руль => Обратная связь
	lcd_display.setCursor(17, 2);
	lcd_display.print(feedback_values.rudder);

	// ====== ===== ===== ===== =====

	// Тормоз => Название
	lcd_display.setCursor(0, 3);
	lcd_display.print("brake");

	// Тормоз => Значение мотора
	lcd_display.setCursor(8, 3);
	lcd_display.print(actuator_motor_list.brake.get_current());

	// Тормоз => Положения поршня
	lcd_display.setCursor(10, 3);
	lcd_display.print(actuator_piston_list.brake.get_current());
}

/* private functions */

void display_move_page()
{
	if (remote_values.left_stick_width < 1200)
	{
		lcd_current_page--;
	}

	if (remote_values.left_stick_width > 1800)
	{
		lcd_current_page++;
	}

	lcd_current_page = constrain(lcd_current_page, lcd_minimum_page, lcd_maximum_page);
}

/* arduino functions */

void configuration_display_handler()
{
	lcd_display.begin(20, 4);
}

void listener_display_handler()
{
	// Обновляю изображение каждые 500 миллисекунд
	if (lcd_timer.get_elapsed_time(false) < 50000)
	{
		return;
	}

	// Если прошло 500 милисекунд,
	// Тогда обнуляю таймер в 0
	// И проверяю нужно ли перелистуть страницу на следующию
	lcd_timer.set_microseconds();
	display_move_page();

	// clearing screen
	lcd_display.clear();

	switch (lcd_current_page)
	{
		case 1: display_page_1(); break;
		case 2: display_page_2(); break;
	}

	// current page
	lcd_display.setCursor(17, 3);
	lcd_display.print(String(lcd_current_page) + "/" + String(lcd_maximum_page));
}
