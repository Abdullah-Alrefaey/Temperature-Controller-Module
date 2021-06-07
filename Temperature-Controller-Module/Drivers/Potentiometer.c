/************************************************************************/
/*                          Potentiometer Driver                        */
/************************************************************************/

#include "Potentiometer.h"

void Potentiometer_vInit(void)
{
	ADC_vInit();
}

void Potentiometer_vDisable(void)
{
	ADC_vDisable();
}

double Potentiometer_Read(void)
{
	double VPot = 0;
	uint16_t ADCReading = 0;
	ADCReading = ADC_u16Read();
	VPot = (5.0/1023.0)*ADCReading;
	return VPot;
}