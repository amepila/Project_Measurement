#include <xc.h>
#include "Phases.h"

PhaseMainMenu_Type initialLoad(PhaseMainMenu_Type data)
{
    /**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu1;

	/**Clear the nokia LCD*/
	LCDNokia_clear();
    

	/**Set with the current state and phase**/
	currentMainMenu1.phaseState = GENERAL_VIEW;
	currentMainMenu1.stateMain = data.stateMain;

	return (currentMainMenu1);
}

PhaseMainMenu_Type generalView(PhaseMainMenu_Type data)
{
    /**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu2;

	/**Set with the current state and phase**/
	currentMainMenu2.phaseState = VIEW_MENU;
	currentMainMenu2.stateMain = data.stateMain;

	return (currentMainMenu2);
}

PhaseMainMenu_Type viewMenu(PhaseMainMenu_Type data)
{
	/**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu3;

	/**Set with the current state and phase**/
	currentMainMenu3.phaseState = data.phaseState;
    currentMainMenu3.stateMain = data.stateMain;

	return (currentMainMenu3);
}

PhasePower1_Type typesPower1(PhasePower1_Type data)
{
    /**Create the variable with current data**/
	static PhasePower1_Type currentPower1_1;

	/**Set with the current state and phase**/
	currentPower1_1.phaseState = PHASES_POWER1;
	currentPower1_1.stateMain = data.stateMain;

	return (currentPower1_1);
}

PhasePower1_Type phPower1(PhasePower1_Type data)
{
    /**Create the variable with current data**/
	static PhasePower1_Type currentPower1_2;

	/**Set with the current state and phase**/
	currentPower1_2.phaseState = VECTOR_POWER1;
	currentPower1_2.stateMain = data.stateMain;

	return (currentPower1_2);
}

PhasePower1_Type vectorPower1(PhasePower1_Type data)
{
    /**Create the variable with current data**/
	static PhasePower1_Type currentPower1_3;

	/**Set with the current state and phase**/
	currentPower1_3.phaseState = EXIT_POWER1;
	currentPower1_3.stateMain = data.stateMain;

	return (currentPower1_3);
}

PhasePower1_Type exitPower1(PhasePower1_Type data)
{
    /**Create the variable with current data**/
	static PhasePower1_Type currentPower1_4;

	/**Set with the current state and phase**/
	currentPower1_4.phaseState = data.phaseState;
	currentPower1_4.stateMain = data.stateMain;

	return (currentPower1_4);
}

PhasePower2_Type fhPower2(PhasePower2_Type data)
{
    /**Create the variable with current data**/
	static PhasePower2_Type currentPower2_1;

	/**Set with the current state and phase**/
	currentPower2_1.phaseState = PHASES_POWER2;
	currentPower2_1.stateMain = data.stateMain;

	return (currentPower2_1);
}

PhasePower2_Type phPower2(PhasePower2_Type data)
{
    /**Create the variable with current data**/
	static PhasePower2_Type currentPower2_2;

	/**Set with the current state and phase**/
	currentPower2_2.phaseState = EXIT_POWER2;
	currentPower2_2.stateMain = data.stateMain;

	return (currentPower2_2);
}

PhasePower2_Type exitPower2(PhasePower2_Type data)
{
    /**Create the variable with current data**/
	static PhasePower2_Type currentPower2_3;

	/**Set with the current state and phase**/
	currentPower2_3.phaseState = data.phaseState;
	currentPower2_3.stateMain = data.stateMain;

	return (currentPower2_3);
}

PhaseRmsVI_Type phRmsVI(PhaseRmsVI_Type data)
{
    /**Create the variable with current data**/
	static PhaseRmsVI_Type currentRms1;

	/**Set with the current state and phase**/
	currentRms1.phaseState = NEUTRAL_RMSVI;
	currentRms1.stateMain = data.stateMain;

	return (currentRms1);
}

PhaseRmsVI_Type neutralRmsVI(PhaseRmsVI_Type data)
{
    /**Create the variable with current data**/
	static PhaseRmsVI_Type currentRms2;

	/**Set with the current state and phase**/
	currentRms2.phaseState = EXIT_RMSVI;
	currentRms2.stateMain = data.stateMain;

	return (currentRms2);
}

PhaseRmsVI_Type exitRmsVI(PhaseRmsVI_Type data)
{
    /**Create the variable with current data**/
	static PhaseRmsVI_Type currentRms3;

	/**Set with the current state and phase**/
	currentRms3.phaseState = data.phaseState;
	currentRms3.stateMain = data.stateMain;

	return (currentRms3);
}

PhasePowerFactor_Type phPowerFactor(PhasePowerFactor_Type data)
{
    /**Create the variable with current data**/
	static PhasePowerFactor_Type currentPowerFactor1;

	/**Set with the current state and phase**/
	currentPowerFactor1.phaseState = EXIT_PF;
	currentPowerFactor1.stateMain = data.stateMain;

	return (currentPowerFactor1);
}

PhasePowerFactor_Type exitPowerFactor(PhasePowerFactor_Type data)
{
    /**Create the variable with current data**/
	static PhasePowerFactor_Type currentPowerFactor2;

	/**Set with the current state and phase**/
	currentPowerFactor2.phaseState = data.phaseState;
	currentPowerFactor2.stateMain = data.stateMain;

	return (currentPowerFactor2);
}

PhasePhaseAngle_Type phPhaseAngle(PhasePhaseAngle_Type data)
{
    /**Create the variable with current data**/
	static PhasePhaseAngle_Type currentPhaseAngle1;

	/**Set with the current state and phase**/
	currentPhaseAngle1.phaseState = VI_PA;
	currentPhaseAngle1.stateMain = data.stateMain;

	return (currentPhaseAngle1);
}

PhasePhaseAngle_Type viPhaseAngle(PhasePhaseAngle_Type data)
{
    /**Create the variable with current data**/
	static PhasePhaseAngle_Type currentPhaseAngle2;

	/**Set with the current state and phase**/
	currentPhaseAngle2.phaseState = EXIT_PA;
	currentPhaseAngle2.stateMain = data.stateMain;

	return (currentPhaseAngle2); 
}

PhasePhaseAngle_Type exitPhaseAngle(PhasePhaseAngle_Type data)
{
    /**Create the variable with current data**/
	static PhasePhaseAngle_Type currentPhaseAngle3;

	/**Set with the current state and phase**/
	currentPhaseAngle3.phaseState = data.phaseState;
	currentPhaseAngle3.stateMain = data.stateMain;

	return (currentPhaseAngle3);   
}

PhaseFrequency_Type showFrequency(PhaseFrequency_Type data)
{
    /**Create the variable with current data**/
	static PhaseFrequency_Type currentFrequency1;

	/**Set with the current state and phase**/
	currentFrequency1.phaseState = EXIT_FREQUENCY;
	currentFrequency1.stateMain = data.stateMain;

	return (currentFrequency1);
}

PhaseFrequency_Type exitFrequency(PhaseFrequency_Type data)
{
    /**Create the variable with current data**/
	static PhaseFrequency_Type currentFrequency2;

	/**Set with the current state and phase**/
	currentFrequency2.phaseState = data.phaseState;
	currentFrequency2.stateMain = data.stateMain;

	return (currentFrequency2);
}

PhaseTemperature_Type showTemperature(PhaseTemperature_Type data)
{
    /**Create the variable with current data**/
	static PhaseTemperature_Type currentTemperature1;

	/**Set with the current state and phase**/
	currentTemperature1.phaseState = EXIT_TEMPERATURE;
	currentTemperature1.stateMain = data.stateMain;

	return (currentTemperature1);
}

PhaseTemperature_Type exitTemperature(PhaseTemperature_Type data)
{
    /**Create the variable with current data**/
	static PhaseTemperature_Type currentTemperature2;

	/**Set with the current state and phase**/
	currentTemperature2.phaseState = data.phaseState;
	currentTemperature2.stateMain = data.stateMain;

	return (currentTemperature2);
}