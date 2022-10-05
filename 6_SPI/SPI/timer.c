/*
 * main_func.c
 *
 * Created: 9/26/2022 11:12:11 AM
 *  Author: Sergiu Maier
 */ 

#include "timer.h"

void init_timer(){
	
	TCCR0A |= (1 << WGM01)|(0 << WGM00);           //mod ctc
	OCR0A = 0xF9;                                  //duty cycle 10ms
	TCCR0B |= (0 << CS02)|(1 << CS01)|(1 << CS00); //prescalar 64
	TIMSK0 |= (1 << OCIE0A);
}

void init_devices(){
	
	cli();
	
	init_timer();
	
	sei();
}

void afisare_timp(){
	
	itoa(secunde, ch_sec, 10);
	itoa(minute, ch_min, 10);
		
	if(secunde >= 60)	//in ISR aveam 01:59 in loc de 01:00
	{
		secunde %= 60;
		minute++;
	}	
		
	if(flag_timer == 1)
	{	
		SendData(CLEAR);
		
		SendData("\n\r");
		SendData(" |-------------|\n\r");
		SendData(" |");
		SendData(" Timp: ");
		
		//Timp:  00:00
		
		if(minute < 10)
		{
			SendData("0");
			SendData(ch_min);
		}
		else
			SendData(ch_min);
		
		if((secunde >= 1) && (secunde <= 10)) //interval pt rezolvare bug 00:059
		{
			SendData(":0");
			SendData(ch_sec);
		}
		else
		{
			SendData(":");
			SendData(ch_sec);
		}
		
		SendData(" |\n\r");
		SendData(" |-------------|");
		
		flag_timer = 0;
	}
}

void introducere_mesaj(){
	
	//SendData(CLEAR);
	
	SendData("\n\r\n\r");
	SendData("<txt>");
	
}

ISR(TIMER0_COMPA_vect){
	
	cli();
	
	contor++;
	
	if(contor >= 1000){
		secunde++;
		contor = 0;
		flag_timer = 1;
	}
	
	sei();
}
