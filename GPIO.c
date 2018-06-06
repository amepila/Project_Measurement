
#include <xc.h>
#include <stdint.h>
#include "GPIO.h"

#define PORTA_INPUT_VALUE       (0x3F)
#define PORTBC_INPUT_VALUE      (0xFF)
#define PORT_OUTPUT_VALUE       (0x0)
#define CLOCK_8MHZ              (0x72)
#define CLOCK_4MHZ              (0x60)
#define CLOCK_2MHZ              (0x50)
#define CLOCK_1MHZ              (0x40)
#define CLOCK_500KHZ            (0x30)
#define CLOCK_250KHZ            (0x20)
#define CLOCK_125KHZ            (0x10)
#define CLOCK_31KHZ             (0x00)

void GPIO_sourceClock(GPIO_SourceClk clk)
{
    switch(clk)
    {
        case CLK_8MHZ:
            OSCCON |= CLOCK_8MHZ;
            break;
        case CLK_4MHZ:
            OSCCON |= CLOCK_4MHZ;
            break;
        case CLK_2MHZ:
            OSCCON |= CLOCK_2MHZ;
            break;
        case CLK_1MHZ:
            OSCCON |= CLOCK_1MHZ;
            break;
        case CLK_500KHZ:
            OSCCON |= CLOCK_500KHZ;
            break;
        case CLK_250KHZ:
            OSCCON |= CLOCK_250KHZ;
            break;
        case CLK_125KHZ:
            OSCCON |= CLOCK_125KHZ;
            break;
        case CLK_31KHZ:
            OSCCON |= CLOCK_31KHZ;
            break;
        default:
            break;
    }
}

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

void GPIO_setPIN
(GPIO_portNameType portName, uint8_t pin)
{
    switch(portName)
    {
        case GPIO_A:
            PORTA |= (1<<pin);
            break;
        case GPIO_B:
            PORTB |= (1<<pin);
            break;
        case GPIO_C:
            PORTC |= (1<<pin);
            break;
        default:
            break;
    }
}

void GPIO_clearPIN
(GPIO_portNameType portName, uint8_t pin)
{
    switch(portName)
    {
        case GPIO_A:
            PORTA &= ~(1<<pin);
            break;
        case GPIO_B:
            PORTB &= ~(1<<pin);
            break;
        case GPIO_C:
            PORTC &= ~(1<<pin);
            break;
        default:
            break;
    }
}

void delay(uint32_t delay)
{
	volatile uint32_t counter;

	for(counter = delay; counter > 0; counter--)
    {}
}