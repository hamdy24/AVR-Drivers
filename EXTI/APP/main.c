/*
 * main.c
 *
 *  Created on: Oct 30, 2021
 *      Author: hamdy
 */
#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorstate.h"

#include "../MCAL/GIE/GIE_int.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/EXTI/EXTI_config.h"

#include "../HAL/SWITCH_LINKING/Switch_int.h"

extern EXTI_T EXTI_enuAstrEXTI_CONFIG[INTERRUPT_NUM];
extern SW_T SWITCH_AstrSwitchConfig[ SW_NUM ] ;

volatile void APP_enuTOG(void)
{
	DIO_enuTogPinValue(DIO_u8PORTD,DIO_u8PIN3);
}

int main()
{
	u8 Local_u8KeyState = 0 ;

	DIO_enuSetPinDirection(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8OUTPUT);

	EXTI_enuInit(EXTI_enuAstrEXTI_CONFIG);
	GIE_enuInit();
	Switch_enuInt(SWITCH_AstrSwitchConfig);

	Switch_enuGetState(&SWITCH_AstrSwitchConfig[1] ,&Local_u8KeyState );
	EXTI_enuCallBack((volatile void (*) (void))APP_enuTOG , 0);
	while(1){
if(Local_u8KeyState == 1)
	{
		EXTI_enuEnableInterrupt(0);
		EXTI_enuSetSenseLevel(0,3);
		DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8HIGH);
	}
			}
return 0;
}
