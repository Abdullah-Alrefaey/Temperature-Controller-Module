/*
 * main.c
 *
 */ 
 
/*#define F_CPU 8000000UL*/
#define F_CPU 16000000UL
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
	HeaterInit();
		
    while (1)
    {
		Display_SET_Temperature(SET_Temperature);
		Display_CRT_Temperature(CRT_Temperature);
		Display_STATE(states[state_indx]);
		
		/* Check if you are in STANDBY STATE:
		 * Update SET_Temperature Value From The User
		 * Check if User Pressed '#' To Switch to OPERATION STATE
		 */
		if (state_indx == 0)
		{
			Update_SET_Temperature();
						
			Check_Operation_State();
		}
		
		/* Check if you are in OPERATION STATE */
		if (state_indx == 1)
		{
			Update_CRT_Temperature();
			Update_Vt();
			Update_Vr();
			
			Check_STANDBY_State();
		}
		
		SetHeaterVolt(Vt, Vr);
		
    }
}
