/************************************************************************/
/*                          Display Manager                             */
/************************************************************************/
#include "DSP_Manager.h"
#include <stdlib.h>

extern uint8_t SET_Temperature;
extern uint8_t CRT_Temperature;
extern uint8_t state_indx;

extern uint8_t LCD_INIT_COUNTER;
extern uint8_t LCD_SHIFT_COUNTER;
extern uint8_t LCD_INITIALIZED;

uint8_t left_shift_steps = 15U;
uint8_t right_shift_steps = 0U;

uint8_t animation_loops = 3U;

/************************************************************************/
/* Function Description:                                                */
/* Shift the Display of the LCD Left and Right based on a periodic      */
/* Poller every 100ms.                                                  */
/* Sets the associated flags and counter based on each loop.            */
/************************************************************************/
void ShiftDisplay()
{
	/* Shift The Screen every 100ms to the left 15 times */
	/* Start Shifting Left */
	if (LCD_SHIFT_COUNTER >= 10U && left_shift_steps > 0)
	{
		/* Shift Left */
		LCD_vShiftDisplay(1U);
		LCD_SHIFT_COUNTER = 0U;
		left_shift_steps--;
	}
	/* Finished Shifting Left */
	
	/* Shift The Screen every 100ms to the right 15 times after */
	/* the left shift is finished */
	/* Start Shifting Right */	
	if (LCD_SHIFT_COUNTER >= 10U && left_shift_steps == 0 && right_shift_steps < 15U)
	{
		/* Shift Right */
		LCD_vShiftDisplay(0U);
		LCD_SHIFT_COUNTER = 0U;
		right_shift_steps++;
	}
	/* Finished Shifting Right */
	
	/* This means finished 1 loop */ 
	if (right_shift_steps == 15U)
	{
		left_shift_steps = 15U;
		right_shift_steps = 0U;
		animation_loops--;
	}
}

/************************************************************************/
/* Function Description:                                                */
/* Initiate the LCD Screen with a Welcoming Animation, Display "WELCOME"*/
/* on the Screen then shift the word left and right for 3 Times         */
/************************************************************************/
void WelcomeScreen(void)
{
    /* Wait 50ms before Initializing the LCD */
    if (LCD_INIT_COUNTER >= 5U)
	{
        /* Setup LCD PORT and PINs Configurations */
        LCD_vInit();

        LCD_vMove_Cursor(1U, 16);
        LCD_vSend_string("WELCOME");

		/* Finish The Initialization */
        LCD_INIT_COUNTER = 0U;
        LCD_INITIALIZED = 1U;
    }
	else
	{
        /* Didn't reach required time yet */
    }
}

/************************************************************************/
/* Function Description:                                                */
/* The Idle Screen Displays the Set Temperature (Default 25 C) and the  */
/* Current Temperature Read from the Temperature Sensor. Also Displays  */
/* the Current Process State                                            */
/************************************************************************/
void IdleScreen(void) {
    LCD_vClear_Screen();
    LCD_vSend_string("SET:");

    LCD_vMove_Cursor(1U, 11U);
    LCD_vSend_string("CRT:");

    /* Update Temperatures Values */
    Display_SET_Temperature(SET_Temperature);
    Display_CRT_Temperature(CRT_Temperature);

    /* Update System State */
    LCD_vMove_Cursor(2U, 1U);
    LCD_vSend_string("STATE:");

    Display_STATE("STANDBY");
}

/************************************************************************/
/* Function Description:                                                */
/* Displays the Set Temperature by the User, The Number entered is      */
/* Converted to a String and passed to the LCD                          */
/************************************************************************/
void Display_SET_Temperature(uint8_t value) {
    char temp_value[2];

    /* If Set temperature is less than 10,*/
    /* its value shall be written on the form 0X */
    if (value < 10U) {
        /* Converts Units to character */
        temp_value[0] = '0';
        temp_value[1] = (char) (value + 48U);
    } else {
        itoa((int32_t) value, temp_value, 10);
        /*sprintf(temp_value, "%d", value);*/
    }

    /* Location of XX in LCD (SET:XX) */
    LCD_vMove_Cursor(1U, 5U);
    LCD_vSend_string(temp_value);
}


/************************************************************************/
/* Function Description:                                                */
/* Displays the Current Temperature by the User, The Number entered is  */
/* Converted to a String and passed to the LCD. This Function Checks if */
/* the Current State is Error State the Display is then Changed         */
/************************************************************************/
void Display_CRT_Temperature(uint8_t value) {
    if ((state_indx == ERROR_INDEX) || (state_indx == STANDBY_INDEX)) {
        Display_CRT_Temperature_ERROR();
    } else {
        char TempValue[2];

        /* If Current temperature is less than 10, */
        /* its value shall be written on the form 0X */
        if (value < 10U) {
            /* Converts Units to character */
            TempValue[0] = '0';
            TempValue[1] = (char) (value + 48U);
        } else {
            itoa((int32_t) value, TempValue, 10);
        }

        /* Location of YY in LCD (CRT:YY) */
        LCD_vMove_Cursor(1U, 15U);
        LCD_vSend_string(TempValue);
    }
}

/************************************************************************/
/* Function Description:                                                */
/* Display the Error State Temperature                                  */
/************************************************************************/
void Display_CRT_Temperature_ERROR(void) {
    /* Location of YY in LCD (CRT:YY) */
    LCD_vMove_Cursor(1U, 15U);
    LCD_vSend_char(0xFFU);
    LCD_vSend_char(0xFFU);
}

/************************************************************************/
/* Function Description:                                                */
/* Display the System State                                             */
/************************************************************************/
void Display_STATE(const char *state) {
    /* System state section shall be written on the form STATE: SSSSS.
     * Where SSSSS is equal to the system state.
     */

    /* Location of System State in LCD (STATE:SSSSS) */
    LCD_vMove_Cursor(2U, 7U);
    LCD_vSend_string(state);
    LCD_vSend_string("     ");
}

