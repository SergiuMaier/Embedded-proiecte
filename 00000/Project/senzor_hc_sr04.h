/*
 * senzor_hc_sr04.h
 *
 * Created: 9/15/2022 10:33:23 AM
 *  Author: sergi
 */ 


#ifndef SENZOR_HC_SR04_H_
#define SENZOR_HC_SR04_H_

#define PIN_TRIG PINB1 //pinii se vor modifica dupa caz	 
#define PIN_ECHO PINB2

#define VITEZA_SUNETULUI 0.034 //(cm/microsec)

#include <avr/io.h>
#include <avr/interrupt.h>

uint8_t durata;
uint8_t distanta;
uint32_t timp_start;
uint32_t timp_final;

//trigger senzor
void trigger();

//calculul distantei
uint8_t calcul_distanta();

#endif /* SENZOR_HC-SR04_H_ */