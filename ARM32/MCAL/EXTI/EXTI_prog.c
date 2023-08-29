/*
 * EXTI_prog.c
 *
 *  Created on: Aug 17, 2023
 *      Author: AyaBaiumy
 */
#include "Std_types.h"
#include "Bit_Math.h"

#include "GPIO_int.h"
#include "RCC_int.h"

#include "EXTI_int.h"
#include "EXTI_priv.h"

// EXTI initialization function
void EXTI_VoidInit(void)
{
	// Configure EXTI
	volatile u16 *exti_imr_reg =  (volatile u16 *)(EXTI_BASE + EXTI_IMR_OFFSET);
	*exti_imr_reg = EXTI_IMR_VALUE;

	volatile u16 *exti_rtsr_reg = (volatile u16 *)(EXTI_BASE + EXTI_RTSR_OFFSET);
	*exti_rtsr_reg = EXTI_RTSR_VALUE;

	volatile u16 *exti_ftsr_reg = (volatile u16 *)(EXTI_BASE + EXTI_FTSR_OFFSET);
	*exti_ftsr_reg = EXTI_FTSR_VALUE;
}

// Enable EXTI interrupt for a specific line
void EXTI_VoidEnableInterrupt(u8 line)
{
	if (line >= 0 && line <= 15)
	{
		volatile u8 *imr_reg = (volatile u8 *)(EXTI_BASE + EXTI_IMR_OFFSET);
		*imr_reg |= (1 << line);
	}
}

// Disable EXTI interrupt for a specific line
void EXTI_VoidDisableInterrupt(u8 line)
{
	if (line >= 0 && line <= 15)
	{
		volatile u8 *imr_reg = (volatile u8 *)(EXTI_BASE + EXTI_IMR_OFFSET);
		*imr_reg &= ~(1 << line);
	}
}

// Set the trigger type for a specific line
void EXTI_VoidSetTrigger(u8 line, u8 trigger)
{
	if (line >= 0 && line <= 15)
	{
		volatile u8 *rtsr_reg = (volatile u8 *)(EXTI_BASE + EXTI_RTSR_OFFSET);
		volatile u8 *ftsr_reg = (volatile u8 *)(EXTI_BASE + EXTI_FTSR_OFFSET);

		if (trigger == EXTI_TRIGGER_RISING)
		{
			*rtsr_reg |= (1 << line);
			*ftsr_reg &= ~(1 << line);
		}
		else if (trigger == EXTI_TRIGGER_FALLING)
		{
			*rtsr_reg &= ~(1 << line);
			*ftsr_reg |= (1 << line);
		}
		else if (trigger == EXTI_TRIGGER_BOTH)
		{
			*rtsr_reg |= (1 << line);
			*ftsr_reg |= (1 << line);
		}
	}
}

// Clear the pending status for a specific line
void EXTI_VoidClearPending(u8 line)
{
	if (line >= 0 && line <= 15)
	{
		volatile u8 *pr_reg = (volatile u8 *)(EXTI_BASE + EXTI_PR_OFFSET);
		*pr_reg = (1 << line);
	}
}
