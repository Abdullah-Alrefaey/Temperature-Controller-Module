/*
 * main.c
 *
 */ 
 
#define F_CPU 16000000UL

#include "Managers/DSP_Manager.h"
#include "Managers/TMP_Manager.h"

#include "Drivers/PWM.h"
#include "Drivers/keypad_driver.h"
#include "Drivers/Timer.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint8_t counter1 = 0;
volatile uint8_t counter2 = 0;
volatile uint8_t counter3 = 0;

extern uint8_t CRT_Temperature;

int main(void)
{
	// Start Main Application
	// WelcomeScreen();
	// IdleScreen();
	LCD_vInit();
	keypad_vInit();
	
	timer_CTC_init_interrupt();
	
	// PWM_Init(2,1,2);
	// uint8_t duty = 127;
	// Set_PWM_Duty(2, duty);
	
	char pressed_key;
	uint8_t op_pressed = 0;
	
    while (1)
    {
		
		update_crt_temp();
		// update_res();
		
		Display_CRT_Temperature(CRT_Temperature);
		
		// pressed_key = keypad_u8check_press();
		
		/*op_pressed = check_OPKey();
		if (op_pressed == 1)
		{
			LCD_vSend_string("ON!");
			_delay_ms(1);
		}*/
    }
}


ISR(TIMER0_COMP_vect)
{
	counter1++;
	counter2++;
	counter3++;
}
