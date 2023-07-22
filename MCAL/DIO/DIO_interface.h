/*
 * DIO_interface.h
 *
 *  Created on: Jul 22, 2023
 *      Author: AyaBaiumy
 */
#include "Std_types.h"
#include "Bit_Math.h"

#ifndef DRIVERS_MCAL_DIO_DIO_INTERFACE_H_
#define DRIVERS_MCAL_DIO_DIO_INTERFACE_H_


//Definitions for DIO HIGH and LOW
#define DIO_u8_HIGH 	  1
#define DIO_u8_LOW 		  0

//Definitions for DIO OUTPUT and INPUT
#define DIO_u8_INPUT 	  0
#define DIO_u8_OUTPUT 	1


//PORTID
#define DIO_u8_PORTA 		0
#define DIO_u8_PORTB		1
#define DIO_u8_PORTC		2
#define DIO_u8_PORTD		3



//PORT PINs
#define DIO_u8_PIN_0 	0
#define DIO_u8_PIN_1 	1
#define DIO_u8_PIN_2 	2
#define DIO_u8_PIN_3 	3
#define DIO_u8_PIN_4 	4
#define DIO_u8_PIN_5 	5
#define DIO_u8_PIN_6 	6
#define DIO_u8_PIN_7 	7



void DIO_voidSetPortDirection(u8 PortID,u8 Direction);


void DIO_voidSetPortValue(u8 PortID,u8 value);


void DIO_voidSetPinDirection(u8 PortID,u8 PinID,u8 Direction);


void DIO_voidSetPinValue(u8 PortID,u8 PinID,u8 value);


u8           DIO_u8GetPinValue(u8 PortID,u8 PinID);

#endif /* DRIVERS_MCAL_DIO_DIO_INTERFACE_H_ */

