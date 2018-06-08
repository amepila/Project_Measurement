#include <xc.h>
#include "GPIO.h"
#include "Buttons.h"

uint8_t FlagButton1 = 0;
uint8_t FlagButton2 = 0;
uint8_t FlagButton3 = 0;

uint8_t getButton1(void)
{
    if(1 == PORTAbits.RA3)
    {
        FlagButton1 = 1;
    }
    else
    {
        FlagButton1 = 0;
    }
    return (FlagButton1);
}

void clearButton1(void)
{
    FlagButton1 = 0;
}

uint8_t getButton2(void)
{
    if(1 == PORTAbits.RA4)
    {
        FlagButton2 = 1;
    }
    else
    {
        FlagButton2 = 0;
    }
    return (FlagButton2);
}

void clearButton2(void)
{
    FlagButton2 = 0;
}

uint8_t getButton3(void)
{
    if(1 == PORTCbits.RC3)
    {
        FlagButton3 = 1;
    }
    else
    {
        FlagButton3 = 0;
    }
    return (FlagButton3);
}

void setButton3(void)
{
    FlagButton3 = 0;
}

void ButtonInt_config()
{
    /**Enable the button 1*/
    GPIO_dataDirectionPIN(GPIO_A, 3, GPIO_INPUT);
    ANSEL0bits.ANS3 = 0;
    /**Enable the button 2*/
    GPIO_dataDirectionPIN(GPIO_A, 4, GPIO_INPUT);
    ANSEL0bits.ANS4 = 0;
    /**Enable the button 3*/
    GPIO_dataDirectionPIN(GPIO_C, 3, GPIO_INPUT);
}