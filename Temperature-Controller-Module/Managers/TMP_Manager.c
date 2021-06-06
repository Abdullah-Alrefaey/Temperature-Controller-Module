/*
 * TMP_Manager.c
 *
 * Created: 05-Jun-21 2:31:24 PM
 *  Author: Refaey
 */ 

#include "TMP_Manager.h"
#include "../Drivers/LCD.h"

#include <util/delay.h>

/* Declare and Define Global Variables Shared with other files */
uint8_t SET_Temperature = 25;
uint8_t CRT_Temperature = 0;

extern uint8_t counter1;
extern uint8_t counter2;
extern uint8_t counter3;

extern uint8_t state_indx;

char reading_buffer[2] = {'0', '0'};
uint8_t pos = 0;		/* Indicates the units and tens in SET Temperature */

void Update_CRT_Temperature()
{
	/* This means when (200 ms) is passed */
	if (counter1 >= 20)
	{
		CRT_Temperature = TC72_Read();
		counter1 = 0;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}

void Update_SET_Temperature()
{	
	/* This means when (150 ms) is passed */
	if (counter2 >= 15)
	{
		/* Get SET Temperature From Keypad */
		reading_buffer[pos] = keypad_u8check_press();
		
		/* Check that User Pressed an actual Key */
		if (reading_buffer[pos] != NOTPRESSED)
		{
			/* Clear SET Temperature */
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
					/* Convert String Value to integer */
					SET_Temperature = atoi(reading_buffer);
					/* (pos is 1 now) we need to reset it with 0*/
					pos = 0;
				}
			}
		}
		counter2 = 0;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}

uint8_t check_off_key()
{
	/* This means when (100 ms) is passed */
	if (counter3 >= 10)
	{
		counter3 = 0;
		return check_OPKey();
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}
