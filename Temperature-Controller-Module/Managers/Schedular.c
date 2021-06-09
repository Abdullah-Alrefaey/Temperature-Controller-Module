/************************************************************************/
/*                          Scheduler Manager                           */
/************************************************************************/
#include "Schedular.h"

volatile uint8_t LCD_INIT_COUNTER = 0;
volatile uint8_t CRT_TEMP_COUNTER = 0;
volatile uint8_t SET_TEMP_COUNTER = 0;
volatile uint8_t HASH_KEY_COUNTER = 0;
volatile uint8_t ADC_COUNTER = 0;
volatile uint16_t ERROR_COUNTER = 0;

extern uint8_t SET_Temperature;
extern uint8_t CRT_Temperature;
extern uint8_t state_indx;

/************************************************************************/
/* Function Description:                                                */
/* Descending the Layers to the HAL Layer and use the Timer Initiator   */
/* Function, SEE DESCRIPTION IN TIMER.C                                 */
/************************************************************************/
void Schedular_vInit(void)
{
	Timer0_CTC_vInit_Interrupt();
}

/************************************************************************/
/* Function Description:                                                */
/* Interrupt Service Routine Function. This is a Timer Function, We use */ 
/* to update our counter and extend it's use to multiple Timer Based    */
/* Processes                                                            */
/************************************************************************/
ISR(TIMER0_COMP_vect)
{
	if (state_indx == STANDBY_INDEX)
	{
		LCD_INIT_COUNTER++;
	}
	
	CRT_TEMP_COUNTER++;
	SET_TEMP_COUNTER++;
	HASH_KEY_COUNTER++;
	ADC_COUNTER++;
	
	if ((state_indx  == OPERATION_INDEX) && ((SET_Temperature - CRT_Temperature) > 5U))
	{
		ERROR_COUNTER++;
	}
}
