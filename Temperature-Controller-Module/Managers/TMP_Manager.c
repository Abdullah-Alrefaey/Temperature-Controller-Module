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

extern uint8_t counter1;
extern uint8_t counter2;
extern uint8_t counter3;

extern uint8_t state_indx;

void update_crt_temp()
{
	/* This means when (200 ms) is passed */
	if (counter1 >= 20)
	{
		CRT_Temperature = tc72_read();
		counter1 = 0;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}

void update_set_temp()
{
	/* Update SET_Temperature */
	
	/* This means when (50 ms) is passed */
	if (counter2 >= 50)
	{
		/* Check if you are in STANDBY State */
		/* Can Update Value now */
		if (state_indx == 0)
		{
			/* Get SET Temp From Keypad */
			char units = keypad_u8check_press();
			char tens = keypad_u8check_press();
			
			/* Convert characters to int and update SET_Temperature */
			// SET_Temperature = 
			counter2 = 0;
		}
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
