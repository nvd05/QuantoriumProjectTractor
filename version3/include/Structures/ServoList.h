#pragma once

#include <Servo.h>

/**
 * @brief Серво => Список
 */
struct ServoList
{
	Servo mute; // Глушение
	Servo gas;  // Газ
};
