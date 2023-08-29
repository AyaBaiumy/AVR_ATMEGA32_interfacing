/*
 * EXTI_priv.h
 *
 *  Created on: Aug 17, 2023
 *      Author: AyaBaiumy
 */

#ifndef EXTI_EXTI_PRIV_H_
#define EXTI_EXTI_PRIV_H_

// EXTI base address
#define EXTI_BASE 0x40013C00

// EXTI register offsets
#define EXTI_IMR_OFFSET  0x00
#define EXTI_RTSR_OFFSET 0x08
#define EXTI_FTSR_OFFSET 0x0C
#define EXTI_PR_OFFSET   0x14

// Register values
#define EXTI_IMR_VALUE 	0x0000FFFF
#define EXTI_RTSR_VALUE 0x00000000
#define EXTI_FTSR_VALUE 0x00000000

// EXTI trigger types
#define EXTI_TRIGGER_RISING  0
#define EXTI_TRIGGER_FALLING 1
#define EXTI_TRIGGER_BOTH    2


#endif /* EXTI_EXTI_PRIV_H_ */
