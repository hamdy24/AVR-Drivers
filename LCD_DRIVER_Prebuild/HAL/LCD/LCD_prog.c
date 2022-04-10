/*
 * LCD_prog.c
 *
 *  Created on: Oct 13, 2021
 *      Author: hamdy
 */
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorstate.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LCD_config.h"
#include "LCD_priv.h"


#include <util/delay.h>

ES_T LCD_enuInit(void)
{
	u8 Local_ErrorState = ES_NOK;

	DIO_enuSetPinDirection(RS_PORT , RS_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(RW_PORT , RW_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(EN_PORT , EN_PIN , DIO_u8OUTPUT);

	DIO_enuSetPinDirection(D7_PORT , D7_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D6_PORT , D6_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D5_PORT , D5_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D4_PORT , D4_PIN , DIO_u8OUTPUT);

	_delay_ms(35); //power on
#if LCD_MODE == FOUR_BIT
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);
	LCD_enuWriteAndLatch(FUNC_SET_FOUR_BIT);

#elif LCD_MODE == EIGHT_BIT
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);
	LCD_enuWriteAndLatch(FUNC_SET_EIGHT_BIT);

	DIO_enuSetPinDirection(D3_PORT , D3_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_PORT , D2_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_PORT , D1_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_PORT , D0_PIN , DIO_u8OUTPUT);

#endif

	_delay_ms(1);
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);
	LCD_enuWriteAndLatch(DIS_ON__CURSOR_ON_BLINKING);

	_delay_ms(1);
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);
	LCD_enuWriteAndLatch(CLEAR_DISPLAY);

	_delay_ms(2);
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);
	LCD_enuWriteAndLatch(ENTRY_MOOD);

	return Local_ErrorState;
}

static ES_T LCD_enuWriteAndLatch(u8 Copy_u8Data)
{

	u8 Local_ErrorState = ES_NOK;

	/******* make sure RW_OORT low to be in write mode *****/
	/******* make sure EN_PORT low to be ready for the latch	*****/

	DIO_enuSetPinValue(RW_PORT , RW_PIN , DIO_u8LOW );  // low as we write
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW );  // low to be ready

				/********** Data Writing ************/

	if(Copy_u8Data == FUNC_SET_FOUR_BIT) // function set for four bit mode
	{
		u8 Local_u8RS_Value;
		DIO_enuGetPinValue(RS_PORT , RS_PIN , &Local_u8RS_Value);

		if(Local_u8RS_Value == DIO_u8LOW)
		{
	DIO_enuSetPinValue(D7_PORT , D7_PIN , (Copy_u8Data >> SHIFT_PIN_7) & MASK_BIT);
	DIO_enuSetPinValue(D6_PORT , D6_PIN , (Copy_u8Data >> SHIFT_PIN_6) & MASK_BIT);
	DIO_enuSetPinValue(D5_PORT , D5_PIN , (Copy_u8Data >> SHIFT_PIN_5) & MASK_BIT);
	DIO_enuSetPinValue(D4_PORT , D4_PIN , (Copy_u8Data >> SHIFT_PIN_4) & MASK_BIT);

				/**********the latch ************/

	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH );
	_delay_ms(5);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW );
	_delay_ms(5);

		}
	}
#if LCD_MODE == FOUR_BIT
 //4-4
	DIO_enuSetPinValue(D7_PORT , D7_PIN , (Copy_u8Data >> SHIFT_PIN_7) & MASK_BIT);
	DIO_enuSetPinValue(D6_PORT , D6_PIN , (Copy_u8Data >> SHIFT_PIN_6) & MASK_BIT);
	DIO_enuSetPinValue(D5_PORT , D5_PIN , (Copy_u8Data >> SHIFT_PIN_5) & MASK_BIT);
	DIO_enuSetPinValue(D4_PORT , D4_PIN , (Copy_u8Data >> SHIFT_PIN_4) & MASK_BIT);
				/*		the latch		*/
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH );
	_delay_ms(5);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW );
	_delay_ms(5);

	DIO_enuSetPinValue(D7_PORT , D7_PIN , (Copy_u8Data >> SHIFT_PIN_3) & MASK_BIT);
	DIO_enuSetPinValue(D6_PORT , D6_PIN , (Copy_u8Data >> SHIFT_PIN_2) & MASK_BIT);
	DIO_enuSetPinValue(D5_PORT , D5_PIN , (Copy_u8Data >> SHIFT_PIN_1) & MASK_BIT);
	DIO_enuSetPinValue(D4_PORT , D4_PIN , (Copy_u8Data >> SHIFT_PIN_0) & MASK_BIT);
				/*		the latch		*/
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH );
	_delay_ms(5);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW );
	_delay_ms(5);

#elif LCD_MODE == EIGHT_BIT
//8
	DIO_enuSetPinValue(D7_PORT , D7_PIN , (Copy_u8Data >> SHIFT_PIN_7) & MASK_BIT);
	DIO_enuSetPinValue(D6_PORT , D6_PIN , (Copy_u8Data >> SHIFT_PIN_6) & MASK_BIT);
	DIO_enuSetPinValue(D5_PORT , D5_PIN , (Copy_u8Data >> SHIFT_PIN_5) & MASK_BIT);
	DIO_enuSetPinValue(D4_PORT , D4_PIN , (Copy_u8Data >> SHIFT_PIN_4) & MASK_BIT);

	DIO_enuSetPinValue(D3_PORT , D3_PIN , (Copy_u8Data >> SHIFT_PIN_3) & MASK_BIT);
	DIO_enuSetPinValue(D2_PORT , D2_PIN , (Copy_u8Data >> SHIFT_PIN_2) & MASK_BIT);
	DIO_enuSetPinValue(D1_PORT , D1_PIN , (Copy_u8Data >> SHIFT_PIN_1) & MASK_BIT);
	DIO_enuSetPinValue(D0_PORT , D0_PIN , (Copy_u8Data >> SHIFT_PIN_0) & MASK_BIT);
					/*		the latch		*/
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8HIGH );
	_delay_ms(5);
	DIO_enuSetPinValue(EN_PORT , EN_PIN , DIO_u8LOW );
	_delay_ms(5);

#else
#error"LCD mode is wrong"


#endif
	return Local_ErrorState;
}

ES_T LCD_enuSendData(u8 Copy_u8Data)
{
	u8 Local_ErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);   // High for Data

	LCD_enuWriteAndLatch(Copy_u8Data);

	return Local_ErrorState;
}

ES_T LCD_enuSendCommand(u8 Copy_u8Command)
{

	u8 Local_ErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);	//Low for Command

	LCD_enuWriteAndLatch(Copy_u8Command);


	return Local_ErrorState;
}

ES_T LCD_enuSendString(const char * Copy_pcString)
{

	u8 Local_ErrorState = ES_NOK;

	while(*Copy_pcString != 0) // 0 == \0 but '0' == ASCII of 48
	{
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);	// High for Data

	LCD_enuWriteAndLatch(*Copy_pcString++);
	}

	return Local_ErrorState;
}

ES_T LCD_enuJumpTo( u8 Copy_u8Line_Order , u8 Copy_u8Line_Position)
{

	u8 Local_ErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);   // Low for Command
	if(Copy_u8Line_Order == 1)
	{
	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);   // Low for Command
	LCD_enuWriteAndLatch((START_OF_LINE1 + Copy_u8Line_Position));
	Local_ErrorState = ES_OK;
	}

	else if(Copy_u8Line_Order == 2)
	{

	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);   // Low for Command
	LCD_enuWriteAndLatch((START_OF_LINE2 + Copy_u8Line_Position));

	Local_ErrorState = ES_OK;
	}
	else
	{
		Local_ErrorState = ES_OUT_OF_RANGE;
	}


	return Local_ErrorState;
}

ES_T LCD_enuDisplayIntNum(s32 Copy_s32IntNumber)   /// bug in all multiplies of 100 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{

	u8 Local_ErrorState = ES_NOK;

	u32 Local_u32Remainder ;
	u32 Local_u32ReverseNum = 0 ;
/******** number givin will be diplayed reversly cause of lcd prints each number of the whole number individualy*******/
 /***********  so we will reverse the whole number just to be displayed correctly at the end of function	 **********/
	if(Copy_s32IntNumber < 0)
	{
		DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
		LCD_enuWriteAndLatch('-');

		Copy_s32IntNumber *= -1 ;
	}

	for( ; Copy_s32IntNumber > 0 ; Copy_s32IntNumber /= 10)
	{
		Local_u32Remainder = Copy_s32IntNumber % 10 ;
		Local_u32ReverseNum = Local_u32ReverseNum * 10 + Local_u32Remainder;


	}

	for( ; Local_u32ReverseNum > 0 ; Local_u32ReverseNum /= 10)
	{
		DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
		LCD_enuWriteAndLatch((Local_u32ReverseNum%10) + '0');
	}

	return Local_ErrorState;
}

/////////////////////////////////// NOT FINISHED /////////////////////////////////////////////////////

ES_T LCD_enuDisplayExtraCharachter(u8 * Copy_u8pAu8CharHEXA , u8 Copy_u8NumOfPattern , u8 Copy_u8InputDirection)
{

	u8 Local_ErrorState = ES_NOK;

	DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8LOW);



	return Local_ErrorState;
}


/*
ES_T LCD_enuDisplayFloatNum(f32 Copy_f32FloatNumber)
{

	u8 Local_ErrorState = ES_NOK;


	if(Copy_f32FloatNumber < 0)
	{
		DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
		LCD_enuWriteAndLatch('-');

		Copy_f32FloatNumber *= -1 ;
	}
	u32 Local_u32IntPart   ;   		  f32 Local_f32FloatPart ;
	u32 Local_u32Remainder ;
	u32 Local_u32ReverseIntNum = 0 ;  f32 Local_f32ReverseFloatNum = 0 ;

	Local_u32IntPart = Copy_f32FloatNumber;
	Local_f32FloatPart = Copy_f32FloatNumber - Local_u32IntPart ;

	for( ; Local_u32IntPart > 0 ; Local_u32IntPart /= 10)
		{
			Local_u32Remainder = Local_u32IntPart % 10 ;
			Local_u32ReverseIntNum = Local_u32ReverseIntNum * 10 + Local_u32Remainder;


		}

		for( ; Local_u32ReverseIntNum > 0 ; Local_u32ReverseIntNum /= 10.0)
		{
			DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
			LCD_enuWriteAndLatch((Local_u32ReverseIntNum%10) + '0');
		}

		while(Local_f32FloatPart%10 == 0)
		{
			Local_f32FloatPart = Local_f32FloatPart*10 ;
		}

		for( ; Local_f32FloatPart > 0 ; Local_f32FloatPart /= 10)
			{
				Local_u32Remainder = Local_f32FloatPart % 10 ;
				Local_f32ReverseFloatNum = Local_f32ReverseFloatNum * 10 + Local_u32Remainder;
			}

		DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
		LCD_enuWriteAndLatch('.');
		for( ; Local_f32ReverseFloatNum > 0 ; Local_f32ReverseFloatNum /= 10.0)
		{
			DIO_enuSetPinValue(RS_PORT , RS_PIN , DIO_u8HIGH);
			LCD_enuWriteAndLatch((Local_f32ReverseFloatNum%10) + '0');
		}
	return Local_ErrorState;
}

*/
