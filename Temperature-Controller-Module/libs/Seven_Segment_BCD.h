#ifndef Seven_Segment_BCD_H_
#define Seven_Segment_BCD_H_

/*
Function Name        : SevenSegment_BCD_SetUp
Function Returns     : void
Function Arguments   : unsigned char portName, unsigned char mode
Function Description : sets the direction of the given port as output 
*/
void SevenSegment_BCD_SetUp(unsigned char portName, unsigned char mode);


/*
Function Name        : SevenSegment_BCD_Display
Function Returns     : void
Function Arguments   : unsigned char value, unsigned char mode, unsigned char value
Function Description : displays the given value on the given port 
*/
void SevenSegment_BCD_Display(unsigned char portName, unsigned char mode, unsigned char value);

#endif /* Seven_Segment_BCD_H_ */