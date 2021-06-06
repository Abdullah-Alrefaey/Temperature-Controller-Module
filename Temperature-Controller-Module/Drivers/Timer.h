/*
 * Timer.h
 *
 */ 


#ifndef TIMER_H_
#define TIMER_H_


#include <avr/io.h>
#include <avr/interrupt.h>

/*
	Function Name        : timer_CTC_init_interrupt
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize the interrupt of the CTC mode of timer0.
*/
void timer_CTC_init_interrupt(void);

#endif /* TIMER_H_ */