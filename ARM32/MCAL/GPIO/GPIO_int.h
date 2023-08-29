/*
 * GPIO_int.h
 *
 *  Created on: Aug 11, 2023
 *      Author: Stitch
 */

#ifndef GPIO_GPIO_INT_H_
#define GPIO_GPIO_INT_H_

#define		OUTPUT							1
#define		INPUT							3

#define		GPIO_PIN_HIGH					1
#define		GPIO_PIN_LOW					0

#define		INPUTMODE						1
#define		GENERALOUTPUT					2
#define		ALTFUN							3
#define		ANALOGMODE						4

#define		OUTPUT_NORMAL					1
#define		OUTPUT_PULL_UP					3
#define		OUTPUT_PULL_DOWN				5

#define		OPEN_DRAIN						53

#define		SPEED_INPUT						1
#define		LOW_SPEED						3
#define		MEDIUM_SPEED					7
#define		HIGH_SPEED						5



#define		INPUT_ANALOG					13
#define		INPUT_FLOATING					14
#define		INPUT_PULLDOWN					15
#define		INPUT_PULLUP					16




#define		PORTA							17
#define		PORTB							18
#define		PORTC							19
#define		PORTD							20
#define		PORTF							22



#define		PIN0							0
#define		PIN1							1
#define		PIN2							2
#define		PIN3							3
#define		PIN4							4
#define		PIN5							5
#define		PIN6							6
#define		PIN7							7
#define		PIN8							8
#define		PIN9							9
#define		PIN10							10
#define		PIN11							11
#define		PIN12							12
#define		PIN13							13
#define		PIN14							14
#define		PIN15							15

//void GPIO_init(u8 PortID);

void DIO_voidSetPinDirection(u8 PortID,u8 PinID,u8 Direction,u8 Mode);


void DIO_voidSetPinValue(u8 PortID,u8 PinID,u8 value);


u8	 DIO_u8GetPinValue(u8 PortID,u8 PinID);



#endif /* GPIO_GPIO_INT_H_ */
