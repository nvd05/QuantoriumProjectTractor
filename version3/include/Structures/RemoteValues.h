#pragma once

/**
 * @brief Пульт => Значения
 */
struct RemoteValues
{
	// Тумблеры
	long three_position_toggle_switch; // Тумблер => Трехпозиционный
	long two_position_toggle_switch;   // Тумблер => Двухпозиционный

	// Правый стик
	long right_stick_height; // Правый стик => Высота
	long right_stick_width;  // Правый стик => Ширина

	// Левый стик
	long left_stick_height; // Левый стик => Высота
	long left_stick_width;  // Левый стик => Ширина
};
