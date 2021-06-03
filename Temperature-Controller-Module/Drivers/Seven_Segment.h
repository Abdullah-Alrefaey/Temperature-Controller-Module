#ifndef Seven_Segment_H_
#define Seven_Segment_H_

/*
Function Name        : SevenSegment_SetUp
Function Returns     : void
Function Arguments   : unsigned char portName
Function Description : sets the direction of the given port as output 
*/
void SevenSegment_SetUp(unsigned char portName);


/*
Function Name        : SevenSegment_Display
Function Returns     : void
Function Arguments   : unsigned char portName, unsigned char value
Function Description : displays the given value on the given port 
*/
void SevenSegment_Display(unsigned char portName, unsigned char value);

#endif /* Seven_Segment_H_ */