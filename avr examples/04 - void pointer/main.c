/*
* 04 - void pointer.c
*
* Created: 1/26/2025 11:24:36 PM
* Author : Nesimi
*/

// CPU FREQUENCY
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

// LIBRARIES
#include <stdint.h>
#include <util/delay.h>

// PORT ADRESSES
#define PIND		*((uint8_t*) 0x29)
#define DDRD		*((uint8_t*) 0x2A)
#define PORTD		*((uint8_t*) 0x2B)

#define LOOP_INDEX			4
#define INNER_LOOP_MS		300

// FUNC PROTOTYPES
void loop1(), loop2(), loop3(), loop4();

// FUNCTIONS

void loop1(){
	PORTD = 0x08;
	_delay_ms(INNER_LOOP_MS);
	PORTD=0x10;
}

void loop2(){
	PORTD = 0x24;
}

void loop3(){
	PORTD = 0x42;
}

void loop4(){
	PORTD = 0x81;
}

int main(void)
{
	void (*fun_ptr_arr[])() = {loop1, loop2, loop3, loop4};
	
	DDRD = 0xFF;
	uint8_t i= 0;
	
	while (1)
	{		
		for(i=0; i<LOOP_INDEX;i++){
			fun_ptr_arr[i]();
			_delay_ms(INNER_LOOP_MS);
		}
		
		for (i=(LOOP_INDEX- 1 ); i>0; i--)
		{
			fun_ptr_arr[i]();
			_delay_ms(INNER_LOOP_MS);
		}
	}
	
	return 0;
}
