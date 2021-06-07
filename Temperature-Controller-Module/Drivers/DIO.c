/************************************************************************/
/*                          DIO Driver                                  */
/************************************************************************/
#include "DIO.h"


void DIO_vsetPINDir(char portName, uint8_t pinNumber, uint8_t dir)
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
				DDRA |= (U_ONE << pinNumber);
			}
			else if (dir == 0)
			{
				// Set the direction of the given pinNumber in port A as input
				DDRA &= ~(U_ONE << pinNumber);
			}
			else
			{
				// Nothing
			}
			break;

		case 'B':
			if (dir == 1)
			{
				DDRB |= (U_ONE << pinNumber);
			}
			else if (dir == 0)
			{
				DDRB &= ~(U_ONE << pinNumber);
			}
			else
			{
				// Nothing
			}
			break;

		case 'C':
			if (dir == 1)
			{
				DDRC |= (U_ONE << pinNumber);
			}
			else if (dir == 0)
			{
				DDRC &= ~(U_ONE << pinNumber);
			}
			else
			{
				// Nothing
			}

			break;

		case 'D':
			if (dir == 1)
			{
				DDRD |= (U_ONE << pinNumber);
			}
			else if (dir == 0)
			{
				DDRD &= ~(U_ONE << pinNumber);
			}
			else
			{
				// Nothing
			}

			break;
		default:
			break;
	}
}

void DIO_Write_PIN(char portName, uint8_t pinNumber, uint8_t value)
{
	switch(portName)
	{
		case 'A':
			if (value == 1)
			{
				// Set the direction of the given pinNumber in port A as high (1)
				PORTA |= (U_ONE << pinNumber);
			}
			else if (value == 0)
			{
				// Set the direction of the given pinNumber in port A as low (0)
				PORTA &= ~(U_ONE << pinNumber);
			}
			else
			{
				// Nothing
			}

			break;

		case 'B':
			if (value == 1)
			{
				PORTB |= (U_ONE << pinNumber);
			}
			else if (value == 0)
			{
				PORTB &= ~(U_ONE << pinNumber);
			}
			else
			{
				// Nothing
			}

			break;

		case 'C':
			if (value == 1)
			{
				PORTC |= (U_ONE << pinNumber);
			}
			else if (value == 0)
			{
				PORTC &= ~(U_ONE << pinNumber);
			}
			else
			{
				// Nothing
			}

			break;

		case 'D':
			if (value == 1)
			{
				PORTD |= (U_ONE << pinNumber);
			}
			else if (value == 0)
			{
				PORTD &= ~(U_ONE << pinNumber);
			}
			else
			{
				// Nothing
			}

			break;
		default:
		    break;
	}
}

uint8_t DIO_Read_PIN(char portName, uint8_t pinNumber)
{
	uint8_t x = 0;

	switch(portName)
	{
		/*READ_BIT(reg, bit) == ((reg & (1 << bit)) >> bit)*/
		case 'A':
			x = ((PINA & (U_ONE << pinNumber)) >> pinNumber);
			break;

		case 'B':
			x = ((PINB & (U_ONE << pinNumber)) >> pinNumber);
			break;

		case 'C':
			x = ((PINC & (U_ONE << pinNumber)) >> pinNumber);
			break;

		case 'D':
			x = ((PIND & (U_ONE << pinNumber)) >> pinNumber);
			break;
		default:
			break;
	}
	return x;
}

void DIO_Toggle_PIN(char portName, uint8_t pinNumber)
{
	switch(portName)
	{
		case 'A':
			PORTA ^= (U_ONE << pinNumber);
			break;

		case 'B':
			PORTB ^= (U_ONE << pinNumber);
			break;

		case 'C':
			PORTC ^= (U_ONE << pinNumber);
			break;

		case 'D':
			PORTD ^= (U_ONE << pinNumber);
			break;
		default:
			break;
	}
}

void DIO_Set_PORT_Direction(char portName, uint8_t dir)
{
	// To set port as output -> write 1
	// To set port as input -> write 0

	switch(portName)
	{
		case 'A':
			if (dir == 1)
			{
				DDRA = 0xffU;
			}
			else if (dir == 0)
			{
				DDRA = 0x00U;
			}
			else
			{
				// Nothing
			}

			break;

		case 'B':
			if (dir == 1)
			{
				DDRB = 0xffU;
			}
			else if (dir == 0)
			{
				DDRB = 0x00U;
			}
			else
			{
				// Nothing
			}

			break;

		case 'C':
			if (dir == 1)
			{
				DDRC = 0xffU;
			}
			else if (dir == 0)
			{
				DDRC = 0x00U;
			}
			else
			{
				// Nothing
			}

			break;

		case 'D':
			if (dir == 1)
			{
				DDRD = 0xffU;
			}
			else if (dir == 0)
			{
				DDRD = 0x00U;
			}
			else
			{
				// Nothing
			}

			break;
		default:
			break;
	}
}

void DIO_Write_PORT(char portName, uint8_t portValue)
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
		default:
			break;
	}
}

uint8_t DIO_Read_PORT(char portName)
{
	uint8_t x = 0;

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
		default:
			break;
	}

	return x;
}

void DIO_Toggle_PORT(char portName)
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
		default:
			break;
	}
}

void DIO_Connect_PullUp(char portName, uint8_t pinNumber, uint8_t value)
{
	switch(portName)
	{
		case 'A':
			if (value == 1)
			{
				PORTA |= (U_ONE << pinNumber);
			}
			else
			{
				PORTA &= ~(U_ONE << pinNumber);
			}
			break;
			
		case 'B':
			if (value == 1)
			{
				PORTB |= (U_ONE << pinNumber);
			}
			else
			{
				PORTB &= ~(U_ONE << pinNumber);
			}

			break;
		
		case 'C':
			if (value == 1)
			{
				PORTC |= (U_ONE << pinNumber);
			}
			else
			{
				PORTC &= ~(U_ONE << pinNumber);
			}

			break;
		
		case 'D':
			if (value == 1)
			{
				PORTD |= (U_ONE << pinNumber);
			}
			else
			{
				PORTD &= ~(U_ONE << pinNumber);
			}
			break;
		default:
			break;	
	}
}

void DIO_Write_Low_Nibble(char portName, uint8_t value)
{
	value &= 0x0f;
	switch(portName)
	{
		case 'A':
			PORTA &= 0xf0U;
			PORTA |= value;
			break;
			
		case 'B':
			PORTB &= 0xf0U;
			PORTB |= value;
			break;
			
		case 'C':
			PORTC &= 0xf0U;
			PORTC |= value;
			break;
			
		case 'D':
			PORTD &= 0xf0U;
			PORTD |= value;
			break;
		default:
			break;
	}
}

void DIO_Write_High_Nibble(char portName, uint8_t value)
{
	value = value << 4;
	value &= 0xf0U;
	switch(portName)
	{
		case 'A':
			PORTA &= 0x0fU;
			PORTA |= value;
			break;
		
		case 'B':
			PORTB &= 0x0fU;
			PORTB |= value;
			break;
		
		case 'C':
			PORTC &= 0x0fU;
			PORTC |= value;
			break;
		
		case 'D':
			PORTD &= 0x0fU;
			PORTD |= value;
			break;
		default:
			break;
	}
}


void DIO_Write_Low_5_Nibble(char portName, uint8_t value)
{
	uint8_t mask = 0x1fU;
	value &= mask;
	
	// value &= 0x1f;

	switch(portName)
	{
		case 'A':
			PORTA &= 0xe0U;
			PORTA |= value;
			break;
		
		case 'B':
			PORTB &= ~ (mask);
			PORTB |= value;
			break;
		
		case 'C':
			PORTC &= 0xe0U;
			PORTC |= value;
			break;
		
		case 'D':
			PORTD &= 0xe0U;
			PORTD |= value;
			break;
		default:
			break;
	}
}