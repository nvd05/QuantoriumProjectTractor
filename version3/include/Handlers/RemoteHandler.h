#pragma once

#include "Configuration/PinList.h"
#include "Memory/VariableList.h"
#include <Arduino.h>

void configuration_remote_handler()
{
	pinMode(PIN_REMOTE_CHANNEL_1, INPUT); // Пульт => Канал 1
	pinMode(PIN_REMOTE_CHANNEL_2, INPUT); // Пульт => Канал 2
	pinMode(PIN_REMOTE_CHANNEL_3, INPUT); // Пульт => Канал 3
	pinMode(PIN_REMOTE_CHANNEL_4, INPUT); // Пульт => Канал 4
	pinMode(PIN_REMOTE_CHANNEL_5, INPUT); // Пульт => Канал 5
	pinMode(PIN_REMOTE_CHANNEL_6, INPUT); // Пульт => Канал 6

	// Serial.begin(9600);
	// Serial.println("running...");
}

void listener_remote_handler()
{
	remote_values.right_stick_width            = pulseIn(PIN_REMOTE_CHANNEL_1, HIGH); // Правый стик => Ширина
	remote_values.right_stick_height           = pulseIn(PIN_REMOTE_CHANNEL_2, HIGH); // Правый стик => Высота
	remote_values.left_stick_height            = pulseIn(PIN_REMOTE_CHANNEL_3, HIGH); // Левый стик  => Высота
	remote_values.left_stick_width             = pulseIn(PIN_REMOTE_CHANNEL_4, HIGH); // Левый стик  => Ширина
	remote_values.three_position_toggle_switch = pulseIn(PIN_REMOTE_CHANNEL_5, HIGH); // Тумблер     => Трехпозиционный
	remote_values.two_position_toggle_switch   = pulseIn(PIN_REMOTE_CHANNEL_6, HIGH); // Тумблер     => Трехпозиционный

	// Serial.println("ch1: " + String(remote_values.right_stick_width));
	// Serial.println("ch2: " + String(remote_values.right_stick_height));
	// Serial.println("ch3: " + String(remote_values.left_stick_height));
	// Serial.println("ch4: " + String(remote_values.left_stick_width));
	// Serial.println("ch5: " + String(remote_values.three_position_toggle_switch));
	// Serial.println("ch6: " + String(remote_values.two_position_toggle_switch));
	// Serial.println();
}
