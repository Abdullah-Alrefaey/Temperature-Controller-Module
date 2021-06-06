/*
 * DSP_Manager.h
 *
 * Created: 03-Jun-21 2:09:46 PM
 *  Author: Refaey
 */ 


#ifndef DSP_MANAGER_H_
#define DSP_MANAGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Drivers/LCD.h"

void WelcomeScreen(void);
void IdleScreen(void);
void Display_SET_Temperature(uint8_t value);
void Display_CRT_Temperature(uint8_t value);
void Display_STATE(char* state);

#endif /* DSP_MANAGER_H_ */