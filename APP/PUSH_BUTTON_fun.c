/****************************
 * PUSH_BUTTON_fun.c			
 *							
 *  Created on: Jul 22, 2023	
 *      Author: AyaBaiumy	
 ****************************/

#include "DIO_interface.h"
#include "DIO_private.h"
#include "std_types.h"
#include "Bit_Math.h"
#include <avr/delay.h>

void PUSH_BUTTON_fun()
{
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN_2, DIO_u8_INPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN_3, DIO_u8_OUTPUT);


	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN_4, DIO_u8_INPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTC,DIO_u8_PIN_7, DIO_u8_OUTPUT);


	DIO_voidSetPinDirection(DIO_u8_PORTB,DIO_u8_PIN_0, DIO_u8_INPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTC,DIO_u8_PIN_2, DIO_u8_OUTPUT);


	while(1)
	{
		u8 Pin0_value = DIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN_0);
		u8 Pin2_value = DIO_u8GetPinValue(DIO_u8_PORTD, DIO_u8_PIN_2);
		u8 Pin4_value = DIO_u8GetPinValue(DIO_u8_PORTB, DIO_u8_PIN_4);


		if(Pin0_value == DIO_u8_HIGH && Pin2_value == DIO_u8_LOW && Pin4_value == DIO_u8_LOW)
		{
			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_HIGH);
		}
		else if(Pin0_value == DIO_u8_LOW && Pin2_value == DIO_u8_HIGH && Pin4_value == DIO_u8_LOW)
		{
			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_LOW);

			_delay_ms(300);

			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_LOW);

			_delay_ms(300);

			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_HIGH);
			_delay_ms(300);
		}
		else if(Pin0_value == DIO_u8_LOW && Pin2_value == DIO_u8_LOW && Pin4_value == DIO_u8_HIGH)
		{
			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_LOW);

			_delay_ms(300);

			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_LOW);

			_delay_ms(300);

			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_LOW);

			_delay_ms(300);

			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_LOW);

			_delay_ms(300);

			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_HIGH);

			_delay_ms(300);

			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_HIGH);

			_delay_ms(300);

			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_HIGH);

			_delay_ms(300);

			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_HIGH);

			_delay_ms(300);
		}
		else
		{
			DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN_3, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_2, DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PORTC, DIO_u8_PIN_7, DIO_u8_LOW);
		}
	}


}
