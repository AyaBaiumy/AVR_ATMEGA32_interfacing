/*
 * NVIC_prog.c
 *
 *  Created on: Aug 13, 2023
 *      Author: AyaBaiumy
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "NVIC_priv.h"
#include "NVIC_int.h"
#include "NVIC_config.h"

//void NVIC_voidInit(void)
//{
//#ifndef SCB_AIRCR
//#define SCB_AIRCR		(*((volatile u32 *)(0xE000ED0C)))
//#endif
//
//	SCB_AIRCR = NUM_OF_GRP_SUB; //configuration b #define fel private for example GRP_4_SUB_4
//	//0x05FA0500
//	//fel private #define NVIC_IPR0 ((volatile u8)(address))
//	// NVIC_IPR		((volatile u8 *)address)
//}


//#define NVIC_BASE_ADDRESS 0xE000E100
// NVIC initialization function
void NVIC_Init(void)
{
	SCB_AIRCR = NUM_OF_GRP_SUB;
    // Implement your code to initialize NVIC
    // This may involve configuring the interrupt priority grouping, enabling interrupts, etc.
}

// Enable an interrupt
void NVIC_EnableIRQ(u8 InterruptNum)
{
    if (InterruptNum >= 0 && InterruptNum <= 239)
    {
    	u8 reg_index = InterruptNum / 32;
    	u8 reg_offset = InterruptNum % 32;

        volatile u8 *isr_reg = (volatile u8 *)(NVIC_ISER_BASE + (reg_index * 4));
        *isr_reg = (1 << reg_offset);
    }
}

// Disable an interrupt
void NVIC_DisableIRQ(u8 InterruptNum)
{
    if (InterruptNum >= 0 && InterruptNum <= 239)
    {
    	u8 reg_index = InterruptNum / 32;
    	u8 reg_offset = InterruptNum % 32;

        volatile u8 *icer_reg = (volatile u8 *)(NVIC_ICER_BASE + (reg_index * 4));
        *icer_reg = (1 << reg_offset);
    }
}

// Set the priority of an interrupt
void NVIC_SetPriority(u8 InterruptNum, u8 priority)
{
    if (InterruptNum >= 0 && InterruptNum <= 239)
    {
    	u8 reg_index = InterruptNum / 4;
    	u8 reg_offset = (InterruptNum % 4) * 8;

        volatile u8 *ipr_reg = (volatile u8 *)(NVIC_IPR_BASE + (reg_index * 4));
        *ipr_reg = (*ipr_reg & ~(0xFF << reg_offset)) | (priority << reg_offset);
    }
}

// Set the pending status of an interrupt
void NVIC_SetPendingIRQ(u8 InterruptNum)
{
    if (InterruptNum >= 0 && InterruptNum <= 239)
    {
    	u8 reg_index = InterruptNum / 32;
    	u8 reg_offset = InterruptNum % 32;

        volatile u8 *ispr_reg = (volatile u8 *)(NVIC_ISPR_BASE + (reg_index * 4));
        *ispr_reg = (1 << reg_offset);
    }
}

// Clear the pending status of an interrupt
void NVIC_ClearPendingIRQ(u8 InterruptNum)
{
    if (InterruptNum >= 0 && InterruptNum <= 239)
    {
    	u8 reg_index = InterruptNum / 32;
    	u8 reg_offset = InterruptNum % 32;

        volatile u8 *icpr_reg = (volatile u8 *)(NVIC_ICPR_BASE + (reg_index * 4));
        *icpr_reg = (1 << reg_offset);
    }
}
//void NVIC_voidEnabeInterrupt(u8 InterruptNum)
//{
//	if(InterruptNum < 32)
//	{
//		NVIC_ISER0 = 1 << InterruptNum;
//	}else if(InterruptNum < 64)
//	{
//		InterruptNum -= 32;
//		NVIC_ISER1 = 1 << InterruptNum;
//	}
//}
//void NVIC_voidDisableInterrupt(u8 InterruptNum)
//{
//	if(InterruptNum < 32)
//	{
//		NVIC_ICER0 = 1 << InterruptNum;
//	}else if(InterruptNum < 64)
//	{
//		InterruptNum -= 32;
//		NVIC_ICER1 = 1 << InterruptNum;
//	}
//}
//
//void NVIC_voidSetPendingFlag(u8 InterruptNum)
//{
//	if(InterruptNum < 32)
//	{
//		NVIC_ISPR0 = 1 << InterruptNum;
//	}else if(InterruptNum < 64)
//	{
//		InterruptNum -= 32;
//		NVIC_ISPR1 = 1 << InterruptNum;
//	}
//}
//void NVIC_voidClrPendingFlag(u8 InterruptNum)
//{
//	if(InterruptNum < 32)
//	{
//		NVIC_ICPR0 = 1 << InterruptNum;
//	}else if(InterruptNum < 64)
//	{
//		InterruptNum -= 32;
//		NVIC_ICPR1 = 1 << InterruptNum;
//	}
//}
//
u8 NVIC_u8ReadActiveFlag(u8 InterruptNum)
{
	u8 Local_u8Acive = 0;
	if(InterruptNum < 32)
	{
		Local_u8Acive = GET_BIT(NVIC_IABR0,InterruptNum);
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		Local_u8Acive = GET_BIT(NVIC_IABR1,InterruptNum);
	}
	return Local_u8Acive;
}
//
//void NVIC_voidSetPriority(u8 InterruptNum,u8 priority)
//{
//	NVIC_IPR[InterruptNum] = (priority << 4);
//}

