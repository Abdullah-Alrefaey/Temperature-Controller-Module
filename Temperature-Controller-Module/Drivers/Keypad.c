/*
 * keypad_driver.c
 * 
 * Edited by: Ahmad Abdalmageed
 */ 
 #include "Keypad.h"

#define DEBOUNCING_COUNTER 1

uint8_t prev[4][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
uint8_t counter_debounce = DEBOUNCING_COUNTER;
uint8_t hash_debounce = DEBOUNCING_COUNTER;

/*
 * Keypad Initialization 
 *
 * Description:
 * Function Initiator for a 4*3 Keypad
 * on PORTD  
 */
 void keypad_vInit(){
	 
	 // Set Output Pins 
	 DIO_vsetPINDir(KEYPADPORT, 0, 1);
	 DIO_vsetPINDir(KEYPADPORT, 1, 1);
	 DIO_vsetPINDir(KEYPADPORT, 2, 1);
	 DIO_vsetPINDir(KEYPADPORT, 3, 1);
	 
	 // Set Input 
	 DIO_vsetPINDir(KEYPADPORT, 4, 0);
	 DIO_vsetPINDir(KEYPADPORT, 5, 0);
	 DIO_vsetPINDir(KEYPADPORT, 6, 0);
	 					   
	 // Pull Up 
	 DIO_Connect_PullUp(KEYPADPORT, 4, 1);
	 DIO_Connect_PullUp(KEYPADPORT, 5, 1);
	 DIO_Connect_PullUp(KEYPADPORT, 6, 1);
	  
 }


/*
 * keypad_u8check_press (Get Pressed Element)
 * 
 * Description:
 * Matrix Loop Function that checks all Elements
 * in the Keypad Matrix (4*3) and Return the 
 * Pressed Element 
 */
 uint8_t keypad_u8check_press(){
	 uint8_t kp[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {0, 0, 12}};
	 uint8_t row;
	 uint8_t coloumn; 
	 uint8_t ON;
	 uint8_t returnval = NOTPRESSED;
	 
	 // Matrix Loop Check for each Keypad Element
	 for(row = 0; row < 4; row++){
		 // Set Output Pins HIGH
		 DIO_Write_PIN(KEYPADPORT, 0, 1);
		 DIO_Write_PIN(KEYPADPORT, 1, 1);
		 DIO_Write_PIN(KEYPADPORT, 2, 1);
		 DIO_Write_PIN(KEYPADPORT, 3, 1);
		 		 
		 // Send Signal LOW
		 DIO_Write_PIN(KEYPADPORT, row, 0);
		 
		 for(coloumn = 0 ; coloumn < 3; coloumn++)
		 {
			 // Read Sent Signal  	 
			 ON = DIO_Read_PIN(KEYPADPORT, (coloumn+4));
			 
			 // Button Pressed
			 if(ON == 0){
				 /*The Button is pressed but needs De-Bouncing*/
				 prev[row][coloumn] = 1;
				 counter_debounce = counter_debounce - 1;
				 
			 } else if (counter_debounce == 0 && prev[row][coloumn] == 1){
				 // Current Element is De-Bounced 
				 returnval = kp[row][coloumn];
				 prev[row][coloumn] = 0;
				 counter_debounce = DEBOUNCING_COUNTER;
				 break;
			 } else {
				 
				 // No Button Pressed
			 }
		 }
		
		// Break Higher Loop 
		if(ON == 0 && counter_debounce == 0){
			break;
		} else{
			// Do Nothing 
		}
	 }
	
	 // Return Pressed Key
	 return returnval;	 
 }
 
 
 /*
  * check_operational (Check the # Key)
  *
  * Description: 
  * This Function return 1 if the # Key is Pressed
  * and 0 if not
  */
uint8_t keypad_Check_OPKey()
{
	char val;
	uint8_t pressed = 0;
	
	// Send Signal in Specified Cow
	DIO_Write_PIN(KEYPADPORT, 0, 1);
	DIO_Write_PIN(KEYPADPORT, 1, 1);
	DIO_Write_PIN(KEYPADPORT, 2, 1);
	DIO_Write_PIN(KEYPADPORT, 3, 0);
	
	// Read from Specified Column
	val = DIO_Read_PIN(KEYPADPORT, 6);
	
	if (val == 0){
		hash_debounce = hash_debounce - 1;
	} else if (hash_debounce == 0) {
		/* Finish Debouncing -> return pressed value */
		hash_debounce = DEBOUNCING_COUNTER;
		pressed = 1;
	}
	
	return pressed;
}