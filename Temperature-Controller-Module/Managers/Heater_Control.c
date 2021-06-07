/************************************************************************/
/*                          Heater Control Manager                      */
/************************************************************************/

#include "Heater_Control.h"

extern uint8_t SET_Temperature;
extern uint8_t CRT_Temperature;

extern uint8_t HASH_KEY_COUNTER;
extern uint8_t ADC_COUNTER;
extern uint16_t ERROR_COUNTER;

const char LEDs_PORT = 'B';

char * states[4] = {"STANDBY", "OPERATION", "NORMAL", "ERROR"};
	
/* First Start in STANDBY STATE */
uint8_t state_indx = 0U;

/* Calibration Resistor Voltage (Used to determine Duty Cycle Percentage) */
double Vt = 0;		
double Vr = 0;

/************************************************************************/
/* Function Description:                                                */
/* Initialize the 4 STATES LEDs which are used to indicate the current  */
/* state of the heater                                                  */
/************************************************************************/
void LEDs_States_vInit()
{
	/* Initialize STATES LEDs for Better Indication */
	LED_vInit(LEDs_PORT, STANDBY_LED);
	LED_vInit(LEDs_PORT, OPERATION_LED);
	LED_vInit(LEDs_PORT, NORMAL_LED);
	LED_vInit(LEDs_PORT, ERROR_LED);
	
	/* Heater start in STANDBY State */
	LED_vTurnOn(LEDs_PORT, STANDBY_LED);
}

/************************************************************************/
/* Function Description:                                                */
/* Initialize the Heater Functionalities (Calibration Resistor and PWM) */
/************************************************************************/
void Heater_vInit(void)
{
	Potentiometer_vInit();
	PWM_vInit(2U, 1U, 2U);
}

/************************************************************************/
/* Function Description:                                                */
/* Disable the Heater Functionalities (Calibration Resistor and PWM)    */
/************************************************************************/
void Heater_vDisable(void)
{
	Potentiometer_vDisable();
	PWM_vDisable(2U);
}

/************************************************************************/
/* Function Description:                                                */
/* Update Target Voltage Value in the given equation based on the       */
/* difference between SET_Temperature and CRT_Temperature               */
/* The Vt is used to determine the Duty Cycle                           */
/************************************************************************/
void Update_Vt()
{
	if (SET_Temperature <= CRT_Temperature)
	{
		Vt = 0;
	}
	else if (SET_Temperature > CRT_Temperature)
	{
		Vt = ((SET_Temperature - CRT_Temperature) / 100.0) * 10;
	} else {
	    /* Impossible Condition, Wrote All Possible Ones For Readability */
	}
}

/************************************************************************/
/* Function Description:                                                */
/* Update Calibration Resistor Voltage Periodically each 500 ms using   */
/* Potentiometer_Read function which is based on ADC.                   */
/* The ADC_COUNTER is reset after                                       */
/************************************************************************/
void Update_Vr()
{
	/* This means when (500 ms) is passed */
	if (ADC_COUNTER >= 50)
	{
		Vr = Potentiometer_Read();
		ADC_COUNTER = 0U;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}

/************************************************************************/
/* Function Description:                                                */
/* Calculate the Duty Cycle Percentage from the given equation and      */
/* start the PWM wave which will be displayed on the Oscilloscope.      */
/************************************************************************/
void Heater_vSet_Volt(double V_target, double V_pot)
{	
	uint8_t Duty = 0U;
	double DutyPercentage = 0;
	DutyPercentage = (((V_pot * 2)/10) * V_target) / 10; /* Range: 0 -> 1 */
	Duty = floor(DutyPercentage*255.0);
	PWM_vSet_Duty(2U, Duty);
}

/************************************************************************/
/* Function Description:                                                */
/* Check if the condition of switching to OPERATION STATE is satisfied  */
/* and update state_indx with the new STATE index                       */
/* Change the LEDs based on the condition                               */
/************************************************************************/
void Check_OPERATION_State()
{
	/* Change To OPERATIONAL State if SET - CRT > 5 */
	if ((SET_Temperature - CRT_Temperature) > 5)
	{
		state_indx = 1U;
		LED_vTurnOff(LEDs_PORT, NORMAL_LED);
		LED_vTurnOn(LEDs_PORT, OPERATION_LED);
	}	
}

/************************************************************************/
/* Function Description:                                                */
/* Check if the condition of switching to NORMAL STATE is satisfied     */
/* and update state_indx with the new STATE index.                      */
/* Reset ERROR_COUNTER to 0, we don't want to start the timer unless if */
/* the heater was in OPERATION STATE                                    */
/* Change the LEDs based on the condition                               */
/************************************************************************/
void Check_NORMAL_State()
{
	if (abs(SET_Temperature - CRT_Temperature) <= 5)
	{
		state_indx = NORMAL_INDEX;
		
		/* Reset Error Counter */
		ERROR_COUNTER = 0U;
		
		LED_vTurnOff(LEDs_PORT, OPERATION_LED);
		LED_vTurnOn(LEDs_PORT, NORMAL_LED);
	}
}

/************************************************************************/
/* Function Description:                                                */
/* Check if the condition of switching to ERROR STATE is satisfied      */
/* and update state_indx with the new STATE index.                      */
/* Change the LEDs based on the condition                               */
/************************************************************************/
void Check_ERROR_State()
{
	/* Change To ERROR State if CRT - SET > 10 */
	if ((CRT_Temperature - SET_Temperature) > 10)
	{
		state_indx = ERROR_INDEX;
		LED_vTurnOff(LEDs_PORT, NORMAL_LED);
		LED_vTurnOff(LEDs_PORT, OPERATION_LED);
		LED_vTurnOn(LEDs_PORT, ERROR_LED);
	}
}

/************************************************************************/
/* Function Description:                                                */
/* Check if the condition of switching to ERROR STATE is satisfied      */
/* and update state_indx with the new STATE index.                      */
/* This ERROR Check in case of (SET-CRT) > 5 for 3 minutes.             */
/* Change the LEDs based on the condition                               */
/************************************************************************/
void Check_ERROR_State_Timer()
{
	/* Each count = 10.048 ms
	* This means when 100 count is equal to 1 second
	* We need 3 minutes, so counter should be 180 second x 100 = 18000
	* But it's actually 17200 for some fractions remaining
	
	* NOTE: When testing with ERROR_COUNTER > 17200, the elapsed time to
	* execute the error was about 3.40 seconds
	* The calculations are determined in a correct way, so to solve then we
	* will decrement the ERROR_COUNTER a little
	*/
	if (ERROR_COUNTER > 14500)
	{
		/* Change To ERROR State */
		state_indx = ERROR_INDEX;
		ERROR_COUNTER = 0U;
		LED_vTurnOff(LEDs_PORT, OPERATION_LED);
		LED_vTurnOn(LEDs_PORT, ERROR_LED);
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}

/************************************************************************/
/* Function Description:                                                */
/* Check periodically every 200ms if the user pressed '#' key.          */
/* keypad_Check_OPKey function returns 1 if user pressed '#'            */
/* Check the current and STATE and based on this STATE the heater will  */
/* switch to other STATE.                                               */        
/* Reset ERROR_COUNTER to 0, we don't want to start the timer unless if */
/* the heater was in OPERATION STATE                                    */
/* Change the LEDs based on the condition                               */
/************************************************************************/
void Check_HASH_Key()
{
	/* This means when (200 ms) is passed */
	if (HASH_KEY_COUNTER >= 20)
	{
		/* Check if user pressed # */
		if (keypad_Check_OPKey() == 1)
		{
			/* Switch to OPERATION STATE if already in STANDBY */
			if (state_indx == STANDBY_INDEX)
			{
				state_indx = OPERATION_INDEX;
				LED_vTurnOff(LEDs_PORT, STANDBY_LED);
				LED_vTurnOn(LEDs_PORT, OPERATION_LED);
			}
			/* Switch to STANDBY STATE if already in STANDBY */
			else if (state_indx == OPERATION_INDEX || state_indx == NORMAL_INDEX)
			{
				state_indx = STANDBY_INDEX;
				LED_vTurnOff(LEDs_PORT, NORMAL_LED);
				LED_vTurnOff(LEDs_PORT, OPERATION_LED);
				LED_vTurnOn(LEDs_PORT, STANDBY_LED);
			}
			else
			{
				/* Do Nothing */
			}
			
			/* Reset Error Counter */
			ERROR_COUNTER = 0U;
		}
		else
		{
			/* Do Nothing (Hash is not pressed) */
		}
		
		HASH_KEY_COUNTER = 0U;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}