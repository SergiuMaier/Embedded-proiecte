/*
 * Project.c
 *
 * Created: 8/30/2022 09:28:50 PM
 * Author : Sergiu Maier
 */ 

#define F_CPU 16000000UL

#define TIMP_APRINDERE 5 //durata de timp in secunde cat LED-urile sunt aprinse

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/timer.h>

#include <util/delay.h>

void pinSet(volatile uint8_t *port, uint8_t pin);
void pinReset(volatile uint8_t *port, uint8_t pin);
void buton_apasat(volatile uint8_t pin_buton);

int flag_aprindere = 0; //initial, led-urile sunt stinse
int contor = 0;
int contorAprins = 0;
int secunde = 0;

int main(void)
{
	//output for LEDs
	DDRB = 0x0F;   //00001111
	PORTB = 0x00;
	DDRD |= (1 << PIND2) | (1 << PIND3);  //INT0 & INT1
	PORTD |= (1 << PIND2) | (1 << PIND3);
	
	cli();
	
	//MCUCR |= (1 << IVSEL)|(1 << IVCE);
	EICRA |= (1 << ISC11) | (1 << ISC10) | (1 << ISC01) | (1 << ISC00);
	EIMSK |= (1 << INT1) | (1 << INT0);
	EIFR |= (0 << INTF1) | (0 << INTF0);
	PCICR |= (0 << PCIE2) | (0 << PCIE1) | (0 << PCIE0);
	
	TCCR0A = (1 << WGM01)|(0 << WGM00); //setare mod de functionare CTC
	TCCR0B |= (1 << CS02)|(0 << CS01)|(0 << CS00); //prescalar
	OCR0A = 0xF9; //val de top
	TIMSK0 |= (1 << OCIE0A); 
	
	sei();
	//SREG |= (1 << SREG_I);
	
	while (1)
	{
		
		if(flag_aprindere == 1){
			
			contorAprins = secunde;
			
			pinSet(&PORTB, PINB0);
			pinSet(&PORTB, PINB1);
			pinSet(&PORTB, PINB2);
			pinSet(&PORTB, PINB3);
		}
		
		if((flag_aprindere == 0) || ((secunde - contorAprins) >= TIMP_APRINDERE)){
			
			//contorAprins = 0;
			
			pinReset(&PORTB, PINB0);
			pinReset(&PORTB, PINB1);
			pinReset(&PORTB, PINB2);
			pinReset(&PORTB, PINB3);
		}
	}
}

void pinSet(volatile uint8_t *port, uint8_t pin){
	
	*port |=  1 << pin;
}

void pinReset(volatile uint8_t *port, uint8_t pin){
	
	*port &=  ~(1 << pin);
}

ISR(TIMER0_COMPA_vect) {
	
	cli();
	
	contor++;
	
	if(contor >= 250){ 
		secunde++;
		contor = 0;
	}
	
	sei();
}

ISR(INT0_vect) {
	
	cli();
	//SREG &= ~(1 << SREG_I);
	
	flag_aprindere = 1; //aprindere LED-uri
	
	sei();
	//SREG |= (1 << SREG_I);
}

ISR(INT1_vect) {
	
	cli();
	//SREG &= ~(1 << SREG_I);
	
	flag_aprindere = 0;	//stingere LED-uri
	
	sei();
	//SREG |= (1 << SREG_I);
}
