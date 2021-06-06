/*
 * keypad_driver.c
 * 
 * Edited by: Ahmad Abdalmageed
 */ 
 #include "Keypad.h"

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
	 uint8_t x;
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
		 
		 for(coloumn = 0 ; coloumn < 3; coloumn++){
			 // Read Sent Signal  	 
			 x = DIO_Read_PIN(KEYPADPORT, (coloumn+4));
			 
			 // Button Pressed
			 if(x == 0){
				 returnval = kp[row][coloumn];
				 break;
			 } else{
				 // Current Element is not Pressed 
			 }
		 }
		
		// Break Higher Loop 
		if(x==0){
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
uint8_t check_OPKey()
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
		pressed = 1;
	} else {
		/* Do Nothing (# is not pressed) */
	}
	
	return pressed;
}