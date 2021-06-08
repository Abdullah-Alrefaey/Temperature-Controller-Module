/************************************************************************/
/*                          LED    Driver                               */
/************************************************************************/
#include "LED.h"




void LED_vInit(char portName, uint8_t pinNumber)
{
	// Set the given pin in the given port as an output
	// Write 1 on the pin
	DIO_vsetPINDir(portName, pinNumber, 1);
}

void LED_vTurnOn(char portName, uint8_t pinNumber)
{
	// Set the given pin in the given port to one (on)
	DIO_Write_PIN(portName, pinNumber, 1);
}

void LED_vTurnOff(char portName, uint8_t pinNumber)
{
	// Set the given pin in the given port to zero (off)
	DIO_Write_PIN(portName, pinNumber, 0);
}

void LED_vToggle(char portName, uint8_t pinNumber)
{
	// Set the given pin in the given port to zero if it is one or set it to one if it is zero
	DIO_Toggle_PIN(portName, pinNumber);
}

unsigned char LED_u8ReadStatus(char portName, uint8_t pinNumber)
{
	// Return the current status of the given pin
	return DIO_Read_PIN(portName, pinNumber);
}
