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
#include "../Drivers/Keypad.h"
#include "../Drivers/SPI.h"

#include <math.h>
#include <stdlib.h>

void HeaterInit(void);
void SetHeaterVolt(double TargetV, double PotV);
void Update_Vt();
void Update_Vr();
void Check_OPERATION_State_Key();
void Check_OPERATION_State();
void Check_STANDBY_State();
void Check_NORMAL_State();
void Check_ERROR_State();

#endif /* HEATER_CONTROL_H_ */