/*
 * LCD.c
 *
 */ 

#include "LCD.h"
#define  F_CPU 8000000UL 
#include <util/delay.h>

void LCD_vInit(void)
{
	_delay_ms(30);
	
	#if defined eight_bits_mode
		DIO_vsetPINDir(PORT_NAME, 0, 1);
		DIO_vsetPINDir(PORT_NAME, 1, 1);
		DIO_vsetPINDir(PORT_NAME, 2, 1);
		DIO_vsetPINDir(PORT_NAME, 3, 1);
		DIO_vsetPINDir(PORT_NAME, 4, 1);
		DIO_vsetPINDir(PORT_NAME, 5, 1);
		DIO_vsetPINDir(PORT_NAME, 6, 1);
		DIO_vsetPINDir(PORT_NAME, 7, 1);
		DIO_vsetPINDir('B', EN, 1);
		DIO_vsetPINDir('B', RW, 1);
		DIO_vsetPINDir('B', RS, 1);
		DIO_Write_PIN('B', RW, 0);
		
		LCD_vSend_cmd(EIGHT_BITS); // 8-bit mode
		_delay_ms(1);
		
		LCD_vSend_cmd(CURSOR_ON_DISPLAN_ON); // display on cursor on
		
		_delay_ms(1);
		
		LCD_vSend_cmd(CLR_SCREEN); // clear the screen
		_delay_ms(10);
		
		LCD_vSend_cmd(ENTRY_MODE); // entry mode
		_delay_ms(1);
		
	#elif defined four_bits_mode
		DIO_vsetPINDir(PORT_NAME, 4, 1);
		DIO_vsetPINDir(PORT_NAME, 5, 1);
		DIO_vsetPINDir(PORT_NAME, 6, 1);
		DIO_vsetPINDir(PORT_NAME, 7, 1);
		DIO_vsetPINDir(PORT_NAME, EN, 1);
		DIO_vsetPINDir(PORT_NAME, RW, 1);
		DIO_vsetPINDir(PORT_NAME, RS, 1);
   		DIO_Write_PIN(PORT_NAME, RW, 0);
		   
		LCD_vSend_cmd(RETURN_HOME); // return home
		_delay_ms(10);
		
		LCD_vSend_cmd(FOUR_BITS); // 4-bit mode
		_delay_ms(1);
		
		LCD_vSend_cmd(CURSOR_OFF_DISPLAN_ON); // display on cursor off
		_delay_ms(1);
		
		LCD_vSend_cmd(CLR_SCREEN); // clear the screen
		_delay_ms(10);
		
		LCD_vSend_cmd(ENTRY_MODE); // entry mode
		_delay_ms(1);
		
	#endif
}


static void send_falling_edge(void)
{
	/* Used to enable the LCD display 
	*/
	DIO_Write_PIN(PORT_NAME, EN, 1);
	_delay_ms(2);
	DIO_Write_PIN(PORT_NAME, EN, 0);
	_delay_ms(2);
}
void LCD_vSend_cmd(char cmd)
{
	#if defined eight_bits_mode
		DIO_Write_PORT(PORT_NAME, cmd);
		DIO_Write_PIN(PORT_NAME, RS, 0);
		send_falling_edge();
	
	#elif defined four_bits_mode
		DIO_Write_High_Nibble(PORT_NAME, cmd >> 4);
		DIO_Write_PIN(PORT_NAME, RS, 0);
		send_falling_edge();
		DIO_Write_High_Nibble(PORT_NAME, cmd);
		DIO_Write_PIN(PORT_NAME, RS, 0);
		send_falling_edge();
	#endif
	
	_delay_ms(1);
}

void LCD_vSend_char(char data)
{
	#if defined eight_bits_mode
		DIO_Write_PORT(PORT_NAME, data);
		DIO_Write_PIN(PORT_NAME, RS, 1);
		send_falling_edge();
	
	#elif defined four_bits_mode
		DIO_Write_High_Nibble(PORT_NAME, data >> 4);
		DIO_Write_PIN(PORT_NAME, RS, 1);
		send_falling_edge();
		DIO_Write_High_Nibble(PORT_NAME, data);
		DIO_Write_PIN(PORT_NAME, RS, 1);
		send_falling_edge();
	#endif
	
	_delay_ms(1);
}


void LCD_vSend_string(char *data)
{
	while((*data) != '\0')
	{
		LCD_vSend_char(*data);
		data++;
	}
}

void LCD_clearscreen()
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
}

void LCD_movecursor(char row, char coloumn)
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
