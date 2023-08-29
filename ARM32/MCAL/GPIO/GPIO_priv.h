/*
 * GPIO_priv.h
 *
 *  Created on: Aug 11, 2023
 *      Author: AyaBaiumy
 */

#ifndef GPIO_GPIO_PRIV_H_
#define GPIO_GPIO_PRIV_H_

#define PORTA_MODE			(0x48000000)
#define	PORTA_MODE_MODER	*((volatile u32 *)(PORTA_MODE + 0x00))
#define	PORTA_MODE_OTYPER	*((volatile u32 *)(PORTA_MODE + 0x04))
#define	PORTA_MODE_OSPEEDR	*((volatile u32 *)(PORTA_MODE + 0x08))
#define	PORTA_MODE_PUPDR	*((volatile u32 *)(PORTA_MODE + 0x0C))
#define	PORTA_MODE_IDR		*((volatile u32 *)(PORTA_MODE + 0x10))
#define	PORTA_MODE_ODR		*((volatile u32 *)(PORTA_MODE + 0x14))

#define PORTB_MODE			(0x48000400)
#define	PORTB_MODE_MODER	*((volatile u32 *)(PORTB_MODE + 0x00))
#define	PORTB_MODE_OTYPER	*((volatile u32 *)(PORTB_MODE + 0x04))
#define	PORTB_MODE_OSPEEDR	*((volatile u32 *)(PORTB_MODE + 0x08))
#define	PORTB_MODE_PUPDR	*((volatile u32 *)(PORTB_MODE + 0x0C))
#define	PORTB_MODE_IDR		*((volatile u32 *)(PORTB_MODE + 0x10))
#define	PORTB_MODE_ODR		*((volatile u32 *)(PORTB_MODE + 0x14))

#define PORTC_MODE			(0x48000800)
#define	PORTC_MODE_MODER	*((volatile u32 *)(PORTC_MODE + 0x00))
#define	PORTC_MODE_OTYPER	*((volatile u32 *)(PORTC_MODE + 0x04))
#define	PORTC_MODE_OSPEEDR	*((volatile u32 *)(PORTC_MODE + 0x08))
#define	PORTC_MODE_PUPDR	*((volatile u32 *)(PORTC_MODE + 0x0C))
#define	PORTC_MODE_IDR		*((volatile u32 *)(PORTC_MODE + 0x10))
#define	PORTC_MODE_ODR		*((volatile u32 *)(PORTC_MODE + 0x14))

#define PORTD_MODE			(0x48000C00)
#define	PORTD_MODE_MODER	*((volatile u32 *)(PORTD_MODE + 0x00))
#define	PORTD_MODE_OTYPER	*((volatile u32 *)(PORTD_MODE + 0x04))
#define	PORTD_MODE_OSPEEDR	*((volatile u32 *)(PORTD_MODE + 0x08))
#define	PORTD_MODE_PUPDR	*((volatile u32 *)(PORTD_MODE + 0x0C))
#define	PORTD_MODE_IDR		*((volatile u32 *)(PORTD_MODE + 0x10))
#define	PORTD_MODE_ODR		*((volatile u32 *)(PORTD_MODE + 0x14))

#define PORTF_MODE			(0x48001400)
#define	PORTF_MODE_MODER	*((volatile u32 *)(PORTF_MODE + 0x00))
#define	PORTF_MODE_OTYPER	*((volatile u32 *)(PORTF_MODE + 0x04))
#define	PORTF_MODE_OSPEEDR	*((volatile u32 *)(PORTF_MODE + 0x08))
#define	PORTF_MODE_PUPDR	*((volatile u32 *)(PORTF_MODE + 0x0C))
#define	PORTF_MODE_IDR		*((volatile u32 *)(PORTF_MODE + 0x10))
#define	PORTF_MODE_ODR		*((volatile u32 *)(PORTF_MODE + 0x14))

#endif /* GPIO_GPIO_PRIV_H_ */
