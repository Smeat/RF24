#include "compatibility.h"


void __msleep(int milisec){
	Timer::delay(milisec);
}
void __usleep(int microsec){
	Timer::delayMicroseconds(microsec);
}
void __start_timer(){
	Timer::init_timer();
}
unsigned long __millis(){
	return Timer::millis();
}
