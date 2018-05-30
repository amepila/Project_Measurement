#include <xc.h>
#include "States.h"

/**Settings of SPI**/
const SPI_ConfigType SPI_Config = 
{
	SPI_LOW_POLARITY,	/**Low Polarity to SPI**/
	SPI_LOW_PHASE,		/**Low Phase to SPI**/
	SPI_SERIAL_CLK4     /**FOsc divided by 4**/
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
    /**First state in the program**/
  	States_MenuType currentState = MAIN_MENU;
	States_MenuType(*mainFunctions)(void);
    
    /**Select the 8MHz as source clock*/
    GPIO_sourceClock(CLK_8MHZ);

    /**Configurations of devices**/
	SPI_init(&SPI_Config);
    LCDNokia_init();
	LCDNokia_clear();
    UART_init(BD_9600);

    for(;;)
    {
        /**Machine states based on tags**/
    	mainFunctions = StateProgram[currentState].stateFunction;
    	currentState = mainFunctions(void);
    }
}