/************************************************************************/
/*                          Heater Control Driver                       */
/************************************************************************/

#ifndef HEATER_CONTROL_H_
#define HEATER_CONTROL_H_

/************************************************************************/
/*                          Library Imports                             */
/************************************************************************/
#include "../Drivers/Potentiometer.h"
#include "../Drivers/PWM.h"
#include "../Drivers/Keypad.h"
#include "../Drivers/LED.h"
#include "Mode_Config.h"

/************************************************************************/
/*                          Driver Functions                            */
/************************************************************************/

/************************************************************************/
/* Function Description : Initialize STATES LEDs                        */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void LEDs_States_vInit(void);

/************************************************************************/
/* Function Description : Initialize The Heater (ADC and PWM ON         */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Heater_vInit(void);

/************************************************************************/
/* Function Description : Disable The Heater (ADC and PWM OFF)          */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Heater_vDisable(void);

/************************************************************************/
/* Function Description : Set The Heater Voltage                        */
/* Function Arguments   : double V_target                               */
/*                        double V_pot                                  */
/* Function Returns     : void                                          */
/************************************************************************/
void Heater_vSet_Volt(double V_target, double V_pot);

/************************************************************************/
/* Function Description : Update Target Voltage                         */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Update_Vt(void);

/************************************************************************/
/* Function Description : Update Potentiometer Voltage Periodically     */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Update_Vr(void);

/************************************************************************/
/* Function Description : Check if the heater entered OPERATION STATE   */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Check_OPERATION_State(void);

/************************************************************************/
/* Function Description : Check if the heater entered STANDBY STATE     */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Check_STANDBY_State(void);

/************************************************************************/
/* Function Description : Check if the heater entered NORMAL STATE      */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Check_NORMAL_State(void);

/************************************************************************/
/* Function Description : Check if the heater entered ERROR STATE       */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Check_ERROR_State(void);

/************************************************************************/
/* Function Description : Check if the heater entered ERROR STATE       */
/*                        in Timer Condition                            */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Check_ERROR_State_Timer(void);

/************************************************************************/
/* Function Description : Check if user pressed '#' Key to switch STATE */
/* Function Arguments   : None                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Check_HASH_Key(void);

#endif /* HEATER_CONTROL_H_ */