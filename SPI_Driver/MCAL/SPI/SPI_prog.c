/*
 * SPI_prog.c
 *
 *  Created on: Oct 29, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "stdTypes.h"

#include "SPI_config.h"
#include "SPI_priv.h"

void SPI_vidInit(void)
{
#if SPI_MODE == MASTER
	SPCR |=(1<<4);
#elif SPI_MODE == SLAVE
	SPCR &=~(1<<4);
#endif

#if SPI_PRES == PRES_64
	SPCR |=(1<<1);
	SPCR &=~(1<<0);
#endif

	SPCR |=(1<<6);
}

u8 SPI_vidTranscieve(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while(! ((SPSR>>7)&1));
	return SPDR;
}
