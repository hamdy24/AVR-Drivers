/*
 * EXTI_config.h
 *
 *  Created on: Oct 30, 2021
 *      Author: hamdy
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

#define INTERRUPT_NUM	3

typedef struct
	{
		u8 INTERRUPT_STATE;		//ENABELED , DISABELED
		u8 INT_SENSE_LEVEL;		//RISING  , FALLING  , ANY_LOGICAL , LOW_LEVEL

	}EXTI_T;



#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
