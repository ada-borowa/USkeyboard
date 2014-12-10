/*
 * segmentDisplay.h
 *
 */ 

#include <avr/io.h>


#ifndef SEGMENTDISPLAY_H_
#define SEGMENTDISPLAY_H_

#define DISPLAY_PORT PORTA
#define DISPLAY_DDR DDRA
#define DISPLAY_GRD_PORT PORTB
#define DISPLAY_GRD_DDR DDRB

void setupDisplay();
void displayNumber(uint16_t val);


#endif /* SEGMENTDISPLAY_H_ */