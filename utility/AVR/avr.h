#ifndef AVR_H
#define	AVR_H

#include <avr/io.h>

#include <stdio.h>

class AVR_io {
public:

/* Constants */
static const int DIRECTION_OUT = 1;
static const int DIRECTION_IN = 0;

static const int OUTPUT_HIGH = 1;
static const int OUTPUT_LOW = 0;

/**
 * Similar to Arduino pinMode(pin,mode);
 * @param pin
 * @param DDR
 */
static void ddr_mode(uint8_t pin, uint8_t dir, volatile uint8_t* DDR);

/**
 * Similar to Arduino digitalRead(pin);
 * @param pin
 * @param port
 */
static int read(uint8_t pin, volatile uint8_t* port);
/**
* Similar to Arduino digitalWrite(pin,state);
* @param pin
* @param value
* @param port
*/
static void write(uint8_t pin,int value, volatile uint8_t* port);

};
#endif

/*@}*/	
