/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2016 Sensnology AB
 * Full contributor list: https://github.com/mysensors/MySensors/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */

#ifndef MyHwRPi_h
#define MyHwRPi_h

#include <stdint.h>
#include <stdlib.h>
#include "MyHwLinuxGeneric.h"
#include "log.h"
#include "bcm2835.h"

class Bcm2835Init
{
public:
	Bcm2835Init()
	{
		if (!bcm2835_init()) {
			logError("Failed to initialized bcm2835.\n");
			exit(1);
		}
	}
	~Bcm2835Init()
	{
		bcm2835_close();
	}
};
Bcm2835Init bcm2835Init;

#undef hwDigitalWrite
inline void hwDigitalWrite(uint8_t, uint8_t);

#undef hwDigitalRead
inline int hwDigitalRead(uint8_t);

#undef hwPinMode
inline void hwPinMode(uint8_t, uint8_t);

#endif
