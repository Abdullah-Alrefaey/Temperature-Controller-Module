/*
 * main.c
 *
 */ 
 
 
 #define F_CPU 16000000UL

 #include <util/delay.h>
 
#include "Managers/Schedular.h"
#include "Managers/TMP_Manager.h"
#include "Managers/DSP_Manager.h"

#include "Drivers/keypad_driver.h"

extern uint8_t CRT_Temperature;
extern uint8_t SET_Temperature;
extern uint8_t state_indx;

extern double Vr;
extern double Vt;

int main(void)
{
	// Start Main Application
	WelcomeScreen();
	IdleScreen();
	// LCD_vInit();
	keypad_vInit();
	
	// HeaterInit();
	
	uint8_t op_pressed = 0;
	
    while (1)
    {
		/* Check if you are in STANDBY State -> Update Value */
		/*if (state_indx == 0)
		{
			Update_SET_Temperature();
		}*/
		
		Update_CRT_Temperature();
		
		Update_Vt();
		Update_Vr();
	
		SetHeaterVolt(Vt, Vr);
		
		Display_SET_Temperature(SET_Temperature);
		Display_CRT_Temperature(CRT_Temperature);
		
		
    }
}
