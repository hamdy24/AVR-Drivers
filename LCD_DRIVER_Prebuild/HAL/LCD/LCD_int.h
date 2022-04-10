/*
 * LCD_int.h
 *
 *  Created on: Oct 13, 2021
 *      Author: hamdy
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_T LCD_enuInit(void);

ES_T LCD_enuSendData(u8 Copy_u8Data);

ES_T LCD_enuSendCommand(u8 Copy_u8Command);

ES_T LCD_enuSendString(const char * Copy_pcString);

ES_T LCD_enuJumpTo( u8 Copy_u8Line_Order , u8 Copy_u8Line_Position);

ES_T LCD_enuDisplayExtraCharachter(u8 * Copy_u8pAu8CharHEXA , u8 Copy_u8NumOfPattern , u8 Copy_u8InputDirection);  // (arr , 3 , right)

ES_T LCD_enuDisplayIntNum(s32 Copy_s32IntNumber);

ES_T LCD_enuDisplayFloatNum(f32 Copy_f32FloatNumber);




#endif /* LCD_INT_H_ */
