/*
 * Project.c
 *
 * Created: 8/30/2022 09:28:50 PM
 * Author : Sergiu Maier
 */ 

#include "main_defines.h"
#include "timer0_func.h"
#include "main_func.h"
#include "main_mcu_init.h"
#include "senzor_hc_sr04.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t valoare;

int main(void){
	
	init_devices();	//porturi, timer, intreruperi
					      
	do
	{
		start_timer0();
		//pinSet(&PORTB, PINB0);
		    
		trigger();
	    valoare = calcul_distanta();
		
		if(valoare <= TIMP_LED_ON) 
		    pinSet(&PORTB, PINB0);
		else
			pinReset(&PORTB, PINB0);	
		
	}while(1);
}




