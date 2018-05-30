
#ifndef GPIO_H
#define	GPIO_H

#include <stdint.h>

typedef enum
{
    CLK_8MHZ,
    CLK_4MHZ,
    CLK_2MHZ,
    CLK_1MHZ,
    CLK_500KHZ,
    CLK_250KHZ,
    CLK_125KHZ,
    CLK_31KHZ
} GPIO_SourceClk;

/*! This definition is used to configure
 *  whether a pin is an input or an output*/
typedef enum 
{
    GPIO_INPUT,/*!< Definition to configure a pin as input */
    GPIO_OUTPUT /*!< Definition to configure a pin as output */
} GPIO_state;

/*! These constants are used to select an 
 * specific port in the different API functions*/
typedef enum
{
    GPIO_A, /*!< Definition to select GPIO A */
	GPIO_B, /*!< Definition to select GPIO B */
	GPIO_C /*!< Definition to select GPIO C */
} GPIO_portNameType;

typedef enum
{
    GPIO_DIGITAL,
    GPIO_ANALOG
} GPIO_analogType;

void GPIO_sourceClock(GPIO_SourceClk clk);

void GPIO_dataDirectionPIN
(GPIO_portNameType portName, uint8_t pin, GPIO_state state);

void GPIO_dataDirectionPORT
(GPIO_portNameType portName, GPIO_state state);

void GPIO_analogSelector
(GPIO_analogType type, uint8_t pin);

void GPIO_setPIN
(GPIO_portNameType portName, uint8_t pin);

void GPIO_clearPIN
(GPIO_portNameType portName, uint8_t pin);

void delay(uint32_t delay);

#endif	

