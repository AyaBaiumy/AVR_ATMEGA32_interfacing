/*
 * LED.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Stitch
 */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "std_types.h"
#include "Bit_Math.h"

void LED()
{
	//DIO_voidSetPortDirection(DIO_u8_PORTC,DIO_u8_OUTPUT);
	//DIO_voidSetPortValue(DIO_u8_PORTC,DIO_u8_HIGH);

	DIO_voidSetPinDirection(DIO_u8_PORTC,DIO_u8_PIN_6, DIO_u8_OUTPUT);
	DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN_6, DIO_u8_HIGH);

	DIO_voidSetPinDirection(DIO_u8_PORTA,DIO_u8_PIN_5, DIO_u8_OUTPUT);
	DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_5, DIO_u8_HIGH);


	DIO_voidSetPinDirection(DIO_u8_PORTA,DIO_u8_PIN_4, DIO_u8_OUTPUT);
	DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_4, DIO_u8_HIGH);
}
