#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "Managers/DSP_Manager.h"
#include "Drivers/PWM.h"

int main(void)
{
	// Start Main Application
	//WelcomeScreen();
	//IdleScreen();
	PWM_Init(0,1,1);
	PWM_Init(2,1,2);
	DIO_vsetPINDir('D', 6, 1);
	DIO_Write_PIN('D', 6, 1);
	uint8_t duty = 200;
	Set_PWM_Duty(0, duty);
	Set_PWM_Duty(2, duty);
    while (1)
    {
		
    }
}
