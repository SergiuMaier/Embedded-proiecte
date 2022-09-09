/*
 * Project.c
 *
 * Created: 8/30/2022 09:28:50 PM
 * Author : Sergiu Maier
 */ 

#include "main_mcu_init.h"
#include "main_defines.h"
#include "timer0_def.h"
#include "stimer.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void){
	
	init_devices();	//porturi, timer, intreruperi
	start_timer0(); 
               
			   //(ID, STARE, AUTORESET, VAL INI, PERIOADA, FUNCTIE)
	creeaza_timer(0, PORNIT, TRUE, 0, 2000, pin_toggle_led0);
	creeaza_timer(1, PORNIT, TRUE, 0, 10000, update_timer);   //update timer 2
	creeaza_timer(2, PORNIT, TRUE, 0, 5000, pin_toggle_led2);     //reset timer 4
	creeaza_timer(3, PORNIT, TRUE, 0, 3000, pin_toggle_led3);

	do
	{	
		if(flag == 1)
		{
			flag = 0;
			evalueaza_timer();	
		}
				
	}while(1);
}




