/************************************************************************/
/*                          PWM Driver Header                           */
/************************************************************************/
#ifndef PWM_H_
#define PWM_H_

/************************************************************************/
/*                          Library Imports                             */
/************************************************************************/
#include "DIO.h"
#include <stdint.h>

/************************************************************************/
/*                          Driver Functions                            */
/************************************************************************/

/*
	Function Name        : PWM_vInit
	Function Returns     : void
	Function Arguments   : uint8_t Timer, uint8_t Mode, uint8_t Scale
	Function Description : Initializes PWM on The Pin of The Selected Timer. Timer=0->PB3, Timer=1->PD7, Mode: 0 -> Phase-Correct PWM, 1 -> Fast PWM, Scale: 0 -> None,  1 -> 1/8, 2 -> 1/64
*/

void PWM_vInit(uint8_t Timer, uint8_t Mode, uint8_t Scale);

/*
	Function Name        : PWM_vDisable
	Function Returns     : void
	Function Arguments   : void
	Function Description : Disables PWN
*/
void PWM_vDisable(uint8_t Timer);

/*
	Function Name        : PWM_vSet_Duty
	Function Returns     : void
	Function Arguments   : uint8_t Timer, uint8_t Duty
	Function Description : Sets The Selected Timer With Chosen Duty Cycle, From 0-255
*/
void PWM_vSet_Duty(uint8_t Timer, uint8_t Duty);

#endif /* PWM_H_ */