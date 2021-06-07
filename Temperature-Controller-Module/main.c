/*
 * main.c
 *
 */ 
 
/*#define F_CPU 8000000UL*/

#include "Managers/Schedular.h"
#include "Managers/TMP_Manager.h"
#include "Managers/DSP_Manager.h"
#include "Managers/Heater_Control.h"

#include "Drivers/Keypad.h"
#include "Drivers/TC72.h"

extern uint8_t CRT_Temperature;
extern uint8_t SET_Temperature;

extern char * states[4];
extern uint8_t state_indx;

extern double Vr;
extern double Vt;

int main(void)
{
	// Start Main Application
	WelcomeScreen();
	IdleScreen();
	keypad_vInit();
	TC72_Init(One_Shot);
	Schedular_vInit();
	LEDs_States_vInit();
		
	while (1)
    {
		Display_SET_Temperature(SET_Temperature);
		Display_CRT_Temperature(CRT_Temperature);
		Display_STATE(states[state_indx]);
		
		/* Check if you are in STANDBY STATE:
		 * Update SET_Temperature Value From The User
		 * Check if User Pressed '#' To Switch to OPERATION STATE
		 */
		if (state_indx == STANDBY_INDEX)
		{
			/* PWM OFF */
			Heater_vDisable();
			
			Update_SET_Temperature();
			Display_SET_Temperature(SET_Temperature);
			Check_HASH_Key();
		}
		
		/* Check if you are in OPERATION STATE */
		if (state_indx == OPERATION_INDEX)
		{
			/* Start Heater */
			Heater_vInit();
			
			Update_CRT_Temperature();
			Update_Vt();
			Update_Vr();
			
			/* Update PWM Wave */
			SetHeaterVolt(Vt, Vr);
			
			Check_HASH_Key();
			Check_NORMAL_State();
			Check_ERROR_State();
			
			/* This function should handle Error 3 min */
			Check_ERROR_State_Timer();
		}
		
		/* Check if you are in NORMAL STATE */
		if (state_indx == NORMAL_INDEX)
		{
			/* PWM OFF */
			Heater_vDisable();
			
			Update_CRT_Temperature();
						
			Check_HASH_Key();		
			Check_OPERATION_State();	
			Check_ERROR_State();		
		}
		
		/* Check if you are in ERROR STATE */
		if (state_indx == ERROR_INDEX)
		{
			/* PWM and ADC OFF */
			Heater_vDisable();
			
			/* Must POWER OFF */
		}
    }
}
