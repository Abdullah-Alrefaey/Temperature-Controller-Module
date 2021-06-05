#ifndef stdint
#define stdint
#include <stdint.h>
#endif

#ifndef DIO_H_
#define DIO_H_

#ifndef avrio
#define avrio
#include <avr/io.h>
#endif

/*
	Function Name        : DIO_vsetPINDir
	Function Returns     : void
	Function Arguments   : char portName, uint8_t pinNumber, uint8_t direction
	Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
*/
void DIO_vsetPINDir(char portName, uint8_t pinNumber, uint8_t direction);


/*
	Function Name        : DIO_Write_PIN
	Function Returns     : void
	Function Arguments   : char portName, uint8_t pinNumber, uint8_t outputvalue
	Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high) 
*/
void DIO_Write_PIN(char portName, uint8_t pinNumber, uint8_t outputvalue);


/*
	Function Name        : DIO_Read_PIN
	Function Returns     : uint8_t
	Function Arguments   : char portName, uint8_t pinNumber
	Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
*/
uint8_t DIO_Read_PIN(char portName, uint8_t pinNumber);


/*
	Function Name        : DIO_Toggle_PIN
	Function Returns     : void
	Function Arguments   : char portName, uint8_t pinNumber
	Function Description : Reverse the value of the given pin in the given port.
*/
void DIO_Toggle_PIN(char portName, uint8_t pinNumber);


/*
	Function Name        : DIO_Set_PORT_Direction
	Function Returns     : void
	Function Arguments   : char portName, uint8_t direction
	Function Description : set the direction of whole port. (direction 0 = input : 1 = output)
*/
void DIO_Set_PORT_Direction(char portName, uint8_t direction);


/*
	Function Name        : DIO_Write_PORT
	Function Returns     : void
	Function Arguments   : char portName, uint8_t portValue
	Function Description : Write the value to all port pins (direction 0 = input : 1 = output).
*/
void DIO_Write_PORT(char portName, uint8_t portValue);


/*
	Function Name        : DIO_Read_PORT
	Function Returns     : uint8_t
	Function Arguments   : char portName
	Function Description : read the value of the port.
*/
uint8_t DIO_Read_PORT(char portName);

/*
	Function Name        : DIO_Toggle_PORT
	Function Returns     : uint8_t
	Function Arguments   : char portName
	Function Description : Reverse the value of the given port.
*/
void DIO_Toggle_PORT(char portName);


/*
	Function Name        : DIO_Write_Low_Nibble
	Function Returns     : void
	Function Arguments   : char portName, uint8_t value
	Function Description : Set low nibble to the given port.
*/
void DIO_Write_Low_Nibble(char portName, uint8_t value);

/*
	Function Name        : DIO_Write_High_Nibble
	Function Returns     : void
	Function Arguments   : char portName, uint8_t value
	Function Description : Set high nibble to the given port.
*/
void DIO_Write_High_Nibble(char portName, uint8_t value);


/*
	Function Name        : DIO_Write_Low_5_Nibble
	Function Returns     : void
	Function Arguments   : char portName, uint8_t value
	Function Description : Set low nibble to the given port.
*/
void DIO_Write_Low_5_Nibble(char portName, uint8_t value);

/*
	Function Name        : DIO_Connect_PullUp
	Function Returns     : void
	Function Arguments   : char portName, uint8_t pinNumber, uint8_t value
	Function Description : Connect PullUp to the given port and pin number.
*/
void DIO_Connect_PullUp(char portName, uint8_t pinNumber, uint8_t value);

#endif