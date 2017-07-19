#include "compatibility.h"
//uint32_t clocks_per_ms;

void __usleep(uint32_t microsec){ //TODO: test
	uint32_t start = DWT->CYCCNT;
	microsec *= (SystemCoreClock / 1000000);
	while ((DWT->CYCCNT - start) < microsec)
	      ;
}

void __msleep(uint32_t milisec){
	__usleep(milisec * 1000);
}
void __start_timer(){
	//SysTick_Config(SystemCoreClock/1000); //1ms
	//clocks_per_ms = SystemCoreClock / 1000;

	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
	DWT->CTRL = 0x40000001;

}
extern uint32_t HAL_GetTick();
unsigned long __millis(){ //TODO: test
	//return DWT->CYCCNT/10;
	return HAL_GetTick();
}
