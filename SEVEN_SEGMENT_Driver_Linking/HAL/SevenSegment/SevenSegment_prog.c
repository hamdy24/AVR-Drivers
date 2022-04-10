/*
 * SevenSegment_prog.c
 *
 *  Created on: Oct 11, 2021
 *      Author: hamdy
 */
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorstate.h"

#include "SevenSegment_config.h"
#include "SevenSegment_priv.h"

#include "../../MCAL/DIO/DIO_int.h"

extern u8 SSG_Number ;

ES_T SevenSegment_enuInit(SSG_T * Copy_AstrSSG_Config)
{
	ES_T Local_enuErrorState = ES_NOK;
#if DECODER == YES

#elif DECODER == NO

	u8 Local_u8Iterator;
	for(Local_u8Iterator = 0 ; Local_u8Iterator< SSG_Number ; Local_u8Iterator++)
	{

  DIO_enuSetPinDirection(Copy_AstrSSG_Config[Local_u8Iterator].A_Port , Copy_AstrSSG_Config[Local_u8Iterator].A_Pin , DIO_u8OUTPUT);
  DIO_enuSetPinDirection(Copy_AstrSSG_Config[Local_u8Iterator].B_Port , Copy_AstrSSG_Config[Local_u8Iterator].B_Pin , DIO_u8OUTPUT);
  DIO_enuSetPinDirection(Copy_AstrSSG_Config[Local_u8Iterator].C_Port , Copy_AstrSSG_Config[Local_u8Iterator].C_Pin , DIO_u8OUTPUT);
  DIO_enuSetPinDirection(Copy_AstrSSG_Config[Local_u8Iterator].D_Port , Copy_AstrSSG_Config[Local_u8Iterator].D_Pin , DIO_u8OUTPUT);
  DIO_enuSetPinDirection(Copy_AstrSSG_Config[Local_u8Iterator].E_Port , Copy_AstrSSG_Config[Local_u8Iterator].E_Pin , DIO_u8OUTPUT);
  DIO_enuSetPinDirection(Copy_AstrSSG_Config[Local_u8Iterator].F_Port , Copy_AstrSSG_Config[Local_u8Iterator].F_Pin , DIO_u8OUTPUT);
  DIO_enuSetPinDirection(Copy_AstrSSG_Config[Local_u8Iterator].G_Port , Copy_AstrSSG_Config[Local_u8Iterator].G_Pin , DIO_u8OUTPUT);

	if(Copy_AstrSSG_Config[Local_u8Iterator].CMN_Port != NOT_CONNECTED &&
			Copy_AstrSSG_Config[Local_u8Iterator].CMN_Pin != NOT_CONNECTED)
	{
	DIO_enuSetPinDirection(Copy_AstrSSG_Config[Local_u8Iterator].CMN_Port , Copy_AstrSSG_Config[Local_u8Iterator].CMN_Pin , DIO_u8OUTPUT);
	};

	if(Copy_AstrSSG_Config[Local_u8Iterator].Dot_Port != NOT_CONNECTED &&
			Copy_AstrSSG_Config[Local_u8Iterator].Dot_Pin != NOT_CONNECTED)
	{
	DIO_enuSetPinDirection(Copy_AstrSSG_Config[Local_u8Iterator].Dot_Port , Copy_AstrSSG_Config[Local_u8Iterator].Dot_Pin , DIO_u8OUTPUT);
	};
	};

#endif
	return Local_enuErrorState;
}

ES_T SevenSegment_enuDisplayNum(SSG_T * Copy_pstrSSG_Info , u8 Copy_u8Number)
{
	ES_T Local_enuErrorState = ES_NOK;
#if DECODER == YES

#elif DECODER == NO
	if(Copy_pstrSSG_Info->SSG_Type == CMN_CATHOD)
	{
		Copy_u8Number = SevenSegment_u8Au8CMN_CTH_Values[Copy_u8Number];
	}

	if(Copy_pstrSSG_Info->SSG_Type == CMN_ANODE)
	{
		Copy_u8Number = ~SevenSegment_u8Au8CMN_CTH_Values[Copy_u8Number];
	}

	DIO_enuSetPinValue(Copy_pstrSSG_Info->A_Port,Copy_pstrSSG_Info->A_Pin, (Copy_u8Number>>0)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->B_Port,Copy_pstrSSG_Info->B_Pin, (Copy_u8Number>>1)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->C_Port,Copy_pstrSSG_Info->C_Pin, (Copy_u8Number>>2)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->D_Port,Copy_pstrSSG_Info->D_Pin, (Copy_u8Number>>3)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->E_Port,Copy_pstrSSG_Info->E_Pin, (Copy_u8Number>>4)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->F_Port,Copy_pstrSSG_Info->F_Pin, (Copy_u8Number>>5)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->G_Port,Copy_pstrSSG_Info->G_Pin, (Copy_u8Number>>6)& 1);
#endif
	return Local_enuErrorState;
}

ES_T SevenSegment_enuStopDisplay(SSG_T * Copy_pstrSSG_Info)
{
	ES_T Local_enuErrorState = ES_NOK;
#if DECODER == YES

#elif DECODER == NO

	u8 Local_u8StopValue = 0;
	if(Copy_pstrSSG_Info->SSG_Type == CMN_ANODE)
	{
		Local_u8StopValue = ~ Local_u8StopValue; //
	}
	DIO_enuSetPinValue(Copy_pstrSSG_Info->A_Port,Copy_pstrSSG_Info->A_Pin, (Local_u8StopValue>>0)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->B_Port,Copy_pstrSSG_Info->B_Pin, (Local_u8StopValue>>1)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->C_Port,Copy_pstrSSG_Info->C_Pin, (Local_u8StopValue>>2)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->D_Port,Copy_pstrSSG_Info->D_Pin, (Local_u8StopValue>>3)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->E_Port,Copy_pstrSSG_Info->E_Pin, (Local_u8StopValue>>4)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->F_Port,Copy_pstrSSG_Info->F_Pin, (Local_u8StopValue>>5)& 1);
	DIO_enuSetPinValue(Copy_pstrSSG_Info->G_Port,Copy_pstrSSG_Info->G_Pin, (Local_u8StopValue>>6)& 1);
#endif
	return Local_enuErrorState;
}

ES_T SevenSegment_enuShowDot(SSG_T * Copy_pstrSSG_Info)
{
	ES_T Local_enuErrorState = ES_NOK;
#if DECODER == YES

#elif DECODER == NO
	if(Copy_pstrSSG_Info->Dot_Port != NOT_CONNECTED
			&& Copy_pstrSSG_Info->D_Pin != NOT_CONNECTED)
{
/*
 * As CMN_ANODE port would be connected to high voltage so we need the numbers and the dot ports
  to be connected to low so that current pass and the effect is done

 * CMN_CATHOD is the same concept with respect to differences
 */
		if(Copy_pstrSSG_Info->SSG_Type == CMN_ANODE)
		{
			DIO_enuSetPinValue(Copy_pstrSSG_Info->D_Port , Copy_pstrSSG_Info->Dot_Pin , DIO_u8LOW);
		}
		else if(Copy_pstrSSG_Info->SSG_Type == CMN_CATHOD)
		{
			DIO_enuSetPinValue(Copy_pstrSSG_Info->D_Port , Copy_pstrSSG_Info->Dot_Pin , DIO_u8HIGH);
		}
}
#endif
	return Local_enuErrorState;
}

ES_T SevenSegment_enuHideDot(SSG_T * Copy_pstrSSG_Info)
{
	ES_T Local_enuErrorState = ES_NOK;
#if DECODER == YES

#elif DECODER == NO
	if(Copy_pstrSSG_Info->Dot_Port != NOT_CONNECTED
			&& Copy_pstrSSG_Info->D_Pin != NOT_CONNECTED)
{
		if(Copy_pstrSSG_Info->SSG_Type == CMN_ANODE)
		{
			DIO_enuSetPinValue(Copy_pstrSSG_Info->D_Port , Copy_pstrSSG_Info->Dot_Pin , DIO_u8HIGH);
		}
		else if(Copy_pstrSSG_Info->SSG_Type == CMN_CATHOD)
		{
			DIO_enuSetPinValue(Copy_pstrSSG_Info->D_Port , Copy_pstrSSG_Info->Dot_Pin , DIO_u8LOW);
		}
}

#endif
	return Local_enuErrorState;
}

ES_T SevenSegment_enuEnableCMN(SSG_T * Copy_pstrSSG_Info)
{
	ES_T Local_enuErrorState = ES_NOK;
#if DECODER == YES

#elif DECODER == NO

	if(Copy_pstrSSG_Info->CMN_Port !=NOT_CONNECTED
			&& Copy_pstrSSG_Info->CMN_Pin != NOT_CONNECTED)
{
/* case of CMN_CATHOD the common port is connected to ground so its value is low when enable*/

	  if(Copy_pstrSSG_Info->SSG_Type == CMN_CATHOD)
	{
	DIO_enuSetPinValue(Copy_pstrSSG_Info->CMN_Port,Copy_pstrSSG_Info->CMN_Pin,DIO_u8LOW);
	}
/* case of CMN_ANODE the common port is connected to power source so its value is high when enable*/

	  else if(Copy_pstrSSG_Info->SSG_Type == CMN_ANODE)
	{
		DIO_enuSetPinValue(Copy_pstrSSG_Info->CMN_Port,Copy_pstrSSG_Info->CMN_Pin,DIO_u8HIGH);
	}
}
#endif
	return Local_enuErrorState;
}

ES_T SevenSegment_enuDisableCMN(SSG_T * Copy_pstrSSG_Info)
{
	ES_T Local_enuErrorState = ES_NOK;
#if DECODER == YES

#elif DECODER == NO

	if(Copy_pstrSSG_Info->CMN_Port !=NOT_CONNECTED
			&& Copy_pstrSSG_Info->CMN_Pin != NOT_CONNECTED)
{
/* to disable SSG we reverse the enable conditions */
	if(Copy_pstrSSG_Info->SSG_Type == CMN_CATHOD)
	{
	DIO_enuSetPinValue(Copy_pstrSSG_Info->CMN_Port,Copy_pstrSSG_Info->CMN_Pin,DIO_u8HIGH);
	}

	else if(Copy_pstrSSG_Info->SSG_Type == CMN_ANODE)
	{
		DIO_enuSetPinValue(Copy_pstrSSG_Info->CMN_Port,Copy_pstrSSG_Info->CMN_Pin,DIO_u8LOW);
	}
}
#endif
	return Local_enuErrorState;
}
