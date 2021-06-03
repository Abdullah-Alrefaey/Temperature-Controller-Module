#include "Seven_Segment.h"
#include "DIO.h"
#include <avr/io.h>

void SevenSegment_SetUp(unsigned char portName)
{
	switch(portName)
	{
		case 'A':
			DIO_Set_PORT_Direction('A', 1);
			break;
			
		case 'B':
			DIO_Set_PORT_Direction('B', 1);
			break;
			
		case 'C':
			DIO_Set_PORT_Direction('C', 1);
			break;
			
		case 'D':
			DIO_Set_PORT_Direction('D', 1);
			break;
	}
}

void SevenSegment_Display(unsigned char portName, unsigned char value)
{
	char numbersArray [] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6D, 0x7d, 0x07, 0x7f, 0x67};
		
	switch(portName)
	{
		case 'A':
			DIO_Write_PORT('A', numbersArray[value]);
			break;
		
		case 'B':
			DIO_Write_PORT('B', numbersArray[value]);
			break;
		
		case 'C':
			DIO_Write_PORT('C', numbersArray[value]);
			break;
		
		case 'D':
			DIO_Write_PORT('D', numbersArray[value]);
			break;
	}
}