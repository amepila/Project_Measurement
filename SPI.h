#ifndef SPI_H
#define	SPI_H

#include <xc.h> // include processor files - each processor file is guarded.  
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

#endif	

