/*
 * KEYPAD_program.c
 *
 *  Created on: Jul 22, 2023
 *      Author: AyaBaiumy
 */

#include "DIO_interface.h"
#include "KEYPAD_config.h"
#include <avr/delay.h>

u8 KEY_PAD_KEYS[4][4]={ {'7','8','9','/'},
						{'4','5','6','*'},
						{'1','2','3','-'},
						{'C','0','=','+'} };
u8 realCol [] = {KEY_PAD_COL1, KEY_PAD_COL2, KEY_PAD_COL3, KEY_PAD_COL4};
u8 realRow [] = {KEY_PAD_ROW1, KEY_PAD_ROW2, KEY_PAD_ROW3, KEY_PAD_ROW4};
void KEYPAD_voidInit()
{
	DIO_voidSetPortDirection(DIO_u8_PORTD, DIO_u8_OUTPUT);
	DIO_voidSetPortDirection(DIO_u8_PORTC, DIO_u8_OUTPUT);

	DIO_voidSetPinDirection(DIO_u8_PORTD, KEY_PAD_COL1 ,DIO_u8_OUTPUT );
	DIO_voidSetPinDirection(DIO_u8_PORTD ,KEY_PAD_COL2 ,DIO_u8_OUTPUT );
	DIO_voidSetPinDirection(DIO_u8_PORTD ,KEY_PAD_COL3 ,DIO_u8_OUTPUT );
	DIO_voidSetPinDirection(DIO_u8_PORTD, KEY_PAD_COL4 ,DIO_u8_OUTPUT );

	DIO_voidSetPinDirection(DIO_u8_PORTC, KEY_PAD_ROW1 ,DIO_u8_INPUT );
	DIO_voidSetPinDirection(DIO_u8_PORTC, KEY_PAD_ROW2 ,DIO_u8_INPUT );
	DIO_voidSetPinDirection(DIO_u8_PORTC, KEY_PAD_ROW3 ,DIO_u8_INPUT );
	DIO_voidSetPinDirection(DIO_u8_PORTC, KEY_PAD_ROW4 ,DIO_u8_INPUT );

	DIO_voidSetPinValue(DIO_u8_PORTC, KEY_PAD_ROW1 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(DIO_u8_PORTC, KEY_PAD_ROW2 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(DIO_u8_PORTC, KEY_PAD_ROW3 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(DIO_u8_PORTC, KEY_PAD_ROW4 ,DIO_u8_HIGH );
}


u8 KEY_PAD_u8GetPressedKey(void) // @suppress("No return")
{

	u8 u8_ROW , u8_COL;
	u8 Local_Key = 0 ;

	DIO_voidSetPinValue(DIO_u8_PORTD, KEY_PAD_COL1 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(DIO_u8_PORTD, KEY_PAD_COL2 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(DIO_u8_PORTD, KEY_PAD_COL3 ,DIO_u8_HIGH );
	DIO_voidSetPinValue(DIO_u8_PORTD, KEY_PAD_COL4 ,DIO_u8_HIGH );

	for( u8_COL = 0 ; u8_COL < 4 ; u8_COL++)
	{
		DIO_voidSetPinValue(DIO_u8_PORTD, realCol [u8_COL],DIO_u8_LOW);
		for(u8_ROW=0;u8_ROW<4;u8_ROW++)
			{
				DIO_u8GetPinValue(DIO_u8_PORTC, realRow [u8_ROW]);
				if (!DIO_u8GetPinValue(DIO_u8_PORTC, realRow [u8_ROW]))
				{
					Local_Key = KEY_PAD_KEYS[u8_ROW][u8_COL];
					while(DIO_u8GetPinValue(DIO_u8_PORTC, realRow [u8_ROW]) == 0)
					{
						_delay_ms(10);
						Local_Key = KEY_PAD_KEYS[u8_ROW][u8_COL];
					}
				}
			}
		DIO_voidSetPinValue(DIO_u8_PORTD, realCol [u8_COL], DIO_u8_HIGH);
	}
	return Local_Key;
}
