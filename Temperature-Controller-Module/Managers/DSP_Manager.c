/*
 * DSP_Manager.c
 *
 * Created: 03-Jun-21 1:51:34 PM
 *  Author: Refaey
 */ 

#include "DSP_Manager.h"

/* Declare and Define Global Variables Shared with other files */
extern int SET_Temperature = 25;
extern int CRT_Temperature = 0;

extern char * states[4] = {"STANDBY", "OPERATION", "NORMAL", "ERROR"};
extern char STATE[10] = "SSSSS";

void WelcomeScreen()
{
	/* Setup LCD PORT and PINs Configurations */
	LCD_vInit();
	
	/* Number of loops for welcome screen animation */
	int animation_loops = 3;
	
	/* The welcome Screen shall display the word “WELCOME” on the Character LCD */
	for (animation_loops = 3; animation_loops > 0; animation_loops--)
	{
		/* The welcome word shall move from right to left until the end of the screen */
		int steps = 16;
		for (steps = 16; steps >= 1; steps--)
		{
			LCD_movecursor(1, steps);
			LCD_vSend_string("WELCOME");
			/* TODO: Convert this delay to a periodic timer function*/
			_delay_ms(100);
			LCD_clearscreen();
		}
		
		/* The welcome word shall move from left to right until the other end of the screen */
		steps = 1;
		for (steps = 1; steps <= 16; steps++)
		{
			LCD_movecursor(1, steps);
			LCD_vSend_string("WELCOME");
			_delay_ms(100);
			LCD_clearscreen();
		}
	}

}

void IdleScreen()
{
	LCD_clearscreen();
	LCD_vSend_string("SET:");
	
	LCD_movecursor(1, 11);
	LCD_vSend_string("CRT:");
	
	/* Update Temperatures Values */
	Update_SET_Temperature(SET_Temperature);
	Update_CRT_Temperature(CRT_Temperature);

	/* Update System State */
	LCD_movecursor(2, 1);
	LCD_vSend_string("STATE:");

	Update_STATE("STANDBY");
}

void Update_SET_Temperature(int value)
{
	SET_Temperature = value;
	
	char temp_value[2];
	
	/* If Set temperature is less than 10, its value shall be written on the form 0X */
	if (SET_Temperature < 10)
	{
		/* Converts Units to character */
		temp_value[0] = '0';
		temp_value[1] = SET_Temperature + '0';
	}
	else
	{
		sprintf(temp_value, "%d", SET_Temperature);
	}
	
	/* Location of XX in LCD (SET:XX) */
	LCD_movecursor(1, 5);
	LCD_vSend_string(temp_value);
	
}

void Update_CRT_Temperature(int value)
{
	CRT_Temperature = value;
	
	char temp_value[2];
	
	/* If Current temperature is less than 10, its value shall be written on the form 0X */
	if (CRT_Temperature < 10)
	{
		/* Converts Units to character */
		temp_value[0] = '0';
		temp_value[1] = CRT_Temperature + '0';
	}
	else
	{
		sprintf(temp_value, "%d", CRT_Temperature);
	}
	
	/* Location of YY in LCD (CRT:YY) */
	LCD_movecursor(1, 15);
	LCD_vSend_string(temp_value);
	
}

void Update_STATE(char *state)
{
	/* System state section shall be written on the form STATE: SSSSS. 
	 * Where SSSSS is equal to the system state.
	 */

	strcpy(STATE, state);
	/* Location of System State in LCD (STATE:SSSSS) */
	LCD_movecursor(2, 7);
	LCD_vSend_string(state);
	LCD_vSend_string("     ");
}