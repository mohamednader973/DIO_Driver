/*
 * DIO_Driver.c
 *
 * Created: 9/6/2020 5:35:51 PM
 * Author : monad
 */ 

#include <avr/io.h>
#include "DIO_Init.h"
#include "DIO_INOUT.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	DIO_init(DIO_PORTC,PIN_TWO,OUTPUT);
	DIO_init(DIO_PORTD,PIN_TWO,INPUT);
    /* Replace with your application code */
    while (1) 
    {
		if (((PIND_IO>>2)&1)==1)
		{
			while(((PIND_IO>>2)&1));
			DIO_WRITE(DIO_PORTC,PIN_TWO,HIGH);
			_delay_ms(500);
			DIO_WRITE(DIO_PORTC,PIN_TWO,LOW);
			_delay_ms(500);
		}
    }
}

