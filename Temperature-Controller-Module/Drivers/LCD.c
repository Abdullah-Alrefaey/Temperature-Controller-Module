/************************************************************************/
/*                          LCD Driver                                  */
/************************************************************************/

#include "LCD.h"

extern char PORTS[4];


/************************************************************************/
/* Function Description:                                                */
/* Initialize of LCD in eight_bits_mode or four_bits_mode depending on  */
/* the defined mode in LCD.h file.                                      */
/* This mode will be checked in each function                           */
/************************************************************************/
void LCD_vInit(void)
{
	#if defined FOUR_BITS_MODE
		DIO_vsetPINDir(PORTS[LCD_PORT], 4, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], 5, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], 6, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], 7, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], EN, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], RW, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], RS, 1);
		DIO_Write_PIN(PORTS[LCD_PORT], RW, 0);
		
		/* Send Return Home Command */
		LCD_vSend_cmd(RETURN_HOME);
		
		/* This is unnecessary delays */
		/*_delay_ms(10);*/
		
		/* Enable 4-bit Mode */
		LCD_vSend_cmd(FOUR_BITS);
		/*_delay_ms(1);*/
		
		/* Display ON, Cursor OFF */
		LCD_vSend_cmd(CURSOR_OFF_DISPLAN_ON);
		/*_delay_ms(1);*/
		
		/* Clear The Entire Screen */
		LCD_vSend_cmd(CLR_SCREEN);
		/*_delay_ms(10);*/
		
		/* Choose Entry Mode */
		LCD_vSend_cmd(ENTRY_MODE);
		/*_delay_ms(1);*/
		
	#endif	
	
	/*_delay_ms(30);*/
		
	/*#if defined FOUR_BITS_MODE
		DIO_vsetPINDir(PORTS[LCD_PORT], 4, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], 5, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], 6, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], 7, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], EN, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], RW, 1);
		DIO_vsetPINDir(PORTS[LCD_PORT], RS, 1);
   		DIO_Write_PIN(PORTS[LCD_PORT], RW, 0);
		   
		/ * Send Return Home Command * /
		LCD_vSend_cmd(RETURN_HOME);
		
		/ * This is unnecessary delays * /
		/ *_delay_ms(10);* /
		
		/ * Enable 4-bit Mode * /
		LCD_vSend_cmd(FOUR_BITS);
		/ *_delay_ms(1);* /
		
		/ * Display ON, Cursor OFF * /
		LCD_vSend_cmd(CURSOR_OFF_DISPLAN_ON); 
		/ *_delay_ms(1);* /
		
		/ * Clear The Entire Screen * /
		LCD_vSend_cmd(CLR_SCREEN); 
		/ *_delay_ms(10);* /
		
		/ * Choose Entry Mode * /
		LCD_vSend_cmd(ENTRY_MODE);
		/ *_delay_ms(1);* /
		
	#endif*/
}

/************************************************************************/
/* Function Description:                                                */
/* Send Falling Edge to Enable LCD Display by setting the EN PIN in the */
/* LCD for 2 ms then clear it                                           */
/************************************************************************/
void send_falling_edge(void)
{
	/* Used to enable the LCD display 
	*/
	DIO_Write_PIN(PORTS[LCD_PORT], EN, 1);
	_delay_ms(2);
	DIO_Write_PIN(PORTS[LCD_PORT], EN, 0);
	_delay_ms(2);
}

/************************************************************************/
/* Function Description:                                                */
/* Send a hex command to the LCD Register to execute a specific command */
/* Commands such as clearing the screen or shift the cursor,.. etc.     */
/************************************************************************/
void LCD_vSend_cmd(char cmd)
{
	#if defined EIGHT_BITS_MODE
		DIO_Write_PORT(PORTS[LCD_PORT], cmd);
		DIO_Write_PIN(PORTS[LCD_PORT], RS, 0);
		send_falling_edge();
	
	#elif defined FOUR_BITS_MODE
		DIO_Write_High_Nibble(PORTS[LCD_PORT], cmd >> 4);
		DIO_Write_PIN(PORTS[LCD_PORT], RS, 0);
		send_falling_edge();
		DIO_Write_High_Nibble(PORTS[LCD_PORT], cmd);
		DIO_Write_PIN(PORTS[LCD_PORT], RS, 0);
		send_falling_edge();
	#endif
	
	/* Required from Datasheet of the LCD */
	_delay_ms(1);
}

/************************************************************************/
/* Function Description:                                                */
/* Display the given character on the LCD                               */
/************************************************************************/
void LCD_vSend_char(char data)
{
	#if defined EIGHT_BITS_MODE
		DIO_Write_PORT(PORTS[LCD_PORT], data);
		DIO_Write_PIN(PORTS[LCD_PORT], RS, 1);
		send_falling_edge();
	
	#elif defined FOUR_BITS_MODE
		DIO_Write_High_Nibble(PORTS[LCD_PORT], data >> 4);
		DIO_Write_PIN(PORTS[LCD_PORT], RS, 1);
		send_falling_edge();
		DIO_Write_High_Nibble(PORTS[LCD_PORT], data);
		DIO_Write_PIN(PORTS[LCD_PORT], RS, 1);
		send_falling_edge();
	#endif
	
	_delay_ms(1);
}

/************************************************************************/
/* Function Description:                                                */
/* Display the given string on the LCD by displaying each character in  */
/* a loop till the string ends.                                         */
/************************************************************************/
void LCD_vSend_string(char *data)
{
	while((*data) != '\0')
	{
		LCD_vSend_char(*data);
		data++;
	}
}

/************************************************************************/
/* Function Description:                                                */
/* Clear The Entire Screen by sending a specific command to the LCD     */
/************************************************************************/
void LCD_vClear_Screen(void)
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(1);
}

/************************************************************************/
/* Function Description:                                                */
/* Move the cursor to the specified location as row and column          */
/************************************************************************/
void LCD_vMove_Cursor(uint8_t row, uint8_t coloumn)
{
	char data = 0;
	
	/* 
	 * Address of first row column 1 : 0x80 + 0
	 * Address of first row column 2 : 0x80 + 1
	 *
     * Address of second row column 1 : 0xC0 + 0
	 * Address of second row column 2 : 0XC0 + 1
	 */

	/* Move Cursor to first row column 1*/	
	if(row > 2 || row < 1 || coloumn > 16 || coloumn < 1)
	{
		data = 0x80;
	}
	
	else if(row == 1)
	{
		data = 0x80 + (coloumn - 1);
	}
	
	else if (row == 2)
	{
		data = 0xc0 + (coloumn - 1);
	}
	
	LCD_vSend_cmd(data);
	
	_delay_ms(1);
}

/************************************************************************/
/* Function Description:                                                */
/* Shift the Entire Display of the LCD by sending a specific command to */
/* the LCD. Doesn't require shifting the cursor and write a new value.  */
/************************************************************************/
void LCD_vShiftDisplay(uint8_t direction)
{
	/* Shift Left */
	if (direction == 1)
	{
		LCD_vSend_cmd(SHIFT_LEFT);
	}
	else if (direction == 0)
	{
		LCD_vSend_cmd(SHIFT_RIGHT);
	}
	
}
