/************************************************************************/
/*                          Timer Driver                                */
/************************************************************************/

#include "Timer.h"

/************************************************************************/
/* Function Description:                                                */
/* Initialize Timer0 with CTC Mode and store a specific value in OCR    */
/* Register to be compared in each Timer Tick.                          */
/* Select the Timer Clock to calculate Timer Tick Time and ISR Time.    */
/* Enable the Global Interrupt Bit and Timer0 Interrupt                 */
/************************************************************************/
void Timer0_CTC_vInit_Interrupt(void) {
    /* select CTC mode*/
    TCCR0 |= (1U << WGM01);

    /* load a value in OCR0 */
    /*  */

    /* OCR0 = 80;*/
    OCR0 = 157;

    /* select timer clock */
    /* clk/1024 */
    TCCR0 |= (1U << CS00);
    TCCR0 |= (1U << CS02);

    /* Timer Clock = System Clock / pre-scaler
     * Timer Tick Time (TTT) = 1 / Timer Clock
     * TTT = 1024/16 MHz = 0.064 ms
     * Timer Count = 157 (Value in OCR we need to compare with)
     * Timer Overflow Time = 157 * 0.064 = 10.048 ms
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
    TIMSK |= (1U << OCIE0);
}

