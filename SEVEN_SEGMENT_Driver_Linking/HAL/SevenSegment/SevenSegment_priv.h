/*
 * SevenSegment_priv.h
 *
 *  Created on: Oct 11, 2021
 *      Author: hamdy
 */

#ifndef SEVENSEGMENT_PRIV_H_
#define SEVENSEGMENT_PRIV_H_

#define CMN_CATHOD		99
#define CMN_ANODE		66

#define NOT_CONNECTED	55

/*
static volatile u8 SevenSegment_u8Au8CMN_CTH_Values[] =
{	0x0F , 0x1F , 0x2F , 0x3F ,
    0x4F , 0x5F , 0x6F , 0x7F ,
	0x8F , 0x9F
};
*/

static volatile u8 SevenSegment_u8Au8CMN_CTH_Values[] =
{	0x3F,0x06,0x5B,0x4F,
	0x66,0x6D,0x7D,0x07,
	0x7F,0x6F
};

#endif /* SEVENSEGMENT_PRIV_H_ */
