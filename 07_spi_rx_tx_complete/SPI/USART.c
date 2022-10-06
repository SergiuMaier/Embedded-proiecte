/*
 * main_func.c
 *
 * Created: 9/29/2022 11:46:57 AM
 * Author: Sergiu Maier
 */ 

#include "USART.h"

void init_USART(uint16_t ubrr){
	
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B |= (1 << RXEN0)|(1 << TXEN0);
	UCSR0B |= (1 << RXCIE0)|(1 << UDRIE0);//(1 << TXCIE0);	
	UCSR0C |= (1 << USBS0)|(3 << UCSZ00);
	
	sei();
}

ISR(USART_UDRE_vect){ //apelata atunci cand se pot trimite info

	flag_tx = 1;	
}

void send_data(char *c){
	
	while(*c != '\0')
	{
		if(flag_tx == 1)
		{
			UDR0 = *c;
			c++;
			flag_tx = 0;
		}
	}
}

ISR(USART_RX_vect){
	
	flag_rx = 1;
}

void receive_data(){
	
	char c;

	if(flag_rx == 1)
	{	
		c = UDR0;
		UDR0 = c; //echo, afisez ce tastez
		
		switch_data(c);
		
		flag_rx = 0;
	}		
}

void switch_data(char c){
	
	switch(c)
	{
		case '1': new_line();
		          flag_afisare_timp = 1;
		          break;
		
		case '2': send_data(CLEAR);
		          send_data("\n\r Ascuns\n\r");
				  afisare_meniu();
		          new_line();
		          flag_afisare_timp = 0;
		          break;
		
		case '5': //new_line();
		          stare_led = !stare_led;
				  
				  if(stare_led == 1)
				  {
					  send_data("\n\rLED ON\n\r");
					  PORTB |= (1 << PINB0) ;
					  new_line();
				  }
				  else
				  {
					  send_data("\n\rLED OFF\n\r");
					  PORTB &= ~(1 << PINB0);
					  new_line();
				  }
				  
		          break;
		
		default: send_data("\n\rINCORECT!\n\r");
	             afisare_meniu();
		         new_line();
		         break;
	}
}

void new_line(){ //apelata in fiecare functie afisata
	
	send_data("\n\r>>");
}

