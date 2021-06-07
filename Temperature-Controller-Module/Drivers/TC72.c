/************************************************************************/
/*                          Keypad Driver                               */
/*                   Author: Ahmad Abdalmageed                          */
/************************************************************************/
#include "TC72.h"

/************************************************************************/
/* Function Description:                                                */
/* TC72 SPI Communication Protocol Initiator Function, Initiates the SPI*/
/* Master Mode and Select the Control Register with 0x80 Address and    */
/* Specify the Sensor's Operation Mode. One-Shot, Only one Temperature  */
/* is taken on writing to the Sensor. Continous Mode, the sensor takes  */
/* a reading ever 150 ms and store it in the Data Register              */ 
/************************************************************************/
void TC72_Init(char mode){
	// Initiate SPI Master in SPI 
	SPI_MasterInit();
	
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

/************************************************************************/
/* Function Description:                                                */
/* Main TC72 Reading Operation Function, TC72 Write mode is done with CE*/
/* Chip Select being HIGH, Then the Reading Process starts, The Master  */
/* Selects from MSB (Lower Resolution Temp.) or LSB (Higher Resolution  */
/* Temp.). We are only Interested in the MSB which is selected from the */
/* 0x02 Register.                                                       */
/************************************************************************/
char TC72_Read(){
	// Create a Rising Edge on the
	// TC72 Port to Start SPI Communication 
	DIO_Write_PIN('B', 4, 1);
	
	// Select the MSB Mode, Since we are 
	// not interested in a High Resolution
	// Temperature Measurement
	char temp;
	temp = SPI_MasterTransmitchar(0x02);
	//_delay_us(20); // Removed Violation for Testing 
	
	// Signal Check with the TC72, TODO: Check Necessity of This Step
	temp = SPI_MasterTransmitchar(0x00);
	//_delay_us(20); // Removed Violation for Testing 
	
	// Finish Communication
	DIO_Write_PIN('B', 4, 0);
	return temp;
}