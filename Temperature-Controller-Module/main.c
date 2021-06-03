/*
 * Temperature-Controller-Module.c
 *
 * Created: 02-Jun-21 4:17:47 PM
 * Author : Refaey
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "Managers/DSP_Manager.h"

int main(void)
{
	// Start Main Application
	WelcomeScreen();
	IdleScreen();

    while (1)
    {
		
    }
}
