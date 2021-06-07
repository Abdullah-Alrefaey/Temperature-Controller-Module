/*
 * keypad_driver.h
 *
 * Edited by: Ahmad Abdalmageed
 */


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

// Driver Definitions
#define NOTPRESSED 0xff
#define KEYPADPORT 'A'
#define HASH_KEY 12

// Driver Imports 
#include "DIO.h"

// Driver Functions
void keypad_vInit();
uint8_t keypad_u8check_press();
uint8_t keypad_Check_OPKey();

#endif /* KEYPAD_DRIVER_H_ */