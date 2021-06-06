/*
 * TC72.c
 *
 * Created: 05-Jun-21 2:34:36 PM
 *  Author: Refaey
 */ 

#include "TC72.h"

void TC72_Init(char mode){
	// Create a Rising Edge on the	
	// TC72 Port to Start SPI Communication
	DIO_Write_PIN('B', 4, 1);
	
	// Send Signal to Select Control
	// Register at 0x80
	SPI_MasterTransmitchar(0x80);
	
	// Send Signal to Specify Mode
	SPI_MasterTransmitchar(mode);
	
	// Finish Communication 
	DIO_Write_PIN('B', 4, 0);  
}

char TC72_Read(){
	// Create a Rising Edge on the
	// TC72 Port to Start SPI Communication 
	DIO_Write_PIN('B', 4, 1);
	
	// Select the MSB Mode, Since we are 
	// not interested in a High Resolution
	// Temperature Measurement
	char temp;
	temp = SPI_MasterTransmitchar(0x02);
	
	// Signal Check with the TC72, TODO: Check Necessity of This Step
	temp = SPI_MasterTransmitchar(0x00);
	
	// Finish Communication
	DIO_Write_PIN('B', 4, 0);
	
	return temp;
}
