#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include <stdint.h>
#include "stm32f1xx_hal_conf.h"

class SPIClass {
public:

	SPIClass(){

	}

	uint8_t transfer(uint8_t _data);

	void begin(); // Default
	void end();
private:
	SPI_HandleTypeDef hspi1;
};

//extern SPIClass SPI; //TODO: understand why this is needed

#endif
