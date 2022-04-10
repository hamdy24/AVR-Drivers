/*
 * main.c
 *
 *  Created on: Nov 9, 2021
 *      Author: hamdy
 */
#include "../LIBRARIES/errorstate.h"
#include "../LIBRARIES/stdTypes.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../HAL/DC_Motor/DC_Motor_interface.h"

int main()
{
	DC_Motor_enuInit(1,0);
	DC_Motor_enuStart(1,1);

	return 0;
}
