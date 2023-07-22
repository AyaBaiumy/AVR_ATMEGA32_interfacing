/*
 * DIO_program.c
 *
 *  Created on: Jul 22, 2023
 *      Author: AyaBaiumy
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_voidSetPortDirection(u8 PortID,u8 Direction)
{
	if(DIO_u8_OUTPUT == Direction)
	{
		switch(PortID)
		{
			case DIO_u8_PORTA: DDRA = 0xff; break;
			case DIO_u8_PORTB: DDRB = 0xff; break;
			case DIO_u8_PORTC: DDRC = 0xff; break;
			case DIO_u8_PORTD: DDRD = 0xff; break;
		}
	}
	else if (DIO_u8_INPUT == Direction)
	{
		switch(PortID)
		{
			case DIO_u8_PORTA: DDRA = 0x00; break;
			case DIO_u8_PORTB: DDRB = 0x00; break;
			case DIO_u8_PORTC: DDRC = 0x00; break;
			case DIO_u8_PORTD: DDRD = 0x00; break;
		}
	}
}
void DIO_voidSetPortValue(u8 PortID,u8 value)
{
	switch(PortID)
	{
		case DIO_u8_PORTA : PORTA = value; break;
		case DIO_u8_PORTB : PORTB = value; break;
		case DIO_u8_PORTC : PORTC = value; break;
		case DIO_u8_PORTD : PORTD = value; break;
	}
}
void DIO_voidSetPinDirection(u8 PortID,u8 PinID,u8 Direction)
{
	if(PortID <= DIO_u8_PORTD && PinID <= DIO_u8_PIN_7)
	{
		if(DIO_u8_OUTPUT == Direction)
		{
			switch(PortID)
			{
				case DIO_u8_PORTA : SET_BIT(DDRA, PinID) ; break;
				case DIO_u8_PORTB : SET_BIT(DDRB, PinID) ; break;
				case DIO_u8_PORTC : SET_BIT(DDRC, PinID) ; break;
				case DIO_u8_PORTD : SET_BIT(DDRD, PinID) ; break;
			}
		}
		else if(DIO_u8_INPUT == Direction)
		{
			switch(PortID)
			{
				case DIO_u8_PORTA : CLR_BIT(DDRA, PinID) ; break;
				case DIO_u8_PORTB : CLR_BIT(DDRB, PinID) ; break;
				case DIO_u8_PORTC : CLR_BIT(DDRC, PinID) ; break;
				case DIO_u8_PORTD : CLR_BIT(DDRD, PinID) ; break;
			}
		}
	}
}
void DIO_voidSetPinValue(u8 PortID,u8 PinID,u8 value)
{
	if(PortID <= DIO_u8_PORTD && PinID <= DIO_u8_PIN_7)
	{
		if(value == DIO_u8_HIGH)
		{
			switch(PortID)
			{
				case DIO_u8_PORTA : SET_BIT(PORTA, PinID) ; break;
				case DIO_u8_PORTB : SET_BIT(PORTB, PinID) ; break;
				case DIO_u8_PORTC : SET_BIT(PORTC, PinID) ; break;
				case DIO_u8_PORTD : SET_BIT(PORTD, PinID) ; break;
			}
		}
		else if(value == DIO_u8_LOW)
		{
			switch(PortID)
			{
				case DIO_u8_PORTA : CLR_BIT(PORTA, PinID) ; break;
				case DIO_u8_PORTB : CLR_BIT(PORTB, PinID) ; break;
				case DIO_u8_PORTC : CLR_BIT(PORTC, PinID) ; break;
				case DIO_u8_PORTD : CLR_BIT(PORTD, PinID) ; break;
			}
		}
	}
}
u8           DIO_u8GetPinValue(u8 PortID,u8 PinID)
{
	u8 PIN_value;
	if(PortID <= DIO_u8_PORTD && PinID <= DIO_u8_PIN_7)
	{
		switch(PortID)
			{
				case DIO_u8_PORTA : PIN_value = GET_BIT(PINA, PinID) ; break;
				case DIO_u8_PORTB : PIN_value = GET_BIT(PINB, PinID) ; break;
				case DIO_u8_PORTC : PIN_value = GET_BIT(PINC, PinID) ; break;
				case DIO_u8_PORTD : PIN_value = GET_BIT(PIND, PinID) ; break;
			}
	}
	return PIN_value;
}

