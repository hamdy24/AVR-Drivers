/*
 * main.c
 *
 *  Created on: Oct 11, 2021
 *      Author: hamdy
 */
#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorstate.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/SevenSegment/SevenSegment_int.h"

#include "../HAL/SevenSegment/SevenSegment_config.h"
#include "../HAL/SevenSegment/SevenSegment_priv.h"

extern SSG_T SevenSegment_AstrSSG_Config[];

int main()
{

	SevenSegment_enuInit( SevenSegment_AstrSSG_Config);

	while(1)
	{

		SevenSegment_enuDisplayNum(&SevenSegment_AstrSSG_Config[0] , 5 );
		SevenSegment_enuShowDot(&SevenSegment_AstrSSG_Config[0]);
		SevenSegment_enuDisplayNum(&SevenSegment_AstrSSG_Config[1] , 2 );

	};

	return 0;
}
