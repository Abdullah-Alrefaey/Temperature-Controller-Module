/*
 * TMP_Manager.c
 *
 * Created: 05-Jun-21 2:31:24 PM
 *  Author: Refaey
 */ 

#include "TMP_Manager.h"

/* Declare and Define Global Variables Shared with other files */
uint8_t SET_Temperature = 25;
uint8_t CRT_Temperature = 0;

extern uint8_t CRT_TEMP_COUNTER;
extern uint8_t SET_TEMP_COUNTER;

extern uint8_t state_indx;

uint8_t reading_buffer = 0;
uint8_t temp_reading = 0;
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

/*
void Update_SET_Temperature()
{
	char value = NOTPRESSED;
	uint8_t temp_reading = 0;
	
	/ * Wait for user to enter tens * /
	do {
		value = keypad_u8check_press();
		
		/ * This delay is used to solve the debouncing problem of buttons * /
		_delay_ms(200);
	} while (value == NOTPRESSED);
	
	/ * Multiply the value by 10 to set it as tens * /
	temp_reading = value * 10;
	value = NOTPRESSED;
	
	/ * Wait for user to enter units * /
	do {
		value = keypad_u8check_press();
		_delay_ms(200);
	} while (value == NOTPRESSED);

	/ * Add units to the previous tens to store the whole number * /
	temp_reading += value;
	
	/ * Update SET_Temperature with the final value * /
	SET_Temperature = temp_reading;
}*/


void Update_SET_Temperature()
{	
	/* This means when (200 ms) is passed */
	if (SET_TEMP_COUNTER >= 10)
	{
		LED_vInit('D', 0);
		LED_vTurnOn('D', 0);
		
		/* Get SET Temperature From Keypad */
		reading_buffer = keypad_u8check_press();
		Display_SET_Temperature(reading_buffer);

		/* Check that User Pressed an actual Key */
		if (reading_buffer != NOTPRESSED)
		{
			if (pos == 0)
			{
				temp_reading = reading_buffer * 10;
				pos++;
			}
			else
			{
				temp_reading += reading_buffer;
				SET_Temperature = temp_reading;
				
				/* (pos is 1 now) we need to reset it with 0*/
				pos = 0;
			}
		}
		else
		{
			/* Do Nothing (Nothing is pressed) */
			// LED_vTurnOff('D', 0);
		}
		
		SET_TEMP_COUNTER = 0;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}	
}


