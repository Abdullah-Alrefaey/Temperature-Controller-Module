/*
 * Potentiometer.h
 *
 * Created: 05-Jun-21 4:23:16 PM
 *  Author: Refaey
 */ 


#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

#include "ADC.h"

void Potentiometer_vInit(void);
void Potentiometer_vDisable(void);
double Potentiometer_Read(void);

#endif /* POTENTIOMETER_H_ */