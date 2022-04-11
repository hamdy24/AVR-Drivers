/*
 * LCD_priv.h
 *
 *  Created on: Oct 13, 2021
 *      Author: hamdy
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define FOUR_BIT						44
#define EIGHT_BIT						88

#define FUNC_SET_FOUR_BIT				0x28
#define FUNC_SET_EIGHT_BIT				0x38

#define DIS_ON__CURSOR_ON_BLINKING		0x0f
#define CLEAR_DISPLAY					0x01
#define ENTRY_MOOD						0x06

#define MASK_BIT						1

#define SHIFT_PIN_7						7
#define SHIFT_PIN_6						6
#define SHIFT_PIN_5						5
#define SHIFT_PIN_4						4
#define SHIFT_PIN_3						3
#define SHIFT_PIN_2						2
#define SHIFT_PIN_1						1
#define SHIFT_PIN_0						0

#define START_OF_LINE1					0x80
#define START_OF_LINE2					0xC0


static ES_T LCD_enuWriteAndLatch(u8 Copy_u8Data);


/**************************************** LCD COMMANDS ******************************************************
0F	LCD ON, cursor ON
01	Clear display screen
02	Return home
04	Decrement cursor (shift cursor to left)
06	Increment cursor (shift cursor to right)
05	Shift display right
07	Shift display left
0E	Display ON, cursor blinking
80	Force cursor to beginning of first line
C0	Force cursor to beginning of second line
38	2 lines and 5×7 matrix
83	Cursor line 1 position 3
3C	Activate second line
08	Display OFF, cursor OFF
C1	Jump to second line, position 1
OC	Display ON, cursor OFF
C1	Jump to second line, position 1
C2	Jump to second line, position 2
 */

#endif /* LCD_PRIV_H_ */
