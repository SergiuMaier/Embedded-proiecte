/*
 * main_mcu_init.h
 *
 * Created: 8/31/2022 9:03:26 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_MCU_INIT_H_
	#define MAIN_MCU_INIT_H_
	
#include "main_defines.h"	

void port_init(void);

void timer0_init(void);

void interrupt_init(void);

void init_devices(void);


#endif /* MAIN_MCU_INIT_H_ */