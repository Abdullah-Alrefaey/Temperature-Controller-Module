/*
 * main.c
 *
 */ 
 
#define F_CPU 16000000UL

#include "Managers/Schedular.h"
#include "Managers/TMP_Manager.h"
#include "Managers/DSP_Manager.h"

#include "Drivers/PWM.h"
#include "Drivers/keypad_driver.h"
#include "Drivers/Timer.h"
#include "Drivers/Potentiometer.h"

#include <util/delay.h>

extern uint8_t CRT_Temperature;
extern uint8_t SET_Temperature;
extern uint8_t state_indx;

int main(void)
{
	// Start Main Application
	// WelcomeScreen();
	// IdleScreen();
	LCD_vInit();
	keypad_vInit();
	timer_CTC_init_interrupt();
	PotInit();
	// PWM_Init(2,1,2);
	// uint8_t duty = 127;
	// Set_PWM_Duty(2, duty);
	char temp_value[5];
	double V = 0;
	uint8_t op_pressed = 0;
	
    while (1)
    {
		/* Check if you are in STANDBY State -> Update Value 
		if (state_indx == 0)
		{
			update_set_temp();
		}*/
		
		// update_crt_temp();
		// update_res();
		//GetPotVolt
		V = GetPotVolt();
		sprintf(temp_value, "%d", (uint8_t)V);
		LCD_movecursor(1, 5);
		LCD_vSend_string(temp_value);
		//Display_SET_Temperature(SET_Temperature);
		// Display_CRT_Temperature(CRT_Temperature);
		
		
    }
}
