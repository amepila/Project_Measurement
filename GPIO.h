
#ifndef GPIO_H
#define	GPIO_H

#include <stdint.h>

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

/*Type for polarity configuration*/
typedef enum 
{
    SPI_LOW_POLARITY,
    SPI_HIGH_POLARITY
} SPI_PolarityType;

/*Type for phase configuration*/
typedef enum 
{
    SPI_LOW_PHASE,
    SPI_HIGH_PHASE
} SPI_PhaseType;

typedef enum
{
    SPI_SERIAL_CLK4,
    SPI_SERIAL_CLK16,
    SPI_SERIAL_CLK64
} SPI_SerialClk;

/*Type that is used for SPI configuration,
 *  It contains all the information needed for a SPI module*/
typedef struct
{
	SPI_PolarityType SPI_Polarity;
	SPI_PhaseType SPI_Phase;
	SPI_SerialClk SPI_Clk;
} SPI_ConfigType;

void GPIO_dataDirectionPIN
(GPIO_portNameType portName, uint8_t pin, GPIO_state state);

void GPIO_setPIN
(GPIO_portNameType portName, uint8_t pin);

void GPIO_clearPIN
(GPIO_portNameType portName, uint8_t pin);

void delay(uint32_t delay);

void ButtonInt_config();

/**Uart functions*/

void UART_init(void);

void UART_putChar(uint8_t character);

void UART_putString(int8_t* string);

uint32_t expBASE10(uint8_t limit);

uint32_t Convert_numberASCIItoDATA(uint8_t *string);

uint8_t Convert_wordASCIItoDATA(uint8_t word);

/**Spi functions*/
void SPI_init(const SPI_ConfigType* SPI_Config);

void SPI_write(uint8_t data);

uint8_t SPI_read(void);

#endif	

