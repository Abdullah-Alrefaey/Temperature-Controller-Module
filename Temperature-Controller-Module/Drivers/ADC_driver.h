/*
 * ADC_driver.h
 *
 */ 


#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <avr/io.h>


void ADC_vinit(void);
uint16_t ADC_u16Read(void);

#endif /* ADC_DRIVER_H_ */