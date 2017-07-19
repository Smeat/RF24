/* 
 * File:   compatiblity.h
 * Author: purinda
 *
 * Created on 24 June 2012, 3:08 PM
 */

 /**
 * @file compatibility.h
 * Class declaration for SPI helper files
 */

 /**
 * Example of compatibility.h class declaration for timing functions portability
 *
 * @defgroup Porting_Timing Porting: Timing
 *
 * 
 * @{
 */
 
#ifndef COMPATIBLITY_H
#define	COMPATIBLITY_H

#include <stdint.h>
#include "stm32f1xx_hal_conf.h"

#define START_TIMER
	
void __msleep(uint32_t milisec);
void __usleep(uint32_t microsec);
void __start_timer();
unsigned long __millis();

#endif	/* COMPATIBLITY_H */

/*@}*/	
