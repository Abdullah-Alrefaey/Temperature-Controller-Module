#include "Seven_Segment_BCD.h"
#include "DIO.h"
#include <avr/io.h>

void SevenSegment_BCD_SetUp(unsigned char portName, unsigned char mode)
{

    // mode 0 -> low nibble
    // mode 1 -> high nibble

    int pinNumber;

	switch(mode)
	{
		case '0':
            // Set the low nibble as output for the given port
			for (pinNumber = 0; pinNumber <= 3; pinNumber++)
			{
				DIO_vsetPINDir(portName, pinNumber, 1);
			}
			break;

		case '1':
			for (pinNumber = 4; pinNumber <= 7; pinNumber++)
			{
				DIO_vsetPINDir(portName, pinNumber, 1);
			}
			break;
	}    
}

void SevenSegment_BCD_Display(unsigned char portName, unsigned char mode, unsigned char value)
{

    // mode 0 -> low nibble
    // mode 1 -> high nibble

	switch(mode)
	{
		case '0':
            // Set the low nibble with the given value
			DIO_Write_Low_Nibble(portName, value);
			break;

		case '1':
            DIO_Write_High_Nibble(portName, value);
			break;		
	}
}