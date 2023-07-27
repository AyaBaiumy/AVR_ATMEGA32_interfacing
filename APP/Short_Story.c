/****************************
 * Short_Story.c			
 *							
 *  Created on: Jul 26, 2023	
 *      Author: AyaBaiumy	
 ****************************/


#include <avr/delay.h>
#include "Std_types.h"
#include "Bit_Math.h"
void LCD_STORY()
{
	u8 Str[15]={  0x0E,
			  0x0E,
			  0x14,
			  0x1E,
			  0x15,
			  0x05,
			  0x0A,
			  0x0A};
	u8 Str2[15]={   0x06,
			  0x06,
			  0x05,
			  0x0E,
			  0x14,
			  0x14,
			  0x0A,
			  0x0A};
	u8 Str3[15]={ 0x00,
			  0x1B,
			  0x1B,
			  0x00,
			  0x0E,
			  0x0A,
			  0x04,
			  0x00};
	u8 Str4[15]={  0x00,
			  0x00,
			  0x00,
			  0x1B,
			  0x00,
			  0x0E,
			  0x00,
			  0x00};
	u8 Str5[15]={  0x00,
			  0x1B,
			  0x1B,
			  0x00,
			  0x00,
			  0x11,
			  0x0E,
			  0x00};
	u8 Str6[15]={  0x0E,
			  0x0E,
			  0x04,
			  0x0E,
			  0x15,
			  0x1F,
			  0x0A,
			  0x0A};
	u8 Str7[15]={  0x0C,
			  0x0D,
			  0x05,
			  0x0E,
			  0x14,
			  0x0C,
			  0x14,
			  0x14};

	LCD_Initialization();
	_delay_ms(2);
	LCD_WriteCmd(0x28);
	LCD_Clear();
	_delay_ms(2);

	while(1)
	{
		LCD_CustomChar(Str,0,1,2);
		_delay_ms(10);
			LCD_Stringxy (1, 4, " Hi !");
			_delay_ms(2000);
			LCD_Clear();
		LCD_CustomChar(Str2,1,1,3);
		_delay_ms(10);
			LCD_Stringxy (2, 1, "can i take some of");
			LCD_Stringxy (3, 1, " your time?");
			_delay_ms(3000);
			LCD_Clear();
		LCD_CustomChar(Str3,2,0,3);
		_delay_ms(10);
			LCD_Stringxy (1, 2, "This is just a ");
			LCD_Stringxy (2, 3, "story of mine");
			_delay_ms(2000);
			LCD_Clear();
		LCD_CustomChar(Str4,3,1,3);
		_delay_ms(10);
			LCD_Stringxy (1, 1, "There was that");
			LCD_Stringxy (2,0 , "young boy who wanted ");
			LCD_Stringxy(3, 1, "to buy a game");
			_delay_ms(2000);
			LCD_Clear();
			LCD_Stringxy (1, 1, "and decided to work");
			LCD_Stringxy(2, 1, " a part-time");
			LCD_Stringxy (3, 1, "to go and buy it");
			_delay_ms(2000);
			LCD_Clear();
		LCD_CustomChar(Str5,4,1,3);
		_delay_ms(10);
			LCD_Stringxy (2, 1, "Finally he bought");
			LCD_Stringxy (3, 1, "the game");
			_delay_ms(2000);
			LCD_Clear();
		LCD_CustomChar(Str6,5,1,3);
		_delay_ms(10);
			LCD_Stringxy (2, 5, "Happy END");
			_delay_ms(2000);
			LCD_Clear();
		LCD_CustomChar(Str7,6,1,3);
		_delay_ms(10);
			LCD_Stringxy (1, 5, "Don't");
			LCD_Stringxy (2, 0, "have a nice day");
			LCD_Stringxy (3, 3, "have a GREAT day");
			_delay_ms(2000);
			LCD_Clear();
			}
}
