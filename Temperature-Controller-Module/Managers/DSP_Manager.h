/************************************************************************/
/*                          Display Manager                             */
/************************************************************************/
#ifndef DSP_MANAGER_H_
#define DSP_MANAGER_H_

/************************************************************************/
/* Manager Imports                                                      */
/************************************************************************/
#include "../Drivers/LCD.h"
#include "Mode_Config.h"

/************************************************************************/
/* Manager Functions                                                    */
/************************************************************************/

/************************************************************************/
/* Function Description : Welcome Screen Display Function               */
/* Function Arguments   : void                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void WelcomeScreen(void);

/************************************************************************/
/* Function Description : Idle Screen Display Function                  */
/* Function Arguments   : void                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void IdleScreen(void);

/************************************************************************/
/* Function Description : Display Set Temperature Function              */
/* Function Arguments   : uint8_t value                                 */
/* Function Returns     : void                                          */
/************************************************************************/
void Display_SET_Temperature(uint8_t value);

/************************************************************************/
/* Function Description : Display Current Temperature Function          */
/* Function Arguments   : uint8_t value                                 */
/* Function Returns     : void                                          */
/************************************************************************/
void Display_CRT_Temperature(uint8_t value);

/************************************************************************/
/* Function Description : Display Error Form in Current Temperature     */
/* Function Arguments   : uint8_t value                                 */
/* Function Returns     : void                                          */
/************************************************************************/
void Display_CRT_Temperature_ERROR();

/************************************************************************/
/* Function Description : Display Current Program State                 */
/* Function Arguments   : char* state                                   */
/* Function Returns     : void                                          */
/************************************************************************/
void Display_STATE(char* state);

#endif /* DSP_MANAGER_H_ */
