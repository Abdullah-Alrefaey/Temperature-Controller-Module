/************************************************************************/
/*                          Potentiometer Driver                        */
/************************************************************************/
#include "Potentiometer.h"

/************************************************************************/
/* Function Description:                                                */
/* Potentiometer Initiation depends on the ADC Driver Initiation,       */
/* SEE DOCUMENTATION IN ADC.H                                           */
/************************************************************************/
void Potentiometer_vInit(void) {
    ADC_vInit();
}

/************************************************************************/
/* Function Description:                                                */
/* Potentiometer Disable Functionality                                  */
/* SEE DOCUMENTATION IN ADC.H                                           */
/************************************************************************/
void Potentiometer_vDisable(void) {
    ADC_vDisable();
}

/************************************************************************/
/* Function Description:                                                */
/* Read Voltage Applied on the Potentiometer using the ADC Functionality*/
/* and Map the Output to 5 Volts                                        */
/************************************************************************/
float64_t Potentiometer_Read(void) {
    float64_t VPot = 0;
    uint16_t ADCReading = 0U;
    ADCReading = ADC_u16Read();
    VPot = (5.0 / 1023.0) * (float64_t) ADCReading;
    return VPot;
}
