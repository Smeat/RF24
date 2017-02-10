
/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.

 */
 
 /**
 * @file RF24_arch_config.h
 * General defines and includes for RF24/Linux
 */

 /**
 * Example of RF24_arch_config.h for RF24 portability
 *
 * @defgroup Porting_General Porting: General
 *
 * 
 * @{
 */
 
 
#ifndef __ARCH_CONFIG_H__
#define __ARCH_CONFIG_H__

#include <stddef.h>
#include "compatibility.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "avr.h"
#include "pins.h"
#include "SPI.h"

#define _SPI SPI

#undef SERIAL_DEBUG
#ifdef SERIAL_DEBUG
#define IF_SERIAL_DEBUG(x) ({x;})
#else
#define IF_SERIAL_DEBUG(x)
#endif

// Avoid spurious warnings
#if 1
#if ! defined( NATIVE ) && defined( ARDUINO )
#undef PROGMEM
#define PROGMEM __attribute__(( section(".progmem.data") ))
#undef PSTR
#define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];}))
#endif
#endif

//typedef uint16_t prog_uint16_t;
#define PSTR(x) (x)
#define printf_P printf
#define strlen_P strlen
#define PROGMEM
#define pgm_read_word(p) (*(p))
#define PRIPSTR "%s"
#define pgm_read_byte(p) (*(p))

// Function, constant map as a result of migrating from Arduino
#define LOW AVR_io::OUTPUT_LOW
#define HIGH AVR_io::OUTPUT_HIGH
#define INPUT AVR_io::DIRECTION_IN
#define OUTPUT AVR_io::DIRECTION_OUT

#define digitalWrite(pin, value) AVR_io::write(pin, value, PORT)
#define pinMode(pin, direction) AVR_io::ddr_mode(pin, direction, DDR_REGISTER)
#define delay(milisec) __msleep(milisec)
#define delayMicroseconds(usec) __usleep(usec)
#define millis() __millis()

#ifdef INT_ENABLE
#define attachInterrupt(pin, function, state) AVR_io::attachInterrupt(pin, function, state)
#define detachInterrupt(pin) AVR_io::detachInterrupt(pin)
#endif

#define byte uint8_t

#endif // __ARCH_CONFIG_H__


/*@}*/	
