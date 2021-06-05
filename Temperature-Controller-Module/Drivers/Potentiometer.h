/*
 * Potentiometer.h
 *
 * Created: 05-Jun-21 4:23:16 PM
 *  Author: Refaey
 */ 


#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

#include "ADC_driver.h"
void PotInit(void);
double GetPotVolt(void);
#endif /* POTENTIOMETER_H_ */