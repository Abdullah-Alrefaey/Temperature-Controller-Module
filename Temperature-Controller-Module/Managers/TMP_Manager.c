/*
 * TMP_Manager.c
 *
 * Created: 05-Jun-21 2:31:24 PM
 *  Author: Refaey
 */ 

#include "TMP_Manager.h"
#include "../Drivers/LCD.h"

/* Declare and Define Global Variables Shared with other files */
uint8_t SET_Temperature = 25;
uint8_t CRT_Temperature = 0;

extern uint8_t CRT_TEMP_COUNTER;
extern uint8_t SET_TEMP_COUNTER;

extern uint8_t state_indx;

char reading_buffer[2] = {'0', '0'};
uint8_t pos = 0;		/* Indicates the units and tens in SET Temperature */

uint8_t debouncing_counter = 0;

void Update_CRT_Temperature()
{
	/* This means when (200 ms) is passed */
	if (CRT_TEMP_COUNTER >= 20)
	{
		CRT_Temperature = TC72_Read();
		CRT_TEMP_COUNTER = 0;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}

void Update_SET_Temperature()
{
	char x = 0xff;
	uint8_t temp = 0;
	
	do {
		x = keypad_u8check_press();
		_delay_ms(200);
	} while (x == 0xff);
	
	temp = x * 10;
	x = 0xff;
	
	do {
		x = keypad_u8check_press();
		_delay_ms(200);
	} while(x == 0xff);

	temp += x;
	
	SET_Temperature = temp;
}

/*
void Update_SET_Temperature()
{		
	
	/ * This means when (200 ms) is passed * /
	if (SET_TEMP_COUNTER >= 20)
	{
		/ * Get SET Temperature From Keypad * /
		/ *reading_buffer[pos] = keypad_u8check_press();* /
				
		/ * Check that User Pressed an actual Key * /
		if (reading_buffer[pos] != NOTPRESSED)
		{
			
			/ * Clear SET Temperature * /
			if (reading_buffer[pos] == '*')
			{
				reading_buffer[0] = '0';
				reading_buffer[1] = '0';
				SET_Temperature = atoi(reading_buffer);
			}
			else
			{
				if (pos == 0)
				{
					pos++;
				}
				else
				{
					/ * Convert String Value to integer * /
					SET_Temperature = atoi(reading_buffer);
					/ * (pos is 1 now) we need to reset it with 0* /
					pos = 0;
				}
			}
		}
		else
		{
			/ * Do Nothing (Nothing is pressed) * /
		}
		
		SET_TEMP_COUNTER = 0;
	}
	else
	{
		/ * Do Nothing, Didn't reach the required time * /
	}
}
*/
