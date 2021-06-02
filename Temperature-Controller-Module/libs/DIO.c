#include "std_macros.h"
#include <avr/io.h>

void DIO_vsetPINDir(unsigned char portName, unsigned char pinNumber, unsigned char dir)
{
	// To Set PIN as Output
	// Write 1 in Pin
	
	// To Set PIN as Input
	// Write 0 in Pin

	switch (portName)
	{
		case 'A':
			if (dir == 1)
			{
				// Set the direction of the given pinNumber in port A as output
				SET_BIT(DDRA, pinNumber);
			}
			else if (dir == 0)
			{
				// Set the direction of the given pinNumber in port A as input
				CLR_BIT(DDRA, pinNumber);
			}
			break;

		case 'B':
			if (dir == 1)
			{
				SET_BIT(DDRB, pinNumber);
			}
			else if (dir == 0)
			{
				CLR_BIT(DDRB, pinNumber);
			}
			break;

		case 'C':
			if (dir == 1)
			{
				SET_BIT(DDRC, pinNumber);
			}
			else if (dir == 0)
			{
				CLR_BIT(DDRC, pinNumber);
			}
			break;

		case 'D':
			if (dir == 1)
			{
				SET_BIT(DDRD, pinNumber);
			}
			else if (dir == 0)
			{
				CLR_BIT(DDRD, pinNumber);
			}
			break;
	}
}

void DIO_Write_PIN(unsigned char portName, unsigned char pinNumber, unsigned char value)
{
	switch(portName)
	{
		case 'A':
			if (value == 1)
			{
				// Set the direction of the given pinNumber in port A as high (1)
				SET_BIT(PORTA, pinNumber);
			}
			else if (value == 0)
			{
				// Set the direction of the given pinNumber in port A as low (0)
				CLR_BIT(PORTA, pinNumber);
			}
			break;

		case 'B':
			if (value == 1)
			{
				SET_BIT(PORTB, pinNumber);
			}
			else if (value == 0)
			{
				CLR_BIT(PORTB, pinNumber);
			}
			break;

		case 'C':
			if (value == 1)
			{
				SET_BIT(PORTC, pinNumber);
			}
			else if (value == 0)
			{
				CLR_BIT(PORTC, pinNumber);
			}
			break;

		case 'D':
			if (value == 1)
			{
				SET_BIT(PORTD, pinNumber);
			}
			else if (value == 0)
			{
				CLR_BIT(PORTD, pinNumber);
			}
			break;
	}
}

unsigned char DIO_Read_PIN(unsigned char portName, unsigned char pinNumber)
{
	unsigned char x;
	switch(portName)
	{
		case 'A':
			x = READ_BIT(PINA, pinNumber);
			break;

		case 'B':
			x = READ_BIT(PINB, pinNumber);
			break;

		case 'C':
			x = READ_BIT(PINC, pinNumber);
			break;

		case 'D':
			x = READ_BIT(PIND, pinNumber);
			break;
	}
	return x;
}

void DIO_Toggle_PIN(unsigned char portName, unsigned char pinNumber)
{
	switch(portName)
	{
		case 'A':
			TOGGLE_BIT(PORTA, pinNumber);
			break;

		case 'B':
			TOGGLE_BIT(PORTB, pinNumber);
			break;

		case 'C':
			TOGGLE_BIT(PORTC, pinNumber);
			break;

		case 'D':
			TOGGLE_BIT(PORTD, pinNumber);
			break;
	}
}

void DIO_Set_PORT_Direction(unsigned char portName, unsigned char dir)
{
	// To set port as output -> write 1
	// To set port as input -> write 0

	switch(portName)
	{
		case 'A':
			if (dir == 1)
			{
				DDRA = 0xff;
			}
			else if (dir == 0)
			{
				DDRA = 0x00;
			}
			break;

		case 'B':
			if (dir == 1)
			{
				DDRB = 0xff;
			}
			else if (dir == 0)
			{
				DDRB = 0x00;
			}
			break;

		case 'C':
			if (dir == 1)
			{
				DDRC = 0xff;
			}
			else if (dir == 0)
			{
				DDRC = 0x00;
			}
			break;

		case 'D':
			if (dir == 1)
			{
				DDRD = 0xff;
			}
			else if (dir == 0)
			{
				DDRD = 0x00;
			}
			break;
	}
}

void DIO_Write_PORT(unsigned char portName, unsigned char portValue)
{
	switch(portName)
	{
		case 'A':
			PORTA = portValue;
			break;

		case 'B':
			PORTB = portValue;
			break;

		case 'C':
			PORTC = portValue;
			break;

		case 'D':
			PORTD = portValue;
			break;
	}
}

unsigned char DIO_Read_PORT(unsigned char portName)
{
	unsigned char x;

	switch(portName)
	{
		case 'A':
			x = PINA;
			break;

		case 'B':
			x = PINB;
			break;

		case 'C':
			x = PINC;
			break;

		case 'D':
			x = PIND;
			break;
	}

	return x;
}

void DIO_Toggle_PORT(unsigned char portName)
{
	switch(portName)
	{
		case 'A':
			PORTA = ~PORTA;
			break;

		case 'B':
			PORTB = ~PORTB;
			break;

		case 'C':
			PORTC = ~PORTC;
			break;

		case 'D':
			PORTD = ~PORTD;
			break;
	}
}

void DIO_Connect_PullUp(unsigned char portName, unsigned char pinNumber, unsigned char value)
{
	switch(portName)
	{
		case 'A':
			if (value == 1)
			{
				SET_BIT(PORTA, pinNumber);
			}
			else
			{
				CLR_BIT(PORTA, pinNumber);
			}
			break;
			
		case 'B':
			if (value == 1)
			{
				SET_BIT(PORTB, pinNumber);
			}
			else
			{
				CLR_BIT(PORTB, pinNumber);
			}
			break;
		
		case 'C':
			if (value == 1)
			{
				SET_BIT(PORTC, pinNumber);
			}
			else
			{
				CLR_BIT(PORTC, pinNumber);
			}
			break;
		
		case 'D':
			if (value == 1)
			{
				SET_BIT(PORTD, pinNumber);
			}
			else
			{
				CLR_BIT(PORTD, pinNumber);
			}
			break;
	}
}

void DIO_Write_Low_Nibble(unsigned char portName, unsigned char value)
{
	value &= 0x0f;
	switch(portName)
	{
		case 'A':
			PORTA &= 0xf0;
			PORTA |= value;
			break;
			
		case 'B':
			PORTB &= 0xf0;
			PORTB |= value;
			break;
			
		case 'C':
			PORTC &= 0xf0;
			PORTC |= value;
			break;
			
		case 'D':
			PORTD &= 0xf0;
			PORTD |= value;
			break;
	}
}

void DIO_Write_High_Nibble(unsigned char portName, unsigned char value)
{
	value = value << 4;
	value &= 0xf0;
	switch(portName)
	{
		case 'A':
			PORTA &= 0x0f;
			PORTA |= value;
			break;
		
		case 'B':
			PORTB &= 0x0f;
			PORTB |= value;
			break;
		
		case 'C':
			PORTC &= 0x0f;
			PORTC |= value;
			break;
		
		case 'D':
			PORTD &= 0x0f;
			PORTD |= value;
			break;
	}
}


void DIO_Write_Low_5_Nibble(unsigned char portName, unsigned char value)
{
	unsigned char mask = 0x1f;
	value &= mask;
	
	// value &= 0x1f;

	switch(portName)
	{
		case 'A':
			PORTA &= 0xe0;
			PORTA |= value;
			break;
		
		case 'B':
			PORTB &= ~ (mask);
			PORTB |= value;
			break;
		
		case 'C':
			PORTC &= 0xe0;
			PORTC |= value;
			break;
		
		case 'D':
			PORTD &= 0xe0;
			PORTD |= value;
			break;
	}
}