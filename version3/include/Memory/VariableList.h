#pragma once

#include "Configuration/PinList.h"
#include <LiquidCrystal.h>
#include "Timer.h"

#include "Structures/ActuatorPistonList.h"
#include "Structures/ActuatorMotorList.h"
#include "Structures/FeedbackValues.h"
#include "Structures/RemoteValues.h"
#include "Structures/ServoList.h"

// Дисплей
LiquidCrystal lcd_display(LCD_DISPLAY_RS, LCD_DISPLAY_ENABLE, LCD_DISPLAY_INPUT_D4, LCD_DISPLAY_INPUT_D5, LCD_DISPLAY_INPUT_D6, LCD_DISPLAY_INPUT_D7); // ЖК Дисплей
long          lcd_maximum_page = 2;
long          lcd_minimum_page = 1;
long          lcd_current_page = 2;
Timer         lcd_timer;

// Коробка передач
long gearbox_status = 0;
long gearbox_back   = 0;

ActuatorPistonList actuator_piston_list;
ActuatorMotorList  actuator_motor_list;
FeedbackValues     feedback_values; // Обратная связь => Значения
RemoteValues       remote_values;   // Пульт          => Значения
ServoList          servo_list;      // Серво          => Список
