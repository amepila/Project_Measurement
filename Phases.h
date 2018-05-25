#ifndef PHASES_H
#define	PHASES_H

#include <stdint.h>
#include "States.h"
/************************************************************/
/**
 * \brief This data type define the data type in MAIN MENU
 */
typedef enum
{
    INITIAL_LOAD1,
    INITIAL_LOAD2,
	GENERAL_VIEW,
	VIEW_MENU
}PhaseStateMenu_Type;

typedef struct
{
	PhaseStateMenu_Type phaseState;
	States_MenuType stateMain;
}PhaseMainMenu_Type;

typedef PhaseMainMenu_Type(*fptrPhaseMainMenu)(PhaseMainMenu_Type);

typedef const struct PhaseMainMenu{
	PhaseMainMenu_Type(*PhaseMainMenu)(PhaseMainMenu_Type);
}PhasePtrMainMenu_Type;
/***********************************************************/
/***********************************************************/
/**
 * \brief This data type define the data type in MESSAGES
 */

typedef enum{WRITE_NUMBER,
			WRITE_MESSAGES,
			SEND_MESSAGES,
			EXIT_MESSAGES
}PhaseStateMessages_Type;

typedef struct{
	PhaseStateMessages_Type phaseState;
	States_MenuType stateMain;
}PhaseMessages_Type;

typedef PhaseMessages_Type(*fptrPhaseMessages)(PhaseMessages_Type);

typedef const struct PhaseMessages{
	PhaseMessages_Type(*PhaseMessages)(PhaseMessages_Type);
}PhasePtrMessages_Type;
/**********************************************************/
/***********************************************************/
/**
 * \brief This data type define the data type in CONTACTS
 */
typedef enum{MODE_ADD,MODE_EDIT}ModeContact_Type;

typedef enum{CONTACT_MENU,
			VIEW_CONTACTS,
			ADD_CONTACTS,
			SAVE_CONTACTS
}PhaseStateContacts_Type;

typedef struct{
	uint8 name[30];
	uint8 number[15];
	uint8 sizeName;
	uint8 sizeNumber;
	uint8 noContact;
	PhaseStateContacts_Type phaseState;
	States_MenuType stateMain;
}PhaseContacts_Type;

typedef PhaseContacts_Type(*fptrPhaseContacts)(PhaseContacts_Type);

typedef const struct PhaseContacts{
	PhaseContacts_Type(*PhaseContacts)(PhaseContacts_Type);
}PhasePtrContacts_Type;
/***********************************************************/
/***********************************************************/

/**
 * \brief This data type define the data type in SNAKE GAME
 */

typedef enum{START_GAME,
			RUN_GAME,
			GAME_LOST,
			SHOW_SCORE,
			PLAY_AGAIN,
			EXIT_GAME
}PhaseStateSnake_Type;

typedef struct{
	uint8 score;
	uint8 lives;
	uint8 nameSize;
	PhaseStateSnake_Type phaseState;
	States_MenuType stateMain;
}PhaseSnake_Type;

typedef PhaseSnake_Type(*fptrPhaseSnake)(PhaseSnake_Type);

typedef const struct PhaseSnake{
	PhaseSnake_Type(*PhaseSnake)(PhaseSnake_Type);
}PhasePtrSnake_Type;
/***********************************************************/
/***********************************************************/
/**
 * \brief This data type define the data type in COMPASS
 */

typedef enum{SHOW_COMPASS,
			EXIT_COMPASS
}PhaseStateCompass_Type;

typedef struct{
	PhaseStateCompass_Type phaseState;
	States_MenuType stateMain;
}PhaseCompass_Type;

typedef PhaseCompass_Type(*fptrPhaseCompass)(PhaseCompass_Type);

typedef const struct PhaseCompass{
	PhaseCompass_Type(*PhaseCompass)(PhaseCompass_Type);
}PhasePtrCompass_Type;
/***********************************************************/
/***********************************************************/
/**
 * \brief This data type define the data type in WALLPAPER
 */

typedef enum{VIEW_WALLPAPER,
			EXIT_WALLPAPER
}PhaseStateWallpaper_Type;

typedef struct{
	PhaseStateWallpaper_Type phaseState;
	States_MenuType stateMain;
}PhaseWallpaper_Type;

typedef PhaseWallpaper_Type(*fptrPhaseWallpaper)(PhaseWallpaper_Type);

typedef const struct PhaseWallpaper{
	PhaseWallpaper_Type(*PhaseWallpaper)(PhaseWallpaper_Type);
}PhasePtrWallpaper_Type;
/**********************************************************/
/**
 * \brief This data type define the data type to Show Contacts
 */
typedef enum{CONTACT1,
			CONTACT2,
			CONTACT3,
			CONTACT4,
			CONTACT5,
			CONTACT6,
			CONTACT7,
			CONTACT8,
			CONTACT9,
			CONTACT10
}ShowContact_Type;

typedef ShowContact_Type(*fptrStateShowContact)(void);

typedef const struct StateShowContact{
	ShowContact_Type(*stateShowContact)(void);
}StateShowContact_Type;

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Clean any contact
 	 \param[in]  contact Contact selected
 	 \return void
 */
void cleanContact(uint8 contact);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the contact saved
 	 \param[in]  void
 	 \return The information of the contact
 */
ShowContact_Type contactNumber1(void);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the contact saved
 	 \param[in]  void
 	 \return The information of the contact
 */
ShowContact_Type contactNumber2(void);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the contact saved
 	 \param[in]  void
 	 \return The information of the contact
 */
ShowContact_Type contactNumber3(void);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the contact saved
 	 \param[in]  void
 	 \return The information of the contact
 */
ShowContact_Type contactNumber4(void);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the contact saved
 	 \param[in]  void
 	 \return The information of the contact
 */
ShowContact_Type contactNumber5(void);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the contact saved
 	 \param[in]  void
 	 \return The information of the contact
 */
ShowContact_Type contactNumber6(void);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the contact saved
 	 \param[in]  void
 	 \return The information of the contact
 */
ShowContact_Type contactNumber7(void);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the contact saved
 	 \param[in]  void
 	 \return The information of the contact
 */
ShowContact_Type contactNumber8(void);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the contact saved
 	 \param[in]  void
 	 \return The information of the contact
 */
ShowContact_Type contactNumber9(void);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the contact saved
 	 \param[in]  void
 	 \return The information of the contact
 */
ShowContact_Type contactNumber10(void);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State that charges the first initialization of the program
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseMainMenu_Type initialLoad1(PhaseMainMenu_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State that charges the second initialization of the program
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseMainMenu_Type initialLoad2(PhaseMainMenu_Type data);


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
 	 \brief	 State to write the number
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseMessages_Type writeNumber(PhaseMessages_Type data);

/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to write the message
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseMessages_Type writeMessages(PhaseMessages_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to send the message
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseMessages_Type sendMessages(PhaseMessages_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to exit of the state
 	 \param[in]  data The current information
 	 \return Updated information
 */

PhaseMessages_Type exitMessages(PhaseMessages_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to enter to menu of contacts
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseContacts_Type contactsMenu(PhaseContacts_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	State to view all the contacts through the rotative menu
 	 \param[in]  delay Value of delay
 	 \return void
 */
PhaseContacts_Type viewContacts(PhaseContacts_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to add the contacts
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseContacts_Type addContacts(PhaseContacts_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Save the contacts in the memory
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseContacts_Type saveContacts(PhaseContacts_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Start the game of snake
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseSnake_Type startGame(PhaseSnake_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Run the game of snake
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseSnake_Type runGame(PhaseSnake_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Show the image of game over
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseSnake_Type gameLost(PhaseSnake_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Show the score
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseSnake_Type showScore(PhaseSnake_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 Print the question about the play again
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseSnake_Type playAgain(PhaseSnake_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to exit and back to the menu
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseSnake_Type exitGame(PhaseSnake_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to show the compass
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseCompass_Type showCompass(PhaseCompass_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to exit of the compass
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseCompass_Type exitCompass(PhaseCompass_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to view the different wallpapers in the phone
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseWallpaper_Type viewWallpaper(PhaseWallpaper_Type data);


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/*!
 	 \brief	 State to exit and come back to the menu
 	 \param[in]  data The current information
 	 \return Updated information
 */
PhaseWallpaper_Type exitWallpaper(PhaseWallpaper_Type data);

#endif

