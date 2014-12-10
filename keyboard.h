/*
 * keyboard.h
 *
 */ 


#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#define KB_PORT PORTC
#define KB_DDR DDRC
#define KB_PIN PINC

uint8_t read();
uint8_t isPressed();
//uint8_t 

#endif /* KEYBOARD_H_ */