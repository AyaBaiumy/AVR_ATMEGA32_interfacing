/****************************
 * KeyPad_LCD.c			
 *							
 *  Created on: Jul 26, 2023	
 *      Author: AyaBaiumy	
 ****************************/

#include <avr/delay.h>
#include "DIO_private.h"
u8 KEY_IS = 0;
void KeyPad_LCD()
{
	u8 pressCount=0,newLine=0,lineCount=1;
	DDRD=0xFF;
	PORTD=0x00;
	LCD_Initialization();
	_delay_ms(2);
	LCD_WriteCmd(0x0E);
	_delay_ms(2);
	LCD_WriteString(" Press any key ");
	LCD_WriteCmd(0xC0);
	KEYPAD_voidInit();
	u8 i = 0;
	while(1)
	{
		KEY_IS = KEY_PAD_u8GetPressedKey();
		if (KEY_IS != 0 )
		{
			LCD_WriteData(KEY_IS);
			pressCount+=1;
			KEY_IS = 0;
		}
		if (pressCount==20)
		{
			newLine=1;
			lineCount++;
			pressCount=0;
		}

		if (newLine)
		{
			newLine=0;
			LCD_Goxy(lineCount,0);
		}
		if (lineCount==4)
		{
			lineCount=1;
			LCD_Goxy(lineCount,0);
		}

	}
}
