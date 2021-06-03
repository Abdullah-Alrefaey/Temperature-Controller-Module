/*
 * Temperature-Controller-Module.c
 *
 * Created: 02-Jun-21 4:17:47 PM
 * Author : Refaey
 */ 

#define F_CPU 16000000UL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avr/io.h>
#include <util/delay.h>

#include "Drivers/LCD.h"
#include "Managers/DSP_Manager.h"

int main(void)
{
	// Start Main Application
	/* Setup LCD PORT and PINs Configurations */
	LCD_vInit();
	// WelcomeScreen();
	
	IdleScreen();
	
    while (1) 
    {
		
    }
}
