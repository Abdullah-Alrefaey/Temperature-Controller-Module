/************************************************************************/
/*                          DIO Driver                                  */
/************************************************************************/
#ifndef DIO_H_
#define DIO_H_

/************************************************************************/
/* Driver Imports                                                       */
/************************************************************************/
#define U_ONE 1U
#define U_ZERO 0U

/************************************************************************/
/* Driver Imports                                                       */
/************************************************************************/
#include <stdint.h>
#include <avr/io.h>



/************************************************************************/
/* Function Description : Set the direction of the given pin given port */
/*                        (direction 0 = input : 1 = output)            */
/* Function Arguments   : char portName                                 */
/*                        uint8_t pinNumber                             */
/*						  uint8_t direction                             */
/* Function Returns     : void                                          */
/************************************************************************/
void DIO_vsetPINDir(char portName, uint8_t pinNumber, uint8_t dir);


/************************************************************************/
/* Function Description : Set the value of the given pin in the given   */
/*                        port (value 0 = low : 1 = high)               */
/* Function Arguments   : char portName                                 */
/*                        uint8_t pinNumber                             */
/*						  uint8_t value                                 */
/* Function Returns     : void                                          */
/************************************************************************/
void DIO_Write_PIN(char portName, uint8_t pinNumber, uint8_t value);



/************************************************************************/
/* Function Description : Returns 1 if the value of the given pin is    */
/*                        high and zero if the value is low             */
/* Function Arguments   : char portName                                 */
/*                        uint8_t pinNumber                             */
/* Function Returns     : uint8_t                                       */
/************************************************************************/
uint8_t DIO_Read_PIN(char portName, uint8_t pinNumber);

/************************************************************************/
/* Function Description : Reverse the value of the given pin in the     */ 
/*                        given port                                    */
/* Function Arguments   : char portName                                 */
/*                        uint8_t pinNumber                             */
/* Function Returns     : void                                          */
/************************************************************************/
void DIO_Toggle_PIN(char portName, uint8_t pinNumber);

/************************************************************************/
/* Function Description : set the direction of whole port.              */
/*                        (direction 0 = input : 1 = output)            */
/* Function Arguments   : char portName                                 */
/*                        uint8_t dir                                   */
/* Function Returns     : void                                          */
/************************************************************************/
void DIO_Set_PORT_Direction(char portName, uint8_t dir);

/************************************************************************/
/* Function Description : Write the value to all port pins              */
/*                        (direction 0 = input : 1 = output)            */
/* Function Arguments   : char portName                                 */
/*                        uint8_t portValue                             */
/* Function Returns     : void                                          */
/************************************************************************/
void DIO_Write_PORT(char portName, uint8_t portValue);


/************************************************************************/
/* Function Description : Read the value of the port                    */
/* Function Arguments   : char portName                                 */
/* Function Returns     : uint8_t                                       */
/************************************************************************/
uint8_t DIO_Read_PORT(char portName);

/************************************************************************/
/* Function Description : Reverse the value of the given port           */
/* Function Arguments   : char portName                                 */
/* Function Returns     : uint8_t                                       */
/************************************************************************/
void DIO_Toggle_PORT(char portName);

/************************************************************************/
/* Function Description : Set low nibble to the given port              */
/* Function Arguments   : char portName                                 */
/*                        uint8_t value                                 */
/* Function Returns     : uint8_t                                       */
/************************************************************************/
void DIO_Write_Low_Nibble(char portName, uint8_t value);

/************************************************************************/
/* Function Description : Set high nibble to the given port.            */
/* Function Arguments   : char portName                                 */
/*                        uint8_t value                                 */
/* Function Returns     : void                                          */
/************************************************************************/
void DIO_Write_High_Nibble(char portName, uint8_t value);


/************************************************************************/
/* Function Description : DIO_Write_Low_5_Nibble.                       */
/* Function Arguments   : char portName                                 */
/*                        uint8_t value                                 */
/* Function Returns     : void                                          */
/************************************************************************/
void DIO_Write_Low_5_Nibble(char portName, uint8_t value);

/************************************************************************/
/* Function Description : Connect PullUp to the given port and pin      */   
/*                        number                                        */
/* Function Arguments   : char portName                                 */
/*                        uint8_t value                                 */
/* Function Returns     : void                                          */
/************************************************************************/
void DIO_Connect_PullUp(char portName, uint8_t pinNumber, uint8_t value);

#endif
/************************************************************************/
