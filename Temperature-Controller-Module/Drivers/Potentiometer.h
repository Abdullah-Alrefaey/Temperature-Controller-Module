/************************************************************************/
/*                          Potentiometer Driver                        */
/************************************************************************/
#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_

/************************************************************************/
/* Library Imports                                                      */
/************************************************************************/
#include "ADC.h"
typedef double float64_t;
/************************************************************************/
/* Driver Functions                                                     */
/************************************************************************/

/************************************************************************/
/* Function Description : Potentiometer Module Initiation Function      */
/* Function Arguments   : void                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Potentiometer_vInit(void);

/************************************************************************/
/* Function Description : Potentiometer Module Disable Function         */
/* Function Arguments   : void                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void Potentiometer_vDisable(void);

/************************************************************************/
/* Function Description : Read Potentiometer Value                      */
/* Function Arguments   : void                                          */
/* Function Returns     : double                                        */
/************************************************************************/
float64_t Potentiometer_Read(void);

#endif /* POTENTIOMETER_H_ */
