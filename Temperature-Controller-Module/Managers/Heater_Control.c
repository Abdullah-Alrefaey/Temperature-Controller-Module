#include "Heater_Control.h"
#include <math.h>

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
		Vt = ((SET_Temperature - CRT_Temperature) / 100) * 10;
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
	double DutyPer = 0;
	DutyPer = (((Vr * 2)/10) * Vt) / 10;
	Duty = floor(DutyPer*255);
	Set_PWM_Duty(2, Duty);
}

void Check_Operation_State()
{	
	/* This means when (100 ms) is passed */
	if (HASH_KEY_COUNTER >= 10)
	{
		/* Change To OPERATIONAL State if user pressed '#' key */
		char x = 0xff;
		
		do {
			x = check_OPKey();
			_delay_ms(200);
		} while (x == 0xff);
		
		state_indx = 1;
		
		/*if (check_OPKey() == 1)
		{
			state_indx = 1;
		}*/
		
		HASH_KEY_COUNTER = 0;
	}
	else
	{
		/* Do Nothing, Didn't reach the required time */
	}
}

void Check_STANDBY_State()
{
	/* This means when (100 ms) is passed */
	if (HASH_KEY_COUNTER >= 10)
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

