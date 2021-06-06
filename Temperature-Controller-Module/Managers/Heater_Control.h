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

void HeaterInit(void);
void SetHeaterVolt(double TargetV, double PotV);
void Update_Vt();
void Update_Vr();

#endif /* HEATER_CONTROL_H_ */