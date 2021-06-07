/************************************************************************/
/*                          Scheduler Manager                           */
/************************************************************************/
#ifndef SCHEDULAR_H_
#define SCHEDULAR_H_

/************************************************************************/
/* Manager Imports                                                      */
/************************************************************************/
#include "../Drivers/Timer.h"
#include "Mode_Config.h"
#include <avr/io.h>
#include <avr/interrupt.h>

/************************************************************************/
/* Driver Functions                                                     */
/************************************************************************/

/************************************************************************/
/* Function Description : Timer Functionality Initiator                 */
/* Function Arguments   : void                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Schedular_vInit(void);

#endif /* SCHEDULAR_H_ */