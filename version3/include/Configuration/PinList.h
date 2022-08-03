#pragma once

#include <Arduino.h>

// Пульт каналы
#define PIN_REMOTE_CHANNEL_1 13 // Пульт => Канал 1
#define PIN_REMOTE_CHANNEL_2 12 // Пульт => Канал 2
#define PIN_REMOTE_CHANNEL_3 11 // Пульт => Канал 3
#define PIN_REMOTE_CHANNEL_4 10 // Пульт => Канал 4
#define PIN_REMOTE_CHANNEL_5 9  // Пульт => Канал 5
#define PIN_REMOTE_CHANNEL_6 8  // Пульт => Канал 6

// ЖК Дисплей
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define LCD_DISPLAY_INPUT_D7 52 // ЖК Дисплей => Вход d7
#define LCD_DISPLAY_INPUT_D6 50 // ЖК Дисплей => Вход d6
#define LCD_DISPLAY_INPUT_D5 48 // ЖК Дисплей => Вход d5
#define LCD_DISPLAY_INPUT_D4 46 // ЖК Дисплей => Вход d4
#define LCD_DISPLAY_ENABLE   44 // ЖК Дисплей => Включено
#define LCD_DISPLAY_RS       42 // ЖК Дисплей => rs (не знаю для чего нужен)

// Обратная связь
#define PIN_FEEDBACK_POTENTIOMETER_RUDDER A7 // Обратная связь => Потенциометр => Руль
#define PIN_FEEDBACK_POTENTIOMETER_WHEEL  A6 // Обратная связь => Потенциометр => Колеса
#define PIN_FEEDBACK_BUTTON_GEARBOX       22 // Обратная связь => Кнопка => Коробка передач

// Коробка передач
#define PIN_DRIVER_GEARBOX_ENABLE  23 // Драйвер => Коробка передач => Включен
#define PIN_DRIVER_GEARBOX_INPUT_A 25 // Драйвер => Коробка передач => Вход А
#define PIN_DRIVER_GEARBOX_INPUT_B 27 // Драйвер => Коробка передач => Вход Б

// Сцепление
#define PIN_DRIVER_CLUTCH_ENABLE  29 // Драйвер => Сцепление => Включен
#define PIN_DRIVER_CLUTCH_INPUT_A 31 // Драйвер => Сцепление => Вход А
#define PIN_DRIVER_CLUTCH_INPUT_B 33 // Драйвер => Сцепление => Вход Б

// Руль
#define PIN_DRIVER_RUDDER_ENABLE  35 // Драйвер => Руль => Включен
#define PIN_DRIVER_RUDDER_INPUT_A 37 // Драйвер => Руль => Вход А
#define PIN_DRIVER_RUDDER_INPUT_B 39 // Драйвер => Руль => Вход Б

// Тормоз
#define PIN_DRIVER_BRAKE_ENABLE  41 // Драйвер => Тормоз => Включен
#define PIN_DRIVER_BRAKE_INPUT_A 43 // Драйвер => Тормоз => Вход А
#define PIN_DRIVER_BRAKE_INPUT_B 45 // Драйвер => Тормоз => Вход Б

// Сервоприводы
#define PIN_SERVO_MUTE 7 // Сервопривод => Глушение
#define PIN_SERVO_GAS  6 // Сервопривод => Газ

// Реле
#define PIN_RELAY_IGNITION 53 // Реле => Зажигание
