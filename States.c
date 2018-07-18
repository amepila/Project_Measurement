#include "Phases.h"

/**Pointer to functions of Main Menu*/
const PhasePtrMainMenu_Type phasesMainMenu[4] =
{
		{initialLoad},
		{generalView},
		{viewMenu},
        {sendData}
};

/**Pointer to functions of Power1*/
const PhasePtrEnergy_Type phasesEnergy[4] =
{
		{activeEnergy},
		{fundamentalEnergy},
        {harmonicEnergy},
        {exitEnergy}
};

/**Pointer to functions of Power1*/
const PhasePtrPower1_Type phasesPower1[3] =
{
		{typesPower1},
		{phPower1},
		{exitPower1}
};

/**Pointer to functions of Power2*/
const PhasePtrPower2_Type phasesPower2[3] =
{
		{fhPower2},
		{phPower2},
		{exitPower2}
};

/**Pointer to functions of Rms VI*/
const PhasePtrRmsVI_Type phasesRmsVI[3] =
{
		{phRmsVI},
		{neutralRmsVI},
		{exitRmsVI}
};

/**Pointer to functions of Power Factor*/
const PhasePtrPowerFactor_Type phasesPowerFactor[2] =
{
		{phPowerFactor},
		{exitPowerFactor}
};

/**Pointer to functions of Phase Angle*/
const PhasePtrPhaseAngle_Type phasesPhaseAngle[4] =
{
		{phPhaseAngle},
        {viPhaseAngle},
        {THDNPhaseAngle},
		{exitPhaseAngle}
};

/**Pointer to functions of Frequency*/
const PhasePtrFreqTemp_Type phasesFreqTemp[2] =
{
		{showFreqTemp},
		{exitFreqTemp}
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

States_MenuType stateEnergy(void)
{
	/**Initialization of state machine of Energy**/
	static PhaseStateEnergy_Type phase = ACTIVE_ENERGY;
	static PhaseEnergy_Type phaseEnergy;
	PhaseEnergy_Type(*energyFunctions)(PhaseEnergy_Type);
	phaseEnergy.stateMain = ENERGY;

	/**Run the state machine and update the state**/
	energyFunctions = phasesEnergy[phase].PhaseEnergy;
	phaseEnergy = energyFunctions(phaseEnergy);

	/**Verified if there a change flow of program**/
	phase = phaseEnergy.phaseState;
	return (phaseEnergy.stateMain);
}

States_MenuType statePower1(void)
{
	/**Initialization of state machine of Power1**/
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
	/**Initialization of state machine of Power2**/
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
	/**Initialization of state machine of RMS VI**/
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
	/**Initialization of state machine of Power Factor**/
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
	/**Initialization of state machine of Phase Angle**/
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

States_MenuType stateFreqTemp(void)
{
	/**Initialization of state machine of Frequency**/
	static PhaseStateFreqTemp_Type phase = SHOW_FREQTEMP;
	static PhaseFreqTemp_Type phaseFreqTemp;
	PhaseFreqTemp_Type(*freqTempFunctions)(PhaseFreqTemp_Type);
	phaseFreqTemp.stateMain = FREQTEMP;

	/**Run the state machine and update the state**/
	freqTempFunctions = phasesFreqTemp[phase].PhaseFreqTemp;
	phaseFreqTemp = freqTempFunctions(phaseFreqTemp);

	/**Verified if there a change flow of program**/
	phase = phaseFreqTemp.phaseState;
	return (phaseFreqTemp.stateMain);
}
