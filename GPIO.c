
#include <xc.h>
#include <stdint.h>
#include "GPIO.h"

#define PORTA_INPUT_VALUE       (0x3F)
#define PORTBC_INPUT_VALUE      (0xFF)
#define PORT_OUTPUT_VALUE       (0x0)

void GPIO_dataDirectionPIN
(GPIO_portNameType portName, uint8_t pin, GPIO_state state)
{
    switch(state)
    {
        case GPIO_INPUT:
            switch(portName)
            {
                case GPIO_A:
                    TRISA |= 1<<pin;
                    break;
                case GPIO_B:
                    TRISB |= 1<<pin;
                    break;
                case GPIO_C:
                    TRISC |= 1<<pin;
                    break;
                default:
                    break;
            }
            break;
        case GPIO_OUTPUT:
            switch(portName)
            {
                case GPIO_A:
                    TRISA &= (0<<pin);
                    break;
                case GPIO_B:
                    TRISB &= (0<<pin);
                    break;
                case GPIO_C:
                    TRISC &= (0<<pin);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void GPIO_dataDirectionPORT
(GPIO_portNameType portName, GPIO_state state)
{
    switch(state)
    {
        case GPIO_INPUT:
            switch(portName)
            {
                case GPIO_A:
                    TRISA = PORTA_INPUT_VALUE;
                    break;
                case GPIO_B:
                    TRISB = PORTBC_INPUT_VALUE;
                    break;
                case GPIO_C:
                    TRISC = PORTBC_INPUT_VALUE;
                    break;
                default:
                    break;
            }
            break;
        case GPIO_OUTPUT:
            switch(portName)
            {
                case GPIO_A:
                    TRISA = PORT_OUTPUT_VALUE;
                    break;
                case GPIO_B:
                    TRISB = PORT_OUTPUT_VALUE;
                    break;
                case GPIO_C:
                    TRISC = PORT_OUTPUT_VALUE;
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void GPIO_analogSelector
(GPIO_analogType type, uint8_t pin)
{
    switch(type)
    {
        case GPIO_ANALOG:
            ANSEL0 |= 1<<pin;
            break;
        case GPIO_DIGITAL:
            ANSEL0 &= 0<<pin;
            break;
        default:
            break;
    }
}
