/****************************
 * SEV_SEG.c			
 *							
 *  Created on: Jul 23, 2023	
 *      Author: AyaBaiumy	
 ****************************/


#include "Std_types.h"
#include "Bit_Math.h"
#include "SEV_SEG.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include <avr/delay.h>

void SEV_SEG_Initialization(void)
{
	DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN_0, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN_1, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN_2, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN_4, DIO_u8_OUTPUT);

	DIO_voidSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN_3, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTA, DIO_u8_PIN_2, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN_5, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTB, DIO_u8_PIN_6, DIO_u8_OUTPUT);
}

void SEV_SEG_Enable(u8 value)
{
	switch(value)
	{
	case 1:
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_3, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_2, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_5, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_6, DIO_u8_HIGH);
		break;
	case 2:
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_3, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_2, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_5, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_6, DIO_u8_HIGH);
		break;
	case 3:
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_3, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_2, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_5, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_6, DIO_u8_HIGH);
		break;
	case 4:
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_3, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_2, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_5, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_6, DIO_u8_LOW);
		break;
	}

}

void SEV_SEG_Disable(u8 value)
{
	switch(value)
	{
	case 1:
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_3, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_2, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_5, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_6, DIO_u8_LOW);
		break;
	case 2:
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_3, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_2, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_5, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_6, DIO_u8_LOW);
		break;
	case 3:
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_3, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_2, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_5, DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_6, DIO_u8_LOW);
		break;
	case 4:
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_3, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTA, DIO_u8_PIN_2, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_5, DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_6, DIO_u8_HIGH);
		break;
	}

}


void SEV_SEG_Write_Number(u8 number)
{
	if (number < 10)
	{
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_0, GET_BIT(number , 0));
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_1, GET_BIT(number , 1));
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_2, GET_BIT(number , 2));
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_4, GET_BIT(number , 3));
	}
}

void SEV_SEG_Display_Number(u16 num)
{
	u8 remain;
	if (num < 10000)
	{
		for(int i=0 ; i < 4 ; i++)
		{
			SEV_SEG_Enable(i+1);
			remain=num%10;
			num/=10;
			SEV_SEG_Write_Number(remain);
			_delay_ms(20);
			SEV_SEG_Disable(i+1);
			_delay_ms(20);
		}
	}
}

