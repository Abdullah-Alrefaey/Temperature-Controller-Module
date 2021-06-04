/*
 * PWM.h
 *
 * Created: 04/06/2021 14:09:33
 *  Author: Salah
 */ 

#ifndef stdint
#define stdint
#include <stdint.h>
#endif

#ifndef PWM_H_
#define PWM_H_
/*
	Function Name        : PWM_Init
	Function Returns     : void
	Function Arguments   : uint8_t Timer, uint8_t Mode, uint8_t Scale
	Function Description : Initializes PWM on The Pin of The Selected Timer. Timer=0->PB3, Timer=1->PD7, Mode: 0 -> Phase-Correct PWM, 1 -> Fast PWM, Scale: 0 -> None,  1 -> 1/8, 2 -> 1/64
*/
void PWM_Init(uint8_t Timer, uint8_t Mode, uint8_t Scale);

/*
	Function Name        : Set_PWM_Duty
	Function Returns     : void
	Function Arguments   : uint8_t Timer, uint8_t Duty
	Function Description : Sets The Selected Timer With Chosen Duty Cycle, From 0-255
*/
void Set_PWM_Duty(uint8_t Timer, uint8_t Duty);

#endif /* PWM_H_ */