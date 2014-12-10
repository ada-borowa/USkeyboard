/*
* USkeyboard.c
*
*/


#define F_CPU 16000000ul

#include <avr/io.h>
#include <util/delay.h>
#include "taskManager.h"
#include "segmentDisplay.h"
#include "keyboard.h"

ISR(TIMER0_COMP_vect){
	schedule();
}

/**
* Setup atmega32's clock for interrupts every 1ms
*/
void setupTimer(){

	TCCR0 |= (1<<WGM01) | (0<<WGM00);	// set clock type as CTC
	OCR0 = 250;							// set Output Compare Register - together with prescaler this will give us
	// interrupt every 1ms
	sei();								// turn interrupts on
	TIMSK |= (1<<OCIE0);				// set interrupts co compare
	TCCR0 |= (1<<CS00) | (1<<CS01 );	// set clock prescaler at 64*250 = 16,000; 16MHz * 16,000 = 1KHZ;

}

static volatile uint16_t valueToDisplay = 0;

void getButtonValue(void* args){
	if (isPressed()){					//read button value only if it's pressed
		valueToDisplay = read();
	}
}

void displayValue(void* args){			//display number of pressed button
	displayNumber(valueToDisplay);
}

int main(void)
{
	setupTimer();
	setupDisplay();
	addTask(0, 4, displayValue, (void*)0);
	addTask(1, 50, getButtonValue, (void*)0);
	execute();
}