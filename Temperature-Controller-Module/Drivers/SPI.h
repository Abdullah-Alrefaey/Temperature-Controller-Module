/*
 * spi_driver.h
 *
 * Created: 5/6/2021 5:20:42 PM
 * Author: Ahmad Abdalmageed
 */ 


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

// Driver Imports
#include "DIO.h"

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Driver Functions 
void SPI_MasterInit(void);
char SPI_MasterTransmitchar(char Data);


#endif /* SPI_DRIVER_H_ */