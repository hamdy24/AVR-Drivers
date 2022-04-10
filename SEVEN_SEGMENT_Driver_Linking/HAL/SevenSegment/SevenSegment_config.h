/*
 * SevenSegment_config.h
 *
 *  Created on: Oct 11, 2021
 *      Author: hamdy
 */

#ifndef SEVENSEGMENT_CONFIG_H_
#define SEVENSEGMENT_CONFIG_H_

#define SSG_NUM			2		/* Seven Segment Number */
#define DECODER			NO		/* YES or NO */

typedef struct
{
	u8 A_Port;	u8 A_Pin;	u8 B_Port;	u8 B_Pin;
	u8 C_Port;	u8 C_Pin;	u8 D_Port;	u8 D_Pin;
	u8 E_Port;	u8 E_Pin;	u8 F_Port;	u8 F_Pin;
	u8 G_Port;	u8 G_Pin;

	u8 CMN_Port;	u8 CMN_Pin;
	u8 Dot_Port;	u8 Dot_Pin;

	u8 SSG_Type;
}SSG_T;


#endif /* SEVENSEGMENT_CONFIG_H_ */
