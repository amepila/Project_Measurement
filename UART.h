#ifndef UART_H
#define	UART_H

#include <stdint.h>

/**
 * \brief It defines some common transmission baud rates
 */
typedef enum 
{
    BD_4800 = 4800,
    BD_9600 = 9600,
    BD_5600 = 5600, 
    BD_115200 = 115200
} UART_BaudRateType;

void UART_init(UART_BaudRateType baudRate);

#endif	

