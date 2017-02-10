#include "avr.h"

#ifdef __AVR_ATmega328P__

#ifdef INT_ENABLE

ISR(INT0_vect){
	if(AVR_io::int0 != 0){
		AVR_io::int0();
	}
}

ISR(INT1_vect){
	if(AVR_io::int1 != 0){
		AVR_io::int1();
	}
}
#endif

#endif


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
#ifdef INT_ENABLE
void AVR_io::attachInterrupt(uint8_t pin, void (*func)(), const int type){
#ifdef __AVR_ATmega328P__
	if(pin == PD2){
		DDRD &= ~(1 << DDD2);
		PORTD |= (1 << PORTD2);

		EICRA |= (1 << ISC00) || (1 << ISC01);    // set INT0 to trigger on ANY logic change //TODO: make right logic
		EIMSK |= (1 << INT0);     // Turns on INT0

		AVR_io::int0 = func;
	}
	else if (pin == PD3){
		DDRD &= ~(1 << DDD3);
		PORTD |= (1 << PORTD3);

		EICRA |= (1 << ISC10) || (1 << ISC11);    //TODO: make right logic
		EIMSK |= (1 << INT1);     // Turns on INT0

		AVR_io::int1 = func;
}
#endif

}

void AVR_io::detachInterrupt(uint8_t pin){
	if(pin == PD2){
		EIMSK &= ~(1 << INT0);
		AVR_io::int0 = 0;
	}
	else if (pin == PD3){
		EIMSK &= ~(1 << INT1);
		AVR_io::int1 = 0;
	}
}
#endif


