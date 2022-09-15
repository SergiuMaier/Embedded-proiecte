/*
 * main_func.c
 *
 * Created: 9/01/2022 10:14:32 AM
 *  Author: Sergiu Maier
 */ 

#include "main_mcu_init.h"
#include "main_func.h"
#include "main_defines.h"
#include "timer0_func.h"

int flag_on = 0;		//initial, led-urile sunt stinse
int contor_on = 0;		//contor pentru masurarea duratei de timp in care LED-urile sunt aprinse
int secunde = 0;
int contor_secunde = 0;	//contor pentru generarea secundelor

void pinSet(volatile uint8_t *port, uint8_t pin){
	
	*port |=  1 << pin;
}

void pinReset(volatile uint8_t *port, uint8_t pin){
	
	*port &=  ~(1 << pin);
}

void led_on(){			
	
	start_timer0(); 
	
	OCR0A = contor_secunde;
}

ISR(TIMER0_COMPA_vect){  //pt caz general
	
	cli();
	
	contor_secunde++;
	
	if(contor_secunde >= (1/GENERARE_INTRERUPERE)){
		contor_secunde = 0;
	}
	
	sei();
}