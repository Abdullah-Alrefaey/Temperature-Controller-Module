/*
 * Seven_Segment_BCD_ETA32.h
 *
 * Created: 10-Apr-21 2:48:43 PM
 *  Author: Refaey
 */ 


#ifndef SEVEN_SEGMENT_BCD_ETA32_H_
#define SEVEN_SEGMENT_BCD_ETA32_H_

// Common Anode

/*
Function Name        : SevenSegment_BCD_ETA32_SetUp
Function Returns     : void
Function Arguments   : unsigned char portName
Function Description : sets the direction of the given port as output
*/
void SevenSegment_BCD_ETA32_SetUp(unsigned char portName);

/*
Function Name        : SevenSegment_BCD_ETA32_Enable
Function Returns     : void
Function Arguments   : unsigned char portName, unsigned char pinNumber
Function Description : sets the direction of the given port as output
*/
void SevenSegment_BCD_ETA32_Enable(unsigned char portName, unsigned char pinNumber);

/*
Function Name        : SevenSegment_BCD_ETA32_Disable
Function Returns     : void
Function Arguments   : unsigned char portName, unsigned char pinNumber
Function Description : sets the direction of the given port as output
*/
void SevenSegment_BCD_ETA32_Disable(unsigned char portName, unsigned char pinNumber);

/*
Function Name        : SevenSegment_BCD_ETA32_Display
Function Returns     : void
Function Arguments   : unsigned char value, unsigned char value
Function Description : displays the given value on the given port
*/
void SevenSegment_BCD_ETA32_Display(unsigned char portName, unsigned char value);



#endif /* SEVEN_SEGMENT_BCD_ETA32_H_ */