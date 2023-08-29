/*
 * EXTI_int.h
 *
 *  Created on: Aug 17, 2023
 *      Author: AyaBaiumy
 */

#ifndef EXTI_EXTI_INT_H_
#define EXTI_EXTI_INT_H_

// Function to initialize EXTI
void EXTI_VoidInit(void);

// Function to enable EXTI interrupt for a specific line
void EXTI_VoidEnableInterrupt(u8 line);

// Function to disable EXTI interrupt for a specific line
void EXTI_VoidDisableInterrupt(u8 line);

// Function to set the trigger type for a specific line
void EXTI_VoidSetTrigger(u8 line, u8 trigger);

// Function to clear the pending status for a specific line
void EXTI_VoidClearPending(u8 line);


#endif /* EXTI_EXTI_INT_H_ */
