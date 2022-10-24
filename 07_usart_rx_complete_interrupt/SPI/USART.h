/*
 * main_func.h
 *
 * Created: 9/29/2022 11:46:43 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

#include "main_defines.h"
#include "functii_afisare.h" //doar pt switch_data

#include <util/delay.h>
#include <string.h>

volatile uint8_t flag_tx;
volatile uint8_t flag_rx;

void init_USART(uint16_t ubrr);
void transmit_data(unsigned char data);
unsigned char receive_data(void);
void send_data(char data[]);
void read_data(char data[]);
ISR(USART_RX_vect);

#endif /* MAIN_FUNC_H_ */