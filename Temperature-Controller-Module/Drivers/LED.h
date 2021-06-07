/*
 * LED.h
 *
 * Created: 07-Sep-19 4:56:29 PM
 *  Author: Abdullah Mohammed
 */ 


#ifndef LED_H_
#define LED_H_

#include <stdint.h>

/*
	Function Name        : LED_vInit
	Function Returns     : void
	Function Arguments   : char portName, uint8_t pinNumber
	Function Description : Initialize the pin as an output pin to connect the led.
*/
void LED_vInit(char portName, uint8_t pinNumber);

/*
	Function Name        : LED_vTurnOn
	Function Returns     : void
	Function Arguments   : char portName, uint8_t pinNumber
	Function Description : Turn on the led connected to the given pin and port.
*/
void LED_vTurnOn(char portName, uint8_t pinNumber);

/*
	Function Name        : LED_vTurnOff
	Function Returns     : void
	Function Arguments   : char portName, uint8_t pinNumber
	Function Description : Turn off the led connected to the given pin and port.
*/
void LED_vTurnOff(char portName, uint8_t pinNumber);

/*
	Function Name        : LED_vToggle
	Function Returns     : void
	Function Arguments   : char portName, uint8_t pinNumber
	Function Description : Toggle the led connected to the given pin and port.
*/
void LED_vToggle(char portName, uint8_t pinNumber);


/*
	Function Name        : LED_u8ReadStatus
	Function Returns     : unsigned char
	Function Arguments   : char portName, uint8_t pinNumber
	Function Description : Returns 0 if the led connected to the given port and pin is off or return 1 if it was on.
*/
unsigned char LED_u8ReadStatus(char portName, uint8_t pinNumber);

#endif /* LED_H_ */