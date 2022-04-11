#ifndef INT_H
#define INT_H

#include "DIO_config.h"

#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorstate.h"

ES_T DIO_enuInit(void);         // void in case of p re processing
ES_T DIO_enuSetPinDirection (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PortDirection);  //output,input
ES_T DIO_enuTogPinValue (u8 Copy_u8PortID , u8 Copy_u8PinID );      //1>>0 , 0>>1
ES_T DIO_enuSetPinValue (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8PinValue);      //0,1
ES_T DIO_enuGetPinValue (u8 Copy_u8PortID , u8 Copy_u8PinID , u8 * Copy_pu8PinValue);      //0,1

enum
{
DIO_u8PORTA 		,
DIO_u8PORTB 		,
DIO_u8PORTC 		,
DIO_u8PORTD 		,

DIO_u8PIN0=0		,
DIO_u8PIN1			,
DIO_u8PIN2			,
DIO_u8PIN3			,
DIO_u8PIN4			,
DIO_u8PIN5			,
DIO_u8PIN6			,
DIO_u8PIN7			,

DIO_u8INPUT=0		,
DIO_u8OUTPUT 		,

DIO_u8LOW=0			,
DIO_u8HIGH			,

DIO_u8FLOAT=0		,
DIO_u8PULL_UP
};

#endif

