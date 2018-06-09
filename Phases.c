#include <xc.h>
#include "Phases.h"

PhaseMainMenu_Type initialLoad(PhaseMainMenu_Type data)
{
    /**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu1;

    /**Load the value of register of IC*/
    //Calibration Normal Mode
    
	/**Set with the current state and phase**/
	currentMainMenu1.phaseState = GENERAL_VIEW;
	currentMainMenu1.stateMain = data.stateMain;

	return (currentMainMenu1);
}

PhaseMainMenu_Type generalView(PhaseMainMenu_Type data)
{
    const uint8_t msgInitial1[] = "MEDICION DE";
    const uint8_t msgInitial2[] = "TRIFASICO";
    const uint8_t buttonRight[] = "Enviar";
    const uint8_t buttonLeft[] = "Menu";
    
    static uint8_t lockClear = 0;
    static uint8_t lockWrite = 0;
    /**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu2;

    currentMainMenu2.phaseState = GENERAL_VIEW;

    if(0 == lockClear)
    {
        /**Clear the nokia LCD*/
        LCDNokia_clear();
        /**Execute once time*/
        lockClear = 1;
    }
    
    if(0 == lockWrite)
    {
        LCDNokia_gotoXY(20,1);
        LCDNokia_sendString(msgInitial1);
    
        LCDNokia_gotoXY(27,1);
        LCDNokia_sendString(msgInitial2);
    
        LCDNokia_gotoXY(0,4);
        LCDNokia_sendString(buttonLeft);
    
        LCDNokia_gotoXY(65,4);
        LCDNokia_sendString(buttonRight);
        
        lockWrite = 1;
    }

    if(getButton1() == 1)
    {
        currentMainMenu2.phaseState = VIEW_MENU;
        lockClear = 0;
        lockWrite = 0;
    }
    if(getButton3() == 1)
    {
        currentMainMenu2.phaseState = SEND_DATA;
        lockClear = 0;
        lockWrite = 0;
    }
    
	/**Set with the current state and phase**/
	currentMainMenu2.stateMain = data.stateMain;

	return (currentMainMenu2);
}

PhaseMainMenu_Type viewMenu(PhaseMainMenu_Type data)
{
    const uint8_t string1_Power1[] = "Potencia Activa";
    const uint8_t string2_Power1[] = "Reactiva, Aparente";
    
    const uint8_t string1_Power2[] = "Potencia";
    const uint8_t string2_Power2[] = "Fundamental";
    const uint8_t string3_Power2[] = "Armonica";

    const uint8_t string1_RMS[] = "Voltage Corriente";
    const uint8_t string2_RMS[] = "RMS";
    
    const uint8_t string1_PowerFactor[] = "Factor de";
    const uint8_t string2_PowerFactor[] = "Potencia";
    
    const uint8_t string1_PhaseAngle[] = "Angulo de";
    const uint8_t string2_PhaseAngle[] = "Fase";
    
    const uint8_t string1_Frequency[] = "Frecuencia";
    
    const uint8_t string1_Temperature[] = "Temperatura";
    
    const uint8_t buttonRight[] = "D";
    const uint8_t buttonCenter[] = "E";
    const uint8_t buttonLeft[] = "I";
    
    static uint8_t lockClear = 0;
    static uint8_t lockWrite = 0;
    static uint8_t counterMenu = 0;
	/**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu3;

    currentMainMenu3.phaseState = VIEW_MENU;
    currentMainMenu3.stateMain = data.stateMain;
    
    if(0 == lockClear)
    {
        /**Clear the nokia LCD*/
        LCDNokia_clear();
        /**Execute once time*/
        lockClear = 1;
    }
    
    if(0 == lockWrite)
    {
        switch(counterMenu)
        {
            case 0:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_Power1);
    
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(string2_Power1);
                break;
            case 1:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_Power2);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_Power2);
                
                LCDNokia_gotoXY(15,3);
                LCDNokia_sendString(string3_Power2);
                break;
            case 2:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_RMS);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_RMS);
                break;
            case 3:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_PowerFactor);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_PowerFactor);
                break;
            case 4:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_PhaseAngle);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_PhaseAngle);
                break;
            case 5:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_Frequency);
                break;
            case 6:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_Temperature);
                break;
            default:
                break;
        }
        
        LCDNokia_gotoXY(0,4);
        LCDNokia_sendString(buttonLeft);
    
        LCDNokia_gotoXY(40,4);
        LCDNokia_sendString(buttonCenter);
        
        LCDNokia_gotoXY(80,4);
        LCDNokia_sendString(buttonRight);
        
        lockWrite = 1;
    }
    
    if(getButton1() == 1)
    {
        if(0 == counterMenu)
        {
            counterMenu = 6;
        }
        else
        {
            counterMenu--;
        }

        lockClear = 0;
        lockWrite = 0;
    }
    if(getButton2() == 1)
    {
        switch(counterMenu)
        {
            case 0:
                currentMainMenu3.phaseState = TYPES_POWER1;
                currentMainMenu3.stateMain = POWER_1;
                break;
            case 1:
                currentMainMenu3.phaseState = FH_POWER2;
                currentMainMenu3.stateMain = POWER_2;
                break;
            case 2:
                currentMainMenu3.phaseState = PHASES_RMSVI;
                currentMainMenu3.stateMain = RMS_VI;
                break;
            case 3:
                currentMainMenu3.phaseState = PHASES_PF;
                currentMainMenu3.stateMain = POWER_FACTOR;
                break;
            case 4:
                currentMainMenu3.phaseState = PHASES_PA;
                currentMainMenu3.stateMain = PHASE_ANGLE;
                break;
            case 5:
                currentMainMenu3.phaseState = SHOW_FREQUENCY;
                currentMainMenu3.stateMain = FREQUENCY;
                break;
            case 6:
                currentMainMenu3.phaseState = SHOW_TEMPERATURE;
                currentMainMenu3.stateMain = TEMPERATURE;
                break;
            default:
                break;
        }
        lockClear = 0;
        lockWrite = 0;
    }
    if(getButton3() == 1)
    {
        counterMenu++;
        if(counterMenu > 6)
        {
            counterMenu = 0;
        }
        lockClear = 0;
        lockWrite = 0;
    }
    
	/**Set with the current state and phase**/
	currentMainMenu3.phaseState = data.phaseState;
    currentMainMenu3.stateMain = POWER_1;

	return (currentMainMenu3);
}

PhaseMainMenu_Type sendData(PhaseMainMenu_Type data)
{
    const uint8_t test[] = "TEST";
	/**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu4;

    
    UART_putString(test);
    /*
     ...Send all the info of the IC
     */
    
	/**Set with the current state and phase**/
	currentMainMenu4.phaseState = GENERAL_VIEW;
    currentMainMenu4.stateMain = data.stateMain;

	return (currentMainMenu4);
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