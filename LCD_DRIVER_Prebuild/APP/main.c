/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: hamdy
 */

/************** Left-> FUN of display extra charachter **********************/
/************** Left-> FUN of display float number **********************/
#include "../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/errorstate.h"

#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/DIO/DIO_int.h"

#include "../HAL/LCD/LCD_config.h"

int main()
{

	LCD_enuInit();

	LCD_enuJumpTo(1,0);
	LCD_enuSendString("EMBBEDED SYSTEMS");
	LCD_enuJumpTo(2,4);
	LCD_enuSendString("HAMDY");

	while(1);
	return 0;
	}

/*
int main()
{

	u8 hamdy[] = { 0x00, 0x00, 0x06, 0x01, 0x1F, 0x00, 0x00, 0x00		// arabic h
				 , 0x00, 0x00, 0x00, 0x04, 0x1B, 0x04, 0x00, 0x00		// arabic m
				 , 0x00, 0x00, 0x04, 0x04, 0x1E, 0x00, 0x00, 0x00		// arabic d
				 , 0x00, 0x00, 0x03, 0x12, 0x1E, 0x00, 0x00, 0x00		// arabic y
				};

LCD_enuInit();
LCD_enuSendCommand(0x58);	// go to cgram pattern 3

for(int i=0 ; i<32 ; i++)			/////////////// pushing array characters to cgrom	////////////////////
{	LCD_enuSendData(hamdy[i]);	}	////////////// starting from address 0x58 of pat 3  ///////////////////////
									///////////////so we can call them back by their address from ddram as usual //
									   //////////////////////////////////////////////////////////////////////
LCD_enuSendCommand(0x8B);	//  command for ddram to display data starting from address mentioned
LCD_enuSendCommand(0x04);	// command for arabic or typing from right

LCD_enuSendData(3);			// sending data from cgram patterns to ddram to display it
LCD_enuSendData(4);
LCD_enuSendData(5);
LCD_enuSendData(6);

LCD_enuSendCommand(0x06);

LCD_enuSendCommand(0x80);

LCD_enuSendString("hamdy");
LCD_enuSendCommand(0xC1);

LCD_enuDisplayIntNum(2001);

while(1);
return 0;
}
*/


