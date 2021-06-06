/*
 * Potentiometer.c
 *
 * Created: 05-Jun-21 4:23:23 PM
 *  Author: Refaey
 */ 

#include "Potentiometer.h"
#include "ADC.h"

void PotInit(void)
{
	ADC_vinit();	
}

double GetPotVolt(void)
{
	double VPot = 0;
	uint16_t ADCReading = 0;
	ADCReading = ADC_u16Read();
	VPot = (5.0/1023.0)*ADCReading;
	return VPot;
}