/************************************************************************/
/*                          Keypad Driver                               */
/************************************************************************/
#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

/************************************************************************/
/* Driver Definitions                                                   */
/************************************************************************/
#define NOTPRESSED 0xffU
#define KEYPADPORT 0U
#define HASH_KEY 12U
#define DEBOUNCING_COUNTER 1U

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
