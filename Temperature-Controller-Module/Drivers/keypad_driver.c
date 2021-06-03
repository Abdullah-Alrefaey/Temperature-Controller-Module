/*
 * keypad_driver.c
 *
 */ 
 #include "keypad_driver.h"

 void keypad_vInit()
 {
	 DIO_vsetPINDir('D',0,1);
	 DIO_vsetPINDir('D',1,1);
	 DIO_vsetPINDir('D',2,1);
	 DIO_vsetPINDir('D',3,1);
	 DIO_vsetPINDir('D',4,0);
	 DIO_vsetPINDir('D',5,0);
	 DIO_vsetPINDir('D',6,0);
	 DIO_vsetPINDir('D',7,0);
	 DIO_Connect_PullUp('D',4,1);
	 DIO_Connect_PullUp('D',5,1);
	 DIO_Connect_PullUp('D',6,1);
	 DIO_Connect_PullUp('D',7,1);
	  
 }

 char keypad_u8check_press()
 {
	 char arr[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	 char row, coloumn, x;
	 char returnval = NOTPRESSED;
	
	 for(row = 0; row < 4; row++)
	 {
		DIO_Write_PIN('D', 0, 1);
		DIO_Write_PIN('D', 1, 1);
		DIO_Write_PIN('D', 2, 1);
		DIO_Write_PIN('D', 3, 1);
		DIO_Write_PIN('D', row, 0);
		 
		for(coloumn = 0 ; coloumn < 4; coloumn++)
		{
			x = DIO_Read_PIN('D', (coloumn+4));
			if(x == 0)
			{
				returnval = arr[row][coloumn];
				break;
			}
		}

		if(x==0)
		{
			break;
		}
	 }

	 return returnval;	 
 }