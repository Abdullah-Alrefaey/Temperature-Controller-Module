#include "Heater_Control.h"


extern uint8_t SET_Temperature;
extern uint8_t CRT_Temperature;

extern uint8_t HASH_KEY_COUNTER;
extern uint8_t ADC_COUNTER;

char * states[4] = {"STANDBY", "OPERATION", "NORMAL", "ERROR"};
	
/* First Start in STANDBY STATE */
uint8_t state_indx = 0;

/* Calibration Resistor Voltage (Used to determine Duty Cycle Percentage) */
double Vt = 0;		
double Vr = 0;

void HeaterInit(void)
{
	PotInit();
	PWM_Init(2, 1, 2);
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
		Vr = GetPotVolt();
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
	Set_PWM_Duty(2, Duty);
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
}

void Check_OPERATION_State()
{
	/* Change To OPERATIONAL State if SET - CRT > 5 */
	if ((SET_Temperature - CRT_Temperature) > 5)
	{
		state_indx = 1;
	}	
}

/*
void Check_Operation_State()
{	
	/ * This means when (100 ms) is passed * /
	if (HASH_KEY_COUNTER >= 10)
	{
		/ * Change To OPERATIONAL State if user pressed '#' key * /
		if (check_OPKey() == 1)
		{
			state_indx = 1;
		}		
		HASH_KEY_COUNTER = 0;
	}
	else
	{
		/ * Do Nothing, Didn't reach the required time * /
	}
}*/

/* TODO: Fix Debouncing Issue */
void Check_STANDBY_State()
{
	/* This means when (200 ms) is passed */
	if (HASH_KEY_COUNTER >= 20)
	{
		/* Change To OPERATIONAL State if user pressed '#' key */
		if (check_OPKey() == 1)
		{
			state_indx = 0;
		}
		
		HASH_KEY_COUNTER = 0;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}

void Check_NORMAL_State()
{
	if (abs(SET_Temperature - CRT_Temperature) <= 5)
	{
		state_indx = 2;
	}
}


void Check_ERROR_State()
{
	/* Change To ERROR State if CRT - SET > 10 */
	if ((CRT_Temperature - SET_Temperature) > 10)
	{
		state_indx = 3;
	}
}