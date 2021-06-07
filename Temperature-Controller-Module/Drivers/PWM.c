/*
 * PWM.c
 *
 * Created: 04/06/2021 14:09:00
 *  Author: Salah
 */
 
#include "PWM.h"

/************************************************************************/
/* Function Description:                                                */
/* Initializes PWM Function on the selected timer by turning on it's    */
/* comparator register, setting it's operation mode & needed prescale,  */
/* the prescale value will be selected to ensure that the PWM frequency */
/* lies within the operating frequency (1KHZ-3KHZ) of the PWM2Analogue  */
/* Module.                                                              */
/************************************************************************/
void PWM_vInit(uint8_t Timer, uint8_t Mode, uint8_t Scale){
	if (Timer == 0U)
	{
		/* Set Timer0 on Fast PWM (Mode=1) or Phase Correct (Mode=0) With Non-Inverted Output */
		TCCR0 = (U_ONE<<WGM00) | (Mode<<WGM01) | (U_ONE<<COM01);
		
		/* Set Freq, 0->Clk, 1->Clk/8 */
		if (Scale == 0U)
		{
			TCCR0 |= (U_ONE<<CS00);
		} 
		else if (Scale == 1U)
		{
			TCCR0 |= (U_ONE<<CS01);
		}
		else if (Scale == 2U)
		{
			TCCR0 |= (U_ONE<<CS02);
		} else {
		    /* Non-Configured Scale Value, Won't Use a Prescaler */
		}
		
		/*Set The OC0 (Timer 0) Pin as Output*/
		DIO_vsetPINDir('B', 3U, 1U);
	}
	else if (Timer == 2U)
	{
		/* Set Timer2 on Fast PWM (Mode=1) or Phase Correct (Mode=2) With Non-Inverted Output */
		TCCR2 = (U_ONE<<WGM20) | (Mode<<WGM21) | (U_ONE<<COM21);
		
		/* Set Freq, 0->Clk, 1->Clk/8 */
		if (Scale == 0U)
		{
			TCCR2 |= (U_ONE<<CS20);
		}
		else if (Scale == 1U)
		{
			TCCR2 |= (U_ONE<<CS21);
		}
		else if (Scale == 2U)
		{
			TCCR2 |= (U_ONE<<CS22);
		} else {
            /* Non-Configured Scale Value, Won't Use a Prescaler */
        }
		DIO_vsetPINDir('D', 7U, 1U);
	} else {
	    /* Unknown Timer Value, None is Set */
	}
	
}

/************************************************************************/
/* Function Description:                                                */
/* Disconnect The Comparator, Enable Normal Pin Operation               */
/************************************************************************/
void PWM_vDisable(uint8_t Timer)
{
    if (Timer == 0U)
    {
        TCCR0 = (U_ZERO<<COM01) | (U_ZERO<<COM00);
    }
    else if (Timer == 2U)
    {
        TCCR2 = (U_ZERO<<COM21) | (U_ZERO<<COM20);
    } else {
        /* Unknown Timer Value */
    }
}

/****************************************************************************/
/* Function Description:                                                    */
/* Sets The Value of The Given Timer's (0/2) Comparator To The Given Value, */
/* the value is from (0-255) and determines the high period in the duty     */
/* cycle                                                                    */
/****************************************************************************/
void PWM_vSet_Duty(uint8_t Timer, uint8_t Duty){
	if (Timer == 0)
	{
		OCR0 = Duty;
	} 
	else if (Timer == 2)
	{
		OCR2 = Duty;
	} else {
        /* Unknown Timer Value */
	}
}