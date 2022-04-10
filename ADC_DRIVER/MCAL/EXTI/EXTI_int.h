/*
 * EXTI_int.h
 *
 *  Created on: Oct 30, 2021
 *      Author: hamdy
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#include "EXTI_config.h"

ES_T EXTI_enuInit(EXTI_T * Copy_AstrEXTI_CONFIG);

ES_T EXTI_enuSetSenseLevel(u8 Copy_u8InterruptNum , u8 Copy_u8SenseLevel);

ES_T EXTI_enuEnableInterrupt(u8 Copy_u8InterruptNum);

ES_T EXTI_enuDisableInterrupt(u8 Copy_u8InterruptNum);

ES_T EXTI_enuCallBack(volatile void  (*pfunAppFunction)(void) , u8 Copy_u8InterruptNum);


#endif /* MCAL_EXTI_EXTI_INT_H_ */
