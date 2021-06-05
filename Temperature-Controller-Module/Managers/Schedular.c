/*
 * Schedular.c
 *
 * Created: 05-Jun-21 4:14:58 PM
 *  Author: Refaey
 */ 

#include "Schedular.h"

volatile uint8_t counter1 = 0;
volatile uint8_t counter2 = 0;
volatile uint8_t counter3 = 0;

ISR(TIMER0_COMP_vect)
{
	counter1++;
	counter2++;
	counter3++;
}
