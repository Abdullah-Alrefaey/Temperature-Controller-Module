#include "Heater_Control.h"
#include <math.h>

extern uint8_t SET_Temperature;
extern uint8_t CRT_Temperature;

char * states[4] = {"STANDBY", "OPERATION", "NORMAL", "ERROR"};
uint8_t state_indx = 0;

void HeaterInit(void){
	PWM_Init(2,1,2);
}

void SetHeaterVolt(double TragetV, double PotV){
	uint8_t Duty = 0;
	double DutyPer = 0;
	DutyPer = (((PotV * 2)/10) * TragetV) / 10;
	Duty = floor(DutyPer*255);
	Set_PWM_Duty(2, Duty);
}