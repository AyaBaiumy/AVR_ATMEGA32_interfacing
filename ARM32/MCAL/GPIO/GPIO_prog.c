/*
 * GPIO_prog.c
 *
 *  Created on: Aug 11, 2023
 *      Author: AyaBaiumy
 */
#include "Std_types.h"
#include "Bit_Math.h"

#include "RCC_int.h"
#include "GPIO_int.h"
#include "../GPIO/GPIO_priv.h"
#include "GPIO_config.h"

//void GPIO_init(u8 PortID)
//{
//	RCC_voidSysClkInit();
//	RCC_voidPerClkEn(AHB, PortID);
//}

void DIO_voidSetPinDirection(u8 PortID,u8 PinID,u8 Direction,u8 Mode)
{
	switch(Direction)
	{
		case GENERALOUTPUT:
			switch(PortID)
			{
			case PORTA:
				SET_BIT(PORTA_MODE_MODER,PinID*2);
				CLR_BIT(PORTA_MODE_MODER,((PinID*2)+1));
				switch(Mode)
				{
					case OPEN_DRAIN:
							SET_BIT(PORTA_MODE_OTYPER,PinID);
					break;

					case OUTPUT_PULL_UP:
							CLR_BIT(PORTA_MODE_OTYPER,PinID);
							CLR_BIT(PORTA_MODE_PUPDR,PinID*2);
							SET_BIT(PORTA_MODE_PUPDR,((PinID*2)+1));
					break;
					case OUTPUT_PULL_DOWN:
							CLR_BIT(PORTA_MODE_OTYPER,PinID);
							CLR_BIT(PORTA_MODE_PUPDR,PinID*2);
							SET_BIT(PORTA_MODE_PUPDR,((PinID*2)+1));
					break;
					case OUTPUT_NORMAL:
							CLR_BIT(PORTA_MODE_OTYPER,PinID);
							CLR_BIT(PORTA_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTA_MODE_PUPDR,((PinID*2)+1));
					break;
				}
				#if SPEED_MODE==LOW_SPEED
				CLR_BIT(PORTA_MODE_OSPEEDR,PinID*2);
				CLR_BIT(PORTA_MODE_OSPEEDR,((PinID*2)+1));
				#elif SPEED_MODE==MEDIUM_SPEED
				SET_BIT(PORTA_MODE_OSPEEDR,PinID*2);
				CLR_BIT(PORTA_MODE_OSPEEDR,((PinID*2)+1));
				#elif SPEED_MODE==HIGH_SPEED
				SET_BIT(PORTA_MODE_OSPEEDR,PinID*2);
				SET_BIT(PORTA_MODE_OSPEEDR,((PinID*2)+1));
				#else
				#endif
			break;

			case PORTB:
				SET_BIT(PORTB_MODE_MODER,PinID*2);
				CLR_BIT(PORTB_MODE_MODER,((PinID*2)+1));
				switch(Mode)
				{
					case OPEN_DRAIN:
							SET_BIT(PORTB_MODE_OTYPER,PinID);
					break;

					case OUTPUT_PULL_UP:
							CLR_BIT(PORTB_MODE_OTYPER,PinID);
							CLR_BIT(PORTB_MODE_PUPDR,PinID*2);
							SET_BIT(PORTB_MODE_PUPDR,((PinID*2)+1));
					break;
					case OUTPUT_PULL_DOWN:
							CLR_BIT(PORTB_MODE_OTYPER,PinID);
							CLR_BIT(PORTB_MODE_PUPDR,PinID*2);
							SET_BIT(PORTB_MODE_PUPDR,((PinID*2)+1));
					break;
					case OUTPUT_NORMAL:
							CLR_BIT(PORTB_MODE_OTYPER,PinID);
							CLR_BIT(PORTB_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTB_MODE_PUPDR,((PinID*2)+1));
					break;
				}
				#if SPEED_MODE==LOW_SPEED
				CLR_BIT(PORTB_MODE_OSPEEDR,PinID*2);
				CLR_BIT(PORTB_MODE_OSPEEDR,((PinID*2)+1));
				#elif SPEED_MODE==MEDIUM_SPEED
				SET_BIT(PORTB_MODE_OSPEEDR,PinID*2);
				CLR_BIT(PORTB_MODE_OSPEEDR,(PinID*2)+1);
				#elif SPEED_MODE==HIGH_SPEED
				SET_BIT(PORTB_MODE_OSPEEDR,PinID*2);
				SET_BIT(PORTB_MODE_OSPEEDR,(PinID*2)+1);
				#else
				#endif
			break;

			case PORTC:
				SET_BIT(PORTC_MODE_MODER,PinID*2);
				CLR_BIT(PORTC_MODE_MODER,((PinID*2)+1));
				switch(Mode)
				{
					case OPEN_DRAIN:
							SET_BIT(PORTC_MODE_OTYPER,PinID);
					break;

					case OUTPUT_PULL_UP:
							CLR_BIT(PORTC_MODE_OTYPER,PinID);
							CLR_BIT(PORTC_MODE_PUPDR,PinID*2);
							SET_BIT(PORTC_MODE_PUPDR,((PinID*2)+1));
					break;
					case OUTPUT_PULL_DOWN:
							CLR_BIT(PORTC_MODE_OTYPER,PinID);
							CLR_BIT(PORTC_MODE_PUPDR,PinID*2);
							SET_BIT(PORTC_MODE_PUPDR,((PinID*2)+1));
					break;
					case OUTPUT_NORMAL:
							CLR_BIT(PORTC_MODE_OTYPER,PinID);
							CLR_BIT(PORTC_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTC_MODE_PUPDR,((PinID*2)+1));
					break;
				}
				#if SPEED_MODE==LOW_SPEED
				CLR_BIT(PORTC_MODE_OSPEEDR,PinID*2);
				CLR_BIT(PORTC_MODE_OSPEEDR,((PinID*2)+1));
				#elif SPEED_MODE==MEDIUM_SPEED
				SET_BIT(PORTC_MODE_OSPEEDR,PinID*2);
				CLR_BIT(PORTC_MODE_OSPEEDR,(PinID*2)+1);
				#elif SPEED_MODE==HIGH_SPEED
				SET_BIT(PORTC_MODE_OSPEEDR,PinID*2);
				SET_BIT(PORTC_MODE_OSPEEDR,(PinID*2)+1);
				#else
				#endif
			break;

			case PORTD:
				SET_BIT(PORTD_MODE_MODER,PinID*2);
				CLR_BIT(PORTD_MODE_MODER,((PinID*2)+1));
				switch(Mode)
				{
					case OPEN_DRAIN:
							SET_BIT(PORTD_MODE_OTYPER,PinID);
					break;

					case OUTPUT_PULL_UP:
							CLR_BIT(PORTD_MODE_OTYPER,PinID);
							CLR_BIT(PORTD_MODE_PUPDR,PinID*2);
							SET_BIT(PORTD_MODE_PUPDR,((PinID*2)+1));
					break;
					case OUTPUT_PULL_DOWN:
							CLR_BIT(PORTD_MODE_OTYPER,PinID);
							CLR_BIT(PORTD_MODE_PUPDR,PinID*2);
							SET_BIT(PORTD_MODE_PUPDR,((PinID*2)+1));
					break;
					case OUTPUT_NORMAL:
							CLR_BIT(PORTD_MODE_OTYPER,PinID);
							CLR_BIT(PORTD_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTD_MODE_PUPDR,((PinID*2)+1));
					break;
				}
				#if SPEED_MODE==LOW_SPEED
				CLR_BIT(PORTD_MODE_OSPEEDR,PinID*2);
				CLR_BIT(PORTD_MODE_OSPEEDR,((PinID*2)+1));
				#elif SPEED_MODE==MEDIUM_SPEED
				SET_BIT(PORTD_MODE_OSPEEDR,PinID*2);
				CLR_BIT(PORTD_MODE_OSPEEDR,(PinID*2)+1);
				#elif SPEED_MODE==HIGH_SPEED
				SET_BIT(PORTD_MODE_OSPEEDR,PinID*2);
				SET_BIT(PORTD_MODE_OSPEEDR,(PinID*2)+1);
				#else
				#endif
			break;

			case PORTF:
				SET_BIT(PORTF_MODE_MODER,PinID*2);
				CLR_BIT(PORTF_MODE_MODER,((PinID*2)+1));
				switch(Mode)
				{
					case OPEN_DRAIN:
							SET_BIT(PORTF_MODE_OTYPER,PinID);
					break;

					case OUTPUT_PULL_UP:
							CLR_BIT(PORTF_MODE_OTYPER,PinID);
							CLR_BIT(PORTF_MODE_PUPDR,PinID*2);
							SET_BIT(PORTF_MODE_PUPDR,((PinID*2)+1));
					break;
					case OUTPUT_PULL_DOWN:
							CLR_BIT(PORTF_MODE_OTYPER,PinID);
							CLR_BIT(PORTF_MODE_PUPDR,PinID*2);
							SET_BIT(PORTF_MODE_PUPDR,((PinID*2)+1));
					break;
					case OUTPUT_NORMAL:
							CLR_BIT(PORTF_MODE_OTYPER,PinID);
							CLR_BIT(PORTF_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTF_MODE_PUPDR,((PinID*2)+1));
					break;
				}
				#if SPEED_MODE==LOW_SPEED
				CLR_BIT(PORTF_MODE_OSPEEDR,PinID*2);
				CLR_BIT(PORTF_MODE_OSPEEDR,((PinID*2)+1));
				#elif SPEED_MODE==MEDIUM_SPEED
				SET_BIT(PORTF_MODE_OSPEEDR,PinID*2);
				CLR_BIT(PORTF_MODE_OSPEEDR,(PinID*2)+1);
				#elif SPEED_MODE==HIGH_SPEED
				SET_BIT(PORTF_MODE_OSPEEDR,PinID*2);
				SET_BIT(PORTF_MODE_OSPEEDR,(PinID*2)+1);
				#else
				#endif
			break;
			}
		break;
		case INPUTMODE:
			switch(PortID)
			{
				case PORTA:
				CLR_BIT(PORTA_MODE_MODER,PinID*2);
				CLR_BIT(PORTA_MODE_MODER,((PinID*2)+1));
				switch(Mode)
				{
					case INPUT_PULLDOWN:
							CLR_BIT(PORTA_MODE_PUPDR,PinID*2);
							SET_BIT(PORTA_MODE_PUPDR,((PinID*2)+1));
					break;
					case INPUT_FLOATING:
						CLR_BIT(PORTA_MODE_PUPDR,PinID*2);
						CLR_BIT(PORTA_MODE_PUPDR,((PinID*2)+1));
						break;
					case INPUT_PULLUP:
						SET_BIT(PORTA_MODE_PUPDR,PinID*2);
						CLR_BIT(PORTA_MODE_PUPDR,((PinID*2)+1));
					break;
				}
				break;
				case PORTB:
					CLR_BIT(PORTB_MODE_MODER,PinID*2);
					CLR_BIT(PORTB_MODE_MODER,((PinID*2)+1));
					switch(Mode)
					{
						case INPUT_PULLDOWN:
							CLR_BIT(PORTB_MODE_PUPDR,PinID*2);
							SET_BIT(PORTB_MODE_PUPDR,((PinID*2)+1));
						break;

						case INPUT_FLOATING:
							CLR_BIT(PORTB_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTB_MODE_PUPDR,((PinID*2)+1));
						break;

						case INPUT_PULLUP:
							SET_BIT(PORTB_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTB_MODE_PUPDR,((PinID*2)+1));
						break;
					}
				break;
				case PORTC:
					CLR_BIT(PORTC_MODE_MODER,PinID*2);
					CLR_BIT(PORTC_MODE_MODER,((PinID*2)+1));
					switch(Mode)
					{
						case INPUT_PULLDOWN:
							CLR_BIT(PORTC_MODE_PUPDR,PinID*2);
							SET_BIT(PORTC_MODE_PUPDR,((PinID*2)+1));
						break;
						case INPUT_FLOATING:
							CLR_BIT(PORTC_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTC_MODE_PUPDR,((PinID*2)+1));
						break;
						case INPUT_PULLUP:
							SET_BIT(PORTC_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTC_MODE_PUPDR,((PinID*2)+1));
						break;
					}
				break;
				case PORTD:
					CLR_BIT(PORTD_MODE_MODER,PinID*2);
					CLR_BIT(PORTD_MODE_MODER,((PinID*2)+1));
					switch(Mode)
					{
						case INPUT_PULLDOWN:
							CLR_BIT(PORTD_MODE_PUPDR,PinID*2);
							SET_BIT(PORTD_MODE_PUPDR,((PinID*2)+1));
						break;
						case INPUT_FLOATING:
							CLR_BIT(PORTD_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTD_MODE_PUPDR,((PinID*2)+1));
						break;
						case INPUT_PULLUP:
							SET_BIT(PORTD_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTD_MODE_PUPDR,((PinID*2)+1));
						break;
					}
				break;
				case PORTF:
					CLR_BIT(PORTF_MODE_MODER,PinID*2);
					CLR_BIT(PORTF_MODE_MODER,((PinID*2)+1));
					switch(Mode)
					{
						case INPUT_PULLDOWN:
							CLR_BIT(PORTF_MODE_PUPDR,PinID*2);
							SET_BIT(PORTF_MODE_PUPDR,((PinID*2)+1));
						break;

						case INPUT_FLOATING:
							CLR_BIT(PORTF_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTF_MODE_PUPDR,((PinID*2)+1));
						break;

						case INPUT_PULLUP:
							SET_BIT(PORTF_MODE_PUPDR,PinID*2);
							CLR_BIT(PORTF_MODE_PUPDR,((PinID*2)+1));
						break;
					}
				break;
				}
		break;
		case ALTFUN:
			switch(PortID)
			{
				case PORTA:
					CLR_BIT(PORTA_MODE_MODER,PinID*2);
					SET_BIT(PORTA_MODE_MODER,((PinID*2)+1));
				break;
				case PORTB:
					CLR_BIT(PORTB_MODE_MODER,PinID*2);
					SET_BIT(PORTB_MODE_MODER,((PinID*2)+1));
				break;
				case PORTC:
					CLR_BIT(PORTC_MODE_MODER,PinID*2);
					SET_BIT(PORTC_MODE_MODER,((PinID*2)+1));
				break;
				case PORTD:
					CLR_BIT(PORTD_MODE_MODER,PinID*2);
					SET_BIT(PORTD_MODE_MODER,((PinID*2)+1));
				break;
				case PORTF:
					CLR_BIT(PORTF_MODE_MODER,PinID*2);
					SET_BIT(PORTF_MODE_MODER,((PinID*2)+1));
				break;
			}
		break;
		case ANALOGMODE:
			switch(PortID)
			{
				case PORTA:
					SET_BIT(PORTA_MODE_MODER,PinID*2);
					SET_BIT(PORTA_MODE_MODER,((PinID*2)+1));
					break;
				case PORTB:
					SET_BIT(PORTB_MODE_MODER,PinID*2);
					SET_BIT(PORTB_MODE_MODER,((PinID*2)+1));
					break;
				case PORTC:
					SET_BIT(PORTC_MODE_MODER,PinID*2);
					SET_BIT(PORTC_MODE_MODER,((PinID*2)+1));
					break;
				case PORTD:
					SET_BIT(PORTD_MODE_MODER,PinID*2);
					SET_BIT(PORTD_MODE_MODER,((PinID*2)+1));
					break;
				case PORTF:
					SET_BIT(PORTF_MODE_MODER,PinID*2);
					SET_BIT(PORTF_MODE_MODER,((PinID*2)+1));
					break;
			}
		break;
	}
}

void DIO_voidSetPinValue(u8 PortID,u8 PinID,u8 value)
{
	switch(value)
		{
			case GPIO_PIN_HIGH :

			switch(PortID)
			{
				case PORTA:
				SET_BIT(PORTA_MODE_ODR , PinID);
				break;
				case PORTB:
				SET_BIT(PORTB_MODE_ODR , PinID);
				break;
				case PORTC:
				SET_BIT(PORTC_MODE_ODR , PinID);
				break;
				case PORTD:
				SET_BIT(PORTD_MODE_ODR , PinID);
				break;
				case PORTF:
				SET_BIT(PORTF_MODE_ODR , PinID);
				break;
				default:
				break;

			}


			break;

			case GPIO_PIN_LOW:

				switch(PortID)
				{
					case PORTA:
					CLR_BIT(PORTA_MODE_ODR , PinID);
					break;
					case PORTB:
					CLR_BIT(PORTB_MODE_ODR , PinID);
					break;
					case PORTC:
					CLR_BIT(PORTC_MODE_ODR , PinID);
					break;
					case PORTD:
					CLR_BIT(PORTD_MODE_ODR , PinID);
					break;
					case PORTF:
					CLR_BIT(PORTF_MODE_ODR , PinID);
					break;
					default:
					break;

				}

			break;

			default:
			break;
		}
}


u8	 DIO_u8GetPinValue(u8 PortID,u8 PinID){

	switch(PortID){
			case PORTA :
			return GET_BIT(PORTA_MODE_IDR,PinID);
			break;

			case PORTB :
			return GET_BIT(PORTB_MODE_IDR,PinID);
			break;

			case PORTC :
			return GET_BIT(PORTC_MODE_IDR,PinID);
			break;

			case PORTD :
			return GET_BIT(PORTD_MODE_IDR,PinID);
			break;

			case PORTF :
			return GET_BIT(PORTF_MODE_IDR,PinID);
			break;

			default:
			break;

		}
return 0;
}
