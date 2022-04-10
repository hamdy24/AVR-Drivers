#include<util/delay.h>

#include"../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorstate.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Switch_config.h"
#include "Switch_priv.h"

extern u8 Switch_u8SwNum;

ES_t Switch_enuInt(SW_t * Copy_pAstrSwitchConfig)
{
	ES_t Local_enuErrorState = ES_NOK;
	ES_t Local_u8Iterator = 0 ;

	for(Local_u8Iterator =0 ; Local_u8Iterator < Switch_u8SwNum ; Local_u8Iterator++)
	{
		 DIO_enuSetPinDirection ((Copy_pAstrSwitchConfig+Local_u8Iterator)->SW_Port  , (Copy_pAstrSwitchConfig+Local_u8Iterator)->SW_Pin , DIO_u8INPUT);  //output,input

		 DIO_enuSetPinValue ( Copy_pAstrSwitchConfig[Local_u8Iterator].SW_Port , Copy_pAstrSwitchConfig[Local_u8Iterator].SW_Pin , Copy_pAstrSwitchConfig[Local_u8Iterator].SW_State);      //0,1

	};

	return Local_enuErrorState;
};

ES_t Switch_enuGetState(SW_t * Copy_pstrSwitchInfo , u8 * Copy_pu8Value)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = DIO_enuGetPinValue(Copy_pstrSwitchInfo->SW_Port , Copy_pstrSwitchInfo->SW_Pin , Copy_pu8Value );

	return Local_enuErrorState;
};




