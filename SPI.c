
#include <xc.h>
#include <stdint.h>
#include "GPIO.h"
#include "SPI.h"

#define SPI_MASTER          (0x40)
#define SPI_CLEAR_SSPSTAT   (0x3F)
#define SPI_CLEAR_SSPCON    (0xC0)


void SPI_enableClock
(SPI_PhaseType phase, SPI_PolarityType cpol)
{
    /**Clear the SPI registers*/
    SSPSTAT &= SPI_CLEAR_SSPSTAT;
    SSPCON &= SPI_CLEAR_SSPCON;
    
    /**Select SPI Master Mode*/
    SSPSTAT |= SPI_MASTER;
    
    switch(phase)
    {
        case SPI_LOW_PHASE:
            SSPCONbits.CKP = 0;
            break;
        case SPI_HIGH_PHASE:
            SSPCONbits.CKP = 1;
            break;
        default:
            break;
    }
    
    switch(cpol)
    {
        case SPI_LOW_POLARITY:
            SSPSTATbits.CKE = 0;
            break;
        case SPI_HIGH_POLARITY:
            SSPSTATbits.CKE = 1;
            break;
        default:
            break;
    }
}

void SPI_enablePINS
(SPI_SerialClk serial)
{
    switch(serial)
    {
        case SPI_SERIAL_CLK4:
            break;
        case SPI_SERIAL_CLK16:
            break;
        case SPI_SERIAL_CLK64:
            break;
        default:
            break;
    }
    
}