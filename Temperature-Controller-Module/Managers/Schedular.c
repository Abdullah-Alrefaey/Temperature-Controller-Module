/*
 * Schedular.c
 *
 * Created: 05-Jun-21 4:14:58 PM
 *  Author: Refaey
 */ 

#include "Schedular.h"

ISR(TIMER0_COMP_vect)
{
	counter1++;
	counter2++;
	counter3++;
}
