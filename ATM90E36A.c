#include <xc.h>
#include "ATM90E36A.h"
#include "GPIO.h"
#include "SPI.h"

void ATM_init(void)
{
    /**CS2 pin*/
    GPIO_dataDirectionPIN(GPIO_B, 3, GPIO_INPUT);
    /**DMA Control pin*/
    GPIO_dataDirectionPIN(GPIO_B, 4, GPIO_INPUT);
    /**PM0 pin*/
    GPIO_dataDirectionPIN(GPIO_B, 5, GPIO_INPUT);
    /**PM1 pin*/
    GPIO_dataDirectionPIN(GPIO_B, 6, GPIO_INPUT);
    /**WarnOut pin*/
    GPIO_dataDirectionPIN(GPIO_B, 7, GPIO_INPUT);
    /**IRQ0 pin*/
    GPIO_dataDirectionPIN(GPIO_C, 2, GPIO_INPUT);
    /**IRQ1 pin*/
    GPIO_dataDirectionPIN(GPIO_C, 1, GPIO_INPUT);
    /**ZX0 pin*/
    GPIO_dataDirectionPIN(GPIO_C, 0, GPIO_INPUT);
    /**ZX1 pin*/
    GPIO_dataDirectionPIN(GPIO_A, 6, GPIO_INPUT);
    /**ZX2 pin*/
    GPIO_dataDirectionPIN(GPIO_A, 7, GPIO_INPUT);
    
    
}