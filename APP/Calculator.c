/*
 * Calculator.c
 *
 *  Created on: Jul 27, 2023
 *      Author: AyaBaiumy
 */


#include <avr/delay.h>
#include "DIO_private.h"

u8 KEY_IS ;
u16 calc_sum(  u8 a[],u8 b[],u8 n,u8 m);
u16 calc_sub(  u8 a[],u8 b[],u8 n,u8 m);
u16 calc_multi(u8 a[],u8 b[],u8 n,u8 m);
u16 calc_div(  u8 a[],u8 b[],u8 n,u8 m);
void CALCULATOR()
{
	KEYPAD_voidInit();
	LCD_Initialization();
	_delay_ms(2);
	LCD_WriteCmd(0x0E);
	_delay_ms(2);
	LCD_Stringxy(0,3," Welcome to ");
	LCD_Stringxy(1,4," ATMEGA32 ");
	LCD_Stringxy(2,1," Real Calculator ");
	_delay_ms(1000);
	LCD_WriteCmd(0x01);

_delay_ms(200);

	u8 counter = 0;
	u8 KpValue=255;

	u8 FristNum[4];
	u8 SecondNum[4];

	u8 opration=0;
while(1)
{
	while(1)
	{
		do{
			KpValue = KEY_PAD_u8GetPressedKey();
			_delay_ms(20);
		}while(KpValue == '\0');
		if(KpValue == '+' || KpValue == '-' || KpValue == '/' || KpValue == '*' || KpValue == 'C')
		{
			opration = KpValue;
			LCD_Dataxy(0,counter+1,KpValue);
			break;
		}
		FristNum[counter]=KpValue;
		counter++;
		LCD_Dataxy(0,counter,KpValue);

	}
	u8 counter2=counter+1;
	u8 counter3=0;


	/*    Getting The Second Number    */
	while(1)
	{
		do{
			KpValue = KEY_PAD_u8GetPressedKey();
			_delay_ms(20);
		}while(KpValue == '\0');
		if(KpValue == '=' )
		{
			LCD_Dataxy(0,counter2+1,KpValue);
			break;
		}
		else if(KpValue == 'C' )
		{
			LCD_Clear();
		}
		SecondNum[counter3]=KpValue;
		counter2++;
		counter3++;
		LCD_Dataxy(0,counter2,KpValue);
	}


	/*     switch which operation was Selected */
	switch(opration)
	{
		case '+':
			LCD_Goxy(1,counter2);
			LCD_WriteNumber(calc_sum(FristNum,SecondNum,counter,counter3));
			break;
		case '-':
			LCD_Goxy(1,counter2);
			LCD_WriteNumber(calc_sub(FristNum,SecondNum,counter,counter3));break;
		case '*':
			LCD_Goxy(1,counter2);
			LCD_WriteNumber(calc_multi(FristNum,SecondNum,counter,counter3));break;
		case '/':
			LCD_Goxy(1,counter2);
			LCD_WriteNumber(calc_div(FristNum,SecondNum,counter,counter3));break;
		case 'C':
			LCD_Clear();break;
	}
	_delay_ms(3000);
	LCD_WriteCmd(0x01);
	}
}

u16 calc_sum(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0]-48;
	u16 num2=b[0]-48;
	for(u8 count=1;count<n;count++)
	{

		num1 = num1*10 +(a[count]-48);
	}

	for(u8 count=1;count<m;count++)
	{
		num2= num2*10 +(b[count]-48);
	}

	return (num1+num2);
}

u16 calc_sub(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0]-48;
	u16 num2=b[0]-48;
	for(u8 count=1;count<n;count++)
	{
		num1 = num1*10 +(a[count]-48);
	}

	for(u8 count=1;count<m;count++)
	{
		num2= num2*10 +(b[count]-48);
	}

	return (num1-num2);
}

u16 calc_multi(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0]-48;
	u16 num2=b[0]-48;
	for(u8 count=1;count<n;count++)
	{
		num1 = num1*10 +(a[count]-48);
	}

	for(u8 count=1;count<m;count++)
	{
		num2= num2*10 +(b[count]-48);
	}

	return (num1*num2);
}

u16 calc_div(u8 a[],u8 b[],u8 n,u8 m){
	u16 num1=a[0]-48;
	u16 num2=b[0]-48;
	for(u8 count=1;count<n;count++)
	{
		num1 = num1*10 +(a[count]-48);
	}

	for(u8 count=1;count<m;count++)
	{
		num2= num2*10 +(b[count]-48);
	}

	return (num1/num2);
}



