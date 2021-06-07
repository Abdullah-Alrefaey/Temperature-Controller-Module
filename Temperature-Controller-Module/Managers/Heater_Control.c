#include "Heater_Control.h"


extern uint8_t SET_Temperature;
extern uint8_t CRT_Temperature;

extern uint8_t HASH_KEY_COUNTER;
extern uint8_t ADC_COUNTER;
extern uint16_t ERROR_COUNTER;

const char LEDs_PORT = 'B';

char * states[4] = {"STANDBY", "OPERATION", "NORMAL", "ERROR"};
	
/* First Start in STANDBY STATE */
uint8_t state_indx = 0;

/* Calibration Resistor Voltage (Used to determine Duty Cycle Percentage) */
double Vt = 0;		
double Vr = 0;

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

void Heater_vInit(void)
{
	Potentiometer_vInit();
	PWM_vInit(2, 1, 2);
}

void Heater_vDisable(void)
{
	Potentiometer_vDisable();
	PWM_vDisable();
}

void Update_Vt()
{
	if (SET_Temperature <= CRT_Temperature)
	{
		Vt = 0;
	}
	else if (SET_Temperature > CRT_Temperature)
	{
		Vt = ((SET_Temperature - CRT_Temperature) / 100.0) * 10;
	}
}

void Update_Vr()
{
	/* This means when (500 ms) is passed */
	if (ADC_COUNTER >= 50)
	{
		Vr = Potentiometer_Read();
		ADC_COUNTER = 0;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}

void SetHeaterVolt(double Vt, double Vr)
{
	/* Vt: Target Voltage
	 * Vr: Calibration Resistor Voltage
	 */
	
	uint8_t Duty = 0;
	double DutyPercentage = 0;
	DutyPercentage = (((Vr * 2)/10) * Vt) / 10; /* Range: 0 -> 1 */
	Duty = floor(DutyPercentage*255.0);
	SPI_MasterTransmitchar(Duty);
	PWM_vSet_Duty(2, Duty);
}

void Check_OPERATION_State_Key()
{	
	/* Change To OPERATIONAL State if user pressed '#' key */
	char value = NOTPRESSED;
	
	/* Wait for user to enter tens */
	do {
		value = keypad_u8check_press();
		
		/* This delay is used to solve the debouncing problem of buttons */
		_delay_ms(300);
	} while (value != 12);
		
	state_indx = 1;
	LED_vTurnOff(LEDs_PORT, STANDBY_LED);
	LED_vTurnOn(LEDs_PORT, OPERATION_LED);
}

void Check_OPERATION_State()
{
	/* Change To OPERATIONAL State if SET - CRT > 5 */
	if ((SET_Temperature - CRT_Temperature) > 5)
	{
		state_indx = 1;
		LED_vTurnOff(LEDs_PORT, NORMAL_LED);
		LED_vTurnOn(LEDs_PORT, OPERATION_LED);
	}	
}

/* TODO: Fix Debouncing Issue */
/*
void Check_STANDBY_State()
{
	/ * This means when (200 ms) is passed * /
	if (HASH_KEY_COUNTER >= 20)
	{
		/ * Change To OPERATIONAL State if user pressed '#' key * /
		if (check_OPKey() == 1)
		{
			state_indx = STANDBY_INDEX;
			
			/ * Reset Error Counter * /
			ERROR_COUNTER = 0;
			
			LED_vTurnOff(LEDs_PORT, NORMAL_LED);
			LED_vTurnOff(LEDs_PORT, OPERATION_LED);
			LED_vTurnOn(LEDs_PORT, STANDBY_LED);
		}
		
		HASH_KEY_COUNTER = 0;
	}
	else
	{
		/ * Do Nothing, Didn't reach the required time * /
	}
}*/

void Check_NORMAL_State()
{
	if (abs(SET_Temperature - CRT_Temperature) <= 5)
	{
		state_indx = NORMAL_INDEX;
		
		/* Reset Error Counter */
		ERROR_COUNTER = 0;
		
		LED_vTurnOff(LEDs_PORT, OPERATION_LED);
		LED_vTurnOn(LEDs_PORT, NORMAL_LED);
	}
}


void Check_ERROR_State()
{
	/* Change To ERROR State if CRT - SET > 10 */
	if ((CRT_Temperature - SET_Temperature) > 10)
	{
		state_indx = ERROR_INDEX;
		LED_vTurnOff(LEDs_PORT, NORMAL_LED);
		LED_vTurnOn(LEDs_PORT, ERROR_LED);
	}
}

void Check_ERROR_State_Timer()
{
	/* Each count = 10.048 ms
	* This means when 100 count is equal to 1 second
	* We need 3 minutes, so counter should be 180 second x 100 = 18000
	* But it's actually 17200 for some fractions remaining
	
	* NOTE: When testing with ERROR_COUNTER > 17200, the elapsed time to execute the error was about 3.40 seconds
	* The calculations are determined in a correct way, so to solve then we will decrement the ERROR_COUNTER a little
	*/
	if (ERROR_COUNTER > 14500)
	{
		/* Change To ERROR State */
		state_indx = ERROR_INDEX;
		ERROR_COUNTER = 0;
		LED_vTurnOff(LEDs_PORT, OPERATION_LED);
		LED_vTurnOn(LEDs_PORT, ERROR_LED);
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}


void Check_HASH_Key()
{
	/* This means when (200 ms) is passed */
	if (HASH_KEY_COUNTER >= 20)
	{
		/* Check if user pressed # */
		if (check_OPKey() == 1)
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
			ERROR_COUNTER = 0;
		}
		else
		{
			/* Do Nothing (Hash is not pressed) */
		}
		
		HASH_KEY_COUNTER = 0;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}