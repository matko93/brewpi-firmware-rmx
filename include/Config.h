/* Copyright (C) 2019 Lee C. Bussy (@LBussy)

This file is part of LBussy's BrewPi Firmware Remix (BrewPi-Firmware-RMX).

BrewPi Firmware RMX is free software: you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

BrewPi Firmware RMX is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with BrewPi Firmware RMX. If not, see <https://www.gnu.org/licenses/>.

These scripts were originally a part of firmware, a part of
the BrewPi project. Legacy support (for the very popular Arduino
controller) seems to have been discontinued in favor of new hardware.

All credit for the original firmware goes to @elcojacobs,
@m-mcgowan, @elnicoCZ, @ntfreak, @Gargy007 and I'm sure many more
contributors around the world. My apologies if I have missed anyone;
those were the names listed as contributors on the Legacy branch.

See: 'original-license.md' for notes about the original project's
license and credits. */

#pragma once

//////////////////////////////////////////////////////////////////////////
//
// Define build version (git tag)
//
#ifndef VERSION_STRING
#define VERSION_STRING PIO_SRC_TAG
#endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Define build commit (short git commit)
//
#ifndef BUILD_NAME
#define BUILD_NAME PIO_SRC_REV
#endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Set verbosity of debug messages 0-3
// 0: means no debug messages
// 1: is typical debug messages required for end users
// 2-3: more verbose debug messages
//
//#ifndef BREWPI_DEBUG
//#define BREWPI_DEBUG 1
//#endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Define which brewpi shield is used.
// BREWPI_SHIELD_REV_A The RevA shield (ca. Feb 2013), two OneWire buses, door, heat, cool.
// BREWPI_SHIELD_REV_C The RevC shield (ca. May 2013). One common OneWire bus, 4 actuators. Dynaconfig.
// BREWPI_SHIELD_TWI   Unofficial TWI shield. Similar to Rev C but moves pins around to support I2C bus on A4/A5
//
#ifndef BREWPI_STATIC_CONFIG
// #define BREWPI_STATIC_CONFIG BREWPI_SHIELD_REV_A
// #define BREWPI_STATIC_CONFIG BREWPI_SHIELD_REV_C
#define BREWPI_STATIC_CONFIG BREWPI_SHIELD_TWI
#endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Enable the simulator. Real sensors/actuators are replaced with simulated versions. In particular, the values reported by
// temp sensors are based on a model of the fridge/beer.
//
// #ifndef BREWPI_SIMULATE
// #define BREWPI_SIMULATE 0
// #endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Enable DS2413 Actuators.
//
// #ifndef BREWPI_DS2413
// #define BREWPI_DS2413 0
// #endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// This flag virtualizes as much of the hardware as possible, so the code can be run in the AvrStudio simulator, which
// only emulates the microcontroller, not any attached peripherals.
//
// #ifndef BREWPI_EMULATE
// #define BREWPI_EMULATE 0
// #endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Flag to control use of cascaded filter
//
// #ifndef TEMP_SENSOR_CASCADED_FILTER
// #define TEMP_SENSOR_CASCADED_FILTER 1
// #endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Flag to control implementation of TempControl as a static class.
// Should normally be left alone unles you are experimenting with multi-instancing.
//
// #ifndef TEMP_CONTROL_STATIC
// #define TEMP_CONTROL_STATIC 1
// #endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Flag to control use of Fast digital pin functions
//
// #ifndef FAST_DIGITAL_PIN
// #define FAST_DIGITAL_PIN 0
// #endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Enable the LCD menu.
//
#ifndef BREWPI_MENU
#define BREWPI_MENU 1
#endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// Enable the LCD display. Without this, a NullDisplay is used
//
#ifndef BREWPI_LCD
#define BREWPI_LCD 1

// If we're using an IIC shield, we need to enable IIC support
#if BREWPI_STATIC_CONFIG == BREWPI_SHIELD_TWI
#define BREWPI_IIC 1
#endif

#endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
#ifndef BREWPI_BUZZER
#define BREWPI_BUZZER 1
#endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
#ifndef BREWPI_ROTARY_ENCODER
#define BREWPI_ROTARY_ENCODER 1
#endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// #ifndef BREWPI_EEPROM_HELPER_COMMANDS
// #define BREWPI_EEPROM_HELPER_COMMANDS BREWPI_DEBUG || BREWPI_SIMULATE
// #endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// BREWPI_SENSOR_PINS - can be disabled if only using onewire devices
//
// #ifndef BREWPI_SENSOR_PINS
// #define BREWPI_SENSOR_PINS 1
// #endif
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// BREWPI_ACTUATOR_PINS - can be disabled if only using onewire devices
#ifndef BREWPI_ACTUATOR_PINS
#define BREWPI_ACTUATOR_PINS 1
#endif
//
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
//
// FORCE_DEVICE_DEFAULTS - Overwrite the chamber/beer number to prevent user
//                         error.
//
#ifndef FORCE_DEVICE_DEFAULTS
#define FORCE_DEVICE_DEFAULTS 1
#endif
//
//////////////////////////////////////////////////////////////////////////
