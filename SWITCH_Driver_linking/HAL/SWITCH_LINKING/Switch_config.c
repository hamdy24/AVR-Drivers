/*
 * Switch_config.c
 *
 *  Created on: Oct 11, 2021
 *      Author: hamdy
 */
#include "Switch_config.h"
#include "Switch_priv.h"

#include "../../MCAL/DIO/DIO_int.h"

#include"../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorstate.h"

u8 Switch_u8SwNum = SW_NUM;

SW_t SWITCH_AstrSwitchConfig[ SW_NUM ] =
{
		{DIO_u8PORTB,DIO_u8PIN0,DIO_u8FLOAT},
		{DIO_u8PORTD,DIO_u8PIN4,DIO_u8FLOAT},
		{DIO_u8PORTD,DIO_u8PIN3,DIO_u8FLOAT}
};
