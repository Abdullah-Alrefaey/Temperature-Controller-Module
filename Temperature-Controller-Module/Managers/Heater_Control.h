/*
 * Heater_Control.h
 *
 * Created: 05-Jun-21 3:46:00 PM
 *  Author: Refaey
 */ 


#ifndef HEATER_CONTROL_H_
#define HEATER_CONTROL_H_

#include "../Drivers/Potentiometer.h"
#include "../Drivers/PWM.h"

extern uint8_t SET_Temperature;
extern uint8_t CRT_Temperature;

char * states[4] = {"STANDBY", "OPERATION", "NORMAL", "ERROR"};
uint8_t state_indx = 0;

#endif /* HEATER_CONTROL_H_ */