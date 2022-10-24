/*
 * main_defines.h
 *
 * Created: 9/21/2022 11:46:26 AM
 *  Author: sergiu
 */ 


#ifndef MAIN_DEFINES_H_
#define MAIN_DEFINES_H_

#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//#define CLEAR "\e[1;1H\e[2J"
#define CLEAR "\033\143"
#define F_CPU 16000000UL
#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD)-1

#endif /* MAIN_DEFINES_H_ */