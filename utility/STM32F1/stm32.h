
#ifndef __stm32_H__
#define __stm32_H__


#include <stdint.h>

#include "stm32f1xx_hal_conf.h"

void setPin(uint8_t pin, bool direction);

void setMode(uint32_t pin, uint32_t mode);

#endif
