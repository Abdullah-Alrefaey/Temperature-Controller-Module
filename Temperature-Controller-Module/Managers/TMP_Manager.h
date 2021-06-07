/************************************************************************/
/*                          Temperature Manager                         */
/************************************************************************/
#ifndef TMP_MANAGER_H_
#define TMP_MANAGER_H_

/************************************************************************/
/* Manager Definitions                                                  */
/************************************************************************/
#define F_CPU 16000000UL

/************************************************************************/
/* Manager Imports                                                      */
/************************************************************************/
#include <stdlib.h>
#include <util/delay.h>
#include "../Drivers/TC72.h"
#include "../Drivers/Keypad.h"
#include "../Drivers/LCD.h"
#include "../Drivers/LED.h"


/************************************************************************/
/* Driver Functions                                                     */
/************************************************************************/

/************************************************************************/
/* Function Description : Current Temperature Update Function           */
/* Function Arguments   : void                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Update_CRT_Temperature(void);

/************************************************************************/
/* Function Description : Current Temperature Update Function           */
/* Function Arguments   : void                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Update_SET_Temperature(void);

#endif /* TMP_MANAGER_H_ */