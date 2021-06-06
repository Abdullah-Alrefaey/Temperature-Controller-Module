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

void HeaterInit(void);
void SetHeaterVolt(double TargetV, double PotV);
void Update_Vt();
void Update_Vr();
void Check_Operation_State();
void Check_STANDBY_State();

#endif /* HEATER_CONTROL_H_ */