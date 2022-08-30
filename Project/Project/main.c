/*
 * Project.c
 *
 * Created: 8/30/2022 09:28:50 PM
 * Author : Sergiu Maier
 */ 

#define F_CPU 16000000UL
#define TIMP_APRINDERE 5			//durata de timp in secunde cat LED-urile sunt aprinse
#define GENERARE_INTRERUPERE 0.004  //generarea unei intreruperi la fiecare x secunde
#define VALOARE_TOP_TIMER 256		//valoarea de top a registrului TCNT0 (pt ca folosesc timer pe 8 biti)

//prescalari
#define TIMER_NO_PRESCALAR      (0 << CS02) | (0 << CS01) | (1 << CS00)        // 001
#define TIMER_PRESCALAR_8       (0 << CS02) | (1 << CS01) | (0 << CS00)        // 010
#define TIMER_PRESCALAR_64      (0 << CS02) | (1 << CS01) | (1 << CS00)        // 011
#define TIMER_PRESCALAR_256     (1 << CS02) | (0 << CS01) | (0 << CS00)        // 100
#define TIMER_PRESCALAR_1024    (1 << CS02) | (0 << CS01) | (1 << CS00)        // 101

#include <avr/io.h>
#include <avr/interrupt.h>

#include <util/delay.h>

void pinSet(volatile uint8_t *port, uint8_t pin);
void pinReset(volatile uint8_t *port, uint8_t pin);
void ledOn();
void determinareFrecventa();

int flag_on = 0;			//initial, led-urile sunt stinse
int contor_secunde = 0;		//contor pentru generarea secundelor
int contor_on = 0;			//contor pentru masurarea duratei de timp in care LED-urile sunt aprinse
int secunde = 0;			

int main(void)
{
	DDRB = 0x0F;   //00001111
	PORTB = 0x00;
	DDRD |= (1 << PIND2) | (1 << PIND3);  //INT0 & INT1
	PORTD |= (1 << PIND2) | (1 << PIND3);
	
	cli();
	
	EICRA |= (1 << ISC11) | (1 << ISC10) | (1 << ISC01) | (1 << ISC00);
	EIMSK |= (1 << INT1) | (1 << INT0);
	EIFR |= (0 << INTF1) | (0 << INTF0);
	PCICR |= (0 << PCIE2) | (0 << PCIE1) | (0 << PCIE0);
	
	
	//momentan time-ul executa o intrerupere la fiecare 4ms
				
	TCCR0B = (1 << CS02) | (0 << CS01) | (0 << CS00); //valoare prescalar
	OCR0A = 0xF9;					      
	TCCR0A = (1 << WGM01) | (0 << WGM00);  //CTC
	//determinareFrecventa();
	TIMSK0 |= (1 << OCIE0A); 
	
	sei();
	
	do
	{
		ledOn();	

	}while (1);
}

void pinSet(volatile uint8_t *port, uint8_t pin){
	
	*port |=  1 << pin;
}

void pinReset(volatile uint8_t *port, uint8_t pin){
	
	*port &=  ~(1 << pin);
}

void ledOn(){
	
	if(flag_on == 1){
		pinSet(&PORTB, PINB0);
		pinSet(&PORTB, PINB1);
		pinSet(&PORTB, PINB2);
		pinSet(&PORTB, PINB3);
	}else{
		pinReset(&PORTB, PINB0);
		pinReset(&PORTB, PINB1);
		pinReset(&PORTB, PINB2);
		pinReset(&PORTB, PINB3);
	}
	
	if((secunde - contor_on) >= TIMP_APRINDERE){
		flag_on = 0;
	}
}

//void determinareFrecventa(){
	//
	//int frecventa_dorita = 1/GENERARE_INTRERUPERE;
	////int frecventa_realizata_general = 16000000/VALOARE_TOP_TIMER; //frecventa_realizata_general > frecventa_dorita 
	//int frecventa_realizata, valoare_aproximata;
	//
	//int valoare_prescalar[5] = {0, 8, 64, 256, 1024};
	//int timer_prescalar[5] = {TIMER_NO_PRESCALAR, TIMER_PRESCALAR_8, TIMER_PRESCALAR_64, TIMER_PRESCALAR_256, TIMER_PRESCALAR_1024};
	//
	//for(int i = 1; i <= 5; i++){
	//
		//frecventa_realizata = 16000000/(256*valoare_prescalar[i]);
		//
		//if(frecventa_realizata > frecventa_dorita){
			//
			//valoare_aproximata = 16000000/(valoare_prescalar[i-1]*frecventa_dorita); //n
			//TCCR0B |= timer_prescalar[i-1];
			//break;
		//}
	//}
	//
	//OCR0A = valoare_aproximata - 1; 
//}

ISR(TIMER0_COMPA_vect) {  //pt caz general
	
	cli();
	
	contor_secunde++;
	
	if(contor_secunde >= (1/GENERARE_INTRERUPERE)){ 
		
		secunde++;
		contor_secunde = 0;
	}
	
	sei();
}

ISR(INT0_vect) { //pt butonul de on
	
	cli();
	
	flag_on = 1;		 //LED-uri on
	contor_on = secunde; //determinarea timpului la care a fost apasat butonul  
	
	sei();
}

ISR(INT1_vect) { //pt butonul de off
	
	cli();
	
	flag_on = 0; //LED-uri off
	
	sei();
}
