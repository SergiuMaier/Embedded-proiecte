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
	
	timere[0] = creeaza_timer(1, PORNIT, TRUE, 0, 2000, pin_toggle_led0);
	timere[1] = creeaza_timer(2, PORNIT, FALSE, 0, 3000, pin_toggle_led1);
	timere[2] = creeaza_timer(3, PORNIT, TRUE, 0, 5000, pin_toggle_led2);
	timere[3] = creeaza_timer(4, PORNIT, TRUE, 0, 10000, pin_toggle_led3);

	do
	{	
		if(flag == 1)
		{
			flag = 0;
			evalueaza_timer();	
		}
			reset_timer(3, 22000);

	}while(1);
}




