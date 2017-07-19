#include "SPI.h"

#include "stm32f1xx_hal_conf.h"


//SPIClass SPI;

uint8_t SPIClass::transfer(uint8_t txData){
	uint8_t rxData = 0;
	int retval = HAL_SPI_TransmitReceive(&hspi1, &txData, &rxData, 1, 0xFF);
	return rxData;
 }



void SPIClass::begin(){

	hspi1.Instance = SPI2;
	hspi1.Init.Mode = SPI_MODE_MASTER;
	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi1.Init.NSS = SPI_NSS_SOFT;
	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 10;

	HAL_SPI_Init(&hspi1); //TODO: DMA

}
void SPIClass::end(){

}
