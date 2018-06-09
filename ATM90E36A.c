#include <xc.h>
#include "ATM90E36A.h"
#include "GPIO.h"
#include "SPI.h"

void ATM_IC(void)
{
    /**Reset pin*/
    GPIO_dataDirectionPIN(GPIO_B, 3, GPIO_OUTPUT);
    
    

}