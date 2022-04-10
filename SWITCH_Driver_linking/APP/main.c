/*
 * main.c
 *
 *  Created on: Nov 6, 2021
 *      Author: hamdy
 */

#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorstate.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../HAL/SWITCH_Linking/Switch_config.h"
#include "../HAL/SWITCH_Linking/Switch_int.h"

#include "../MCAL/AVR_REG.H"


#include <util/delay.h>


extern SW_t SWITCH_AstrSwitchConfig[ SW_NUM ] ;


void delay(void)
{
  for(int x=0 ; x<220 ; x++)
	for(int y=0 ; y<200 ; y++)
		__asm("NOP");
}

int main()
{
	Switch_enuInt( SWITCH_AstrSwitchConfig);

	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8OUTPUT);

	//u8 Local_u8Sw0Value;

	while(1)
	{

		DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8HIGH);
		_delay_ms(9);
		DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8LOW);

	}

	return 0;
}

/*
int main()
{
  	DIO_enuInit();         // void in case of prebuild

	Switch_enuInt( SWITCH_AstrSwitchConfig);

		while(1)
		{
	u8 Local_u8Sw1Value;
	u8 Local_u8Sw2Value;
	u8 Local_u8Sw0Value;

	Switch_enuGetState( &SWITCH_AstrSwitchConfig[0] , &Local_u8Sw0Value);
	Switch_enuGetState( &SWITCH_AstrSwitchConfig[1] , &Local_u8Sw1Value);
	Switch_enuGetState( &SWITCH_AstrSwitchConfig[2] , &Local_u8Sw2Value);

	if(Local_u8Sw0Value == 1)
	{
		DIO_enuSetPinDirection(DIO_u8PORTC,DIO_u8PIN2,DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8HIGH);
		delay();
		DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8LOW);
		delay();
	}
	else if(Local_u8Sw1Value == 1)
	{
		DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8HIGH);
		delay();
		DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8LOW);
		delay();
	}

	else if(Local_u8Sw2Value == 1)
	{
		DIO_enuSetPinDirection(DIO_u8PORTC,DIO_u8PIN7,DIO_u8OUTPUT);
		DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8HIGH);
		delay();
		DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8LOW);
		delay();
	}



	}
	return 0;
}
*/


