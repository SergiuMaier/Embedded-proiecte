/*
 * main_func.c
 *
 * Created: 8/31/2022 9:14:32 AM
 *  Author: Sergiu Maier
 */ 

#include "main_func.h"
#include "main_defines.h"

int flag_on = 0;		//initial, led-urile sunt stinse
int contor_secunde = 0;	//contor pentru generarea secundelor
int contor_on = 0;		//contor pentru masurarea duratei de timp in care LED-urile sunt aprinse
int secunde = 0;

void pinSet(volatile uint8_t *port, uint8_t pin){
	
	*port |=  1 << pin;
}

void pinReset(volatile uint8_t *port, uint8_t pin){
	
	*port &=  ~(1 << pin);
}

void ledOn(){
	
	if(secunde % 2 == 0)		//test timer
		pinSet(&PORTB, PINB0);
	
	if(flag_on == 1)
	{
		pinSet(&PORTB, PINB0);
		pinSet(&PORTB, PINB1);
		pinSet(&PORTB, PINB2);
		pinSet(&PORTB, PINB3);
	}
	else
	{
		pinReset(&PORTB, PINB0);
		pinReset(&PORTB, PINB1);
		pinReset(&PORTB, PINB2);
		pinReset(&PORTB, PINB3);
	}
	
	if((secunde - contor_on) >= TIMP_ON)
		flag_on = 0;
}

void calculValoareRegistru(){
	
	int frecventa_dorita = 1/GENERARE_INTRERUPERE;
	//int prescalar = 0;
	int frecventa_realizata = 0;
	int valoare_preferentiala = 0;	
	int valoare_prescalar[5] = { 1, 8, 64, 256, 1024};
	//volatile uint8_t alegere_prescalar[5] = {TIMER_NO_PRESCALAR, TIMER_PRESCALAR_8, TIMER_PRESCALAR_64, TIMER_PRESCALAR_256, TIMER_PRESCALAR_1024};
	const int dimensiune = sizeof(valoare_prescalar)/sizeof(int);

	for(int i = 1; i <= dimensiune; i++) //pt fiecare element din valoare_prescalar[]
	{
		frecventa_realizata = 16000000/(VALOARE_TOP_REGISTRU*valoare_prescalar[i]);
		
		if(frecventa_realizata > frecventa_dorita)
		{
			//prescalar = valoare_prescalar[i-1];
			break;
		}	

		valoare_preferentiala = 16000000/(valoare_prescalar[i]*frecventa_dorita); //n
	}
	
	//switch(prescalar){	//alegere prescalar in registrul TCCR0B
		//case 1:
			//TCCR0B |= TIMER_NO_PRESCALAR;
			//break;
		//case 8:
			//TCCR0B |= TIMER_PRESCALAR_8;
			//break;
		//case 64:
			//TCCR0B |= TIMER_PRESCALAR_64;
			//break;
		//case 256:
			//TCCR0B |= TIMER_PRESCALAR_256;
			//break;
		//case 1024:
			//TCCR0B |= TIMER_PRESCALAR_1024;
			//break;
	//}

	OCR0A = valoare_preferentiala - 1;
}

ISR(TIMER0_COMPA_vect){  //pt caz general
	
	cli();
	
	contor_secunde++;
	
	if(contor_secunde >= (1/GENERARE_INTRERUPERE))
	{	
		secunde++;
		contor_secunde = 0;
	}
	
	sei();
}

ISR(INT0_vect){ //pt butonul de on
	
	cli();
	
	flag_on = 1;		 //LED-uri on
	contor_on = secunde; //determinarea timpului la care a fost apasat butonul
	
	sei();
}

ISR(INT1_vect){ //pt butonul de off
	
	cli();
	
	flag_on = 0; //LED-uri off
	
	sei();
}