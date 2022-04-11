/*
 * main.c
 *
 *  Created on: Nov 9, 2021
 *      Author: hamdy
 */
#include "../LIBRARIES/errorstate.h"
#include "../LIBRARIES/stdTypes.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/UART/UART_interface.h"
#include "../MCAL/GIE/GIE_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LCD/LCD_config.h"


u8 App_enuStrCmp(u8 * str1 , u8 * str2 );
u8 flag=0;
void Flagup()
{
	flag=1;
}


int main()
{
	u8  Local_u8Data[22];

	UART_enuUART_Init();
	GIE_enuInit();
	LCD_enuInit();
	GIE_enuEnable();

	UART_enuCall_Back((volatile void (*)(void))Flagup);
	DIO_enuSetPinDirection(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8OUTPUT); // the led we control
	DIO_enuSetPinDirection(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8OUTPUT); // the led we control
	DIO_enuSetPinDirection(DIO_u8PORTC , DIO_u8PIN7 , DIO_u8OUTPUT); // the led we control

	DIO_enuSetPinDirection(DIO_u8PORTD , DIO_u8PIN1 , DIO_u8OUTPUT); //TXD --> 1 & RXD --> 0


	//	UART_enuSendString("Welcome to remote login system:\n");
		LCD_enuJumpTo(1,0);
		LCD_enuSendString("Welcome to remote");
		LCD_enuJumpTo(2,4);
		//	UART_enuEnable_UART_RX_INT();
	while(1)
	  {
if(UART_enuCheck_Connection())
{

	UART_enuRecieveString(Local_u8Data);
	if(App_enuStrCmp(Local_u8Data,"led1"))
	{
		DIO_enuTogPinValue(DIO_u8PORTD , DIO_u8PIN3 );

	}

}
u8 Local_u8Data2;
UART_enuRecieveString(Local_u8Data2);

		switch(Local_u8Data2)
		{
		case '1':
			DIO_enuTogPinValue(DIO_u8PORTD , DIO_u8PIN3 );
			DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN3 , DIO_u8LOW);

			break;
		case '2':
			DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8LOW);
			DIO_enuTogPinValue(DIO_u8PORTC , DIO_u8PIN7 );
			DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8LOW);

			break;
		case '3':
			DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN7 , DIO_u8LOW);
			DIO_enuTogPinValue(DIO_u8PORTC , DIO_u8PIN2 );

			break;
		case '0':
			DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN7 , DIO_u8LOW);
			DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8LOW);
			break;
		case '4':
			DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8HIGH);
			DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN7 , DIO_u8HIGH);
			DIO_enuSetPinValue(DIO_u8PORTC , DIO_u8PIN2 , DIO_u8HIGH);
			break;
		default:

			break;
		}
		  }

	return 0;
}

u8 App_enuStrCmp(u8 * str1 , u8 * str2 )
{
	u8 Local_u8Iter = 0;
// polling till one at least of the two strings end
	for( ; str1[Local_u8Iter] == str2[Local_u8Iter] ; Local_u8Iter++);

	if(str1[Local_u8Iter-1] == '\0' && str2[Local_u8Iter-1] == '\0')
	{
		return 1;
	}
		return 0;
}

