
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

#define printf_P printf
#define strlen_P strlen

#define PSTR_RF24(x) (x)

#define PROGMEM_RF24
#define pgm_read_word_rf24(p) (*(p))
#define pgm_read_byte_rf24(addr) (*(const unsigned char *)(addr))

#define PRIPSTR_RF24 "%s"

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
