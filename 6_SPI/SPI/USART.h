/*
 * main_func.h
 *
 * Created: 9/21/2022 11:46:43 AM
 *  Author: Sergiu Maier
 */ 

#ifndef MAIN_FUNC_H_
#define MAIN_FUNC_H_

#include "main_defines.h"
#include <util/delay.h>

volatile uint8_t flag;
volatile char *str;

void USART_Init(uint16_t ubrr);

void SendData(char *c);

ISR(USART_UDRE_vect);

#endif /* MAIN_FUNC_H_ */