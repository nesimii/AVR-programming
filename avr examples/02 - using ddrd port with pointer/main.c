/*
* main.c
*
* Created: 1/22/2025 11:51:20 PM
*  Author: Nesimi
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <stdint.h>
#include <util/delay.h>

uint8_t on = 0xFF;
uint8_t off	= 0x00;

#define PIND		*((uint8_t*) 0x29)
#define DDRD		*((uint8_t*) 0x2A)
#define PORTD		*((uint8_t*) 0x2B)

void change(uint8_t* x, uint8_t* y);

void change(uint8_t* x, uint8_t* y){
	uint8_t temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main(void)
{
	void (*change_ptr)(uint8_t*, uint8_t*) = change;
	DDRD = 0xFF;
	
	while (1)
	{
		PORTD = on;
		_delay_ms(1000);
		(*change_ptr)(&on , &off);
	}
}
