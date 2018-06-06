#include <xc.h>
#include "GPIO.h"
#include "Buttons.h"

uint8_t FlagButton1 = 0;
uint8_t FlagButton2 = 0;

void interrupt Button1(void)
{
    /**Activate the function*/
    if(INT0IF)
    {
        /**Clear the interrupt flag*/
        INT0IF = 0;
        FlagButton1 = 1;
    }
}

uint8_t getButton1(void)
{
    return (FlagButton1);
}

void setButton1(uint8_t set)
{
    FlagButton1 = set;
}

uint8_t getButton2(void)
{
    return (FlagButton2);
}

void setButton2(uint8_t set)
{
    FlagButton2 = set;
}


void ButtonInt_config()
{
    /**Set the RC3 as an input*/
    GPIO_dataDirectionPIN(GPIO_C, 3, GPIO_INPUT);
    /**Clear the interrupt flag*/
    INT0IF = 0;
    /**Enable external interrupt*/
    INT0IE = 1;
    /**Global interrupt enable*/
    GIE = 1;
}