/*
 * Seven_Segment_BCD_ETA32.c
 *
 * Created: 10-Apr-21 2:49:01 PM
 *  Author: Refaey
 */ 

#include "Seven_Segment_BCD_ETA32.h"
#include "DIO.h"

#define SEG1_EN_PIN 3
#define SEG2_EN_PIN 2
#define SEG3_EN_PIN 5
#define SEG4_EN_PIN 6

void SevenSegment_BCD_ETA32_SetUp(unsigned char portName)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		DIO_vsetPINDir(portName, i, 1);
	}
	DIO_vsetPINDir(portName, 4, 1);
	
	// Setup ENABLE PINs
	DIO_vsetPINDir('A', SEG1_EN_PIN, 1);
	DIO_vsetPINDir('A', SEG2_EN_PIN, 1);
	DIO_vsetPINDir('B', SEG3_EN_PIN, 1);
	DIO_vsetPINDir('B', SEG4_EN_PIN, 1);
}


void SevenSegment_BCD_ETA32_Display(unsigned char portName, unsigned char value)
{
	char numbersArray_ETA32 [] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x10, 0x11};
	
	// Set the low 5 nibble with the given value
	DIO_Write_Low_5_Nibble(portName, numbersArray_ETA32[value]);
	
}


void SevenSegment_BCD_ETA32_Enable(unsigned char portName, unsigned char pinNumber)
{
	// Write 1 on the given pin to enable the seven segment
	DIO_Write_PIN(portName, pinNumber, 1);
}

void SevenSegment_BCD_ETA32_Disable(unsigned char portName, unsigned char pinNumber)
{
	// Write 0 on the given pin to enable the seven segment
	DIO_Write_PIN(portName, pinNumber, 0);
}