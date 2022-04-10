#include<stdio.h>

#include "Switch_int.h"
#include "Switch_config.h"
#include "DIO_int.h"

#include"stdTypes.h"
#include "errorstate.h"

void delay(void)
{
	for(int x=0;x<500;x++)
		for(int y=0;y<500;y++)
			__asm("NOP");
}


int main()
{
	 DIO_enuInit();
	 Switch_enuInt();
		while(1)
		{
			u8 Local_u8SW_State = 0;

	Switch_enuGetState( &Local_u8SW_State );

			if(Local_u8SW_State == 1)
			{
			DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8HIGH);
				delay();
			DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8LOW);

			DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8HIGH);
				delay();
			DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8LOW);


			}

			else if(Local_u8SW_State == 0)
			{
			DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8HIGH);
			delay();
			DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8LOW);
			delay();
			}




		}
	return 0;
}


