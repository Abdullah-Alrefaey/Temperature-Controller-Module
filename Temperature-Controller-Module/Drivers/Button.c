#include "Button.h"
#include "DIO.h"

void Button_Initialize(unsigned char portName, unsigned char pinNumber)
{
	// Set the direction of the given pin in the given port (direction 0 = input)
	DIO_vsetPINDir(portName, pinNumber, 0);
}

unsigned char Button_Read(unsigned char portName, unsigned char pinNumber)
{
	unsigned char x;
	// Returns 1 if the value of the given pin is high and zero if the value is low
	x = DIO_Read_PIN(portName, pinNumber);
	return x;
}