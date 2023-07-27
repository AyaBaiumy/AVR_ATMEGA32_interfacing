/****************************
 * SEV_SEG_APP.c			
 *							
 *  Created on: Jul 23, 2023	
 *      Author: AyaBaiumy	
 ****************************/


#include "DIO_interface.h"
#include <avr/delay.h>

void SEV_SEG_APP()
{
	SEV_SEG_Initialization();

	SEV_SEG_Enable(1);


	//SEV_SEG_Write_Number(5);
	_delay_ms(3000);

	SEV_SEG_Display_Number(123);
}
