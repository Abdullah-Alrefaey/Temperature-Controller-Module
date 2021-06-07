/*
 * Schedular.h
 *
 * Created: 05-Jun-21 4:15:06 PM
 *  Author: Refaey
 */ 


#ifndef SCHEDULAR_H_
#define SCHEDULAR_H_

#define F_CPU 16000000UL

#include "../Drivers/Timer.h"
#include "Mode_Config.h"

#include <avr/io.h>
#include <avr/interrupt.h>

void Schedular_vInit();

#endif /* SCHEDULAR_H_ */