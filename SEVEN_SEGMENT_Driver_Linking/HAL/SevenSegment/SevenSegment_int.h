/*
 * SevenSegment_int.h
 *
 *  Created on: Oct 11, 2021
 *      Author: hamdy
 */

#ifndef SEVENSEGMENT_INT_H_
#define SEVENSEGMENT_INT_H_

#include "SevenSegment_config.h"

ES_T SevenSegment_enuInit(SSG_T * Copy_AstrSSG_Config);

ES_T SevenSegment_enuDisplayNum(SSG_T * Copy_pstrSSG_Info , u8 Copy_u8Number);

ES_T SevenSegment_enuStopDisplay(SSG_T * Copy_pstrSSG_Info);

ES_T SevenSegment_enuShowDot(SSG_T * Copy_pstrSSG_Info);

ES_T SevenSegment_enuHideDot(SSG_T * Copy_pstrSSG_Info);

ES_T SevenSegment_enuEnableCMN(SSG_T * Copy_pstrSSG_Info);

ES_T SevenSegment_enuDisableCMN(SSG_T * Copy_pstrSSG_Info);


#endif /* SEVENSEGMENT_INT_H_ */
