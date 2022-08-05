#include "Handlers/FeedbackHandler.h"
#include "Handlers/RemoteHandler.h"
#include "Handlers/DisplayHandler.h"

#include "Handlers/GearboxHandler.h"
#include "Handlers/ServoHandler.h"
#include "Handlers/RelayHandler.h"
#include "Handlers/ActuatorsHandler.h"

// Дисплей закоментировал, мы его все равно даже не подключаем, а время на его обработку требуется.

void setup()
{
	configuration_feedback_handler();  // Обратная связь
	configuration_remote_handler();    // Пульт
	// configuration_display_handler();   // ЖК Дисплей

	configuration_relay_handler();     // Реле
	configuration_servo_handler();     // Серво
	configuration_actuators_handler(); // Актуаторы
}

void loop()
{
	listener_feedback_handler();  // Обратная связь
	listener_remote_handler();    // Пульт
	// listener_display_handler();   // ЖК Дисплей

	listener_gearbox_handler();   // Коробка Передач (КПП)
	listener_relay_handler();     // Реле
	listener_servo_handler();     // Серво
	listener_actuators_handler(); // Актуаторы
}
