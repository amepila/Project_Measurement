#include <xc.h>
#include <stdio.h>
#include "States.h"

#define DEBUG   0

// PIC18F2331 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = IRCIO      // Oscillator Selection bits (Internal oscillator block, port function on RA6 and port function on RA7)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config IESO = ON        // Internal External Oscillator Switchover bit (Internal External Switchover mode enabled)

// CONFIG2L
#pragma config PWRTEN = OFF     // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bits (Brown-out Reset enabled)
// BORV = No Setting

// CONFIG2H
#pragma config WDTEN = OFF      // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDPS = 32768     // Watchdog Timer Postscale Select bits (1:32768)
#pragma config WINEN = OFF      // Watchdog Timer Window Enable bit (WDT window disabled)

// CONFIG3L
#pragma config PWMPIN = OFF     // PWM output pins Reset state control (PWM outputs disabled upon Reset (default))
#pragma config LPOL = HIGH      // Low-Side Transistors Polarity (PWM0, 2, 4 and 6 are active-high)
#pragma config HPOL = HIGH      // High-Side Transistors Polarity (PWM1, 3, 5 and 7 are active-high)
#pragma config T1OSCMX = ON     // Timer1 Oscillator MUX (Low-power Timer1 operation when microcontroller is in Sleep mode)

// CONFIG3H
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (Disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Low-Voltage ICSP Enable bit (Low-voltage ICSP disabled)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000200-000FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (001000-001FFF) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot Block (000000-0001FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000200-000FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (001000-001FFF) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0001FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000200-000FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (001000-001FFF) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0001FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

/**Settings of SPI**/
const SPI_ConfigType SPI_Config = 
{
	SPI_LOW_POLARITY,	/**Low Polarity to SPI**/
	SPI_LOW_PHASE,		/**Low Phase to SPI**/
	SPI_SERIAL_CLK64     /**FOsc divided by 4**/
};

/**Simple machine state only change the tag**/

const StateType StateProgram[8] =
{
		{stateMainMenu},
		{statePower1},
		{statePower2},
		{stateRmsVI},
		{statePowerFactor},
		{statePhaseAngle},
        {stateFrequency},
        {stateTemperature}
};

void main(void) 
{
#if DEBUG
    /**First state in the program**/
  	States_MenuType currentState = MAIN_MENU;
	States_MenuType(*mainFunctions)(void);
#endif
    /**Select the 8MHz as source clock*/
    GPIO_sourceClock(CLK_8MHZ);

    /**Configurations of devices**/
	SPI_init(&SPI_Config);
    LCDNokia_init();
	LCDNokia_clear();
#if DEBUG
    UART_init(BD_9600);
    ButtonInt_config();
#endif
    uint8_t test = 'o';
    uint8_t arrayTest[] = "Hola Mundo";
    for(;;)
    {
        
        //LCDNokia_writeByte(LCD_DATA, 0x11);
        LCDNokia_sendChar(test);
        //LCDNokia_sendString(arrayTest);
        delay(1000); 
#if DEBUG
        /**Machine states based on tags**/
    	mainFunctions = StateProgram[currentState].stateFunction;
    	currentState = mainFunctions();
#endif
    }
}