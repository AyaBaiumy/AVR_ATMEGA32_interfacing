/****************************
 * SEV_SEG.h			
 *							
 *  Created on: Jul 23, 2023	
 *      Author: AyaBaiumy	
 ****************************/

#include "Std_types.h"
#include "Bit_Math.h"

#ifndef DRIVERS_HAL_SEVEN_SEGMENT_SEV_SEG_H_
#define DRIVERS_HAL_SEVEN_SEGMENT_SEV_SEG_H_


void SEV_SEG_Initialization(void);

void SEV_SEG_Write_Number(u8 number);

void SEV_SEG_Display_Number(u16 number);

void SEV_SEG_Enable(u8 value);

void SEV_SEG_Disable(u8 value);

void SEV_SEG_APP(void);
#endif /* DRIVERS_HAL_SEVEN_SEGMENT_SEV_SEG_H_ */

