#include <xc.h>
#include "States.h"
#include "Phases.h"

/**Pointer to functions of Main Menu*/
const PhasePtrMainMenu_Type phasesMainMenu[3] =
{
		{initialLoad},
		{generalView},
		{viewMenu}
};

/**Pointer to functions of Messages*/
const PhasePtrPower1_Type phasesPower1[4] =
{
		{typesPower1},
		{phPower1},
		{vectorPower1},
		{exitPower1}
};

/**Pointer to functions of Contacts*/
const PhasePtrPower2_Type phasesPower2[3] =
{
		{fhPower2},
		{phPower2},
		{exitPower2}
};

/**Pointer to functions of Snake*/
const PhasePtrRmsVI_Type phasesRmsVI[3] =
{
		{phRmsVI},
		{neutralRmsVI},
		{exitRmsVI}
};

/**Pointer to functions of Compass*/
const PhasePtrPowerFactor_Type phasesPowerFactor[2] =
{
		{phPowerFactor},
		{exitPowerFactor}
};

/**Pointer to functions of Wallpapers*/
const PhasePtrPhaseAngle_Type phasesPhaseAngle[3] =
{
		{phPhaseAngle},
        {viPhaseAngle},
		{exitPhaseAngle}
};

/**Pointer to functions of Wallpapers*/
const PhasePtrFrequency_Type phasesFrequency[2] =
{
		{showFrequency},
		{exitFrequency}
};

/**Pointer to functions of Wallpapers*/
const PhasePtrTemperature_Type phasesTemperature[2] =
{
		{showTemperature},
		{exitTemperature}
};

States_MenuType stateMainMenu(void)
{
	/**Initialization of state machine of Main Menu**/
	static PhaseStateMenu_Type phase = INITIAL_LOAD;
	static PhaseMainMenu_Type phaseMain;
	PhaseMainMenu_Type(*mainMenuFunctions)(PhaseMainMenu_Type);
	phaseMain.stateMain = MAIN_MENU;

	/**Run the state machine and update the state**/
	mainMenuFunctions = phasesMainMenu[phase].PhaseMainMenu;
	phaseMain = mainMenuFunctions(phaseMain);

	/**Verified if there a change flow of program**/
	phase = phaseMain.phaseState;
	return (phaseMain.stateMain);
}

States_MenuType statePower1(void)
{
	/**Initialization of state machine of Contacts**/
	static PhaseStatePower1_Type phase = TYPES_POWER1;
	static PhasePower1_Type phasePower1;
	PhasePower1_Type(*power1Functions)(PhasePower1_Type);
	phasePower1.stateMain = POWER_1;

	/**Run the state machine and update the state**/
	power1Functions = phasesPower1[phase].PhasePower1;
	phasePower1 = power1Functions(phasePower1);

	/**Verified if there a change flow of program**/
	phase = phasePower1.phaseState;
	return (phasePower1.stateMain);
}

States_MenuType statePower2(void)
{
	/**Initialization of state machine of Messages**/
	static PhaseStatePower2_Type phase = FH_POWER2;
	static PhasePower2_Type phasePower2;
	PhasePower2_Type(*power2Functions)(PhasePower2_Type);
	phasePower2.stateMain = POWER_2;

	/**Run the state machine and update the state**/
	power2Functions = phasesPower2[phase].PhasePower2;
	phasePower2 = power2Functions(phasePower2);

	/**Verified if there a change flow of program**/
	phase = phasePower2.phaseState;
	return (phasePower2.stateMain);
}

States_MenuType stateRmsVI(void)
{
	/**Initialization of state machine of Snake game**/
	static PhaseStateRmsVI_Type phase = PHASES_RMSVI;
	static PhaseRmsVI_Type phaseRmsVI;
	PhaseRmsVI_Type(*rmsVIFunctions)(PhaseRmsVI_Type);
	phaseRmsVI.stateMain = RMS_VI;

	/**Run the state machine and update the state**/
	rmsVIFunctions = phasesRmsVI[phase].PhaseRmsVI;
	phaseRmsVI = rmsVIFunctions(phaseRmsVI);

	/**Verified if there a change flow of program**/
	phase = phaseRmsVI.phaseState;
	return (phaseRmsVI.stateMain);
}

States_MenuType statePowerFactor(void)
{
	/**Initialization of state machine of Compass**/
	static PhaseStatePowerFactor_Type phase = PHASES_PF;
	static PhasePowerFactor_Type phasePowerFactor;
	PhasePowerFactor_Type(*powerFactorFunctions)(PhasePowerFactor_Type);
	phasePowerFactor.stateMain = POWER_FACTOR;

	/**Run the state machine and update the state**/
	powerFactorFunctions = phasesPowerFactor[phase].PhasePowerFactor;
	phasePowerFactor = powerFactorFunctions(phasePowerFactor);

	/**Verified if there a change flow of program**/
	phase = phasePowerFactor.phaseState;
	return (phasePowerFactor.stateMain);
}

States_MenuType statePhaseAngle(void)
{
	/**Initialization of state machine of Wallpaper**/
	static PhaseStatePhaseAngle_Type phase = PHASES_PA;
	static PhasePhaseAngle_Type phasePhaseAngle;
	PhasePhaseAngle_Type(*phaseAngleFunctions)(PhasePhaseAngle_Type);
	phasePhaseAngle.stateMain = PHASE_ANGLE;

	/**Run the state machine and update the state**/
	phaseAngleFunctions = phasesPhaseAngle[phase].PhasePhaseAngle;
	phasePhaseAngle = phaseAngleFunctions(phasePhaseAngle);

	/**Verified if there a change flow of program**/
	phase = phasePhaseAngle.phaseState;
	return (phasePhaseAngle.stateMain);
}

States_MenuType stateFrequency(void)
{
	/**Initialization of state machine of Compass**/
	static PhaseStateFrequency_Type phase = SHOW_FREQUENCY;
	static PhaseFrequency_Type phaseFrequency;
	PhaseFrequency_Type(*frequencyFunctions)(PhaseFrequency_Type);
	phaseFrequency.stateMain = FREQUENCY;

	/**Run the state machine and update the state**/
	frequencyFunctions = phasesFrequency[phase].PhaseFrequency;
	phaseFrequency = frequencyFunctions(phaseFrequency);

	/**Verified if there a change flow of program**/
	phase = phaseFrequency.phaseState;
	return (phaseFrequency.stateMain);
}

States_MenuType stateTemperature(void)
{
	/**Initialization of state machine of Compass**/
	static PhaseStateTemperature_Type phase = SHOW_TEMPERATURE;
	static PhaseTemperature_Type phaseTemperature;
	PhaseTemperature_Type(*temperatureFunctions)(PhaseTemperature_Type);
	phaseTemperature.stateMain = TEMPERATURE;

	/**Run the state machine and update the state**/
	temperatureFunctions = phasesTemperature[phase].PhaseTemperature;
	phaseTemperature = temperatureFunctions(phaseTemperature);

	/**Verified if there a change flow of program**/
	phase = phaseTemperature.phaseState;
	return (phaseTemperature.stateMain);
}