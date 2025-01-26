/*
* 03 - address holding variables.c
*
* Created: 1/25/2025 8:48:44 PM
* Author : Nesimi
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdint.h>
#include <util/delay.h>

#define REGISTER_ZER0		0x29
#define MY_DDRD				*myDDRD			//0x2A
#define MY_PORTD			*(myDDRD + 1)	//0x2B

#define ON					0xFF
#define OFF					0x00

#define LEDS(led_status, delay) do {MY_PORTD = led_status; _delay_ms(delay);} while (0)

uint8_t* myDDRD = (uint8_t* ) (42);						//0x2A
//uint8_t* myDDRD = (uint8_t* ) (REGISTER_ZER0 + 1);	//0x2A

uint8_t* arr[2] = {(uint8_t*) 0x2A, (uint8_t*) 0x2B};
uint8_t** parr=arr;

#define PIND		*((uint8_t*) 0x29)
#define DDRD		*((uint8_t*) 0x2A)
#define PORTD		*((uint8_t*) 0x2B)


int main()
{
	example1();
	example2();
	example3();
}

void example1(){
	
	MY_DDRD = ON;
	MY_PORTD = OFF;
	
	while(1){
		MY_PORTD = ON;
		_delay_ms(1000);
		MY_PORTD = OFF;
		_delay_ms(1000);
	}
}

void example2(){
	while(1){
		LEDS(ON,1000);
		LEDS(OFF,500);
	}
}

void example3(){
	*parr[0]=ON;

	while(1){
		*parr[1]=ON;
		_delay_ms(2000);
		*parr[1]=OFF;
		_delay_ms(2000);
	}
}

void example4(){
	DDRD=0xFF;
	
	while(1){
		PORTD=0xFF;
		_delay_ms(1000);
		PORTD=0x00;
		_delay_ms(1000);
	}
}