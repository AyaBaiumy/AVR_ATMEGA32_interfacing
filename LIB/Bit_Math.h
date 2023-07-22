/*
 * DIO_program.c
 *
 *  Created on: Jul 22, 2023
 *      Author: AyaBaiumy
 */


#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(Reg, bitnum)       	(Reg |=1<<bitnum)
#define CLR_BIT(Reg, bitnum)     	(Reg &=~(1<<bitnum))
#define TOGGLE_BIT(Reg, bitnum)    	(Reg ^=(1<<bitnum))
#define GET_BIT(Reg, bitnum)       	((Reg>>bitnum)& 0x01)


#endif

