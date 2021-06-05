/*
 * ADC_driver.c
 *
 */ 

#include "ADC_driver.h"

void ADC_vinit(void)
{
	/* Use AVcc as Ref Voltage, Connect Capacitor (to ground) to ARef */
	SET_BIT(ADMUX, REFS0);
	
	/* Select Pin 7 For ADC */
	ADMUX |= (1<<MUX0) | (1<<MUX1) | (1<<MUX2);
	
	/* Enable ADC */
	SET_BIT(ADCSRA, ADEN);
	
	/* Set ADC Clock Scaler to 1/128 */
	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS0);
}

uint16_t ADC_u16Read(void)
{
	uint16_t ADCVal = 0;
	
	/*Start ADC Conversion*/
	SET_BIT(ADCSRA, ADSC); 
	
	/* Wait Till ADC Conversion is Done*/
	while(IS_BIT_CLR(ADCSRA, ADIF));
	
	/* Clear ADC Interrupt  Flag */
	SET_BIT(ADCSRA, ADIF);
	
	/* Read The ADC Value*/
	ADCVal = (ADCL);
	ADCVal |= (ADCH<<8);
	return ADCVal;
}