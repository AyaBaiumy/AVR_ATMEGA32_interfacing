/****************************
 * LCD.h			
 *							
 *  Created on: Jul 23, 2023	
 *      Author: AyaBaiumy	
 ****************************/

#ifndef DRIVERS_HAL_LCD_LCD_H_
#define DRIVERS_HAL_LCD_LCD_H_

#include "LCD.h"
//

void LCD_Initialization();

void LCD_WriteCmd(u8 Cmd);

void LCD_WriteData(u16 Data);

void LCD_Clear();

void LCD_WriteString (u8 *str);

void LCD_Goxy (u8 row, u8 pos);

void LCD_Dataxy (u8 row, u8 pos, u8 Data);

void LCD_Stringxy (u8 row, u8 pos, u8 str);

u16 LCD_NumberDigits(u32 number);

void LCD_WriteNumber(u16 number);

void LCD_scroll(u8 direction);

void LCD_CustomChar(u8 Char_Str[8],u8 row,u8 pos);

#endif /* DRIVERS_HAL_LCD_LCD_H_ */

