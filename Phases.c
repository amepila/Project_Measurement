#include "Phases.h"

/*
 * Button 1 RA3
 * Button 2 RA4
 * Button 3 RC3
 */

    const uint8_t msgInitial1_gv[13] = "Three Phase\0";
    const uint8_t msgInitial2_gv[13] = "Measurement\0";
    const uint8_t buttonRight_gv[6] = "Send\0";
    const uint8_t buttonLeft_gv[6] = "Menu\0";
    
    const uint8_t string_Energy[7] = "Energy";
    
    const uint8_t string1_Power1[17] = "Active Reactive\0";
    const uint8_t string2_Power1[17] = "Apparent Power\0";
    
    const uint8_t string1_Power2[12] = "Fundamental\0";
    const uint8_t string2_Power2[10] = "Harmonic\0";
    const uint8_t string3_Power2[7] = "Power\0";

    const uint8_t string1_RMS[17] = "Voltage Current\0";
    const uint8_t string2_RMS[5] = "RMS\0";
    
    const uint8_t string1_PowerFactor[7] = "Power\0";
    const uint8_t string2_PowerFactor[8] = "Factor\0";
    
    const uint8_t string1_PhaseAngle[7] = "Phase\0";
    const uint8_t string2_PhaseAngle[7] = "Angle\0";
    
    const uint8_t string1_FreqTemp[10] = "FreqTemp\0";
    
    const uint8_t buttonRight[3] = "R\0";
    const uint8_t buttonCenter[3] = "E\0";
    const uint8_t buttonLeft[3] = "L\0";
    
    const uint8_t active_Forward1[15] = "PA Forw Act: \0";
    const uint8_t active_Forward2[15] = "PB Forw Act: \0";
    const uint8_t active_Forward3[15] = "PC Forw Act: \0";
    
    const uint8_t active_Reverse1[14] = "PA Rev Act: \0";
    const uint8_t active_Reverse2[14] = "PB Rev Act: \0";
    const uint8_t active_Reverse3[14] = "PC Rev Act: \0";
    
    const uint8_t active_Forward_Total[18] = "Total Forw Act: \0";
    const uint8_t active_Reverse_Total[17] = "Total Rev Act: \0";
   
    const uint8_t reactive_Forward1[17] = "PA Forw React: \0";
    const uint8_t reactive_Forward2[17] = "PB Forw React: \0";
    const uint8_t reactive_Forward3[17] = "PC Forw React: \0";
    
    const uint8_t reactive_Reverse1[16] = "PA Rev React: \0";
    const uint8_t reactive_Reverse2[16] = "PB Rev React: \0";
    const uint8_t reactive_Reverse3[16] = "PC Rev React: \0";
    
    const uint8_t reactive_Forward_Total[20] = "Total Forw React: \0";
    const uint8_t reactive_Reverse_Total[19] = "Total Rev React: \0";
    
    const uint8_t apparent_energyP1[10] = "PA App: \0";
    const uint8_t apparent_energyP2[10] = "PB App: \0";
    const uint8_t apparent_energyP3[10] = "PC App: \0";
    
    const uint8_t apparentAri_energyTotal[19] = "Total AriApp En: \0";
    const uint8_t apparentVec_energyTotal[19] = "Total VecApp En: \0";
        
    const uint8_t fund_ForwardP1[17] = "PA ForwFund E: \0";
    const uint8_t fund_ForwardP2[17] = "PB ForwFund E: \0";
    const uint8_t fund_ForwardP3[17] = "PC ForwFund E: \0";
    
    const uint8_t fund_ReverseP1[16] = "PA RevFund E: \0";
    const uint8_t fund_ReverseP2[16] = "PB RevFund E: \0";
    const uint8_t fund_ReverseP3[16] = "PC RevFund E: \0";
    
    const uint8_t fund_ForwardTotal[20] = "Total ForwFund E: \0";
    const uint8_t fund_ReverseTotal[19] = "Total RevFund E: \0";
    
    const uint8_t harmonic_ForwardP1[13] = "PA ForwHE: \0";
    const uint8_t harmonic_ForwardP2[13] = "PB ForwHE: \0";
    const uint8_t harmonic_ForwardP3[13] = "PC ForwHE: \0";
    
    const uint8_t harmonic_ReverseP1[12] = "PA RevHE: \0";
    const uint8_t harmonic_ReverseP2[12] = "PB RevHE: \0";
    const uint8_t harmonic_ReverseP3[12] = "PC RevHE: \0";
  
    const uint8_t harmonic_ForwardTotal[16] = "Total ForwHE: \0";
    const uint8_t harmonic_ReverseTotal[15] = "Total RevHE: \0";
    
    const uint8_t active_powerP1[11] = "PA APow: \0";
    const uint8_t active_powerP2[11] = "PB APow: \0";
    const uint8_t active_powerP3[11] = "PC APow: \0";

    const uint8_t reactive_powerP1[11] = "PA RPow: \0";
    const uint8_t reactive_powerP2[11] = "PB RPow: \0";
    const uint8_t reactive_powerP3[11] = "PC RPow: \0";
    
    const uint8_t apparent_powerP1[12] = "PA APPow: \0";
    const uint8_t apparent_powerP2[12] = "PB APPow: \0";
    const uint8_t apparent_powerP3[12] = "PC APPow: \0";

    const uint8_t total_active_power[14] = "Total APow: \0";
    const uint8_t total_reactive_power[14] = "Total RPow: \0";
    const uint8_t total_apparent_power[15] = "Total APPow: \0";
    
    const uint8_t fundamental_PowerP1[11] = "PA FPow: \0";
    const uint8_t fundamental_PowerP2[11] = "PB FPow: \0";
    const uint8_t fundamental_PowerP3[11] = "PC FPow: \0";
 
    const uint8_t harmonic_PowerP1[11] = "PA HPow: \0";
    const uint8_t harmonic_PowerP2[11] = "PB HPow: \0";
    const uint8_t harmonic_PowerP3[11] = "PC HPow: \0";
    
    const uint8_t fundamental_Total_Power[14] = "Total FPow: \0";
    const uint8_t harmonic_Total_Power[14] = "Total HPow: \0";
    
    const uint8_t voltage1_RMS[11] = "PA VRMS: \0";
    const uint8_t voltage2_RMS[11] = "PB VRMS: \0";
    const uint8_t voltage3_RMS[11] = "PC VRMS: \0";

    const uint8_t current1_RMS[11] = "PA CRMS: \0";
    const uint8_t current2_RMS[11] = "PB CRMS: \0";
    const uint8_t current3_RMS[11] = "PC CRMS: \0";
    
    const uint8_t nline_calculated_RMS[13] = "N CalCRMS: \0";
    const uint8_t nline_sampled_RMS[13] = "N SamCRMS: \0";
    
    const uint8_t factor_powerP1[9] = "PA PF: \0";
    const uint8_t factor_powerP2[9] = "PB PF: \0";
    const uint8_t factor_powerP3[9] = "PC PF: \0";
    
    const uint8_t total_factor_power[12] = "Total PF: \0";
    
    const uint8_t anglePhase1[11] = "PA phA: \0";
    const uint8_t anglePhase2[11] = "PB phA: \0";
    const uint8_t anglePhase3[11] = "PC phA: \0";
    
    const uint8_t angle_VoltageP1[11] = "PA VphA: \0";
    const uint8_t angle_VoltageP2[11] = "PB VphA: \0";
    const uint8_t angle_VoltageP3[11] = "PC VphA: \0";
    
    const uint8_t voltage1_THDN[12] = "PA vTHDN: \0";
    const uint8_t voltage2_THDN[12] = "PB vTHDN: \0";
    const uint8_t voltage3_THDN[12] = "PC vTHDN: \0";

    const uint8_t current1_THDN[12] = "PA cTHDN: \0";
    const uint8_t current2_THDN[12] = "PB cTHDN: \0";
    const uint8_t current3_THDN[12] = "PC cTHDN: \0";
    
    const uint8_t frequency[8] = "Freq: \0";
    const uint8_t temperature[8] = "Temp: \0";
    
/**Settings of SPI**/
const SPI_ConfigType SPI_Config2 = 
{
	SPI_HIGH_POLARITY,	/**Low Polarity to SPI**/
	SPI_LOW_PHASE,		/**Low Phase to SPI**/
	SPI_SERIAL_CLK64     /**FOsc divided by 4**/
};

PhaseMainMenu_Type initialLoad(PhaseMainMenu_Type data)
{
#if 1
    /**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu1;

    /**Calibration of the IC*/
    //ATM_init();
    //ATM_calibration();
    delay(1500);
    
	/**Set with the current state and phase**/
	currentMainMenu1.phaseState = GENERAL_VIEW;
	currentMainMenu1.stateMain = data.stateMain;
	return (currentMainMenu1);
#endif
}

PhaseMainMenu_Type generalView(PhaseMainMenu_Type data)
{
#if 1
    /**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu2;
    static uint8_t lockClear = 0;
    static uint8_t lockWrite = 0;

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
        LCDNokia_sendString(msgInitial1_gv);
    
        LCDNokia_gotoXY(27,1);
        LCDNokia_sendString(msgInitial2_gv);
    
        LCDNokia_gotoXY(0,4);
        LCDNokia_sendString(buttonLeft_gv);
    
        LCDNokia_gotoXY(65,4);
        LCDNokia_sendString(buttonRight_gv);
        
        lockWrite = 1;
    }

    if(1 == PORTAbits.RA3)
    {
        currentMainMenu2.phaseState = VIEW_MENU;
        lockClear = 0;
        lockWrite = 0;
    }
    if(1 == PORTCbits.RC3)
    {
        currentMainMenu2.phaseState = SEND_DATA;
        lockClear = 0;
        lockWrite = 0;
    }
    
	/**Set with the current state and phase**/
	currentMainMenu2.stateMain = data.stateMain;
	return (currentMainMenu2);
#endif
}

PhaseMainMenu_Type viewMenu(PhaseMainMenu_Type data)
{
#if 1
    /**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu3;
    static uint8_t lockClear = 0;
    static uint8_t lockWrite = 0;
    static uint8_t counterMenu = 0;

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
        LCDNokia_gotoXY(15,1);
        switch(counterMenu)
        {
            case 0: 
                LCDNokia_sendString(string_Energy);
                break;
            case 1:
                LCDNokia_sendString(string1_Power1);
    
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(string2_Power1);
                break;
            case 2:
                LCDNokia_sendString(string1_Power2);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_Power2);
                
                LCDNokia_gotoXY(15,3);
                LCDNokia_sendString(string3_Power2);
                break;
            case 3:
                LCDNokia_sendString(string1_RMS);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_RMS);
                break;
            case 4:
                LCDNokia_sendString(string1_PowerFactor);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_PowerFactor);
                break;
            case 5:
                LCDNokia_sendString(string1_PhaseAngle);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_PhaseAngle);
                break;
            case 6:
                LCDNokia_sendString(string1_FreqTemp);
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
    
    if(1 == PORTAbits.RA3)
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
    if(1 == PORTAbits.RA4)
    {
        switch(counterMenu)
        {
            case 0:
                currentMainMenu3.phaseState = ACTIVE_ENERGY;
                currentMainMenu3.stateMain = ENERGY;
                break;
            case 1:
                currentMainMenu3.phaseState = TYPES_POWER1;
                currentMainMenu3.stateMain = POWER_1;
                break;
            case 2:
                currentMainMenu3.phaseState = FH_POWER2;
                currentMainMenu3.stateMain = POWER_2;
                break;
            case 3:
                currentMainMenu3.phaseState = PHASES_RMSVI;
                currentMainMenu3.stateMain = RMS_VI;
                break;
            case 4:
                currentMainMenu3.phaseState = PHASES_PF;
                currentMainMenu3.stateMain = POWER_FACTOR;
                break;
            case 5:
                currentMainMenu3.phaseState = PHASES_PA;
                currentMainMenu3.stateMain = PHASE_ANGLE;
                break;
            case 7:
                currentMainMenu3.phaseState = SHOW_FREQTEMP;
                currentMainMenu3.stateMain = FREQTEMP;
                break;
            default:
                break;
        }
        lockClear = 0;
        lockWrite = 0;
    }
    if(1 == PORTCbits.RC3)
    {
        counterMenu++;
        if(counterMenu > 6)
        {
            counterMenu = 0;
        }
        lockClear = 0;
        lockWrite = 0;
    }
	return (currentMainMenu3);
#endif
}

PhaseMainMenu_Type sendData(PhaseMainMenu_Type data)
{
#if 0
	/**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu4;
    /**Confiuration of Bluetooth*/
    UART_init(void);
 
	/**Set with the current state and phase**/
	currentMainMenu4.phaseState = GENERAL_VIEW;
    currentMainMenu4.stateMain = MAIN_MENU;

    /**Configurations of SPI**/
	SPI_init(&SPI_Config2);
    LCDNokia_init();
	LCDNokia_clear();
	return (currentMainMenu4);
#endif
}

PhaseEnergy_Type activeEnergy(PhaseEnergy_Type data)
{
#if 1
    /**Create the variable with current data**/
	static PhaseEnergy_Type currentEnergy1;
    static uint8_t counter = 0;
    static uint8_t counterPhase = 0;

    /**Set with the current state and phase**/
	currentEnergy1.phaseState = ACTIVE_ENERGY;
	currentEnergy1.stateMain = data.stateMain;

    if(1 == PORTAbits.RA3)
    {
        currentEnergy1.phaseState = FUNDAMENTAL_ENERGY;
    }
    if(1 == PORTAbits.RA4)
    {        
        counterPhase++;
        if(3 == counterPhase)
        {
            counterPhase = 0;
        }
        counter = 0;
        LCDNokia_clear();
    }
    if(1 == PORTCbits.RC3)
    {
        counter++;
        LCDNokia_clear();
        if(counter > 3)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        LCDNokia_gotoXY(0,1);
        case 0:
            if(0 == counterPhase)
            {
                LCDNokia_sendString(active_Forward1);
                //LCDNokia_printValue(ATM_registers(ACTIVE_ENERGY_TYPE, PHASE_A_FORW_ACTIVE_ENERGY));
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(active_Forward2);
                //LCDNokia_printValue(ATM_registers(ACTIVE_ENERGY_TYPE, PHASE_B_FORW_ACTIVE_ENERGY));
                LCDNokia_gotoXY(0,3);
                LCDNokia_sendString(active_Forward3);
                //LCDNokia_printValue(ATM_registers(ACTIVE_ENERGY_TYPE, PHASE_C_FORW_ACTIVE_ENERGY));
            }
            if(1 == counterPhase)
            {
                LCDNokia_sendString(reactive_Forward1);
                //LCDNokia_printValue(ATM_registers(REACTIVE_ENERGY_TYPE, PHASE_A_FORW_REACTIVE_ENERGY));
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(reactive_Forward2);
                //LCDNokia_printValue(ATM_registers(REACTIVE_ENERGY_TYPE, PHASE_B_FORW_REACTIVE_ENERGY));
                LCDNokia_gotoXY(0,3);
                LCDNokia_sendString(reactive_Forward3);
                //LCDNokia_printValue(ATM_registers(REACTIVE_ENERGY_TYPE, PHASE_C_FORW_REACTIVE_ENERGY));                
            }
            if(2 == counterPhase)
            {
                LCDNokia_sendString(apparent_energyP1);
                //LCDNokia_printValue(ATM_registers(APPARENT_ENERGY_TYPE, PHASE_A_APPARENT_ENERGY));
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(apparent_energyP2);
                //LCDNokia_printValue(ATM_registers(APPARENT_ENERGY_TYPE, PHASE_B_APPARENT_ENERGY));
                LCDNokia_gotoXY(0,3);
                LCDNokia_sendString(apparent_energyP3);
                //LCDNokia_printValue(ATM_registers(APPARENT_ENERGY_TYPE, PHASE_C_APPARENT_ENERGY));                
            }

            break;
        case 1:
            if(0 == counterPhase)
            {
                LCDNokia_sendString(active_Reverse1);
                //LCDNokia_printValue(ATM_registers(ACTIVE_ENERGY_TYPE, PHASE_A_REV_ACTIVE_ENERGY));
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(active_Reverse2);
                //LCDNokia_printValue(ATM_registers(ACTIVE_ENERGY_TYPE, PHASE_B_REV_ACTIVE_ENERGY));
                LCDNokia_gotoXY(0,3);
                LCDNokia_sendString(active_Reverse3);
                //LCDNokia_printValue(ATM_registers(ACTIVE_ENERGY_TYPE, PHASE_C_REV_ACTIVE_ENERGY));
            }
            if(1 == counterPhase)
            {
                LCDNokia_sendString(reactive_Reverse1);
                //LCDNokia_printValue(ATM_registers(REACTIVE_ENERGY_TYPE, PHASE_A_REV_REACTIVE_ENERGY));
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(reactive_Reverse2);
                //LCDNokia_printValue(ATM_registers(REACTIVE_ENERGY_TYPE, PHASE_B_REV_REACTIVE_ENERGY));
                LCDNokia_gotoXY(0,3);
                LCDNokia_sendString(reactive_Reverse3);
                //LCDNokia_printValue(ATM_registers(REACTIVE_ENERGY_TYPE, PHASE_C_REV_REACTIVE_ENERGY));
            }
            if(2 == counterPhase)
            {
                LCDNokia_sendString(apparentAri_energyTotal);
                //LCDNokia_printValue(ATM_registers(APPARENT_ENERGY_TYPE, TOTAL_ARIT_APPARENT_ENERGY));
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(apparentVec_energyTotal);
                //LCDNokia_printValue(ATM_registers(APPARENT_ENERGY_TYPE, TOTAL_VECT_APPARENT_ENERGY));
            }

            break;
        case 2:
            if(0 == counterPhase)
            {
                LCDNokia_sendString(active_Forward_Total);
                //LCDNokia_printValue(ATM_registers(ACTIVE_ENERGY_TYPE, TOTAL_FORW_ACTIVE_ENERGY));
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(active_Reverse_Total);
                //LCDNokia_printValue(ATM_registers(ACTIVE_ENERGY_TYPE, TOTAL_REV_ACTIVE_ENERGY));
            }
            if(1 == counterPhase)
            {
                LCDNokia_sendString(reactive_Forward_Total);
                //LCDNokia_printValue(ATM_registers(REACTIVE_ENERGY_TYPE, TOTAL_FORW_REACTIVE_ENERGY));
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(reactive_Reverse_Total);
                //LCDNokia_printValue(ATM_registers(REACTIVE_ENERGY_TYPE, TOTAL_REVERSE_REACTIVE_ENERGY));                
            }
            break;
        default:
            break;
    }
	return (currentEnergy1);
#endif
}

PhaseEnergy_Type fundamentalEnergy(PhaseEnergy_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhaseEnergy_Type currentEnergy4;
    static uint8_t counter = 0;
    /**Set with the current state and phase**/
	currentEnergy4.phaseState = FUNDAMENTAL_ENERGY;
	currentEnergy4.stateMain = data.stateMain;

    if(1 == PORTAbits.RA3)
    {
        currentEnergy4.phaseState = EXIT_ENERGY;
    }
    if(1 == PORTAbits.RA4)
    {
        currentEnergy4.phaseState = HARMONIC_ENERGY;
        LCDNokia_clear();
    }
    if(1 == PORTCbits.RC3)
    {
        counter++;
        LCDNokia_clear();
        if(counter > 2)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(fund_ForwardP1);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_ENERGY_TYPE, PHASE_A_FORW_ACTIVE_FUND_ENERGY));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(fund_ForwardP2);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_ENERGY_TYPE, PHASE_B_FORW_ACTIVE_FUND_ENERGY));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(fund_ForwardP3);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_ENERGY_TYPE, PHASE_C_FORW_ACTIVE_FUND_ENERGY));
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(fund_ReverseP1);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_ENERGY_TYPE, PHASE_A_REV_ACTIVE_FUND_ENERGY));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(fund_ReverseP2);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_ENERGY_TYPE, PHASE_B_REV_ACTIVE_FUND_ENERGY));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(fund_ReverseP3);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_ENERGY_TYPE, PHASE_C_REV_ACTIVE_FUND_ENERGY));
            break;
        case 2: 
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(fund_ForwardTotal);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_ENERGY_TYPE, TOTAL_FORW_ACTIVE_FUND_ENERGY));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(fund_ReverseTotal);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_ENERGY_TYPE, TOTAL_REV_ACTIVE_FUND_ENERGY));
            break;
        default:
            break;
    }
	return (currentEnergy4);
#endif
    
}
 
PhaseEnergy_Type harmonicEnergy(PhaseEnergy_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhaseEnergy_Type currentEnergy5;
    static uint8_t counter = 0;
    /**Set with the current state and phase**/
	currentEnergy5.phaseState = HARMONIC_ENERGY;
	currentEnergy5.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentEnergy5.phaseState = EXIT_ENERGY;
    }
    if(1 == PORTAbits.RA4)
    {
        currentEnergy5.phaseState = EXIT_ENERGY;
    }
    if(1 == PORTCbits.RC3)
    {
        counter++;
        LCDNokia_clear();
        if(counter > 2)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(harmonic_ForwardP1);
            //LCDNokia_printValue(ATM_registers(HARMONIC_ENERGY_TYPE, PHASE_A_FORW_ACTIVE_HARM_ENERGY));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(harmonic_ForwardP2);
            //LCDNokia_printValue(ATM_registers(HARMONIC_ENERGY_TYPE, PHASE_B_FORW_ACTIVE_HARM_ENERGY));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(harmonic_ForwardP3);
            //LCDNokia_printValue(ATM_registers(HARMONIC_ENERGY_TYPE, PHASE_C_FORW_ACTIVE_HARM_ENERGY));
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(harmonic_ReverseP1);
            //LCDNokia_printValue(ATM_registers(HARMONIC_ENERGY_TYPE, PHASE_A_REV_ACTIVE_HARM_ENERGY));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(harmonic_ReverseP2);
            //LCDNokia_printValue(ATM_registers(HARMONIC_ENERGY_TYPE, PHASE_B_REV_ACTIVE_HARM_ENERGY));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(harmonic_ReverseP3);
            //LCDNokia_printValue(ATM_registers(HARMONIC_ENERGY_TYPE, PHASE_C_REV_ACTIVE_HARM_ENERGY));
            break;
        case 2: 
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(harmonic_ForwardTotal);
            //LCDNokia_printValue(ATM_registers(HARMONIC_ENERGY_TYPE, TOTAL_FORW_ACTIVE_HARM_ENERGY));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(harmonic_ReverseTotal);
            //LCDNokia_printValue(ATM_registers(HARMONIC_ENERGY_TYPE, TOTAL_REV_ACTIVE_HARM_ENERGY));
            break;
        default:
            break;
    }
	return (currentEnergy5);
#endif
}

PhaseEnergy_Type exitEnergy(PhaseEnergy_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhaseEnergy_Type currentEnergy6;
    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentEnergy6.phaseState = VIEW_MENU;
	currentEnergy6.stateMain = MAIN_MENU;
	return (currentEnergy6);
#endif
}

PhasePower1_Type typesPower1(PhasePower1_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhasePower1_Type currentPower1_1;
    static uint8_t counter = 0;
    /**Set with the current state and phase**/
	currentPower1_1.phaseState = TYPES_POWER1;
	currentPower1_1.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentPower1_1.phaseState = EXIT_POWER1;
    }
    if(1 == PORTAbits.RA4)
    {
        currentPower1_1.phaseState = PHASES_POWER1;
        LCDNokia_clear();
    }
    if(1 == PORTCbits.RC3)
    {
        counter++;
        LCDNokia_clear();
        if(counter > 2)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(active_powerP1);
            //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, PHASE_A_ACTIVE_POWER));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(active_powerP2);
            //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, PHASE_B_ACTIVE_POWER));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(active_powerP3);
            //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, PHASE_C_ACTIVE_POWER));
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(reactive_powerP1);
            //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, PHASE_A_REACTIVE_POWER));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(reactive_powerP2);
            //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, PHASE_B_REACTIVE_POWER));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(reactive_powerP3);
            //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, PHASE_C_REACTIVE_POWER));
            break;
        case 2: 
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(apparent_powerP1);
            //LCDNokia_printValue(ATM_registers(APPARENT_POWER_TYPE, PHASE_A_APPARENT_POWER));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(apparent_powerP2);
            //LCDNokia_printValue(ATM_registers(APPARENT_POWER_TYPE, PHASE_B_APPARENT_POWER));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(apparent_powerP3);
            //LCDNokia_printValue(ATM_registers(APPARENT_POWER_TYPE, PHASE_C_APPARENT_POWER));
            break;
        default:
            break;
    }
	return (currentPower1_1);
#endif
}

PhasePower1_Type phPower1(PhasePower1_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhasePower1_Type currentPower1_2;
    /**Set with the current state and phase**/
	currentPower1_2.phaseState = PHASES_POWER1;
	currentPower1_2.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentPower1_2.phaseState = EXIT_POWER1;
    }
    if(1 == PORTAbits.RA4)
    {
        currentPower1_2.phaseState = EXIT_POWER1;
        LCDNokia_clear();
    }

    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(total_active_power);
    //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, TOTAL_ACTIVE_POWER));
    LCDNokia_gotoXY(0,2);
    LCDNokia_sendString(total_reactive_power);
    //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, TOTAL_REACTIVE_POWER));
    LCDNokia_gotoXY(0,3);
    LCDNokia_sendString(total_apparent_power);
    //LCDNokia_printValue(ATM_registers(APPARENT_POWER_TYPE, TOTAL_APPARENT_POWER));
	return (currentPower1_2);
#endif
}

PhasePower1_Type exitPower1(PhasePower1_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhasePower1_Type currentPower1_4;
    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentPower1_4.phaseState = data.phaseState;
	currentPower1_4.stateMain = data.stateMain;
	return (currentPower1_4);
#endif
}

PhasePower2_Type fhPower2(PhasePower2_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhasePower2_Type currentPower2_1;
    static uint8_t counter = 0;
    /**Set with the current state and phase**/
	currentPower2_1.phaseState = FH_POWER2;
	currentPower2_1.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentPower2_1.phaseState = EXIT_POWER2;
    }
    if(1 == PORTAbits.RA4)
    {
        currentPower2_1.phaseState = PHASES_POWER2;
        LCDNokia_clear();
    }
    if(1 == PORTCbits.RC3)
    {
        counter++;
        LCDNokia_clear();
        if(counter > 1)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(fundamental_PowerP1);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_POWER, PHASE_A_ACTIVE_FUND_POWER));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(fundamental_PowerP2);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_POWER, PHASE_B_ACTIVE_FUND_POWER));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(fundamental_PowerP3);
            //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_POWER, PHASE_C_ACTIVE_FUND_POWER));
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(harmonic_PowerP1);
            //LCDNokia_printValue(ATM_registers(HARMONIC_POWER, PHASE_A_ACTIVE_HARM_POWER));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(harmonic_PowerP2);
            //LCDNokia_printValue(ATM_registers(HARMONIC_POWER, PHASE_B_ACTIVE_HARM_POWER));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(harmonic_PowerP3);
            //LCDNokia_printValue(ATM_registers(HARMONIC_POWER, PHASE_C_ACTIVE_HARM_POWER));
            break;
        default:
            break;
    }
	return (currentPower2_1);
#endif
}

PhasePower2_Type phPower2(PhasePower2_Type data)
{    
#if 0
    /**Create the variable with current data**/
	static PhasePower2_Type currentPower2_2;

	/**Set with the current state and phase**/
	currentPower2_2.phaseState = PHASES_POWER2;
	currentPower2_2.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentPower2_2.phaseState = EXIT_POWER2;
    }
    if(1 == PORTAbits.RA4)
    {
        currentPower2_2.phaseState = EXIT_POWER2;
    }
    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(fundamental_Total_Power);
    //LCDNokia_printValue(ATM_registers(FUNDAMENTAL_POWER, TOTAL_ACTIVE_FUND_POWER));
    LCDNokia_gotoXY(0,2);
    LCDNokia_sendString(harmonic_Total_Power);
    //LCDNokia_printValue(ATM_registers(HARMONIC_POWER, TOTAL_ACTIVE_HARM_POWER));
	return (currentPower2_2);
#endif
}

PhasePower2_Type exitPower2(PhasePower2_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhasePower2_Type currentPower2_3;
    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentPower2_3.phaseState = data.phaseState;
	currentPower2_3.stateMain = data.stateMain;
	return (currentPower2_3);
#endif
}

PhaseRmsVI_Type phRmsVI(PhaseRmsVI_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhaseRmsVI_Type currentRms1;
    static uint8_t counter = 0;
    /**Set with the current state and phase**/
	currentRms1.phaseState = PHASES_RMSVI;
	currentRms1.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentRms1.phaseState = EXIT_RMSVI;
    }
    if(1 == PORTAbits.RA4)
    {
        currentRms1.phaseState = NEUTRAL_RMSVI;
        LCDNokia_clear();
    }
    if(1 == PORTCbits.RC3)
    {
        counter++;
        LCDNokia_clear();
        if(counter > 1)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(voltage1_RMS);
            //LCDNokia_printValue(ATM_registers(VOLTAGE_RMS, PHASE_A_VOLTAGE_RMS));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(voltage2_RMS);
            //LCDNokia_printValue(ATM_registers(VOLTAGE_RMS, PHASE_B_VOLTAGE_RMS));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(voltage3_RMS);
            //LCDNokia_printValue(ATM_registers(VOLTAGE_RMS, PHASE_C_VOLTAGE_RMS));
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(current1_RMS);
            //LCDNokia_printValue(ATM_registers(CURRENT_RMS, PHASE_A_CURRENT_RMS));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(current2_RMS);
            //LCDNokia_printValue(ATM_registers(CURRENT_RMS, PHASE_B_CURRENT_RMS));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(current3_RMS);
            //LCDNokia_printValue(ATM_registers(CURRENT_RMS, PHASE_C_CURRENT_RMS));
            break;
        default:
            break;
    }
	return (currentRms1);
#endif
}

PhaseRmsVI_Type neutralRmsVI(PhaseRmsVI_Type data)
{
    /**Create the variable with current data**/
	static PhaseRmsVI_Type currentRms2;
#if 0
    /**Set with the current state and phase**/
	currentRms2.phaseState = NEUTRAL_RMSVI;
	currentRms2.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
       currentRms2.phaseState = EXIT_RMSVI;
       
    }
    if(1 == PORTAbits.RA4)
    {
       currentRms2.phaseState = EXIT_RMSVI;
    }
    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(nline_calculated_RMS);
    //LCDNokia_printValue(ATM_registers(CURRENT_RMS, NLINE_CALCULATED_CURRENT_RMS));
    LCDNokia_gotoXY(0,2);
    LCDNokia_sendString(nline_sampled_RMS);
    //LCDNokia_printValue(ATM_registers(CURRENT_RMS, NLINE_SAMPLED_CURRENT_RMS));
#endif
	return (currentRms2);
}

PhaseRmsVI_Type exitRmsVI(PhaseRmsVI_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhaseRmsVI_Type currentRms3;
    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentRms3.phaseState = data.phaseState;
	currentRms3.stateMain = data.stateMain;
	return (currentRms3);
#endif
}

PhasePowerFactor_Type phPowerFactor(PhasePowerFactor_Type data)
{
    /**Create the variable with current data**/
	static PhasePowerFactor_Type currentPowerFactor1;
#if 0
    static uint8_t counter = 0;

	/**Set with the current state and phase**/
	currentPowerFactor1.phaseState = PHASES_PF;
	currentPowerFactor1.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentPowerFactor1.phaseState = EXIT_PF;
    }
    if(1 == PORTAbits.RA4)
    {
        currentPowerFactor1.phaseState = EXIT_PF;
    }
    if(1 == PORTCbits.RC3)
    {
        counter++;
        LCDNokia_clear();
        if(counter > 1)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(factor_powerP1);
            //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, PHASE_A_POWER_FACTOR));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(factor_powerP2);
            //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, PHASE_B_POWER_FACTOR));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(factor_powerP3);
            //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, PHASE_C_POWER_FACTOR));
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(total_factor_power);
            //LCDNokia_printValue(ATM_registers(POWER_FACTOR_TYPE, TOTAL_POWER_FACTOR));
            break;
        default:
            break;
    }
#endif
	return (currentPowerFactor1);
}

PhasePowerFactor_Type exitPowerFactor(PhasePowerFactor_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhasePowerFactor_Type currentPowerFactor2;
    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentPowerFactor2.phaseState = data.phaseState;
	currentPowerFactor2.stateMain = data.stateMain;
	return (currentPowerFactor2);
#endif
}

PhasePhaseAngle_Type phPhaseAngle(PhasePhaseAngle_Type data)
{
    /**Create the variable with current data**/
	static PhasePhaseAngle_Type currentPhaseAngle1;
#if 0
    /**Set with the current state and phase**/
	currentPhaseAngle1.phaseState = PHASES_PA;
	currentPhaseAngle1.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentPhaseAngle1.phaseState = EXIT_PA;
    }
    if(1 == PORTAbits.RA4)
    {
        currentPhaseAngle1.phaseState = VI_PA;
        LCDNokia_clear();
    }

    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(anglePhase1);
    //LCDNokia_printValue(ATM_registers(PHASE_ANGLE_TYPE, PHASE_A_MEAN_ANGLE_PHASE));
    LCDNokia_gotoXY(0,2);
    LCDNokia_sendString(anglePhase2);
    //LCDNokia_printValue(ATM_registers(PHASE_ANGLE_TYPE, PHASE_B_MEAN_ANGLE_PHASE));
    LCDNokia_gotoXY(0,3);
    LCDNokia_sendString(anglePhase3);
    //LCDNokia_printValue(ATM_registers(PHASE_ANGLE_TYPE, PHASE_C_MEAN_ANGLE_PHASE));
#endif
	return (currentPhaseAngle1);
}

PhasePhaseAngle_Type viPhaseAngle(PhasePhaseAngle_Type data)
{
    /**Create the variable with current data**/
	static PhasePhaseAngle_Type currentPhaseAngle2;
#if 0
    
    /**Set with the current state and phase**/
	currentPhaseAngle2.phaseState = VI_PA;
	currentPhaseAngle2.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentPhaseAngle2.phaseState = EXIT_PA;
    }
    if(1 == PORTAbits.RA4)
    {
       	currentPhaseAngle2.phaseState = THDN_PA;
        LCDNokia_clear();
    }
    
    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(angle_VoltageP1);
    //LCDNokia_printValue(ATM_registers(PHASE_ANGLE_TYPE, PHASE_A_VOLTAGE_ANGLE_PHASE));
    LCDNokia_gotoXY(0,2);
    LCDNokia_sendString(angle_VoltageP2);
    //LCDNokia_printValue(ATM_registers(PHASE_ANGLE_TYPE, PHASE_B_VOLTAGE_ANGLE_PHASE));
    LCDNokia_gotoXY(0,3);
    LCDNokia_sendString(angle_VoltageP3);
    //LCDNokia_printValue(ATM_registers(PHASE_ANGLE_TYPE, PHASE_C_VOLTAGE_ANGLE_PHASE));
#endif
	return (currentPhaseAngle2); 
}

PhasePhaseAngle_Type THDNPhaseAngle(PhasePhaseAngle_Type data)
{
    /**Create the variable with current data**/
	static PhasePhaseAngle_Type currentPhaseAngle3;
#if 0
    static uint8_t counter = 0;
    
    /**Set with the current state and phase**/
	currentPhaseAngle3.phaseState = THDN_PA;
	currentPhaseAngle3.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentPhaseAngle3.phaseState = EXIT_PA;

    }
    if(1 == PORTAbits.RA4)
    {
       	currentPhaseAngle3.phaseState = EXIT_PA;  
    }
    if(1 == PORTCbits.RC3)
    {
        counter++;
        LCDNokia_clear();
        if(counter > 1)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(voltage1_THDN);
            //LCDNokia_printValue(ATM_registers(PHASE_ANGLE_TYPE, PHASE_A_VOLTAGE_ANGLE_PHASE));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(voltage2_THDN);
            //LCDNokia_printValue(ATM_registers(PHASE_ANGLE_TYPE, PHASE_B_VOLTAGE_ANGLE_PHASE));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(voltage3_THDN);
            //LCDNokia_printValue(ATM_registers(PHASE_ANGLE_TYPE, PHASE_C_VOLTAGE_ANGLE_PHASE));
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(current1_THDN);
            //LCDNokia_printValue(ATM_registers(THDN_TYPE, PHASE_A_CURRENT_THDN));
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(current2_THDN);
            //LCDNokia_printValue(ATM_registers(THDN_TYPE, PHASE_B_CURRENT_THDN));
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(current3_THDN);
            //LCDNokia_printValue(ATM_registers(THDN_TYPE, PHASE_C_CURRENT_THDN));
            break;
        default:
            break;
    }
#endif
    return (currentPhaseAngle3);
}

PhasePhaseAngle_Type exitPhaseAngle(PhasePhaseAngle_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhasePhaseAngle_Type currentPhaseAngle3;

    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentPhaseAngle3.phaseState = data.phaseState;
	currentPhaseAngle3.stateMain = data.stateMain;

	return (currentPhaseAngle3);   
#endif
}

PhaseFreqTemp_Type showFreqTemp(PhaseFreqTemp_Type data)
{
    /**Create the variable with current data**/
	static PhaseFreqTemp_Type currentFreqTemp1;
#if 0
	/**Set with the current state and phase**/
	currentFrequency1.phaseState = SHOW_FREQTEMP;
	currentFrequency1.stateMain = data.stateMain;
    
    if(1 == PORTAbits.RA3)
    {
        currentFreqTemp1.phaseState = EXIT_FREQTEMP;
    }
    if(1 == PORTAbits.RA4)
    {
        currentFreqTemp1.phaseState = EXIT_FREQTEMP;
    }
    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(frequency);
    //LCDNokia_printValue(ATM_registers(FREQUENCY_TYPE, FREQUENCY_REG));
    LCDNokia_gotoXY(1,1);
    LCDNokia_sendString(temperature);
    //LCDNokia_printValue(ATM_registers(TEMPERATURE_TYPE, TEMPERATURE_REG));
#endif
	return (currentFreqTemp1);
}

PhaseFreqTemp_Type exitFreqTemp(PhaseFreqTemp_Type data)
{
#if 0
    /**Create the variable with current data**/
	static PhaseFreqTemp_Type currentFreqTemp2;

    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentFreqTemp2.phaseState = data.phaseState;
	currentFreqTemp2.stateMain = data.stateMain;

	return (currentFreqTemp2);
#endif
}
