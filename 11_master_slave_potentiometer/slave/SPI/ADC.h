/*
 * ADC.h
 *
 * Created: 10/26/2022 12:58:55 PM
 *  Author: Sergiu
 */ 

#ifndef ADC_H_
#define ADC_H_

#include "main_defines.h"

uint16_t val_adc;
char buffer[5]; //conversie var_adc in char 

void init_ADC();
void start_conversie();
ISR(ADC_vect);

#endif /* ADC_H_ */