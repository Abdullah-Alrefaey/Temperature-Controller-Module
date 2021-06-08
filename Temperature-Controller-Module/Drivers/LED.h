/************************************************************************/
/*                          LED    Driver                               */
/************************************************************************/
#ifndef LED_H_
#define LED_H_
 
/************************************************************************/
/* Driver  Imports                                                      */
/************************************************************************/
#include <stdint.h>
#include "DIO.h"

/************************************************************************/
/* Driver Functions                                                     */
/************************************************************************/

/************************************************************************/
/* Function Description : Initialize the pin as an output pin to connect*/
/*						  the led                                       */
/* Function Arguments   : char portName, uint8_t pinNumber              */
/* Function Returns     : void                                          */
/************************************************************************/
void LED_vInit(char portName, uint8_t pinNumber);

/************************************************************************/
/* Function Description : Turn on the led connected to the given pin    */
/*						  and port                                      */
/* Function Arguments   : char portName, uint8_t pinNumber              */
/* Function Returns     : void                                          */
/************************************************************************/
void LED_vTurnOn(char portName, uint8_t pinNumber);

/************************************************************************/
/* Function Description : Turn OFF the led connected to the given pin   */
/*						  and port                                      */
/* Function Arguments   : char portName, uint8_t pinNumber              */
/* Function Returns     : void                                          */
/************************************************************************/
void LED_vTurnOff(char portName, uint8_t pinNumber);
#endif /* LED_H_ */