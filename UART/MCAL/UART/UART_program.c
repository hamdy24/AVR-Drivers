/*
 * UART_program.c
 *
 *  Created on: Nov 9, 2021
 *      Author: hamdy
 */
/*********************************************************
 *********************************************************
 ************* SOLID CONFIGURATION ***********************
 *********************************************************
 **********************************************************/

#include "../../MCAL/UART/UART_private.h"
#include "../../MCAL/UART/UART_config.h"

#include "../../LIBRARIES/errorstate.h"
#include "../../LIBRARIES/stdTypes.h"

u8 UART_First_ConnectionFlag=0;
static volatile void (* UART_pfunISR_Fun) (void) = NULL ;

ES_T UART_enuUART_Init(void)
{
	ES_T Local_ErorrState = ES_NOK;

	UCSRA = 0x00; // flags RXC,TXC,UDRE -> 0,, U2X -> 0(Synchronous)
	UCSRB = 0x18; // set to be a reciever and a transmiter
	UCSRC = 0x86; // set frame format

	UBRRL = 103; // 0110 0111 (BAUD)
	UBRRH = 0;   // BAUD>>8  -> 0

	return Local_ErorrState;
}

ES_T UART_enuSendChar( u8 Copy_u8CharData)
{
	ES_T Local_ErorrState = ES_NOK;
	// check if UDR ready(empty)for write or not using UDRE bit--> if ready..go else wait.

	while(! ((UCSRA >> 5) & 1)); // (UCSRA >> 5) -> UDRE
	UDR = Copy_u8CharData;

/*
 * previous is polling with (udre)
 * next is polling with (txc)
// we will send data to UDR then wait in while until all data is transimiteted then we put the TXc flag down again.

	  UDR = Copy_u8CharData;
	  while(!((UCSRA >> 6) & 1));
	  UCSRA |= (1>>6);

*/
	return Local_ErorrState;
}

ES_T UART_enuRecieveChar(u8 * Copy_u8RxChar)
{
	ES_T Local_ErorrState = ES_NOK;

// As long the RXc is 0 so there is no recieved data at that moment --> recieve the new data

	while(((UCSRA >> 7) & 1) == 0); // (UCSRA >> 7) -> RXc
	*Copy_u8RxChar = UDR;

	return Local_ErorrState;
}

ES_T UART_enuSendString(u8 * Copy_Au8StringData)
{
	ES_T Local_ErorrState = ES_NOK;

	u8 Local_u8Iter = 0;

	while(Copy_Au8StringData[Local_u8Iter] != 0) // check if data not equal  NULL
	{
		while(! ((UCSRA>>5) & 1 )); // wait until the UDR is empty using (UCSRA>>5) -> UDRE
		UDR = (Copy_Au8StringData[Local_u8Iter]);
		UART_First_ConnectionFlag++;
		Local_u8Iter++;
	}

	return Local_ErorrState;
}

ES_T UART_enuRecieveString(u8 * Copy_Au8RxString)
{
	ES_T Local_ErorrState = ES_NOK;

#if NEW_LINE == NO
	u8 Local_u8EndChar , Local_u8TempChar, Local_u8Iter = 0;

	while(((UCSRA >> 7) & 1) == 0); // (UCSRA >> 7)-> RXc
	Local_u8EndChar = UDR;

//to display what is typed

	while(! ((UCSRA>>5) & 1 ));
	UDR = Local_u8EndChar;

	while(1)
	{

		while(((UCSRA >> 7) & 1) == 0); // (UCSRA >> 7)-> RXc
		Local_u8TempChar = UDR ;

//to display what is typed

		while(! ((UCSRA>>5) & 1 )); // (UCSRA>>5)-> UDRE
		UDR = Local_u8TempChar;

		if(Local_u8EndChar == Local_u8TempChar )
		{
			(Copy_Au8RxString[Local_u8Iter++]) = 0;
			break;
		}

	(Copy_Au8RxString[Local_u8Iter++]) = Local_u8TempChar;

	}
#elif NEW_LINE == YES
	u8 Local_u8Iter = 0;

	while(1)
	{

		while(((UCSRA >> 7) & 1) == 0); // (UCSRA >> 7)-> RXc
		(Copy_Au8RxString[Local_u8Iter]) = UDR ;

//to display what is typed

		while(! ((UCSRA>>5) & 1 )); // (UCSRA>>5)-> UDRE
		UDR = (Copy_Au8RxString[Local_u8Iter]);

		if( (Copy_Au8RxString[Local_u8Iter])=='\r' || (Copy_Au8RxString[Local_u8Iter])=='\n')
		{
			(Copy_Au8RxString[Local_u8Iter++]) = 0;
			break;
		}

		Local_u8Iter++;
	}

#endif
	return Local_ErorrState;
}

ES_T  UART_enuEnable_UART_RXEN(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	UCSRB |= (MASK_BIT << UART_RX_ENABLE_BIT_4);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_T  UART_enuDisable_UART_RXEN(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	UCSRB |= (MASK_BIT << UART_RX_ENABLE_BIT_4);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_T  UART_enuEnable_UART_TXEN(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	UCSRB &= ~(MASK_BIT << UART_TX_ENABLE_BIT_3);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_T  UART_enuDisable_UART_TXEN(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	UCSRB &= ~(MASK_BIT << UART_TX_ENABLE_BIT_3);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_T  UART_enuEnable_UART_RX_INT(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	UCSRB |= (MASK_BIT << UART_RX_INT_ENABLE_BIT_7);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_T  UART_enuDisable_UART_RX_INT(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	UCSRB &= ~(MASK_BIT << UART_RX_INT_ENABLE_BIT_7);

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

u8 UART_enuCheck_Connection()
{
	if(UART_First_ConnectionFlag!=0)
	{
		return 1;
	}

	return 0;
}

ES_T  UART_enuCall_Back(volatile void (*Copy_pfun_AppFun) (void))
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_pfun_AppFun != NULL)
	{
		UART_pfunISR_Fun = Copy_pfun_AppFun;
		Local_enuErrorState = ES_OK;
	}
	else
	Local_enuErrorState = ES_POINTER_TO_VOID;

	return Local_enuErrorState;
}

ISR(VECT_UART)
{

	if(UART_pfunISR_Fun != NULL)
	{
		*((volatile u8*) 0x3A) = 0XFF;
		UART_pfunISR_Fun();
	}

}

