/*
 * functii_afisare.c
 *
 * Created: 10/6/2022 10:51:48 AM
 *  Author: Sergiu Maier
 */ 

#include "functii_afisare.h"

void new_line()
{
	send_data("\n\r>>");
}

void afisare_meniu()
{
	send_data("\n\rComenzi:\n\r 1. meniu\n\r 2. timp\n\r 3. led on\n\r 4. led off\n\r 5. clear\n\r");
}

void switch_data(char data[])
{			
	if (strcmp(data, "1") == 0){
		send_data("LED ON\n\r");
	}
	else if(strcmp(data, "2") == 0){
		send_data("LED OFF\n\r");
	}
	else if((strcmp(data, "3") == 0)){
		send_data("TIMP\n\r");
	}
	else if(strcmp(data, "4") == 0){
		send_data("CLEAR\n\r");
	}
	else{
		send_data("r: ");
		send_data(data);
		send_data("\n\r");
	}
}
