#ifndef BUTTONS_H_
#define	BUTTONS_H_

#include <stdint.h>

uint8_t getButton1(void);

void setButton1(uint8_t set);

uint8_t getButton2(void);

void setButton2(uint8_t set);

uint8_t getButton3(void);

void setButton3(uint8_t set);

void ButtonInt_config();

#endif

