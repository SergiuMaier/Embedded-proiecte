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
	else if((strcmp(data, "timp") == 0)||(strcmp(data, "TIMP") == 0)){
		send_data("timp\n\r");
	}
	else if((strcmp(data, "clear") == 0)||(strcmp(data, "CLEAR") == 0)){
		send_data(CLEAR);
		send_data("\n\r");
	}
	else if((strcmp(data, "clear slave") == 0)||(strcmp(data, "CLEAR SLAVE") == 0)){
		send_data("clear\n\r");
	}
	else{
		send_data("\n\rr: ");
		send_data(data);
		send_data("\n\r\n\r");
	}
}
