
#include <xc.h>
#include "UART.h"
#include "GPIO.h"

void UART_init(UART_BaudRateType baudRate)
{
    GPIO_dataDirectionPIN(GPIO_C, 6, GPIO_OUTPUT);  //TX
    GPIO_dataDirectionPIN(GPIO_C, 7, GPIO_INPUT);   //RX

    /**Asychronous mode*/
    TXSTAbits.SYNC = 0;
    /**Select 8 bits-transmission*/
    TXSTAbits.TX9 = 0;
    /**Enable trasmitter*/
    TXSTAbits.TXEN = 1;
    
    /**Select 8 bits-transmission*/
    RCSTAbits.RX9 = 0;
    /**Enable receiver*/
    RCSTAbits.CREN = 1;
    /**Serial port enabled*/
    RCSTAbits.SPEN = 1;
    
    BAUDCONbits.BRG16 = 0;
    
}