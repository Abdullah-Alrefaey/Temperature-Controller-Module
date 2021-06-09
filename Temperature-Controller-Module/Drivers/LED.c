/************************************************************************/
/*                          LED    Driver                               */
/************************************************************************/
#include "LED.h"




void LED_vInit(char portName, uint8_t pinNumber)
{
	/* Set the given pin in the given port as an output
	   Write 1 on the pin */
	DIO_vsetPINDir(portName, pinNumber, 1U);
}

void LED_vTurnOn(char portName, uint8_t pinNumber)
{
	/* Set the given pin in the given port to one (on) */
	DIO_Write_PIN(portName, pinNumber, 1U);
}

void LED_vTurnOff(char portName, uint8_t pinNumber)
{
	/* Set the given pin in the given port to zero (off) */
	DIO_Write_PIN(portName, pinNumber, 0U);
}
