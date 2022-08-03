# Настройки
* `include\Configuration\PWMValues.h` - список шим значений
* `include\Configuration\PinList.h` - список пинов подключения

# Список обработчиков кода
* `include\Handlers\ActuatorsHandler.h` - отвечает за обновление положений актуаторов + выставляет значение тормоза и руля по значениям приемника пульта
* `include\Handlers\DisplayHandler.h` - отвечает за жк дисплей (подключение пинов в `PinList.h`)(+ библиотека `LiquidCrystal.h`)
> `Примичание`: нужно переписать под использование callback функций с использованием массивов (возможно Vector).
* `include\Handlers\FeedbackHandler.h` - обратная связь (пока что бесполезный файл)
* `include\Handlers\GearboxHandler.h` - отвечает за переключение коробки передач
* `include\Handlers\RelayHandler.h` - отвечает за реле (у нас она одна)
* `include\Handlers\RemoteHandler.h` - слушает приемник пульта и записывает значения в `struct RemoteValues remote_values`
* `include\Handlers\ServoHandler.h` - обработчик серво прикодов (+ библиотека `Servo.h`)

# Список переменных
* `include\Memory\VariableList.h` - список всех обьявленный переменных проекта

# Список страктур
* В папке `include\Structures\*.h` находятся все `struct` файлы

# Список библиотек
* `LiquidCrystal.h` - жк дисплей.
* `Servo.h` - серво приводы.
* `lib\LinearActuator\src\*\*.h` находиться самописная библиотека линейных приводов.
> `Примичание`: данная библиотека требует правки, так как я накосячил с памятью и ее разделением.
> По этому на дисплее всегда значение мотора актуторов в положение 0, даже когда моторы двигаются
> Чтобы это исправить надо переписать код под использование `Указателей`(знак `*`)
* `lib\Timer\src\*.h` - самописная библиотека таймера, отвечает за подсчет времени в микросекундах.

# Сборка проекта
```text
Processing megaatmega2560 (platform: atmelavr; board: megaatmega2560; framework: arduino)
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------Verbose mode can be enabled via `-v, --verbose` option
CONFIGURATION: https://docs.platformio.org/page/boards/atmelavr/megaatmega2560.html
PLATFORM: Atmel AVR (4.0.0) > Arduino Mega or Mega 2560 ATmega2560 (Mega 2560)
HARDWARE: ATMEGA2560 16MHz, 8KB RAM, 248KB Flash
DEBUG: Current (avr-stub) On-board (avr-stub, simavr)
PACKAGES:
 - framework-arduino-avr @ 5.1.0
 - toolchain-atmelavr @ 1.70300.191015 (7.3.0)
LDF: Library Dependency Finder -> https://bit.ly/configure-pio-ldf
LDF Modes: Finder ~ chain, Compatibility ~ soft
Found 9 compatible libraries
Scanning dependencies...
Dependency Graph
|-- LiquidCrystal @ 1.0.7
|-- Servo @ 1.1.8        
|   |-- Timer
|-- Timer
|-- LinearActuator
|   |-- Timer
Building in release mode
Compiling .pio\build\megaatmega2560\src\main.cpp.o
Linking .pio\build\megaatmega2560\firmware.elf
Checking size .pio\build\megaatmega2560\firmware.elf
Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
RAM:   [=         ]   8.1% (used 664 bytes from 8192 bytes)
Flash: [          ]   4.5% (used 11364 bytes from 253952 bytes)
Building .pio\build\megaatmega2560\firmware.hex
================================================================================================ [SUCCESS] Took 3.03 seconds ================================================================================================
```
