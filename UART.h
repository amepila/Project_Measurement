#ifndef UART_H
#define	UART_H

#include <stdint.h>

/**
 * \brief It defines some common transmission baud rates
 */
typedef enum 
{
    BD_1200 = 1200,
    BD_2400 = 2400, 
    BD_9600 = 9600
} UART_BaudRateType;

void UART_init(UART_BaudRateType baudRate);

void UART_putChar(uint8_t character);

void UART_putString(int8_t* string);

uint32_t expBASE10(uint8_t limit);

uint32_t Convert_numberASCIItoDATA(uint8_t *string);

uint8_t Convert_wordASCIItoDATA(uint8_t word);

#endif	

