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

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void){
	
	init_devices();	//porturi, timer, intreruperi
					      
	do
	{		
		led_on();	

	}while(1);
}




