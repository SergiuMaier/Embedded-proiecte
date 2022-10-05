/*
 * main_mcu_init.h
 *
 * Created: 8/31/2022 9:03:26 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_MCU_INIT_H_
	#define MAIN_MCU_INIT_H_
	
#include "main_defines.h"	

//functii pentru toggle diferiti pini
void pin_toggle_led0();

void pin_toggle_led1();

void pin_toggle_led2();

void pin_toggle_led3();

void update_timer_dorit(uint8_t index);

void reset_timer_dorit(uint8_t index);

void port_init(void);

void timer0_init(void);

void interrupt_init(void);

void init_devices(void);

ISR(TIMER0_COMPA_vect);

#endif /* MAIN_MCU_INIT_H_ */