/************************************************************************/
/*                          Keypad Driver                               */
/************************************************************************/
#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

/************************************************************************/
/* Driver Definitions                                                   */
/************************************************************************/
#define NOTPRESSED 0xff
#define KEYPADPORT 0
#define HASH_KEY 12
#define DEBOUNCING_COUNTER 1

/************************************************************************/
/* Driver Imports                                                       */
/************************************************************************/
#include "DIO.h"

/************************************************************************/
/* Driver Functions                                                     */
/************************************************************************/

/************************************************************************/
/* Function Description : Keypad Interface Initiators Function          */
/* Function Arguments   : void                                          */ 
/* Function Returns     : void                                          */
/************************************************************************/
void keypad_vInit(void);

/************************************************************************/
/* Function Description : Main Keypad Function, Checks Pressed Key and  */
/*						  Return It                                     */
/* Function Arguments   : void                                          */
/* Function Returns     : uint8_t                                       */
/************************************************************************/
uint8_t keypad_u8check_press(void);

/************************************************************************/
/* Function Description : Check # Key State Function                    */
/* Function Arguments   : void                                          */
/* Function Returns     : uint8_t                                       */
/************************************************************************/
uint8_t keypad_Check_OPKey(void);

#endif /*KEYPAD_DRIVER_H_*/
/************************************************************************/