/*
 * NVIC_priv.h
 *
 *  Created on: Aug 13, 2023
 *      Author: AyaBaiumy
 */

#ifndef NVIC_NVIC_PRIV_H_
#define NVIC_NVIC_PRIV_H_

//#define NVIC				(0xE000E100)
//#define	NVIC_ISER0			*((volatile u32 *)(NVIC + 0x100))
//#define	NVIC_ISER1			*((volatile u32 *)(NVIC + 0x104))
//#define	NVIC_ISER7			*((volatile u32 *)(NVIC + 0x11C))
//#define	NVIC_ICER0			*((volatile u32 *)(NVIC + 0x180))
//#define	NVIC_ICER1			*((volatile u32 *)(NVIC + 0x184))
//#define	NVIC_ICER7			*((volatile u32 *)(NVIC + 0x19C))
//
//#define	NVIC_ISPR0			*((volatile u32 *)(NVIC + 0x200))
//#define	NVIC_ISPR1			*((volatile u32 *)(NVIC + 0x204))
//#define	NVIC_ISPR7			*((volatile u32 *)(NVIC + 0x21C))
//#define	NVIC_ICPR0			*((volatile u32 *)(NVIC + 0x280))
//#define	NVIC_ICPR1			*((volatile u32 *)(NVIC + 0x284))
//#define	NVIC_ICPR7			*((volatile u32 *)(NVIC + 0x29C))
//

// NVIC base addresses
#define NVIC_BASE_ADDRESS 0xE000E100
#define NVIC_ISER_BASE    (NVIC_BASE_ADDRESS + 0x000)
#define NVIC_ICER_BASE    (NVIC_BASE_ADDRESS + 0x080)
#define NVIC_ISPR_BASE    (NVIC_BASE_ADDRESS + 0x100)
#define NVIC_ICPR_BASE    (NVIC_BASE_ADDRESS + 0x180)
#define NVIC_IPR_BASE     (NVIC_BASE_ADDRESS + 0x300)
#define SCB_AIRCR		(*((volatile u32 *)(0xE000ED0C)))

#define	NVIC_IABR0			*((volatile u32 *)(NVIC_BASE_ADDRESS + 0x200))
#define	NVIC_IABR1			*((volatile u32 *)(NVIC_BASE_ADDRESS + 0x204))
#define	NVIC_IABR7			*((volatile u32 *)(NVIC_BASE_ADDRESS + 0x21C))
//#define	NVIC_IPR0			*((volatile u32 *)(NVIC + 0x400))
//#define	NVIC_IPR1			*((volatile u32 *)(NVIC + 0x404))
//#define	NVIC_IPR59			*((volatile u32 *)(NVIC + 0x4EC))
//
//
//#define  GROUP_16_SUBBRIORITY_0      0x05FA0300      //4 Bit For Group And 0 Bit For SubPriority
//#define  GROUP_8_SUBBRIORITY_2       0x05FA0400      //3 Bit For Group And 1 Bit For SubPriority
//#define  GROUP_4_SUBBRIORITY_4       0x05FA0500      //2 Bit For Group And 2 Bit For SubPriority
//#define  GROUP_2_SUBBRIORITY_8       0x05FA0600      //1 Bit For Group And 3 Bit For SubPriority
//#define  GROUP_0_SUBBRIORITY_16      0x05FA0700     //0 Bit For Group And 4 Bit For SubPriority
//
//#define NVIC_IPR		((volatile u8 *)0xE000E400)
//#define SCB_AIRCR		*((volatile u32 *)0xE000ED00+0x0C)




#endif /* NVIC_NVIC_PRIV_H_ */
