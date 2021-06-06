/*
 * TC72.h
 *
 * Created: 05-Jun-21 2:34:47 PM
 * Author: Ahmad Abdalmageed
 */ 


#ifndef TC72_H_
#define TC72_H_

// Driver Includes
#include "DIO.h"
#include "SPI_driver.h"

// Driver Defines 
#define One_Shot 0x14
#define Continous 0x04

// Driver Functions
void TC72_Init(char mode);
char TC72_Read();

#endif /* TC72_H_ */