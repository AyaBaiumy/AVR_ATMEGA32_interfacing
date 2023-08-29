/*
 * RCC_prog.c
 *
 *  Created on: Aug 11, 2023
 *      Author: AyaBaiumy
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "RCC_int.h"
#include "RCC_priv.h"
#include "RCC_config.h"

void	RCC_voidSysClkInit(void) //RCC_CR , RCC_CFGR
	   // RCC_voidPerClkEn(RCC_AHB1, 17);
{
//	SET_BIT(RCC_CR,0);
		#if 	CLOCK_TYPE == HSI
		/* internal 8 MHZ RC oscillator 			*/
		/*	HSI clock enable						*/
				SET_BIT(RCC_CR , 0 );
				/*HSI selected as system clock		*/
				CLR_BIT(RCC_CFGR , 0 );
				CLR_BIT(RCC_CFGR , 1 );

				/*	HSI Ready Flag					*/
				while(!GET_BIT(RCC_CR , 1 ) );

		#elif	CLOCK_TYPE == HSE
				/*	HSE clock enable				*/
				SET_BIT(RCC_CR , 16 );

				/*HSE selected as system clock		*/
				SET_BIT(RCC_CFGR , 0 );
				CLR_BIT(RCC_CFGR , 1 );

				/*	HSE Ready Flag					*/
				while(!GET_BIT(RCC_CR , 17 ) );

		#elif	CLOCK_TYPE == PLL
			/*	The PLL output frequency must not exceed 72 MHz */
				/*PLL selected as system clock		*/
				CLR_BIT(RCC_CFGR , 0 );
				SET_BIT(RCC_CFGR , 1 );

				/*PLL multiplication factor*/
				#if CLOCK_FACTOR == MULTIPLY_BY_2
				CLR_BIT(RCC_CFGR , 18 );
				CLR_BIT(RCC_CFGR , 19 );
				CLR_BIT(RCC_CFGR , 20 );
				CLR_BIT(RCC_CFGR , 21 );

				#elif CLOCK_FACTOR == MULTIPLY_BY_3
				SET_BIT(RCC_CFGR , 18 );
				CLR_BIT(RCC_CFGR , 19 );
				CLR_BIT(RCC_CFGR , 20 );
				CLR_BIT(RCC_CFGR , 21 );

				#elif CLOCK_FACTOR == MULTIPLY_BY_4
				CLR_BIT(RCC_CFGR , 18 );
				SET_BIT(RCC_CFGR , 19 );
				CLR_BIT(RCC_CFGR , 20 );
				CLR_BIT(RCC_CFGR , 21 );


				#elif CLOCK_FACTOR == MULTIPLY_BY_5
				SET_BIT(RCC_CFGR , 18 );
				SET_BIT(RCC_CFGR , 19 );
				CLR_BIT(RCC_CFGR , 20 );
				CLR_BIT(RCC_CFGR , 21 );


				#elif CLOCK_FACTOR == MULTIPLY_BY_6
				CLR_BIT(RCC_CFGR , 18 );
				CLR_BIT(RCC_CFGR , 19 );
				SET_BIT(RCC_CFGR , 20 );
				CLR_BIT(RCC_CFGR , 21 );


				#elif CLOCK_FACTOR == MULTIPLY_BY_7
				SET_BIT(RCC_CFGR , 18 );
				CLR_BIT(RCC_CFGR , 19 );
				SET_BIT(RCC_CFGR , 20 );
				CLR_BIT(RCC_CFGR , 21 );

				#elif CLOCK_FACTOR == MULTIPLY_BY_8
				CLR_BIT(RCC_CFGR , 18 );
				SET_BIT(RCC_CFGR , 19 );
				SET_BIT(RCC_CFGR , 20 );
				CLR_BIT(RCC_CFGR , 21 );

				#elif CLOCK_FACTOR == MULTIPLY_BY_9
				SET_BIT(RCC_CFGR , 18 );
				SET_BIT(RCC_CFGR , 19 );
				SET_BIT(RCC_CFGR , 20 );
				CLR_BIT(RCC_CFGR , 21 );

				#elif CLOCK_FACTOR == MULTIPLY_BY_10
				CLR_BIT(RCC_CFGR , 18 );
				CLR_BIT(RCC_CFGR , 19 );
				CLR_BIT(RCC_CFGR , 20 );
				SET_BIT(RCC_CFGR , 21 );

				#elif CLOCK_FACTOR == MULTIPLY_BY_11
				SET_BIT(RCC_CFGR , 18 );
				CLR_BIT(RCC_CFGR , 19 );
				CLR_BIT(RCC_CFGR , 20 );
				SET_BIT(RCC_CFGR , 21 );


				#elif CLOCK_FACTOR == MULTIPLY_BY_12
				CLR_BIT(RCC_CFGR , 18 );
				SET_BIT(RCC_CFGR , 19 );
				CLR_BIT(RCC_CFGR , 20 );
				SET_BIT(RCC_CFGR , 21 );

				#elif CLOCK_FACTOR == MULTIPLY_BY_13
				SET_BIT(RCC_CFGR , 18 );
				SET_BIT(RCC_CFGR , 19 );
				CLR_BIT(RCC_CFGR , 20 );
				SET_BIT(RCC_CFGR , 21 );

				#elif CLOCK_FACTOR == MULTIPLY_BY_14
				CLR_BIT(RCC_CFGR , 18 );
				CLR_BIT(RCC_CFGR , 19 );
				SET_BIT(RCC_CFGR , 20 );
				SET_BIT(RCC_CFGR , 21 );

				#elif CLOCK_FACTOR == MULTIPLY_BY_15
				SET_BIT(RCC_CFGR , 18 );
				CLR_BIT(RCC_CFGR , 19 );
				SET_BIT(RCC_CFGR , 20 );
				SET_BIT(RCC_CFGR , 21 );

				#elif CLOCK_FACTOR == MULTIPLY_BY_16
				CLR_BIT(RCC_CFGR , 18 );
				SET_BIT(RCC_CFGR , 19 );
				SET_BIT(RCC_CFGR , 20 );
				SET_BIT(RCC_CFGR , 21 );

				#else

				#endif

						#if 	PLL_SOURCE	==	PLL_HSI_DIVIDED_BY_2
								/*PLL entry clock source is HSI divdided by 2		*/
								CLR_BIT(RCC_CFGR , 16 );
						#elif	PLL_SOURCE	==	PLL_HSE
								/*PLL entry clock source is HSE						*/
								SET_BIT(RCC_CFGR , 16 );
								/*HSE divider for PLL entry : clock not divided 	*/
								CLR_BIT(RCC_CFGR , 17 );
						#elif	PLL_SOURCE	==	PLL_HSE_DIVIDED_BY_2
								/*PLL entry clock source is HSE						*/
								SET_BIT(RCC_CFGR , 16 );
								/*HSE divider for PLL entry : clock divided		 	*/
								SET_BIT(RCC_CFGR , 17 );
						#endif

					/*	PLL clock enable				*/
//					SET_BIT(MRCC -> CR , 24 );
//					/*	PLL Ready Flag					*/
//					while(!GET_BIT( MRCC -> CR , 25 ) );
//
//			#elif	CLOCK_TYPE == HSEPYPASS
//					/*The HSEBYP bit can be written only if the HSE oscillator is disabled*/
//					/*	HSE clock Disable				*/
//					CLR_BIT(MRCC -> CR , 16 );
//
//					/*	HSEBYPASS clock Enable			*/
//					SET_BIT(MRCC -> CR , 18 );
//
//					/*HSE selected as system clock		*/
//					SET_BIT(MRCC -> CFGR , 0 );
//					CLR_BIT(MRCC -> CFGR , 1 );
//
//					/*	HSE clock Enable				*/
//					SET_BIT(MRCC -> CR , 16 );
//
//					/*	HSE Ready Flag					*/
//					while(!GET_BIT( MRCC -> CR , 17 ) );


			#else

			#endif
//			/*FOR Clock Security System				*/
//			#if		CLOCK_SECURITY_SYSTEM	==	OFF
//					CLR_BIT(MRCC -> CR , 19 );
//
//			#elif	CLOCK_SECURITY_SYSTEM	==	ON
//					SET_BIT(MRCC -> CR , 19 );
//			#else
//					#warning	"Wrong clock security system configuration choice!"
//			#endif
}
void	RCC_voidPerClkEn(u8 BusId, u8 PerId)
{
	switch( BusId )
	{
		case AHB  :	SET_BIT( RCC_AHBENR  ,  PerId ); break;
		case APB1 :	SET_BIT( RCC_APB1ENR ,  PerId ); break;
		case APB2 : SET_BIT( RCC_APB2ENR ,  PerId ); break;
		default	  :	;
	}
}
void	RCC_voidPerClkDis(u8 BusId, u8 PerId)
{
	switch( BusId )
	{
		case AHB  :	CLR_BIT( RCC_AHBENR  ,  PerId ); break;
		case APB1 :	CLR_BIT( RCC_APB1ENR ,  PerId ); break;
		case APB2 : CLR_BIT( RCC_APB2ENR ,  PerId ); break;
		default	  :	;
	}
}

void	RCC_voidPerClkRESET(u8 BusId, u8 PerId)
{
	switch( BusId )
	{
		case APB1 :	SET_BIT( RCC_APB1ENR ,  PerId ); break;
		case APB2 : SET_BIT( RCC_APB2ENR ,  PerId ); break;
		default	  :	;
	}
}
