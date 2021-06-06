/*
 * ADC_driver.c
 *
 */ 

#include "ADC_driver.h"

void ADC_vinit(void)
{
	/* Use AVcc as Ref Voltage, Connect Capacitor (to ground) to ARef */
	ADMUX |= (1 << REFS0);
	
	/* Select Pin 7 For ADC */
	ADMUX |= (1<<MUX0) | (1<<MUX1) | (1<<MUX2);
	
	/* Enable ADC */
	ADCSRA |= (1 << ADEN);
	
	/* Set ADC Clock Scaler to 1/128 */
	ADCSRA |= (1 << ADPS2);
	ADCSRA |= (1 << ADPS1);
	ADCSRA |= (1 << ADPS0);
}

uint16_t ADC_u16Read(void)
{
	uint16_t ADCVal = 0;
	
	/*Start ADC Conversion*/
	ADCSRA |= (1 << ADSC); 
	
	/* Wait Till ADC Conversion is Done*/
	/*IS_BIT_CLR(reg, bit)	! ( (reg & (1 << bit) ) >> bit)*/
	while(!((ADCSRA & (1 << ADIF)) >> ADIF));
	
	/* Clear ADC Interrupt  Flag */
	ADCSRA |= (1 << ADIF);
	
	/* Read The ADC Value*/
	ADCVal = (ADCL);
	ADCVal |= (ADCH<<8);
	return ADCVal;
}