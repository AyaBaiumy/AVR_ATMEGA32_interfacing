#include "Std_types.h"
#include "Bit_Math.h"
#include "SYSTICK_priv.h"
#include "SYSTICK.h"
#include "SYSTICK_config.h"

systickcbf_t APPcbf ;
void SYSTICK_Init (void)
{
	#if SYSTICK_CLK_SRC == SYSTICK_CLK_AHB_DIV_8
		CLR_BIT(STK_CTRL,2);
	#elif SYSTICK_CLK_SRC == SYSTICK_CLK_AHB
		SET_BIT(STK_CTRL,2);
	#else
	#endif

	#if SYSTICK_TICK_INT == SYSTICK_TICK_INT_ENABLE
		SET_BIT(STK_CTRL,1);
	#elif SYSTICK_TICK_INT == SYSTICK_TICK_INT_DISABLE
		CLR_BIT(STK_CTRL,1);
	#else
	#endif
	// clk src and int enable
}
void SYSTICK_Start (void)
{
	SET_BIT(STK_CTRL,0);
	//systick enable
}
void SYSTICK_Stop (void)
{
	CLR_BIT(STK_CTRL,0);
	//systick disable
}
u8 SYSTICK_SetCallback (systickcbf_t cbf)
{
	//setcallback
	APPcbf = cbf;
	return 0;
}
void SYSTICK_SetTime (u32 times)
{
	// added value to systick load register based on equation 
	STK_LOAD = times;
}
void SysTick_Handler(void)
{
//	u8 Local_u8Temp;hh
//	if (STK_u8ModelOfInterval == STK_SINGLE_INTERVAL)
//	{
//		CLR_BIT(STK_CTRL , 1 );
//
//		CLR_BIT(STK_CTRL , 0 );
//
//		STK_LOAD = 0;
//		STK_VAL = 0;
//	}
	APPcbf();
//	Local_u8Temp = GET_BIT(STK_CTRL , 16 );
	// call function needed 
}
