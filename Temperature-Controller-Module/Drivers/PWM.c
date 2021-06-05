/*
 * PWM.c
 *
 * Created: 04/06/2021 14:09:00
 *  Author: Salah
 */
 
#include "DIO.h"

void PWM_Init(uint8_t Timer, uint8_t Mode, uint8_t Scale){
	if (Timer == 0)
	{
		/* Set Timer0 on Fast PWM (Mode=1) or Phase Correct (Mode=0) With Non-Inverted Output */
		TCCR0 = (1<<WGM00) | (Mode<<WGM01) | (1<<COM01);
		
		/* Set Freq, 0->Clk, 1->Clk/8 */
		if (Scale == 0)
		{
			TCCR0 |= (1<<CS00);
		} 
		else if (Scale == 1)
		{
			TCCR0 |= (1<<CS01);
		}
		else if (Scale == 2)
		{
			TCCR0 |= (1<<CS02);
		}
		
		/*Set The OC0 (Timer 0) Pin as Output*/
		DIO_vsetPINDir('B', 3, 1);
	}
	else if (Timer == 2) 
	{
		/* Set Timer2 on Fast PWM (Mode=1) or Phase Correct (Mode=2) With Non-Inverted Output */
		TCCR2 = (1<<WGM20) | (Mode<<WGM21) | (1<<COM21);
		
		/* Set Freq, 0->Clk, 1->Clk/8 */
		if (Scale == 0)
		{
			TCCR2 |= (1<<CS20);
		}
		else if (Scale == 1)
		{
			TCCR2 |= (1<<CS21);
		}
		else if (Scale == 2)
		{
			TCCR2 |= (1<<CS22);
		}
		DIO_vsetPINDir('D', 7, 1);
	}
	
}

void Set_PWM_Duty(uint8_t Timer, uint8_t Duty){
	if (Timer == 0)
	{
		OCR0 = Duty;
	} 
	else if (Timer == 2)
	{
		OCR2 = Duty;
	}
	
}