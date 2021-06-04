/*
 * DSP_Manager.h
 *
 * Created: 03-Jun-21 2:09:46 PM
 *  Author: Refaey
 */ 


#ifndef DSP_MANAGER_H_
#define DSP_MANAGER_H_

#define F_CPU 16000000UL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avr/io.h>
#include <util/delay.h>

#include "../Drivers/LCD.h"

void WelcomeScreen(void);
void IdleScreen(void);
void Update_SET_Temperature(uint8_t value);
void Update_CRT_Temperature(uint8_t value);
void Update_STATE(char* state);

#endif /* DSP_MANAGER_H_ */