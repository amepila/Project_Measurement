
#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "GPIO.h"
#include "SPI.h"

/**Settings of SPI**/
const SPI_ConfigType SPI_Config = 
{
							SPI_LOW_POLARITY,	/**Low Polarity to SPI**/
							SPI_LOW_PHASE,		/**Low Phase to SPI**/
							SPI_SERIAL_CLK4     /**FOsc divided by 4**/
};

void main(void) 
{
    /**Configurations of devices**/
	SPI_init(&SPI_Config);
    
    for(;;)
    {
        
    }
}
