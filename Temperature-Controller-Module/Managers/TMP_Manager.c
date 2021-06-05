/*
 * TMP_Manager.c
 *
 * Created: 05-Jun-21 2:31:24 PM
 *  Author: Refaey
 */ 

#include "../Drivers/TC72.h"
#include "../Drivers/keypad_driver.h"

/* Declare and Define Global Variables Shared with other files */
uint8_t SET_Temperature = 25;
uint8_t CRT_Temperature = 0;

extern uint8_t counter1;
extern uint8_t counter3;

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