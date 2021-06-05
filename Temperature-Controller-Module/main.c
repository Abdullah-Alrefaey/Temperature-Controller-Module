/*
 * main.c
 *
 */ 
 
#define F_CPU 16000000UL

#include "Managers/DSP_Manager.h"
#include "Drivers/PWM.h"
#include "Drivers/keypad_driver.h"
#include "Drivers/Timer.h"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned char counter1 = 0;
volatile unsigned char counter2 = 0;
volatile unsigned short counter3 = 0;


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
		
		/* This means when 1 second (1000 ms) is passed */
		if (counter1 >= 100)
		{
			LCD_vSend_string("c1");
			counter1 = 0;
		}
		/* This means when 2 seconds are passed */
		if (counter2 >= 200)
		{
			LCD_clearscreen();
			LCD_vSend_string("c1 ");
			LCD_vSend_string("c2");
			counter2 = 0;
		}
		
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