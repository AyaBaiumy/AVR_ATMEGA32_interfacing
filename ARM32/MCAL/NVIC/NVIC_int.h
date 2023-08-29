/*
 * NVIC_int.h
 *
 *  Created on: Aug 13, 2023
 *      Author: AyaBaiumy
 */

#ifndef NVIC_NVIC_INT_H_
#define NVIC_NVIC_INT_H_

//#define NUM_OF_GRP_SUB		1

// Function to initialize NVIC
void NVIC_VoidInit(void);

// Function to enable an interrupt
void NVIC_VoidEnableIRQ(u8 InterruptNum);

// Function to disable an interrupt
void NVIC_VoidDisableIRQ(u8 InterruptNum);

// Function to set the priority of an interrupt
void NVIC_VoidSetPriority(u8 InterruptNum, u8 priority);

// Function to set the pending status of an interrupt
void NVIC_VoidSetPendingIRQ(u8 InterruptNum);

// Function to clear the pending status of an interrupt
void NVIC_VoidClearPendingIRQ(u8 InterruptNum);

u8 NVIC_u8ReadActiveFlag(u8 InterruptNum);



#define GRP_3			0x05FA0300
#define GRP_4			0x05FA0400
#define GRP_5			0x05FA0500
#define GRP_6			0x05FA0600
#define GRP_7			0x05FA0700

#endif /* NVIC_NVIC_INT_H_ */
