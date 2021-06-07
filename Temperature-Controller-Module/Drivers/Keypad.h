/************************************************************************/
/*                          Keypad Driver                               */
/*                   Author: Ahmad Abdalmageed                          */
/************************************************************************/
#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

/************************************************************************/
/* Driver Definitions                                                   */
/************************************************************************/
#define NOTPRESSED 0xff
#define KEYPADPORT 'A'
#define HASH_KEY 12

/************************************************************************/
/* Library Imports                                                      */
/************************************************************************/
#include "DIO.h"
#define DEBOUNCING_COUNTER 1

/************************************************************************/
/* Driver Functions                                                     */
/************************************************************************/

/************************************************************************/
/* Function Description : Keypad Interface Initiators Function          */
/* Function Arguments   : None                                          */ 
/* Function Returns     : None                                          */
/************************************************************************/
void keypad_vInit();

/************************************************************************/
/* Function Description : Main Keypad Function, Checks Pressed Key and  */
/*						  Return It                                     */
/* Function Arguments   : None                                          */
/* Function Returns     : None                                          */
/************************************************************************/
uint8_t keypad_u8check_press();

/************************************************************************/
/* Function Description : Check # Key State Function                    */
/* Function Arguments   : None                                          */
/* Function Returns     : None                                          */
/************************************************************************/
uint8_t keypad_Check_OPKey();

#endif KEYPAD_DRIVER_H_
/************************************************************************/