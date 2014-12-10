/*
 * segmentDisplay.c
 *
 */ 

#include "segmentDisplay.h"

static uint8_t CYFRA[10] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10011001, 0b10010010, 0b10000010, 0b11111000, 0b10000000, 0b10010000};
static uint8_t blank = 0b11111111;

volatile static uint8_t actual_display = 0; //variable specifying which button is pressed, before pressing any buttons 0 is shown

void displayNumber(uint16_t val){
	DISPLAY_GRD_PORT |= 0x0f;
	actual_display = (actual_display + 1) % 4;												//changing display between four displays
	if (actual_display==0) DISPLAY_PORT = CYFRA[(val)%10];
	else if (actual_display==1) DISPLAY_PORT = val/10 ? CYFRA[(val/10)%10] : blank;			//if button is lower then 10 shows nothing
	else if (actual_display==2) DISPLAY_PORT = val/100 ? CYFRA[(val/100)%10] : blank;
	else if (actual_display==3) DISPLAY_PORT = val/1000 ? CYFRA[(val/1000)%10] : blank;
	DISPLAY_GRD_PORT &= (0xF0 | (~(1<<actual_display)));
}

void setupDisplay(){
	DISPLAY_DDR = 0xFF;
	DISPLAY_PORT = 0x0;
	DISPLAY_GRD_DDR = DISPLAY_GRD_DDR | 0x0F;
	DISPLAY_GRD_PORT = DISPLAY_GRD_PORT & 0xFF;
}