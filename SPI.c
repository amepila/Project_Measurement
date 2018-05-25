
#include <xc.h>
#include <stdint.h>
#include "SPI.h"

#define SPI_MASTER          (0x40)
#define SPI_CLEAR_SSPSTAT   (0x3F)
#define SPI_CLEAR_SSPCON    (0xC0)
#define SPI_SCLOCK_4        (0x00)
#define SPI_SCLOCK_16       (0x01)
#define SPI_SCLOCK_64       (0x02)
#define SPI_ENABLE_PINS     (0x20)

static void SPI_enableClock(SPI_PhaseType phase, SPI_PolarityType cpol)
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

static void SPI_enablePins(SPI_SerialClk serial)
{
    switch(serial)
    {
        case SPI_SERIAL_CLK4:
            SSPCON &= SPI_SCLOCK_4;
            break;
        case SPI_SERIAL_CLK16:
            SSPCON |= SPI_SCLOCK_16;
            break;
        case SPI_SERIAL_CLK64:
            SSPCON |= SPI_SCLOCK_64;
            break;
        default:
            break;
    }
    
    /**Clock pin as output*/
    TRISCbits.TRISC5 = 0;
    /**SDI pin as input*/
    TRISCbits.TRISC4 = 1;
    /**SDO pin as output*/
    TRISCbits.TRISC7 = 0;
    
    /**Enable pins of SPI*/
    SSPCON |= SPI_ENABLE_PINS;
}

void SPI_init(const SPI_ConfigType* SPI_Config)
{
    SPI_enableClock(SPI_Config->SPI_Polarity, SPI_Config->SPI_Phase);
    SPI_enablePins(SPI_Config->SPI_Clk);
}

int8_t SPI_write(uint8_t data)
{
    int8_t success;
    
    SSPCONbits.WCOL = 0;
    SSPBUF = data;
    while(!SSPSTATbits.BF);
    
    success = (SSPCONbits.WCOL == 1) ? 0: 1;
 
    return success;
}

uint8_t SPI_read(void)
{
    const uint8_t dummy = 0;
    
    /**Send the dummy data*/
    SSPBUF = dummy;
            
    /**Wait the data*/
    while(!SSPSTATbits.BF);
    
    return SSPBUF;
}




