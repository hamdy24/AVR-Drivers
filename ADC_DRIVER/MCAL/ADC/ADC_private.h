/*
 * ADC_private.h
 *
 *  Created on: Nov 15, 2021
 *      Author: hamdy
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define PRES_2			22
#define PRES_4			44
#define PRES_8			88
#define PRES_16			16
#define PRES_32			32
#define PRES_64			64
#define PRES_128		128



#define AREF_REF		34
#define AVCC_REF		55
#define INTERNAL_REF	256


#define LEFT_ADJ		99
#define RIGHT_ADJ		66

	/* auto triggering modes */
#define FREE_RUNNIG					0
#define ANALOG_COMPARATOR			1
#define EXTI_INT_0					2
#define TIMER_0_COMPARE_MATCH		3
#define TIMER_0_OVERFLOW			4
#define TIMER_COMPARE_MATCH_B		5
#define TIMER_1_OVERFLOW			6
#define TIMER_1_CAPTURE_EVENT		7
/////////////////////////////////////

#define MASK_BIT 						1

#define PRES2_DIVISION_FACTOR_SET		0x01
#define PRES4_DIVISION_FACTOR_SET		0x02
#define PRES8_DIVISION_FACTOR_SET		0x03
#define PRES16_DIVISION_FACTOR_SET		0x04
#define PRES32_DIVISION_FACTOR_SET		0x05
#define PRES64_DIVISION_FACTOR_SET		0x06
#define PRES128_DIVISION_FACTOR_SET		0x07

#define REFS0_BIT_6						6	// of ADMUX
#define REFS1_BIT_7						7	// of ADMUX

#define ADLAR_BIT_5						5	// of ADMUX

#define START_CONVERSION_BIT			6  // of ADCSRA

#define ADC_ENABLE_BIT_7				7 // of ADCSRA

#define ADC_INT_ENABLE_BIT_3			3 // of ADCSRA

#define ADCIF_BIT_4						4
#define LOGIC_ONE						1


#define SFIOR 	*((volatile u8*) 0x50)  // auto trigger mode select register

#define ADC_AUTO_TRIGGER_BIT_5			5

#define ADC_TRIGGER_SELECT_BIT_5		5
#define SFIOR_MASK_VALUE				0x1F
#define ADMUX_CHANNELS_MASK_VALUE		0x1F


#define CHANNEL_NUM_0	     0
#define CHANNEL_NUM_1	     1
#define CHANNEL_NUM_2	     2
#define CHANNEL_NUM_3	     3
#define CHANNEL_NUM_4	     4
#define CHANNEL_NUM_5	     5
#define CHANNEL_NUM_6	     6
#define CHANNEL_NUM_7	     7
#define CHANNEL_NUM_8	     8
#define CHANNEL_NUM_9	     9
#define CHANNEL_NUM_10       10
#define CHANNEL_NUM_11       11
#define CHANNEL_NUM_12       12
#define CHANNEL_NUM_13       13
#define CHANNEL_NUM_14       14
#define CHANNEL_NUM_15       15
#define CHANNEL_NUM_16       16
#define CHANNEL_NUM_17       17
#define CHANNEL_NUM_18       18
#define CHANNEL_NUM_19       19
#define CHANNEL_NUM_20       20
#define CHANNEL_NUM_21       21
#define CHANNEL_NUM_22       22
#define CHANNEL_NUM_23       23
#define CHANNEL_NUM_24       24
#define CHANNEL_NUM_25       25
#define CHANNEL_NUM_26       26
#define CHANNEL_NUM_27       27
#define CHANNEL_NUM_28       28
#define CHANNEL_NUM_29       29
#define CHANNEL_NUM_30       30
#define CHANNEL_NUM_31       31

/**** INTERRUPT REGISTERS ****/

#define MCUCR 	*((volatile u8*) 0x55)
#define MCUCSR	*((volatile u8*) 0x54)
#define GICR 	*((volatile u8*) 0x5b)
#define SREG  	*((volatile u8*) 0x5f)
#define GIFR  	*((volatile u8*) 0x5a)

/**** ADC REGISTERS *****/
#define ADMUX	*((volatile u8*) 0x27)
#define ADCSRA	*((volatile u8*) 0x26)
#define ADCH	*((volatile u8*) 0x25)
#define ADCL	*((volatile u8*) 0x24)


#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
