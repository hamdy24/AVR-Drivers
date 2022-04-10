/*
 * ADC_interface.h
 *
 *  Created on: Nov 15, 2021
 *      Author: hamdy
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

ES_T  ADC_enuInit(void);

ES_T  ADC_enuStart_Conversion(void);

ES_T  ADC_enuRead_High_Registers(u8 * Copy_pu8Higher_Value);

ES_T  ADC_enuFully_Read(u16 * Copy_pu16Full_Value);

ES_T  ADC_enuEnable_AutoTriggering(u8 Copy_u8INT_Source);

ES_T  ADC_enuDisable_AutoTriggering(void);

ES_T  ADC_enuSelect_Channel(u8 Copy_u8Channel_ID);

ES_T  ADC_enuEnable_ADC(void);

ES_T  ADC_enuDisable_ADC(void);

ES_T  ADC_enuEnable_ADC_INT(void);

ES_T  ADC_enuDisable_ADC_INT(void);

ES_T  ADC_enuPolling(void);

ES_T  ADC_enuCall_Back(volatile void (*Copy_pfun_AppFun) (void));

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
