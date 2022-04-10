/*
 * EXTI_prog.c
 *
 *  Created on: Oct 30, 2021
 *      Author: hamdy
 */
#include "../../LIBRARIES/errorstate.h"
#include "../../LIBRARIES/stdTypes.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"

#include "../interrupt.h"

static volatile void (* EXTI_pfunISR_fun[INTERRUPT_NUM]) (void) = { NULL , NULL , NULL };

ES_T EXTI_enuInit(EXTI_T * Copy_AstrEXTI_CONFIG)
{
ES_T Local_enuErrorState = ES_NOK ;
///////////////////////////////////////////////////////////////////////////////

if(Copy_AstrEXTI_CONFIG[INT0].INTERRUPT_STATE == ENABELED)
{
			GICR |= (1<<6);

		switch(Copy_AstrEXTI_CONFIG[INT0].INT_SENSE_LEVEL)
		{
		case LOW_LEVEL:

			MCUCR &= ~(3<<0);	//mask bit 0,1
			break;
		case ANY_LOGICAL:

			MCUCR |= (1<<0);	//set bit 0

			MCUCR &= ~(1<<1);	//mask bit 1

			break;
		case FALLING:

			MCUCR &= ~(1<<0);	//mask bit 0

			MCUCR |= (1<<1);	//set bit 1

			break;
		case RISING:

			MCUCR |= (3<<0);	//set bit 0,1

			break;
		default :
			Local_enuErrorState =ES_OUT_OF_RANGE;

		}
}

	else if(Copy_AstrEXTI_CONFIG[INT0].INTERRUPT_STATE == DISABELED)
		{
			GICR &= ~(1<<6);
		}

/////////////////////////////////////////////////////////////////////////////////////////
if(Copy_AstrEXTI_CONFIG[INT1].INTERRUPT_STATE == ENABELED)
{
			GICR |= (1<<7);

			switch(Copy_AstrEXTI_CONFIG[INT1].INT_SENSE_LEVEL)
					{
					case LOW_LEVEL:

						MCUCR &= ~(3<<2);

						break;
					case ANY_LOGICAL:

						MCUCR |= (1<<2);

						MCUCR &= ~(1<<3);
						break;
					case FALLING:

						MCUCR &= ~(1<<2);

						MCUCR |= (1<<3);
						break;
					case RISING:

						MCUCR |= (3<<2);

						break;
					default :
						Local_enuErrorState =ES_OUT_OF_RANGE;

					}
}
////////////////////////////////////////////////////////////////////////////////////////////////
		else if(Copy_AstrEXTI_CONFIG[INT0].INTERRUPT_STATE == DISABELED)
		{
			GICR &= ~(1<<7);
		}
///////////////////////////////////////////////////////////////////////////////////////////////
if(Copy_AstrEXTI_CONFIG[INT2].INTERRUPT_STATE == ENABELED)
{
			GICR |= (1<<5);
			switch(Copy_AstrEXTI_CONFIG[INT2].INT_SENSE_LEVEL)
				{
					case FALLING:

						MCUCSR &= ~(1<<6);
						break;
					case RISING:

						MCUCSR |= (1<<6);
						break;
					default :
						Local_enuErrorState =ES_OUT_OF_RANGE;

				}
}
/////////////////////////////////////////////////////////////////////////////////////
		else if(Copy_AstrEXTI_CONFIG[INT2].INTERRUPT_STATE == DISABELED)
		{
			GICR &= ~(1<<5);
		}

return Local_enuErrorState;
}

ES_T EXTI_enuSetSenseLevel(u8 Copy_u8InterruptNum , u8 Copy_u8SenseLevel)
{
ES_T Local_enuErrorState = ES_NOK ;

if(Copy_u8InterruptNum == INT0)
{

		switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL:

			MCUCR &= ~(3<<0);	//mask bit 0,1
			Local_enuErrorState = ES_OK;
			break;
		case ANY_LOGICAL:

			MCUCR |= (1<<0);	//set bit 0

			MCUCR &= ~(1<<1);	//mask bit 1
			Local_enuErrorState = ES_OK;

			break;
		case FALLING:

			MCUCR &= ~(1<<0);	//mask bit 0

			MCUCR |= (1<<1);	//set bit 1
			Local_enuErrorState = ES_OK;

			break;
		case RISING:

			MCUCR |= (3<<0);	//set bit 0,1
			Local_enuErrorState = ES_OK;

			break;

		default :
			Local_enuErrorState =ES_OUT_OF_RANGE;

		}
}

if(Copy_u8InterruptNum == INT1)
{

		switch(Copy_u8SenseLevel)
		{
		case LOW_LEVEL:
		{
			MCUCR &= ~(3<<2);	//mask bit 2,3
			Local_enuErrorState = ES_OK;
		}
		break;
		case ANY_LOGICAL:
		{
			MCUCR |= (1<<2);	//set bit 2

			MCUCR &= ~(1<<3);	//mask bit 3
			Local_enuErrorState = ES_OK;
		}
			break;
		case FALLING:
		{
			MCUCR &= ~(1<<2);	//mask bit 2

			MCUCR |= (1<<3);	//set bit 3
			Local_enuErrorState = ES_OK;
		}
			break;
		case RISING:
		{
			MCUCR |= (3<<2);	//set bit 2,3
			Local_enuErrorState = ES_OK;
		}
			break;

		default :
			Local_enuErrorState =ES_OUT_OF_RANGE;

		}
}


if(Copy_u8InterruptNum == INT2)
{

		switch(Copy_u8SenseLevel)
		{
		case FALLING:
		{
			MCUCSR &= ~(1<<6);	//mask bit 6
			Local_enuErrorState = ES_OK;
		}
			break;
		case RISING:
		{
			MCUCSR |= (1<<6);	//set bit 6
			Local_enuErrorState = ES_OK;
		}
			break;

		default :
			Local_enuErrorState =ES_OUT_OF_RANGE;

		}
}

return Local_enuErrorState;
}

ES_T EXTI_enuEnableInterrupt(u8 Copy_u8InterruptNum)
{
ES_T Local_enuErrorState = ES_NOK ;
	switch(Copy_u8InterruptNum)
	{
	case INT0:

		GICR |= (1<<6);
		Local_enuErrorState = ES_OK;
		break;
	case INT1:

		GICR |= (1<<7);
		Local_enuErrorState = ES_OK;
		break;
	case INT2:

		GICR |= (1<<5);
		Local_enuErrorState = ES_OK;
		break;
	default:
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
return Local_enuErrorState;
}

ES_T EXTI_enuDisableInterrupt(u8 Copy_u8InterruptNum)
{
ES_T Local_enuErrorState = ES_NOK ;
	switch(Copy_u8InterruptNum)
	{
	case INT0:

		GICR &= ~(1<<6);
		Local_enuErrorState = ES_OK;
		break;
	case INT1:

		GICR &= ~(1<<7);
		Local_enuErrorState = ES_OK;
		break;
	case INT2:

		GICR &= ~(1<<5);
		Local_enuErrorState = ES_OK;
		break;
	default:
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

return Local_enuErrorState;
}

ES_T EXTI_enuCallBack(volatile void  (* pfunAppFunction)(void),u8 Copy_u8InterruptNum)
{
ES_T Local_enuErrorState = ES_NOK ;

	if(pfunAppFunction != NULL)
	{
		if(Copy_u8InterruptNum <= 2)
		{
			EXTI_pfunISR_fun[Copy_u8InterruptNum] = pfunAppFunction;

			Local_enuErrorState = ES_OK;
		}
	}
	else
	{
		Local_enuErrorState = ES_POINTER_TO_VOID;
	}

	return Local_enuErrorState;
}

ISR(VECT_INT0)
{
	if(EXTI_pfunISR_fun[0] != NULL)
	{
		EXTI_pfunISR_fun[0] ();
	}
}
ISR(VECT_INT1)
{
	if(EXTI_pfunISR_fun[1] != NULL)
	{
		EXTI_pfunISR_fun[1] ();
	}
}
ISR(VECT_INT2)
{
	if(EXTI_pfunISR_fun[2] != NULL)
	{
		EXTI_pfunISR_fun[2] ();
	}
}
