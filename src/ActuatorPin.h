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

#include "Actuator.h"

class DigitalPinActuator ACTUATOR_BASE_CLASS_DECL
{
  private:
	bool invert;
	uint8_t pin;

  public:
	DigitalPinActuator(uint8_t pin, bool invert)
	{
		this->invert = invert;
		this->pin = pin;
		setActive(false);
		pinMode(pin, OUTPUT);
	}

	inline ACTUATOR_METHOD void setActive(bool active)
	{
		digitalWrite(pin, active ^ invert ? HIGH : LOW);
	}

	bool isActive() { return ((digitalRead(pin) != LOW) ^ invert); }
};