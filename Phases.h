#ifndef PHASES_H_
#define	PHASES_H_

#include <xc.h>
#include <stdint.h>
#include "GPIO.h"
#include "LCDNokia5110.h"
#include "States.h"

/************************************************************/
/**
 * \brief This data type define the data type in MAIN MENU
 */
typedef enum
{
    INITIAL_LOAD,
	GENERAL_VIEW,
	VIEW_MENU,
    SEND_DATA
}PhaseStateMenu_Type;

typedef struct
{
	PhaseStateMenu_Type phaseState;
	States_MenuType stateMain;
}PhaseMainMenu_Type;

typedef PhaseMainMenu_Type(*fptrPhaseMainMenu)(PhaseMainMenu_Type);

typedef const struct PhaseMainMenu
{
	PhaseMainMenu_Type(*PhaseMainMenu)(PhaseMainMenu_Type);
}PhasePtrMainMenu_Type;

/***********************************************************/
/***********************************************************/
/**
 * \brief This data type define the data type in MESSAGES
 */

typedef enum
{
    ACTIVE_ENERGY,
    FUNDAMENTAL_ENERGY,
    HARMONIC_ENERGY,
    EXIT_ENERGY        
}PhaseStateEnergy_Type;

typedef struct
{
	PhaseStateEnergy_Type phaseState;
	States_MenuType stateMain;
}PhaseEnergy_Type;

typedef PhaseEnergy_Type(*fptrPhaseEnergy)(PhaseEnergy_Type);

typedef const struct PhaseEnergy
{
	PhaseEnergy_Type(*PhaseEnergy)(PhaseEnergy_Type);
}PhasePtrEnergy_Type;

/**********************************************************/
/***********************************************************/
/**
 * \brief This data type define the data type in MESSAGES
 */

typedef enum
{
    TYPES_POWER1,
	PHASES_POWER1,
	EXIT_POWER1
}PhaseStatePower1_Type;

typedef struct
{
	PhaseStatePower1_Type phaseState;
	States_MenuType stateMain;
}PhasePower1_Type;

typedef PhasePower1_Type(*fptrPhasePower1)(PhasePower1_Type);

typedef const struct PhasePower1
{
	PhasePower1_Type(*PhasePower1)(PhasePower1_Type);
}PhasePtrPower1_Type;

/**********************************************************/
/***********************************************************/
/**
 * \brief This data type define the data type in CONTACTS
 */

typedef enum
{
    FH_POWER2,
	PHASES_POWER2,
    EXIT_POWER2
}PhaseStatePower2_Type;

typedef struct
{
	PhaseStatePower2_Type phaseState;
	States_MenuType stateMain;
}PhasePower2_Type;

typedef PhasePower2_Type(*fptrPhasePower2)(PhasePower2_Type);

typedef const struct PhasePower2
{
	PhasePower2_Type(*PhasePower2)(PhasePower2_Type);
}PhasePtrPower2_Type;
/***********************************************************/
/***********************************************************/

/**
 * \brief This data type define the data type in SNAKE GAME
 */

typedef enum
{
    PHASES_RMSVI,
    NEUTRAL_RMSVI,
    EXIT_RMSVI
}PhaseStateRmsVI_Type;

typedef struct
{
	PhaseStateRmsVI_Type phaseState;
	States_MenuType stateMain;
}PhaseRmsVI_Type;

typedef PhaseRmsVI_Type(*fptrPhaseRmsVI)(PhaseRmsVI_Type);

typedef const struct PhaseRmsVI
{
	PhaseRmsVI_Type(*PhaseRmsVI)(PhaseRmsVI_Type);
}PhasePtrRmsVI_Type;
/***********************************************************/
/***********************************************************/
/**
 * \brief This data type define the data type in COMPASS
 */

typedef enum
{
    PHASES_PF,
	EXIT_PF
}PhaseStatePowerFactor_Type;

typedef struct
{
	PhaseStatePowerFactor_Type phaseState;
	States_MenuType stateMain;
}PhasePowerFactor_Type;

typedef PhasePowerFactor_Type(*fptrPhasePowerFactor)(PhasePowerFactor_Type);

typedef const struct PhasePowerFactor
{
	PhasePowerFactor_Type(*PhasePowerFactor)(PhasePowerFactor_Type);
}PhasePtrPowerFactor_Type;
/***********************************************************/
/***********************************************************/
/**
 * \brief This data type define the data type in WALLPAPER
 */

typedef enum
{
    PHASES_PA,
    VI_PA,
    THDN_PA,
    EXIT_PA
}PhaseStatePhaseAngle_Type;

typedef struct
{
	PhaseStatePhaseAngle_Type phaseState;
	States_MenuType stateMain;
}PhasePhaseAngle_Type;

typedef PhasePhaseAngle_Type(*fptrPhasePhaseAngle)(PhasePhaseAngle_Type);

typedef const struct PhasePhaseAngle
{
	PhasePhaseAngle_Type(*PhasePhaseAngle)(PhasePhaseAngle_Type);
}PhasePtrPhaseAngle_Type;
/**********************************************************/
/**
 * \brief This data type define the data type to Show Contacts
 */
typedef enum
{
    SHOW_FREQTEMP,
    EXIT_FREQTEMP
}PhaseStateFreqTemp_Type;

typedef struct
{
	PhaseStateFreqTemp_Type phaseState;
	States_MenuType stateMain;
}PhaseFreqTemp_Type;

typedef PhaseFreqTemp_Type(*fptrPhaseFreqTemp)(PhaseFreqTemp_Type);

typedef const struct PhaseFreqTemp
{
	PhaseFreqTemp_Type(*PhaseFreqTemp)(PhaseFreqTemp_Type);
}PhasePtrFreqTemp_Type;


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State that charges the first initialization of the program
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseMainMenu_Type initialLoad(PhaseMainMenu_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State that show the wallpaper
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseMainMenu_Type generalView(PhaseMainMenu_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State that enters in the menu
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseMainMenu_Type viewMenu(PhaseMainMenu_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State that enters in the menu
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseMainMenu_Type sendData(PhaseMainMenu_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to write the number
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseEnergy_Type activeEnergy(PhaseEnergy_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to write the number
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseEnergy_Type fundamentalEnergy(PhaseEnergy_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to write the number
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseEnergy_Type harmonicEnergy(PhaseEnergy_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to write the number
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseEnergy_Type exitEnergy(PhaseEnergy_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to write the number
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePower1_Type typesPower1(PhasePower1_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to write the message
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePower1_Type phPower1(PhasePower1_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to send the message
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePower1_Type vectorPower1(PhasePower1_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to exit of the state
 	 \param[in]  data The current information
 	 \return Updated information
 */

PhasePower1_Type exitPower1(PhasePower1_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to enter to menu of contacts
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePower2_Type fhPower2(PhasePower2_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	State to view all the contacts through the rotative menu
 	 \param[in]  delay Value of delay
 	 \return void
 */
PhasePower2_Type phPower2(PhasePower2_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to add the contacts
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePower2_Type exitPower2(PhasePower2_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Save the contacts in the memory
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseRmsVI_Type phRmsVI(PhaseRmsVI_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Start the game of snake
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseRmsVI_Type neutralRmsVI(PhaseRmsVI_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Run the game of snake
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseRmsVI_Type exitRmsVI(PhaseRmsVI_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Show the image of game over
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePowerFactor_Type phPowerFactor(PhasePowerFactor_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Show the score
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePowerFactor_Type exitPowerFactor(PhasePowerFactor_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the question about the play again
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePhaseAngle_Type phPhaseAngle(PhasePhaseAngle_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to exit and back to the menu
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePhaseAngle_Type viPhaseAngle(PhasePhaseAngle_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to exit and back to the menu
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePhaseAngle_Type THDNPhaseAngle(PhasePhaseAngle_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to show the compass
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhasePhaseAngle_Type exitPhaseAngle(PhasePhaseAngle_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to exit of the compass
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseFreqTemp_Type showFreqTemp(PhaseFreqTemp_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to exit and come back to the menu
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseFreqTemp_Type exitFreqTemp(PhaseFreqTemp_Type data);

#endif

