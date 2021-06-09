/************************************************************************/
/*                          SPI    Driver                               */
/************************************************************************/
#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

/************************************************************************/
/* Driver Definitions                                                   */
/************************************************************************/
#define F_CPU 16000000UL

/************************************************************************/
/* Driver  Imports                                                      */
/************************************************************************/
#include "DIO.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/************************************************************************/
/* Driver Functions                                                     */
/************************************************************************/

/************************************************************************/
/* Function Description : SPI Communication Protocol Initiator Function */
/* Function Arguments   : void                                          */
/* Function Returns     : void                                          */
/************************************************************************/
void SPI_MasterInit(void);

/************************************************************************/
/* Function Description : Master Transmit Data Using SPI Protocol       */
/* Function Arguments   : char Data                                     */
/* Function Returns     : char                                          */
/************************************************************************/
char SPI_MasterTransmitchar(char Data);


#endif /* SPI_DRIVER_H_ */
