/****************************
 * LCD.c			
 *							
 *  Created on: Jul 23, 2023	
 *      Author: AyaBaiumy	
 ****************************/
#include <avr/delay.h>
#include "Std_types.h"
#include "Bit_Math.h"
void LCD_APP()
{
	u8 Str[15]={  0x0C,
			  0x0D,
			  0x06,
			  0x0E,
			  0x14,
			  0x0B,
			  0x09,
			  0x10};
	u8 Str2[15]={  0x06,
			  0x17,
			  0x0E,
			  0x0E,
			  0x04,
			  0x1A,
			  0x12,
			  0x01};
	LCD_Initialization();
	_delay_ms(2);
	LCD_Clear();
	_delay_ms(2);
	u16 i;
		LCD_Goxy(1,3);  // col,row
		LCD_WriteString("Welcome To");
		_delay_ms(500);
		LCD_Goxy(2,4);
		LCD_WriteString("STITCH LCD");
		_delay_ms(100);
			for(i=0;i<4;i++)
			LCD_scroll(0);
			_delay_ms(500);

			for(i=0;i<4;i++)
			LCD_scroll(1);
			_delay_ms(500);
			for(i=0;i<2;i++)
			LCD_scroll(0);
			_delay_ms(500);
	for(i=0;i<6;i++)
	{
		LCD_CustomChar(Str,i,1,i);
		_delay_ms(10);
		LCD_WriteCmd (0x01);
		LCD_CustomChar(Str2,i+1,1,i+1);
		_delay_ms(10);
		LCD_WriteCmd (0x01);
	}
}
