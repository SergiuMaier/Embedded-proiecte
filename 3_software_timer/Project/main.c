/*
 * Project.c
 *
 * Created: 8/30/2022 09:28:50 PM
 * Author : Sergiu Maier
 */ 

#include "main_defines.h"
#include "timer0_func_def.h"
#include "main_func.h"
#include "main_mcu_init.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void){
	
	init_devices();	//porturi, timer, intreruperi
	start_timer0(); //aici sau in creeaza_timer
	//exemplu struct timer t1 = creeaza_timer(PORNIT, TRUE, 0, 1000,  *f1);
			      
	do
	{
		if(flag == 1)
		{
			flag = 0;
			evalueaza_timer();
		}
		
		
	}while(1);
}




