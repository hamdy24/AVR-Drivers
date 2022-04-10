/*
 * SevenSegment_config.c
 *
 *  Created on: Oct 11, 2021
 *      Author: hamdy
 */
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorstate.h"

#include "SevenSegment_config.h"
#include "SevenSegment_priv.h"

#include "../../MCAL/DIO/DIO_int.h"

u8 SSG_Number = SSG_NUM;

SSG_T SevenSegment_AstrSSG_Config[SSG_NUM] =
{
/////////////////////////*First SevenSegment Configuration*////////////////////
		{
		DIO_u8PORTC , DIO_u8PIN0 , DIO_u8PORTC , DIO_u8PIN1 ,
		DIO_u8PORTC , DIO_u8PIN2 , DIO_u8PORTC , DIO_u8PIN3 ,
		DIO_u8PORTC , DIO_u8PIN4 , DIO_u8PORTC , DIO_u8PIN5 ,
		DIO_u8PORTC , DIO_u8PIN6 ,

		NOT_CONNECTED , NOT_CONNECTED ,
		NOT_CONNECTED , NOT_CONNECTED ,
		CMN_CATHOD
		},
/////////////////////////*Second SevenSegment Configuration*////////////////////
		{
			DIO_u8PORTD , DIO_u8PIN0 , DIO_u8PORTD , DIO_u8PIN1 ,
			DIO_u8PORTD , DIO_u8PIN2 , DIO_u8PORTD , DIO_u8PIN3 ,
			DIO_u8PORTD , DIO_u8PIN4 , DIO_u8PORTD , DIO_u8PIN5 ,
			DIO_u8PORTD , DIO_u8PIN6 ,

			NOT_CONNECTED , NOT_CONNECTED ,
			NOT_CONNECTED , NOT_CONNECTED ,
			CMN_CATHOD
		}

};
