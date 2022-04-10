/*
 * Switch_config.c
 *
 *  Created on: Oct 11, 2021
 *      Author: hamdy
 */
#include "Switch_config.h"
#include "Switch_priv.h"
#include "DIO_int.h"

#include "errorstate.h"
#include "stdTypes.h"

u8 Switch_u8SwNum = SW_NUM;

SW_T SWITCH_AstrSwitchConfig[ SW_NUM ] =
{
		{DIO_u8PORTD,DIO_u8PIN5,DIO_u8FLOAT},
		{DIO_u8PORTD,DIO_u8PIN4,DIO_u8FLOAT},
		{DIO_u8PORTD,DIO_u8PIN3,DIO_u8FLOAT}
};
