/************************************************************************/
/*                          ADC Driver                                  */
/************************************************************************/

#include "ADC.h"


void ADC_vInit(void)
{
	/* Use AVcc as Ref Voltage, Connect Capacitor (to ground) to ARef */
	ADMUX |= (1U << REFS0);
	
	/* Select Pin 7 For ADC */
	ADMUX |= (1U<<MUX0);
	ADMUX |= (1U<<MUX1);
	ADMUX |= (1U<<MUX2);
	
	/* Enable ADC */
	ADCSRA |= (1U << ADEN);
	
	/* Set ADC Clock Scaler to 1/128 */
	ADCSRA |= (1U << ADPS2);
	ADCSRA |= (1U << ADPS1);
	ADCSRA |= (1U << ADPS0);
}

void ADC_vDisable(void)
{
	/* Disable ADC */
	ADCSRA &= ~(1U << ADEN);
}

uint16_t ADC_u16Read(void)
{
	uint16_t ADCVal = 0U;
	
	/*Start ADC Conversion*/
	ADCSRA |= (1U << ADSC);

	while(!((ADCSRA & (1U << ADIF)) >> ADIF)){
        /* Wait Till ADC Conversion is Done*/
	};
	
	/* Clear ADC Interrupt  Flag */
	ADCSRA |= (1U << ADIF);
	
	/* Read The 10-Bit ADC Value */
	ADCVal = (ADCL);
	ADCVal |= ((volatile uint16_t)ADCH<<8);
	return ADCVal;
}
