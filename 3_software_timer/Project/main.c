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
	//struct timer t1 = creeaza_timer(id, PORNIT, TRUE, 0, 1000,  *f1);

	numar_timere_create();	//determinare numar timere
	      
	do
	{
		if(counter_timere_create == 5) //broken, trebuie o legatura intre struct/ variabilele globale si main
			startup();
		
		
	}while(1);
}




