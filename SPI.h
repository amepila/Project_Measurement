#ifndef SPI_H
#define	SPI_H

#include <stdint.h>

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

void SPI_init(const SPI_ConfigType* SPI_Config);

int8_t SPI_write(uint8_t data);

uint8_t SPI_read(void);


#endif	

