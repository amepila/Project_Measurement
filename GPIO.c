
#include <xc.h>
#include <stdint.h>
#include "GPIO.h"

/**Gpio defines*/
#define PORTA_INPUT_VALUE       (0x3F)
#define PORTBC_INPUT_VALUE      (0xFF)
#define PORT_OUTPUT_VALUE       (0x0)

/**Uart defines*/
#define SPBRG_BAUDRATE_9600 (31)
#define DELAY_UART          (1500)

/**Spi define*/
#define SPI_MASTER          (0x40)
#define SPI_CLEAR_SSPSTAT   (0x3F)
#define SPI_CLEAR_SSPCON    (0xC0)
#define SPI_SCLOCK_4        (0x00)
#define SPI_SCLOCK_16       (0x01)
#define SPI_SCLOCK_64       (0x02)
#define SPI_ENABLE_PINS     (0x20)


void GPIO_dataDirectionPIN
(GPIO_portNameType portName, uint8_t pin, GPIO_state state)
{
    switch(state)
    {
        case GPIO_INPUT:
            switch(portName)
            {
                case GPIO_A:
                    TRISA |= 1<<pin;
                    break;
                case GPIO_B:
                    TRISB |= 1<<pin;
                    break;
                case GPIO_C:
                    TRISC |= 1<<pin;
                    break;
                default:
                    break;
            }
            break;
        case GPIO_OUTPUT:
            switch(portName)
            {
                case GPIO_A:
                    TRISA &= (0<<pin);
                    break;
                case GPIO_B:
                    TRISB &= (0<<pin);
                    break;
                case GPIO_C:
                    TRISC &= (0<<pin);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

void GPIO_setPIN
(GPIO_portNameType portName, uint8_t pin)
{
    switch(portName)
    {
        case GPIO_A:
            PORTA |= (1<<pin);
            break;
        case GPIO_B:
            PORTB |= (1<<pin);
            break;
        case GPIO_C:
            PORTC |= (1<<pin);
            break;
        default:
            break;
    }
}

void GPIO_clearPIN
(GPIO_portNameType portName, uint8_t pin)
{
    switch(portName)
    {
        case GPIO_A:
            PORTA &= ~(1<<pin);
            break;
        case GPIO_B:
            PORTB &= ~(1<<pin);
            break;
        case GPIO_C:
            PORTC &= ~(1<<pin);
            break;
        default:
            break;
    }
}

void delay(uint32_t delay)
{
	volatile uint32_t counter;

	for(counter = delay; counter > 0; counter--)
    {}
}

void ButtonInt_config()
{
    /**Enable the button 1*/
    GPIO_dataDirectionPIN(GPIO_A, 3, GPIO_INPUT);
    ANSEL0bits.ANS3 = 0;
    /**Enable the button 2*/
    GPIO_dataDirectionPIN(GPIO_A, 4, GPIO_INPUT);
    ANSEL0bits.ANS4 = 0;
    /**Enable the button 3*/
    GPIO_dataDirectionPIN(GPIO_C, 3, GPIO_INPUT);
}



void UART_init(void)
{
    GPIO_dataDirectionPIN(GPIO_C, 6, GPIO_OUTPUT);  //TX
    //GPIO_dataDirectionPIN(GPIO_C, 7, GPIO_INPUT);   //RX

    SPBRG =  SPBRG_BAUDRATE_9600;
          
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




static void SPI_enableClock(SPI_PhaseType phase, SPI_PolarityType cpol)
{
    /**Clock pin as output*/
    TRISCbits.TRISC5 = 0;
    /**SDI pin as input*/
    TRISCbits.TRISC4 = 1;
    /**SDO pin as output*/
    TRISCbits.TRISC7 = 0;
    
    /**Clear the SPI registers*/
    //SSPSTAT &= 0x00;
    //SSPCON &= 0x00;
    
    /**Select SPI Master Mode*/
    SSPSTAT |= SPI_MASTER;
    SSPSTATbits.BF = 0;
    
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
    
    /**Enable pins of SPI*/
    SSPCON |= SPI_ENABLE_PINS;

    /**Clean the interrupt flag*/
    PIR1bits.SSPIF = 0;
}

void SPI_init(const SPI_ConfigType* SPI_Config)
{
    SPI_enableClock(SPI_Config->SPI_Polarity, SPI_Config->SPI_Phase);
    SPI_enablePins(SPI_Config->SPI_Clk);
}

void SPI_write(uint8_t data)
{    
    //const uint8_t dummy = 0;
    SSPBUF = data;
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF = 0;
    
    //SSPBUF = dummy;
}

uint8_t SPI_read(void)
{
    const uint8_t dummy = 0;
    
    /**Send the dummy data*/
    SSPBUF = dummy;
#if 0
    /**Wait the data*/
    while(0 == SSPSTATbits.BF);
#endif
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF = 0;
    return (SSPBUF);
}
