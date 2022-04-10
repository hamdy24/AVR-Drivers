#include<util/delay.h>

#include "../../LIBRARIES/errorstate.h"
#include "../../LIBRARIES/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Switch_config.h"
#include "Switch_priv.h"

ES_T Switch_enuInt(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection (SW_PORT, SW_PIN , DIO_u8INPUT );

	Local_enuErrorState = DIO_enuSetPinValue (SW_PORT, SW_PIN ,SW_STATE);

	return Local_enuErrorState;
};

ES_T Switch_enuGetState(u8 * Copy_pu8Value)
{
	ES_T Local_enuErrorState = ES_NOK;

	Local_enuErrorState = DIO_enuGetPinValue (SW_PORT, SW_PIN ,Copy_pu8Value);


	return Local_enuErrorState;
};




