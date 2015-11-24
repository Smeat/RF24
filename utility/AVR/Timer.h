/*
 * Timer.h
 *
 *  Created on: 31.10.2014
 *      Author: kevin
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>

class Timer {
public:
	static uint32_t millis();

	static uint32_t micros();

	static void delay(unsigned long ms);

	static void delayMicroseconds(unsigned int us);

	static void init_timer();
};


#endif /* TIMER_H_ */
