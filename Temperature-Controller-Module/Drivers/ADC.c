/************************************************************************/
/*                          ADC Driver                                  */
/************************************************************************/

/************************************************************************/
/*                          MISRA Justifications                        */
/************************************************************************/
/* The MISRA Advisory Rule 5.7 is Broken according to CCS when we use AVR's
 * built-in definitions for Registers & Bit names, this is seems like an
 * error by CCS's Analyzer as per the rule, defining an identifier in a
 * header & reusing it is accepted, since it always refers to the same
 * value */

#include "ADC.h"

/************************************************************************/
/* Function Description:                                                */
/* Initialize ADC on Pin A7, Reference voltage is selected as external, */
/* the pin is selected using the built-in multiplexer & the prescaler   */
/* is set to 1/128 so that the ADC Frequency is less than 200KHz,       */
/* a requirement to ensure maximum accuracy                             */
/************************************************************************/
void ADC_vInit(void) {
    /* Use AVcc as Ref Voltage, Connect Capacitor (to ground) to ARef */
    ADMUX |= (1U << REFS0);

    /* Select Pin 7 For ADC */
    ADMUX |= (1U << MUX0);
    ADMUX |= (1U << MUX1);
    ADMUX |= (1U << MUX2);

    /* Enable ADC */
    ADCSRA |= (1U << ADEN);

    /* Set ADC Clock Scaler to 1/128 */
    ADCSRA |= (1U << ADPS2);
    ADCSRA |= (1U << ADPS1);
    ADCSRA |= (1U << ADPS0);
}

/************************************************************************/
/* Function Description:                                                */
/* Clear the ADC enable bit, disabling the ADC                          */
/************************************************************************/
void ADC_vDisable(void) {
    /* Disable ADC */
    ADCSRA &= ~(1U << ADEN);
}

/************************************************************************/
/* Function Description:                                                */
/* Reads the ADC value, Due to the registers being 8-bit & the ADC      */
/* 8-bit, the value is divided to 2 registers, first we read the lowest */
/* value bits & store them in a variable, then we read the remaining    */
/* high bits shifted by 8 and store them in the same variable, hence we */
/* use the right-justified mode, this shift produces the correct order  */
/* of the bits, thus the correct number                                 */
/************************************************************************/
uint16_t ADC_u16Read(void) {
    uint16_t ADCVal = 0U;

    /*Start ADC Conversion*/
    ADCSRA |= (1U << ADSC);

    while ((ADCSRA & (1U << ADIF)) == 0U) {
        /* Wait Till ADC Conversion is Done, By Waiting Till ADC Interrupt Flag is Set */
    };

    /* Clear ADC Interrupt  Flag */
    ADCSRA |= (1U << ADIF);

    /* Read The 10-Bit ADC Value */
    ADCVal = (ADCL);
    ADCVal |= ((volatile uint16_t) ADCH << 8);
    return ADCVal;
}
