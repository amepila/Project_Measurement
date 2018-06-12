
#ifndef STATES_H_
#define	STATES_H_

#include "GPIO.h"
#include "SPI.h"
#include "UART.h"
#include "LCDNokia5110.h"
#include "Bluetooth.h"
#include "ATM90E36A.h"
#include "Buttons.h"

/**
 * \brief This data type define the states of program
 */
typedef enum
{
    MAIN_MENU,
    ENERGY,
	POWER_1,
	POWER_2,
	RMS_VI,
	POWER_FACTOR,
    PHASE_ANGLE,
	FREQUENCY,
    TEMPERATURE
}States_MenuType;

/*Data type to main functions*/
typedef States_MenuType(*fptrState)(void);

/**Data type to machine state**/
typedef const struct State
{
	States_MenuType (*stateFunction)(void);
}StateType;


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Main state of Main Menu
 	 \param[in]  void
 	 \return The next state
 */
States_MenuType stateMainMenu(void);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Main state of edit the contacts
 	 \param[in]  void
 	 \return The next state
 */
States_MenuType stateEnergy(void);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Main state of edit the contacts
 	 \param[in]  void
 	 \return The next state
 */
States_MenuType statePower1(void);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Main state of the messages
 	 \param[in]  void
 	 \return The next state
 */
States_MenuType statePower2(void);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Main state of the snake game
 	 \param[in]  void
 	 \return The next state
 */
States_MenuType stateRmsVI(void);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Main state of compass
 	 \param[in]  void
 	 \return The next state
 */
States_MenuType statePowerFactor(void);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Main state of set the wallpaper
 	 \param[in]  void
 	 \return The next state
 */
States_MenuType statePhaseAngle(void);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Main state of set the wallpaper
 	 \param[in]  void
 	 \return The next state
 */
States_MenuType stateFrequency(void);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Main state of set the wallpaper
 	 \param[in]  void
 	 \return The next state
 */
States_MenuType stateTemperature(void);

#endif	

