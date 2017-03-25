
/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.

 */
 
 /**
 * @file RF24_arch_config.h
 * General defines and includes for STM32F1
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
#include "SPI.h"
#include "stm32f1xx_hal_conf.h"
#include "stm32.h"

#define _BV(x) (1<<(x))

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
#define LOW 0
#define HIGH 1
#define INPUT GPIO_MODE_INPUT
#define OUTPUT GPIO_MODE_OUTPUT_OD

#define digitalWrite(pin, value) setPin(pin, value)
#define pinMode(pin, direction) setMode(pin, direction)
#define delay(milisec) __msleep(milisec)
#define delayMicroseconds(usec) __usleep(usec)
#define millis() __millis() //TODO: use systick

#endif // __ARCH_CONFIG_H__


/*@}*/	
