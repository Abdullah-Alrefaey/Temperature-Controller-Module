#ifndef DIO_H_
#define DIO_H_

/*
	Function Name        : DIO_vsetPINDir
	Function Returns     : void
	Function Arguments   : unsigned char portName, unsigned char pinNumber, unsigned char direction
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/
void DIO_vsetPINDir(unsigned char portName, unsigned char pinNumber, unsigned char direction);


/*
	Function Name        : DIO_Write_PIN
	Function Returns     : void
	Function Arguments   : unsigned char portName, unsigned char pinNumber, unsigned char outputvalue
	Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high) 
*/
void DIO_Write_PIN(unsigned char portName, unsigned char pinNumber, unsigned char outputvalue);


/*
	Function Name        : DIO_Read_PIN
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portName, unsigned char pinNumber
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
unsigned char DIO_Read_PIN(unsigned char portName, unsigned char pinNumber);


/*
	Function Name        : DIO_Toggle_PIN
	Function Returns     : void
	Function Arguments   : unsigned char portName, unsigned char pinNumber
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_Toggle_PIN(unsigned char portName, unsigned char pinNumber);


/*
	Function Name        : DIO_Set_PORT_Direction
	Function Returns     : void
	Function Arguments   : unsigned char portName, unsigned char direction
	Function Description : set the direction of whole port. (direction 0 = input : 1 = output)
*/
void DIO_Set_PORT_Direction(unsigned char portName, unsigned char direction);


/*
	Function Name        : DIO_Write_PORT
	Function Returns     : void
	Function Arguments   : unsigned char portName, unsigned char portValue
	Function Description : Write the value to all port pins (direction 0 = input : 1 = output).
*/
void DIO_Write_PORT(unsigned char portName, unsigned char portValue);


/*
	Function Name        : DIO_Read_PORT
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portName
	Function Description : read the value of the port.
*/
unsigned char DIO_Read_PORT(unsigned char portName);

/*
	Function Name        : DIO_Toggle_PORT
	Function Returns     : unsigned char
	Function Arguments   : unsigned char portName
	Function Description : Reverse the value of the given port.
*/
void DIO_Toggle_PORT(unsigned char portName);


/*
	Function Name        : DIO_Write_Low_Nibble
	Function Returns     : void
	Function Arguments   : unsigned char portName, unsigned char value
	Function Description : Set low nibble to the given port.
*/
void DIO_Write_Low_Nibble(unsigned char portName, unsigned char value);

/*
	Function Name        : DIO_Write_High_Nibble
	Function Returns     : void
	Function Arguments   : unsigned char portName, unsigned char value
	Function Description : Set high nibble to the given port.
*/
void DIO_Write_High_Nibble(unsigned char portName, unsigned char value);


/*
	Function Name        : DIO_Write_Low_5_Nibble
	Function Returns     : void
	Function Arguments   : unsigned char portName, unsigned char value
	Function Description : Set low nibble to the given port.
*/
void DIO_Write_Low_5_Nibble(unsigned char portName, unsigned char value);

/*
	Function Name        : DIO_Connect_PullUp
	Function Returns     : void
	Function Arguments   : unsigned char portName, unsigned char pinNumber, unsigned char value
	Function Description : Connect PullUp to the given port and pin number.
*/
void DIO_Connect_PullUp(unsigned char portName, unsigned char pinNumber, unsigned char value);

#endif