/*
 * Timer.c
 *
 */ 
 
#include "std_macros.h"

#include <avr/io.h>
#include <avr/interrupt.h>

void timer_CTC_init_interrupt(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR0, WGM01);
	
	/* load a value in OCR0 */
	/*  */
	
	// OCR0 = 80;
	OCR0 = 157;
	
	/* select timer clock */	
	/* clk/1024 */
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS02);
	
	/* Timer Clock = System Clock / Prescaler
	 * Timer Tick Time (TTT) = 1 / Timer Clock
	 * TTT = 1024/16 MHz = 0.064 ms
	 * Timer Count = 157 (Value in OCR we need to compare with)
	 * Timer Overflow Time = 157 * 0.064 = 10 ms
	 * This means every 10 ms The Timer Interrupt will occur
	 */
	
	/* Enable Interrupt */
	/* Enables the Global Interrupt Enable (I-bit) in the Status Register (SREG) */
	sei();
	
	/* The OCF0 bit is set (one) (in Timer/Counter Interrupt Flag Register - TIFR) 
	 * when a compare match occurs between the Timer/Counter0 Register (TCNT0)
	 * and the data in OCR0 - Output Compare Register0
	 */
	
	/* When the OCIE0 bit is enabled, and the I-bit in the Status Register is set (one),
	 * the Timer/Counter Compare Match Interrupt is enabled.
	 */
	SET_BIT(TIMSK, OCIE0);
}


void timer_wave_nonPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* toggle OC0 on compare match*/
	SET_BIT(TCCR0,COM00);
}

void timer_wave_fastPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select fast PWM mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}


void timer_wave_phasecorrectPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select phase correct PWM mode*/
	SET_BIT(TCCR0,WGM00);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting.*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}

