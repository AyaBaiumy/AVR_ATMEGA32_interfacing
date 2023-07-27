/****************************
 * LCD.c			
 *							
 *  Created on: Jul 23, 2023	
 *      Author: AyaBaiumy	
 ****************************/


#include "DIO_interface.h"
#include "DIO_private.h"
#include "LCD_config.h"
#include <avr/delay.h>
static u8 InitStepFinished = 0;


void LCD_WriteCmd(u8 Cmd)
{

	DIO_voidSetPinValue(RS, DIO_u8_LOW);

	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_0, GET_BIT(Cmd , 4));
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_1, GET_BIT(Cmd , 5));
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_2, GET_BIT(Cmd , 6));
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_4, GET_BIT(Cmd , 7));

	DIO_voidSetPinValue(EN, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(EN, DIO_u8_LOW);

	if(InitStepFinished)
	{
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_0, GET_BIT(Cmd , 0));
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_1, GET_BIT(Cmd , 1));
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_2, GET_BIT(Cmd , 2));
		DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_4, GET_BIT(Cmd , 3));

		DIO_voidSetPinValue(EN, DIO_u8_HIGH);
		_delay_ms(1);
		DIO_voidSetPinValue(EN, DIO_u8_LOW);
	}
	_delay_ms(2);
}

void LCD_Initialization(void)
{
	DIO_voidSetPortDirection(DIO_u8_PORTA, DIO_u8_OUTPUT);
	DIO_voidSetPortDirection(DIO_u8_PORTB, DIO_u8_OUTPUT);

	_delay_ms(30);

//	LCD_WriteCmd(0x03);
//	_delay_ms(10);
//	LCD_WriteCmd(0x03);
//	_delay_ms(2);
//	LCD_WriteCmd(0x03);
//	_delay_ms(2);

	LCD_WriteCmd(0x20);
	_delay_ms(1);
	LCD_WriteCmd(0x20);
	LCD_WriteCmd(0x80);
	_delay_ms(1);

	LCD_WriteCmd(0x08);
	LCD_WriteCmd(0x00);
	LCD_WriteCmd(0x08);
	LCD_WriteCmd(0x28);
	_delay_ms(1);

	LCD_WriteCmd(0x00);
	LCD_WriteCmd(0x10);
	//LCD_WriteCmd(0x06);

	_delay_ms(2);

	InitStepFinished = 1;

}



void LCD_WriteData(u16 Data)
{
	DIO_voidSetPinValue(RS, DIO_u8_HIGH);//RS

	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_0, GET_BIT(Data , 4));
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_1, GET_BIT(Data , 5));
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_2, GET_BIT(Data , 6));
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_4, GET_BIT(Data , 7));

	DIO_voidSetPinValue(EN, DIO_u8_HIGH);//EN
	_delay_ms(1);
	DIO_voidSetPinValue(EN, DIO_u8_LOW);//EN


	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_0, GET_BIT(Data , 0));
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_1, GET_BIT(Data , 1));
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_2, GET_BIT(Data , 2));
	DIO_voidSetPinValue(DIO_u8_PORTB, DIO_u8_PIN_4, GET_BIT(Data , 3));

	DIO_voidSetPinValue(EN, DIO_u8_HIGH);//EN
	_delay_ms(1);
	DIO_voidSetPinValue(EN, DIO_u8_LOW);//EN

	_delay_ms(2);
}

void LCD_WriteString (u8 *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_WriteData (str[i]);
	}
}

void LCD_Clear()
{
	LCD_WriteCmd (0x01);
	/* clear display */
	LCD_WriteCmd (0x80);
	/* cursor at home position */
	LCD_WriteCmd(0x0E);
	//blinking is off
}

void LCD_Goxy (u8 row, u8 pos)
{
		if (row == 0 && pos<20)
		LCD_WriteCmd(pos + 128 );
		else if (row == 1 && pos<20)
		LCD_WriteCmd(pos+192);
		else if (row == 2 && pos<20)
		LCD_WriteCmd(pos+148);
		else if (row == 3 && pos<20)
		LCD_WriteCmd(pos+212);
}

void LCD_Dataxy (u8 row, u8 pos, u8 Data)
{
	if (row == 0 && pos<20)
	LCD_WriteCmd(pos + 128 );
	else if (row == 1 && pos<20)
	LCD_WriteCmd(pos+192);
	else if (row == 2 && pos<20)
	LCD_WriteCmd(pos+148);
	else if (row == 3 && pos<20)
	LCD_WriteCmd(pos+212);

	_delay_ms(50);
	LCD_WriteData(Data);
	_delay_ms(50);
}

void LCD_Stringxy (u8 row, u8 pos, u8 *str)
{
	if (row == 0 && pos<20)
	LCD_WriteCmd(pos + 128 );
	else if (row == 1 && pos<20)
	LCD_WriteCmd(pos+192);
	else if (row == 2 && pos<20)
	LCD_WriteCmd(pos+148);
	else if (row == 3 && pos<20)
	LCD_WriteCmd(pos+212);

	LCD_WriteString (str);
}

u16 LCD_NumberDigits(u32 number)
{
	u16 count=0;
	do {
	    number /= 10;
	    ++count;
	  } while (number != 0);
	return count;
}

void LCD_WriteNumber(u16 number)
{
	u16 count = LCD_NumberDigits(number);
	u8 i=0, c[count];
	while(number > 0)
		{
			c[i]=(number%10)+48;
			number/=10;
			i++;
		}
	i=0;
	while(c[i]!='\0')
	{
		LCD_WriteData(c[count-1-i]);
		i++;
		_delay_ms(5);
	}
}

void LCD_scroll(u8 direction)
{
	if(direction == 0)
	LCD_WriteCmd(0x18);
	else
	LCD_WriteCmd(0x1C);

	_delay_ms(300);
}

void LCD_CustomChar(u8 *Char_Str ,u8 loc ,u8 row ,u8 pos)
{
	u8 add = 0,i;
	add = loc*8;
	LCD_WriteCmd(add + 64);
		for( i = 0; i < 8; i++)
		{
			LCD_WriteData(Char_Str[i]);
		}
	LCD_Goxy ( row,  pos);
	LCD_WriteData(loc);
}

