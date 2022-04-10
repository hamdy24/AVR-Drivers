/*
 * H_Bridge_program.c
 *
 *  Created on: Nov 11, 2021
 *      Author: hamdy
 */

#include "../../LIBRARIES/errorstate.h"
#include "../../LIBRARIES/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "H_Bridge_private.h"
#include "H_Bridge_config.h"



ES_t H_Bridge_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

#if MOTOR1_STATE == CONNECTED

	DIO_enuSetPinDirection(MOTOR1_EN_PORT,MOTOR1_EN_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinValue(MOTOR1_EN_PORT,MOTOR1_EN_PIN,DIO_u8HIGH);

	if(MOTOR1_DIR == CW)
	{

		DIO_enuSetPinDirection(MOTOR1_INPUT_PORT , MOTOR1_INPUT_PIN , DIO_u8OUTPUT);
		DIO_enuSetPinValue(MOTOR1_INPUT_PORT , MOTOR1_INPUT_PIN , DIO_u8HIGH);

		DIO_enuSetPinDirection(MOTOR1_OUTPUT_PORT , MOTOR1_OUTPUT_PIN , DIO_u8OUTPUT);
		DIO_enuSetPinValue(MOTOR1_OUTPUT_PORT , MOTOR1_OUTPUT_PIN , DIO_u8LOW);

		Local_enuErrorState = ES_OK;
	}
	else if(MOTOR1_DIR == CCW)
	{
		DIO_enuSetPinDirection(MOTOR1_INPUT_PORT , MOTOR1_INPUT_PIN , DIO_u8OUTPUT);
		DIO_enuSetPinValue(MOTOR1_INPUT_PORT , MOTOR1_INPUT_PIN , DIO_u8LOW);

		DIO_enuSetPinDirection(MOTOR1_OUTPUT_PORT , MOTOR1_OUTPUT_PIN , DIO_u8OUTPUT);
		DIO_enuSetPinValue(MOTOR1_OUTPUT_PORT , MOTOR1_OUTPUT_PIN , DIO_u8HIGH);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

#endif

#if MOTOR2_STATE == CONNECTED

	DIO_enuSetPinDirection(MOTOR2_EN_PORT,MOTOR2_EN_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinValue(MOTOR2_EN_PORT,MOTOR2_EN_PIN,DIO_u8HIGH);

	if(MOTOR2_DIR == CW)
	{

		DIO_enuSetPinDirection(MOTOR2_INPUT_PORT , MOTOR2_INPUT_PIN , DIO_u8OUTPUT);
		DIO_enuSetPinValue(MOTOR2_INPUT_PORT , MOTOR2_INPUT_PIN , DIO_u8HIGH);

		DIO_enuSetPinDirection(MOTOR2_OUTPUT_PORT , MOTOR2_OUTPUT_PIN , DIO_u8OUTPUT);
		DIO_enuSetPinValue(MOTOR2_OUTPUT_PORT , MOTOR2_OUTPUT_PIN , DIO_u8LOW);

		Local_enuErrorState = ES_OK;
	}
	else if(MOTOR2_DIR == CCW)
	{
		DIO_enuSetPinDirection(MOTOR2_INPUT_PORT , MOTOR2_INPUT_PIN , DIO_u8OUTPUT);
		DIO_enuSetPinValue(MOTOR2_INPUT_PORT , MOTOR2_INPUT_PIN , DIO_u8LOW);

		DIO_enuSetPinDirection(MOTOR2_OUTPUT_PORT , MOTOR2_OUTPUT_PIN , DIO_u8OUTPUT);
		DIO_enuSetPinValue(MOTOR2_OUTPUT_PORT , MOTOR2_OUTPUT_PIN , DIO_u8HIGH);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

#endif

		return Local_enuErrorState;
}
