/************************************************************************/
/*                          LCD Driver                                  */
/************************************************************************/

#ifndef LCD_H_
#define LCD_H_

/************************************************************************/
/*                          Library Imports                             */
/************************************************************************/
#include "DIO.h"
#include "LCD_config.h"

#define F_CPU 16000000UL
#include <util/delay.h>


/************************************************************************/
/* Driver Definitions                                                   */
/************************************************************************/
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

/************************************************************************/
/*                          LCD Functions                               */
/************************************************************************/

/************************************************************************/
/* Function Description : Initialize of LCD and Setup Connected PINs    */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void LCD_vInit(void);

/************************************************************************/
/* Function Description : Send Falling Edge to Enable LCD Display       */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void send_falling_edge(void);

/************************************************************************/
/* Function Description : Send A Command (in Hex) to the LCD            */
/* Function Arguments   : char cmd: hex value to send to LCD Register   */
/* Function Returns     : void                                          */
/************************************************************************/
void LCD_vSend_cmd(char cmd);

/************************************************************************/
/* Function Description : Display a character on LCD                    */
/* Function Arguments   : char data: character to be displayed on LCD   */
/* Function Returns     : void                                          */
/************************************************************************/
void LCD_vSend_char(char data);

/************************************************************************/
/* Function Description : Display a string on LCD                       */
/* Function Arguments   : char *data: string to be displayed on LCD     */
/* Function Returns     : void                                          */
/************************************************************************/
void LCD_vSend_string(char *data);

/************************************************************************/
/* Function Description : Clear the entire Display off the LCD          */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void LCD_clearscreen(void);

/************************************************************************/
/* Function Description : Display a character on LCD                    */
/* Function Arguments   : uint8_t row: row number (1 or 2)              */
/*                      : uint8_t col: col number (1 -> 16)             */
/* Function Returns     : void                                          */
/************************************************************************/
void LCD_movecursor(uint8_t row, uint8_t coloumn);

/************************************************************************/
/* Function Description : Shift the Entire Display of the LCD           */
/* Function Arguments   : uint8_t direction: 0 -> Left or 1 -> Right    */
/* Function Returns     : void                                          */
/************************************************************************/
void LCD_vShiftDisplay(uint8_t direction);

#endif /* LCD_H_ */