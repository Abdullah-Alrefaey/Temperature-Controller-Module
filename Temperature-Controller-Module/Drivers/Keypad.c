/************************************************************************/
/*                          Keypad Driver                               */
/************************************************************************/
#include "Keypad.h"

extern char PORTS[4];
uint8_t prev[4][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
uint8_t counter_debounce = DEBOUNCING_COUNTER;
uint8_t hash_debounce = DEBOUNCING_COUNTER;

/************************************************************************/
/* Function Description:                                                */
/* Function Initiator for a 4*3 Keypad on PORTD, The Function set the   */
/* Keypad Ports Direction as outputs (First Four) and Input (Last 3)    */
/* Then Enable Port Pull Ups                                            */
/************************************************************************/
 void keypad_vInit(){
	 
	 // Set Output Pins 
	 DIO_vsetPINDir(PORTS[KEYPADPORT], 0, 1);
	 DIO_vsetPINDir(PORTS[KEYPADPORT], 1, 1);
	 DIO_vsetPINDir(PORTS[KEYPADPORT], 2, 1);
	 DIO_vsetPINDir(PORTS[KEYPADPORT], 3, 1);
	 
	 // Set Input 
	 DIO_vsetPINDir(PORTS[KEYPADPORT], 4, 0);
	 DIO_vsetPINDir(PORTS[KEYPADPORT], 5, 0);
	 DIO_vsetPINDir(PORTS[KEYPADPORT], 6, 0);
	 					   
	 // Pull Up 
	 DIO_Connect_PullUp(PORTS[KEYPADPORT], 4, 1);
	 DIO_Connect_PullUp(PORTS[KEYPADPORT], 5, 1);
	 DIO_Connect_PullUp(PORTS[KEYPADPORT], 6, 1);
	  
 }

/************************************************************************/
/* Function Description:                                                */ 
/* Matrix Loop Function that checks all Elements in the Keypad Matrix   */
/* (4*3) and Return the Pressed Element if the Circuit was closed, It	*/
/* also Includes a solution for De-bouncing the Button State which      */
/* Affected our Process                                                 */ 
/************************************************************************/
 uint8_t keypad_u8check_press(){
	 // Keypad Matrix Definition 
	 uint8_t kp[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {0, 0, 12}};
	 uint8_t row;
	 uint8_t coloumn; 
	 uint8_t ON;
	 uint8_t returnval = NOTPRESSED;
	 
	 // Matrix Loop Check for each Keypad Element
	 for(row = 0; row < 4; row++){
		 // Set Output Pins HIGH
		 DIO_Write_PIN(PORTS[KEYPADPORT], 0, 1);
		 DIO_Write_PIN(PORTS[KEYPADPORT], 1, 1);
		 DIO_Write_PIN(PORTS[KEYPADPORT], 2, 1);
		 DIO_Write_PIN(PORTS[KEYPADPORT], 3, 1);
		 		 
		 // Send Signal LOW
		 DIO_Write_PIN(PORTS[KEYPADPORT], row, 0);
		 for(coloumn = 0 ; coloumn < 3; coloumn++)
		 {
			 // Read Sent Signal  	 
			 ON = DIO_Read_PIN(PORTS[KEYPADPORT], (coloumn+4));
			 
			 // Button Pressed
			 if(ON == 0)
			 {
				 // The Button is pressed but needs De-Bouncing
				 prev[row][coloumn] = 1;
				 // Decrease The count
				 counter_debounce = counter_debounce - 1;
			 } else if (counter_debounce == 0 && prev[row][coloumn] == 1)
			 {
				 // Current Element is De-Bounced
				 returnval = kp[row][coloumn];
				 // Reset Previous State
				 prev[row][coloumn] = 0;
				 // Reset Counter
				 counter_debounce = DEBOUNCING_COUNTER;
				 // Break Loop to Return
				 break;
			 } else 
			 {
				 // No Button Pressed
			 }
		 }
		// Break Higher Loop 
		if(ON == 0 && counter_debounce == 0)
		{
			break;
		} else{
			// Do Nothing 
		}
	 }
	
	 // Return Pressed Key
	 return returnval;	 
 }
 
 /************************************************************************/
 /* Function Description:                                                */
 /* This Function is a Specific Driver Function that Checks the # Key in */
 /* the matrix, Return True When the Button is Pressed, Also Added the   */
 /* De-bouncing Algorithm                                                */
 /************************************************************************/
uint8_t keypad_Check_OPKey()
{
	// Button State
	char btn_val;
	// Condition Return
	uint8_t pressed = 0;
	
	// Send Signal in Specified Cow
	DIO_Write_PIN(PORTS[KEYPADPORT], 0, 1);
	DIO_Write_PIN(PORTS[KEYPADPORT], 1, 1);
	DIO_Write_PIN(PORTS[KEYPADPORT], 2, 1);
	DIO_Write_PIN(PORTS[KEYPADPORT], 3, 0);
	
	// Read from Specified Column
	btn_val = DIO_Read_PIN(PORTS[KEYPADPORT], 6);
	
	if (btn_val == 0){
		// Decrease Counter
		hash_debounce = hash_debounce - 1;
	} else if (hash_debounce == 0)
	{
		// Finish De-bouncing -> return pressed value
		hash_debounce = DEBOUNCING_COUNTER;
		pressed = 1;
	}
	return pressed;
}
/************************************************************************/