/*
 * functii_afisare.c
 *
 * Created: 10/6/2022 10:51:48 AM
 *  Author: Sergiu Maier
 */ 

#include "functii_afisare.h"

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
		send_data("VALOARE\n\r");
	}
	else if(strcmp(data, "5") == 0){	
		send_data("CLEAR\n\r");	//clear putty
	}
	else{
		
		//asa afisez momentan raspunsul de la slave
		
		send_data("r: ");
		send_data(data);
		send_data("\n\r");
		
		//trebuie tratate si comenzile incorecte cumva!
	}
}
