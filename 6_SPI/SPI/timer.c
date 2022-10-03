/*
 * main_func.c
 *
 * Created: 9/26/2022 11:12:11 AM
 *  Author: Sergiu Maier
 */ 

#include "timer.h"

void timer_init(){
	
	TCCR0A |= (1 << WGM01)|(0 << WGM00);           //mod ctc
	OCR0A = 0xF9;                                  //duty cycle 10ms
	TCCR0B |= (0 << CS02)|(1 << CS01)|(1 << CS00); //prescalar 64
	TIMSK0 |= (1 << OCIE0A);
}

void init_devices(){
	
	cli();
	
	timer_init();
	
	sei();
}

void afisare_timp(){
	
	itoa(secunde, ch_sec, 10);
	itoa(minute, ch_min, 10);
		
	if(flag_timer == 1)
	{	
		SendData(CLEAR);
		SendData("Timp: ");
		
		if(minute < 10)
		{
			SendData(" 0");
			SendData(ch_min);
		}
		else
		{
			SendData(" ");
			SendData(ch_min);
		}
		
		if(secunde <= 10){
			SendData(":0");
			SendData(ch_sec);
		}
		else
		{
			SendData(":");
			SendData(ch_sec);
		}
		
		//if((secunde <= 10) && (minute <= 10))
		//{
			//SendData(" 0");
			//SendData(ch_min);
			//SendData(":0");
			//SendData(ch_sec);
		//}
		//else if((secunde <= 10) && (minute > 10))
		//{
			//SendData(ch_min);
			//SendData(":0");
			//SendData(ch_sec);
		//}
		//else if((secunde > 10) && (minute <= 10))
		//{
			//SendData(" 0");
			//SendData(ch_min);
			//SendData(":");
			//SendData(ch_sec);
		//}
		//else if((secunde > 10) && (minute > 10))
		//{
			//SendData(ch_min);
			//SendData(":");
			//SendData(ch_sec);
		//}
		
		flag_timer = 0;
	}
}

ISR(TIMER0_COMPA_vect){
	
	cli();
	
	contor++;
	
	if(contor >= 1000){
		++secunde;
		flag_timer = 1;
		contor = 0;
		
		if(secunde >= 60)
		{
			secunde %= 60;
			++minute;
		}
	}
	
	sei();
}
