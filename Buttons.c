#include <xc.h>
#include "GPIO.h"
#include "Buttons.h"

void interrupt Button1(void)
{
    /**Activate the function*/
    if(INT0IF)
    {
        /**Clear the interrupt flag*/
        INT0IF = 0;
        /**Do something*/
    }
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