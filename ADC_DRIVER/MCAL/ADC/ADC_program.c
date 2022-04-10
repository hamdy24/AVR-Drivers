/*
 * ADC_program.c
 *
 *  Created on: Nov 15, 2021
 *      Author: hamdy
 */
#include "../../LIBRARIES/errorstate.h"
#include "../../LIBRARIES/stdTypes.h"

#include "../../MCAL/interrupt.h"
#include "ADC_private.h"
#include "ADC_config.h"


static volatile void (* ADC_pfunISR_Fun) (void) = NULL ;

ES_T  ADC_enuInit(void)
{
	ES_T Local_enuErrorState = ES_NOK;

#if ADC_PRES ==	PRES_2

	ADCSRA = PRES2_DIVISION_FACTOR_SET;
	Local_enuErrorState = ES_OK;

#elif ADC_PRES == PRES_4

	ADCSRA = PRES4_DIVISION_FACTOR_SET;
	Local_enuErrorState = ES_OK;

#elif ADC_PRES == PRES_8

	ADCSRA = PRES8_DIVISION_FACTOR_SET;
	Local_enuErrorState = ES_OK;

#elif ADC_PRES == PRES_16

	ADCSRA = PRES16_DIVISION_FACTOR_SET;
	Local_enuErrorState = ES_OK;

#elif ADC_PRES == PRES_32

	ADCSRA = PRES32_DIVISION_FACTOR_SET;
	Local_enuErrorState = ES_OK;

#elif ADC_PRES == PRES_64

	ADCSRA = PRES64_DIVISION_FACTOR_SET;

	Local_enuErrorState = ES_OK;

#elif ADC_PRES == PRES_128

	ADCSRA = PRES128_DIVISION_FACTOR_SET;
	Local_enuErrorState = ES_OK;

#else
#error"Wrong ADC Prescaler"
#endif

#if ADC_VREF == AREF_REF
/* REFS1 -> bit7   REFS0 -> bit6 */
	ADMUX &= ~(MASK_BIT << REFS0_BIT_6);
	ADMUX &= ~ (MASK_BIT << REFS1_BIT_7);
	Local_enuErrorState = ES_OK;

#elif ADC_VREF == AVCC_REF
/* REFS1 -> bit7   REFS0 -> bit6 */
	ADMUX |= (MASK_BIT << REFS0_BIT_6);
	ADMUX &= ~ (MASK_BIT << REFS1_BIT_7);
	Local_enuErrorState = ES_OK;

#elif ADC_VREF == INTERNAL_REF
/* REFS1 -> bit7   REFS0 -> bit6 */
	ADMUX |= (MASK_BIT << REFS0_BIT_6);
	ADMUX |= (MASK_BIT << REFS1_BIT_7);
	Local_enuErrorState = ES_OK;

#else
#error"Wrong ADC Voltage Refrance"
#endif


#if ADC_ADJ == LEFT_ADJ
/******* ADLAR is Bit 5 of ADMUX ******/

	ADMUX |= (MASK_BIT << ADLAR_BIT_5);
	Local_enuErrorState = ES_OK;

#elif ADC_ADJ == RIGHT_ADJ
/******* ADLAR is Bit 5 of ADMUX ******/

	ADMUX &= ~(MASK_BIT << ADLAR_BIT_5);
	Local_enuErrorState = ES_OK;

#else
#error"Wrong ADC Adjustment"
#endif

	return Local_enuErrorState;
}

ES_T  ADC_enuStart_Conversion(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	ADCSRA = (MASK_BIT << START_CONVERSION_BIT);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_T  ADC_enuRead_High_Registers(u8 * Copy_pu8Higher_Value)
{
	ES_T Local_enuErrorState = ES_NOK;

#if ADC_ADJ == LEFT_ADJ

	*Copy_pu8Higher_Value = ADCH;

	Local_enuErrorState = ES_OK;

#elif ADC_ADJ == RIGHT_ADJ

	*Copy_pu8Higher_Value  = (ADCL >> 2);
	*Copy_pu8Higher_Value |= (ADCH << 6);

	Local_enuErrorState = ES_OK;
#else
#error"Wrong ADC Adjustment!"
#endif


	return Local_enuErrorState;
}

ES_T  ADC_enuFully_Read(u16 * Copy_pu16Full_Value)
{
	ES_T Local_enuErrorState = ES_NOK;

#if ADC_ADJ == LEFT_ADJ

	*Copy_pu16Full_Value  = (ADCL >> 6);
	*Copy_pu16Full_Value |= ((u16)ADCH << 2);

	Local_enuErrorState = ES_OK;

#elif ADC_ADJ == RIGHT_ADJ

	*Copy_pu16Full_Value  = ADCL;
	*Copy_pu16Full_Value |= ((u16)ADCH << 8);

	Local_enuErrorState = ES_OK;
#else
#error"Wrong ADC Adjustment!"
#endif


	return Local_enuErrorState;
}

ES_T  ADC_enuEnable_AutoTriggering(u8 Copy_u8INT_Source)
{
	ES_T Local_enuErrorState = ES_NOK;

	if(Copy_u8INT_Source <= TIMER_1_CAPTURE_EVENT)
	{

	ADCSRA &= ~(MASK_BIT << ADC_AUTO_TRIGGER_BIT_5);
	SFIOR &= SFIOR_MASK_VALUE; //0x0001 1111

	SFIOR |= (Copy_u8INT_Source << ADC_TRIGGER_SELECT_BIT_5);
	ADCSRA |= (MASK_BIT << ADC_AUTO_TRIGGER_BIT_5); // without this one set...selecting interrupt scource has no effect

	Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_T  ADC_enuDisable_AutoTriggering(void)
{
	ES_T Local_enuErrorState =ES_NOK;

	ADCSRA &= ~(MASK_BIT << ADC_AUTO_TRIGGER_BIT_5);

	return Local_enuErrorState;
}

ES_T  ADC_enuSelect_Channel(u8 Copy_u8Channel_ID)
{
	ES_T Local_enuErrorState = ES_NOK;

	if(Copy_u8Channel_ID <= CHANNEL_NUM_31)
	{

	ADMUX &= ~ADMUX_CHANNELS_MASK_VALUE;  //0xddd0 0000 at ADMUX
	ADMUX |= Copy_u8Channel_ID;

	Local_enuErrorState =ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}

ES_T  ADC_enuEnable_ADC(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	ADCSRA |= (MASK_BIT << ADC_ENABLE_BIT_7);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_T  ADC_enuDisable_ADC(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	ADCSRA &= ~(MASK_BIT << ADC_ENABLE_BIT_7);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_T  ADC_enuEnable_ADC_INT(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	ADCSRA |= (MASK_BIT << ADC_INT_ENABLE_BIT_3);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_T  ADC_enuDisable_ADC_INT(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	ADCSRA &= ~(MASK_BIT << ADC_INT_ENABLE_BIT_3);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_T  ADC_enuPolling(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	while(! (ADCSRA << ADCIF_BIT_4 ) & LOGIC_ONE);
	ADCSRA |= (MASK_BIT << ADCIF_BIT_4); // clear mechanism of this flag

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_T  ADC_enuCall_Back(volatile void (*Copy_pfun_AppFun) (void))
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_pfun_AppFun != NULL)
	{
		ADC_pfunISR_Fun = Copy_pfun_AppFun;
		Local_enuErrorState = ES_OK;
	}
	else
	Local_enuErrorState = ES_POINTER_TO_VOID;

	return Local_enuErrorState;
}


ISR(VECT_ADC)
{

	if(ADC_pfunISR_Fun != NULL)
	{
		ADC_pfunISR_Fun();
	}

}







