/*
 * ADC.h
 *
 * Created: 10/26/2022 12:58:55 PM
 *  Author: Sergiu
 */ 

#ifndef ADC_H_
#define ADC_H_

#include "main_defines.h"

uint8_t val_adc;
char buffer[5];

void init_ADC();
uint16_t read_ADC(uint8_t input);
void start_conversie();

#endif /* ADC_H_ */