/*
 * Heater_Control.c
 *
 * Created: 05-Jun-21 3:45:50 PM
 *  Author: Refaey
 */ 

#include "Heater_Control.h"


extern uint8_t SET_Temperature;
extern uint8_t CRT_Temperature;

char * states[4] = {"STANDBY", "OPERATION", "NORMAL", "ERROR"};
uint8_t state_indx = 0;
