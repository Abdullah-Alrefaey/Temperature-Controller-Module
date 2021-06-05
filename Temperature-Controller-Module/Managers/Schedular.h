/*
 * Schedular.h
 *
 * Created: 05-Jun-21 4:15:06 PM
 *  Author: Refaey
 */ 


#ifndef SCHEDULAR_H_
#define SCHEDULAR_H_

#ifndef stdint
#define stdint
#include <stdint.h>
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t counter1 = 0;
volatile uint8_t counter2 = 0;
volatile uint8_t counter3 = 0;

#endif /* SCHEDULAR_H_ */