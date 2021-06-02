/*
 * LED.c
 *
 * Created: 07-Sep-19 4:56:14 PM
 *  Author: Abdullah Mohammed
 */ 

#include "LED.h"
#include "DIO.h"



void LED_vInit(unsigned char portName, unsigned char pinNumber)
{
	// Set the given pin in the given port as an output
	// Write 1 on the pin
	DIO_vsetPINDir(portName, pinNumber, 1);
}

void LED_vTurnOn(unsigned char portName, unsigned char pinNumber)
{
	// Set the given pin in the given port to one (on)
	DIO_Write_PIN(portName, pinNumber, 1);
}

void LED_vTurnOff(unsigned char portName, unsigned char pinNumber)
{
	// Set the given pin in the given port to zero (off)
	DIO_Write_PIN(portName, pinNumber, 0);
}

void LED_vToggle(unsigned char portName, unsigned char pinNumber)
{
	// Set the given pin in the given port to zero if it is one or set it to one if it is zero
	DIO_Toggle_PIN(portName, pinNumber);
}

unsigned char LED_u8ReadStatus(unsigned char portName, unsigned char pinNumber)
{
	// Return the current status of the given pin
	return DIO_Read_PIN(portName, pinNumber);
}
