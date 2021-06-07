/************************************************************************/
/*                          ADC Driver                                  */
/************************************************************************/


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_
/************************************************************************/
/*                          Library Imports                             */
/************************************************************************/
#include <avr/io.h>
/************************************************************************/
/*                          Driver Functions                            */
/************************************************************************/

/*
	Function Name        : ADC_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initializes ADC on PA7 With 1/128 Prescaler
*/
void ADC_vInit(void);

/*
	Function Name        : ADC_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : Initializes ADC on PA7 With 1/128 Prescaler
*/
uint16_t ADC_u16Read(void);

/*
	Function Name        : ADC_vDisable
	Function Returns     : void
	Function Arguments   : void
	Function Description : Disables ADC
*/
void ADC_vDisable(void);

#endif /* ADC_DRIVER_H_ */