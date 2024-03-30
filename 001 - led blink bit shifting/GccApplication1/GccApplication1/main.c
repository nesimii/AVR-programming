/*
* GccApplication1.c
*
* Created: 30/03/2024 22:15:46
* Author : Nesimi
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD=0xFF;
	PORTD=0X00;
	
	//example 1
	//bitZeroOne();
	
	//example 2
	//zeroToLast();
	
	//example 3
	//zeroToLastSlider();
	zeroToLastSliderAlternativeXOR();

}

void bitZeroOne(){
	
	//	0000 0000
	//	0000 0011
	PORTD=(1<<PORTD0) | (1<<PORTD1);
}

void zeroToLast(){
	
	//	0000 0000 => 0000 0010 => 0000 0100 ...
	//	0000 0000 => 0000 0010 => 0000 0100 ...
	
	uint8_t counter=0;
	while(1){
		for (counter=0; counter<8;counter++)
		{
			PORTD = (1<<counter);
			_delay_ms(300);
		}
	}
}

void zeroToLastSlider(){
	uint8_t counter=0;
	while(1){
		//	0000 0000 => 0000 0001 => 0000 0011 => 0000 0111 ...
		//	0000 0000 => 0000 0001 => 0000 0010 => 0000 0100 ...
		for (counter=0; counter<8;counter++)
		{
			PORTD |= (1<<counter);
			_delay_ms(300);
		}
		
		//	1111 1111 => 1111 1110 => 1111 1100 => 1111 1000 ...
		//	0000 0000 => 0000 0001 => 0000 0010 => 0000 0100 ...
		for (counter=0; counter<8;counter++)
		{
			PORTD &= ~(1<<counter);
			_delay_ms(300);
		}
	}
}

void zeroToLastSliderAlternativeXOR(){
	uint8_t counter=0;
	while(1){
		//	0000 0000 => 0000 0001 => 0000 0011 => 0000 0111 ...
		//	0000 0000 => 0000 0001 => 0000 0010 => 0000 0100 ...
		
		//	1111 1111 => 1111 1110 => 1111 1100 => 1111 1000 ...
		//	0000 0000 => 0000 0001 => 0000 0010 => 0000 0100 ...
		
		for (counter=0; counter<8;counter++)
		{
			PORTD ^= (1<<counter);
			_delay_ms(300);
		}
	}
}