#include<util/delay.h>

#include "../MCAL/DIO/DIO_int.h"

#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorstate.h"


void delay(void)
{
	for(int x=0;x<500;x++)
		for(int y=0;y<500;y++)
			__asm("NOP");
}

int main()
{
	DIO_enuInit();
		while(1)
		{

			DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8HIGH);
			delay();
			DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN2,DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8HIGH);
			delay();
			DIO_enuSetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8LOW);

		}
	return 0;
}


