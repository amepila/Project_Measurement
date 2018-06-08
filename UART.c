
#include <xc.h>
#include "UART.h"
#include "GPIO.h"

#define SPBRG_BAUDRATE_1200 (103)
#define SPBRG_BAUDRATE_2400 (51)
#define SPBRG_BAUDRATE_9600 (12)
#define DELAY_UART          (1500)

void UART_init(UART_BaudRateType baudRate)
{

    GPIO_dataDirectionPIN(GPIO_C, 6, GPIO_OUTPUT);  //TX
    //GPIO_dataDirectionPIN(GPIO_C, 7, GPIO_INPUT);   //RX

    switch(baudRate)
    {
        case BD_1200:
            SPBRG =  SPBRG_BAUDRATE_1200;
            break;
        case BD_2400:
            SPBRG =  SPBRG_BAUDRATE_2400;
            break;
        case BD_9600:
            SPBRG =  SPBRG_BAUDRATE_9600;
            break;
        default:
            break;
    }
        
    /**Asychronous mode*/
    TXSTAbits.SYNC = 0;
    /**Select 8 bits-transmission*/
    TXSTAbits.TX9 = 0;
    /**Enable trasmitter*/
    TXSTAbits.TXEN = 1;
    
    /**Select 8 bits-transmission*/
    //RCSTAbits.RX9 = 0;
    /**Enable receiver*/
    //RCSTAbits.CREN = 0;
    /**Serial port enabled*/
    RCSTAbits.SPEN = 1;
    
    /**Only 8 bit baud rate generator*/
    BAUDCTLbits.BRG16 = 0;
    /**Low speed*/
    TXSTAbits.BRGH = 0;
}

void UART_putChar(uint8_t character)
{
    while(!TXSTAbits.TRMT);
    TXREG = character;
}

void UART_putString(int8_t* string)
{
    uint8_t counter;

    for(counter = 0; string[counter] != '\0'; counter++)
    {
        UART_putChar(string[counter]);
        delay(DELAY_UART);
    }
}

uint32_t expBASE10(uint8_t limit)
{
	/*Use the exponent base 10 to different digits*/
	static uint32_t value;

	if(0 == limit)
    {	
        value = 1;
    }
	if(1 == limit)
    {	
        value = 10;
    }
	if(limit > 1)
    {	
        value *= 10;
    }

	return value;
}
uint32_t Convert_numberASCIItoDATA(uint8_t *string)
{
	const uint32_t adjustASCII = 48;
	const uint32_t CR = 13;
	uint32_t counter1 = 0;
	uint32_t counter2 = 0;
	uint32_t counter3 = 0;
	uint32_t data;
	uint32_t tmpData1 = 0;
	uint32_t tmpData2 = 0;
	uint32_t expValue;

	/*First loop to manage find the size*/
	while(string[counter1] != CR){
		counter1++;
	}

	/*Second loop to begin in last position of array*/
	for(counter2 = counter1; counter2 != 0; counter2--)
    {
		/*Elevate the number by 10 depending of its position*/
		expValue = expBASE10(counter3);

		/*Converts the ASCII to INT*/
		if(counter3 == 0)
        {
			tmpData2 = string[counter2 - 1];
			tmpData2 -= adjustASCII;
			tmpData1 += tmpData2;
		}
		/*Save the value and sums*/
		if(counter3 > 0)
        {
			tmpData2 = string[counter2 - 1];
			tmpData2 -= adjustASCII;
			tmpData2 *= expValue;
			tmpData1 += tmpData2;
		}
		counter3++;
	}
	/**Save the data*/
	data = tmpData1;
	return (data);
}

uint8_t Convert_wordASCIItoDATA(uint8_t word)
{
	/**Translate the character ascii to data*/
	uint8_t valueWord = (uint8_t)word;
	return (valueWord);
}
