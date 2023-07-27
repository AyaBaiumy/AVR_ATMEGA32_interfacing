/****************************
 * PSH_BUTTON.c
 *
 *  Created on: Jul 22, 2023
 *      Author: AyaBaiumy
 ****************************/


#include "DIO_interface.h"
#include "DIO_private.h"
#include "std_types.h"
#include "Bit_Math.h"

void PUSH_BUTTON()
{
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN_2, DIO_u8_INPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN_3, DIO_u8_OUTPUT);
	u8 Pin_value = DIO_u8GetPinValue(DIO_u8_PORTD, DIO_u8_PIN_2);
	while(1)
	{
		if(Pin_value == DIO_u8_HIGH)
		{
			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_LOW);
		}
	}


}
