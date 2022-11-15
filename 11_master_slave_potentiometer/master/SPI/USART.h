/*
 * main_func.h
 *
 * Created: 9/29/2022 11:46:43 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

#include "main_defines.h"
#include "functii_afisare.h"

#include <util/delay.h>
#include <string.h>
#include <avr/sfr_defs.h>

/* VARIABILE */

//flag_rx devine 1 atunci cand este apasata tasta Enter
volatile uint8_t flag_rx; 
char mesaj[50];

/* PROTOTIPURI */

//initializare USART
void init_USART(uint16_t ubrr); 

//transmitere date
void transmit_data(unsigned char data); 

//primire date
unsigned char receive_data(void); 

//trimiterea unui nou mesaj
void send_data(char data[]);  

//citirea unui mesaj primit
void read_data(char data[]);  

//citirea si executarea comenzilor primite
void start_program(); 

ISR(USART_RX_vect);

#endif /* MAIN_FUNC_H_ */