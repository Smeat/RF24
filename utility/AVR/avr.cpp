#include "avr.h"

void AVR_io::ddr_mode(uint8_t pin, uint8_t direction, volatile uint8_t* DDR){
	if(direction == DIRECTION_OUT){
		*DDR |= (1 << pin);
	}
	else {
		*DDR &= ~(1 << pin);
	}
}

int AVR_io::read(uint8_t pin, volatile uint8_t* port){
	return *port & (1 << pin);
}

void AVR_io::write(uint8_t pin,int value, volatile uint8_t* port){
	if(value == OUTPUT_HIGH){
		*port |= (1 << pin);
	}
	else {
		*port &= ~(1 << pin);
	}
}



