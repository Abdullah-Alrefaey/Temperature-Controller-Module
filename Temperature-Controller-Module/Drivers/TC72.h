/************************************************************************/
/*                          TC27   Driver                               */
/************************************************************************/
#ifndef TC72_H_
#define TC72_H_

/************************************************************************/
/* Driver Definitions                                                   */
/************************************************************************/
#define ONE_SHOT_MODE 0x14U
#define CONTINOUS_MODE 0x04U

/************************************************************************/
/* Library Imports                                                      */
/************************************************************************/
#include "DIO.h"
#include "SPI.h"


/************************************************************************/
/* Driver Functions                                                     */
/************************************************************************/

/************************************************************************/
/* Function Description : TC72 Sensor Initiator Function                */
/* Function Arguments   : char mode                                     */
/* Function Returns     : void                                          */
/************************************************************************/
void TC72_Init(char mode);

/************************************************************************/
/* Function Description : TC72 Communication Protocol Function          */
/* Function Arguments   : void                                          */
/* Function Returns     : char                                          */
/************************************************************************/
char TC72_Read(void);

#endif /*TC72_H_*/
/************************************************************************/
