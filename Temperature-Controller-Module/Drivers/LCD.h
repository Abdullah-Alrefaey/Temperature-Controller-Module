/*
 * LCD.h
 *
 */ 

#ifndef LCD_H_
#define LCD_H_

#include "DIO.h"
#include "LCD_config.h"

#define F_CPU 16000000UL

#include <util/delay.h>

#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define CURSOR_OFF_DISPLAN_ON 0x0c
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define SHIFT_LEFT 0x18
#define SHIFT_RIGHT 0x1c

#if defined four_bits_mode
#define RS 1
#define RW 2
#define EN 3
#define FOUR_BITS 0x28

#elif defined eight_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif

void LCD_vInit(void);
static void send_falling_edge(void);
void LCD_vSend_cmd(char cmd);
void LCD_vSend_char(char data);
void LCD_vSend_string(char *data);
void LCD_clearscreen();
void LCD_movecursor(char row, char coloumn);
void LCD_vShiftDisplay(uint8_t direction);

#endif /* LCD_H_ */