#include<stdio.h>
#include<util/delay.h>

#include "DIO_int.h"
#include"stdTypes.h"
#include "errorstate.h"

#include "Switch_config.h"
#include "Switch_int.h"

extern SW_T SWITCH_AstrSwitchConfig[ SW_NUM ] ;


void delay(void){
  for(int x=0 ; x<220 ; x++)
	for(int y=0 ; y<200 ; y++)
		__asm("NOP");
}

int main()
{
  	DIO_enuInit();         /* void in case of prebuild */

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


