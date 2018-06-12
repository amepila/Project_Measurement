#include <xc.h>
#include "Phases.h"

/**Settings of SPI**/
const SPI_ConfigType SPI_Config = 
{
	SPI_LOW_POLARITY,	/**Low Polarity to SPI**/
	SPI_LOW_PHASE,		/**Low Phase to SPI**/
	SPI_SERIAL_CLK16     /**FOsc divided by 4**/
};

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
    const uint8_t msgInitial1[] = "Three Phase";
    const uint8_t msgInitial2[] = "Measurement";
    const uint8_t buttonRight[] = "Send";
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
    const uint8_t maxScreens = 7;
    const uint8_t string_Energy[] = "Energy";
    
    const uint8_t string1_Power1[] = "Active Reactive";
    const uint8_t string2_Power1[] = "Apparent Power";
    
    const uint8_t string1_Power2[] = "Fundamental";
    const uint8_t string2_Power2[] = "Harmonic";
    const uint8_t string3_Power2[] = "Power";

    const uint8_t string1_RMS[] = "Voltage Current";
    const uint8_t string2_RMS[] = "RMS";
    
    const uint8_t string1_PowerFactor[] = "Power";
    const uint8_t string2_PowerFactor[] = "Factor";
    
    const uint8_t string1_PhaseAngle[] = "Phase";
    const uint8_t string2_PhaseAngle[] = "Angle";
    
    const uint8_t string1_Frequency[] = "Frequency";
    
    const uint8_t string1_Temperature[] = "Temperature";
    
    const uint8_t buttonRight[] = "R";
    const uint8_t buttonCenter[] = "E";
    const uint8_t buttonLeft[] = "L";
    
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
                LCDNokia_sendString(string_Energy);
                break;
            case 1:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_Power1);
    
                LCDNokia_gotoXY(0,2);
                LCDNokia_sendString(string2_Power1);
                break;
            case 2:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_Power2);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_Power2);
                
                LCDNokia_gotoXY(15,3);
                LCDNokia_sendString(string3_Power2);
                break;
            case 3:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_RMS);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_RMS);
                break;
            case 4:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_PowerFactor);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_PowerFactor);
                break;
            case 5:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_PhaseAngle);
    
                LCDNokia_gotoXY(15,2);
                LCDNokia_sendString(string2_PhaseAngle);
                break;
            case 6:
                LCDNokia_gotoXY(15,1);
                LCDNokia_sendString(string1_Frequency);
                break;
            case 7:
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
            counterMenu = maxScreens;
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
            case 6:
                currentMainMenu3.phaseState = SHOW_FREQUENCY;
                currentMainMenu3.stateMain = FREQUENCY;
                break;
            case 7:
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
        if(counterMenu > maxScreens)
        {
            counterMenu = 0;
        }
        lockClear = 0;
        lockWrite = 0;
    }

	return (currentMainMenu3);
}

PhaseMainMenu_Type sendData(PhaseMainMenu_Type data)
{
    const uint8_t title1[] = "THREE PHASE\r\n";
    const uint8_t title2[] = "MEASUREMENT\r\n";
    
    const uint8_t watts[] = "\t W\r\n";
    const uint8_t joules[] = "\t J\r\n";
    const uint8_t voltage[] = "\t V\r\n";
    const uint8_t current[] = "\t A\r\n";
    const uint8_t centigrades[] = "\t C\n";
    const uint8_t hertz[] = "\t H\n";
    const uint8_t grades[] = "\t G\n";

    const uint8_t subtitle_1[] = "Active/Reactive/Apparent Energy\r\n";
    
    const uint8_t active_fp1[] = "Phase A Forward Active Energy = \t";
    const uint8_t active_fp2[] = "Phase B Forward Active Energy = \t";
    const uint8_t active_fp3[] = "Phase C Forward Active Energy = \t";
    const uint8_t active_fTotal[] = "Total Forward Active Energy = \t";
    
    const uint8_t active_rp1[] = "Phase A Reverse Active Energy = \t";
    const uint8_t active_rp2[] = "Phase B Reverse Active Energy = \t";
    const uint8_t active_rp3[] = "Phase C Reverse Active Energy = \t";
    const uint8_t active_rTotal[] = "Total Reverse Active Energy = \t";
    
    const uint8_t reactive_fp1[] = "Phase A Forward Reactive Energy = \t";
    const uint8_t reactive_fp2[] = "Phase B Forward Reactive Energy = \t";
    const uint8_t reactive_fp3[] = "Phase C Forward Reactive Energy = \t";
    const uint8_t reactive_fTotal[] = "Total Forward Reactive Energy = \t";
    
    const uint8_t reactive_rp1[] = "Phase A Reverse Reactive Energy = \t";
    const uint8_t reactive_rp2[] = "Phase B Reverse Reactive Energy = \t";
    const uint8_t reactive_rp3[] = "Phase C ReverseReactive Energy = \t";
    const uint8_t reactive_rTotal[] = "Total Reverse Reactive Energy = \t";
    
    const uint8_t apparent_energyP1[] = "Phase A Apparent Energy = \t";
    const uint8_t apparent_energyP2[] = "Phase B Apparent Energy = \t";
    const uint8_t apparent_energyP3[] = "Phase C Apparent Energy = \t";
    
    const uint8_t apparentAri_energyTotal[] = "Total Aritmetic Apparent Energy = \t";
    const uint8_t apparentVec_energyTotal[] = "Total Vector Apparent Energy = \t";
    const uint8_t apparentVec_powerTotal[] = "Total Vector Apparent Energy = \t";

    const uint8_t subtitle_2[] = "Fundamental/Harmonic Energy\r\t";
    
    const uint8_t activeF_fp1[] = "Phase A Forward Active Fundamental Energy = \t";
    const uint8_t activeF_fp2[] = "Phase B Forward Active Fundamental Energy = \t";
    const uint8_t activeF_fp3[] = "Phase C Forward Active Fundamental Energy = \t";
    const uint8_t activeF_fTotal[] = "Total Forward Active Fundamental Energy = \t";
    
    const uint8_t activeF_rp1[] = "Phase A Reverse Active Fundamental Energy = \t";
    const uint8_t activeF_rp2[] = "Phase B Reverse Active Fundamental Energy = \t";
    const uint8_t activeF_rp3[] = "Phase C Reverse Active Fundamental Energy = \t";
    const uint8_t activeF_rTotal[] = "Total Reverse Active Fundamental Energy = \t";
   
    const uint8_t activeH_fp1[] = "Phase A Forward Active Harmonic Energy = \t";
    const uint8_t activeH_fp2[] = "Phase B Forward Active Harmonic Energy = \t";
    const uint8_t activeH_fp3[] = "Phase C Forward Active Harmonic Energy = \t";
    const uint8_t activeH_fTotal[] = "Total Forward Active Harmonic Energy = \t";
    
    const uint8_t activeH_rp1[] = "Phase A Reverse Active Harmonic Energy = \t";
    const uint8_t activeH_rp2[] = "Phase B Reverse Active Harmonic Energy = \t";
    const uint8_t activeH_rp3[] = "Phase C Reverse Active Harmonic Energy = \t";
    const uint8_t activeH_rTotal[] = "Total Reverse Active Harmonic Energy = \t";
    
    const uint8_t subtitle_3[] = "Power and Power Factor = \r\t";
    
    const uint8_t active_powerP1[] = "Phase A Active Power = \t";
    const uint8_t active_powerP2[] = "Phase B Active Power = \t";
    const uint8_t active_powerP3[] = "Phase C Active Power = \t";
    const uint8_t total_active_power[] = "Total Active Power = \t";

    const uint8_t reactive_powerP1[] = "Phase A Reactive Power = \t";
    const uint8_t reactive_powerP2[] = "Phase B Reactive Power = \t";
    const uint8_t reactive_powerP3[] = "Phase C Reactive Power = \t";
    const uint8_t total_reactive_power[] = "Total Reactive Power = \t";
    
    const uint8_t apparent_powerP1[] = "Phase A Apparent Power = \t";
    const uint8_t apparent_powerP2[] = "Phase B Apparent Power = \t";
    const uint8_t apparent_powerP3[] = "Phase C Apparent Power = \t";
    const uint8_t total_apparent_power[] = "Total Apparent Power = \t";

    const uint8_t factor_powerP1[] = "Phase A Power Factor = \t";
    const uint8_t factor_powerP2[] = "Phase B Power Factor = \t";
    const uint8_t factor_powerP3[] = "Phase C Power Factor = \t";
    const uint8_t total_factor_power[] = "Total Factor Power Factor = \t";
    
    const uint8_t subtitle_4[] = "Fundamental/Harmonic Power = \r\n";
    
    const uint8_t activeF_powerP1[] = "Phase A Active Fundamental Power = \t";
    const uint8_t activeF_powerP2[] = "Phase B Active Fundamental Power = \t";
    const uint8_t activeF_powerP3[] = "Phase C Active Fundamental Power = \t";
    const uint8_t activeF_Total_Power[] = "Total Active Fundamental Power = \t";
 
    const uint8_t activeH_powerP1[] = "Phase A Active Harmonic Power = \t";
    const uint8_t activeH_powerP2[] = "Phase B Active Harmonic Power = \t";
    const uint8_t activeH_powerP3[] = "Phase C Active Harmonic Power = \t";
    const uint8_t activeH_Total_Power[] = "Total Active Harmonic Power = \t";
    
    const uint8_t subtitle_5[] = "Voltage/Current RMS = \r\n";
    
    const uint8_t voltage1_RMS[] = "Phase A Voltage RMS = \t";
    const uint8_t voltage2_RMS[] = "Phase B Voltage RMS = \t";
    const uint8_t voltage3_RMS[] = "Phase C Voltage RMS = \t";

    const uint8_t current1_RMS[] = "Phase A Current RMS = \t";
    const uint8_t current2_RMS[] = "Phase B Current RMS = \t";
    const uint8_t current3_RMS[] = "Phase C Current RMS = \t";
    
    const uint8_t nline_calculated_RMS[] = "N Line Calculated Current RMS = \t";
    const uint8_t nline_sampled_RMS[] = "N Line Sampled Current RMS = \t";

    const uint8_t subtitle_6[] = "THD+N/Frequency/Angle/Temperature RMS = \r\n";

    const uint8_t voltage1_THDN[] = "Phase A Voltage THD+N = \t";
    const uint8_t voltage2_THDN[] = "Phase B Voltage THD+N = \t";
    const uint8_t voltage3_THDN[] = "Phase C Voltage THD+N = \t";

    const uint8_t current1_THDN[] = "Phase A Current THD+N = \t";
    const uint8_t current2_THDN[] = "Phase B Current THD+N = \t";
    const uint8_t current3_THDN[] = "Phase C Current THD+N = \t";
    
    const uint8_t frequency[] = "Frequency = \t";
    
    const uint8_t anglePhase1[] = "Phase A mean phase angle = \t";
    const uint8_t anglePhase2[] = "Phase B mean phase angle = \t";
    const uint8_t anglePhase3[] = "Phase C mean phase angle = \t";

    const uint8_t temperature[] = "Temperature = \t";
    
    const uint8_t angle_VoltageP1[] = "Phase A Voltage Phase Angle = \t";
    const uint8_t angle_VoltageP2[] = "Phase B Voltage Phase Angle = \t";
    const uint8_t angle_VoltageP3[] = "Phase C Voltage Phase Angle = \t";
    
	/**Create the variable with current data**/
	static PhaseMainMenu_Type currentMainMenu4;

    /**Confiuration of Bluetooth*/
    UART_init(BD_9600);
    
    UART_putString(title1);
    UART_putString(title2);
    
    UART_putString(subtitle_1);
    
    UART_putString(active_fp1);
    UART_putString(joules);
    UART_putString(active_fp2);
    UART_putString(joules);
    UART_putString(active_fp3);
    UART_putString(joules);
    UART_putString(active_fTotal);
    UART_putString(joules);

    UART_putString(active_rp1);
    UART_putString(joules);
    UART_putString(active_rp2);
    UART_putString(joules);    
    UART_putString(active_rp3);
    UART_putString(joules);
    UART_putString(active_rTotal);
    UART_putString(joules);
    
    UART_putString(reactive_fp1);
    UART_putString(joules);
    UART_putString(reactive_fp2);
    UART_putString(joules);
    UART_putString(reactive_fp3);
    UART_putString(joules);
    UART_putString(reactive_fTotal);
    UART_putString(joules);
    
    UART_putString(reactive_rp1);
    UART_putString(joules);
    UART_putString(reactive_rp2);
    UART_putString(joules);
    UART_putString(reactive_rp3);
    UART_putString(joules);
    UART_putString(reactive_rTotal);
    UART_putString(joules);
    
    UART_putString(apparent_energyP1);
    UART_putString(joules);
    UART_putString(apparent_energyP2);
    UART_putString(joules);
    UART_putString(apparent_energyP3);
    UART_putString(joules);

    UART_putString(apparentAri_energyTotal);
    UART_putString(joules);
    UART_putString(apparentVec_energyTotal);
    UART_putString(joules);
    UART_putString(apparentVec_powerTotal);
    UART_putString(joules);
    
    UART_putString(subtitle_2);

    UART_putString(activeF_fp1);
    UART_putString(joules);
    UART_putString(activeF_fp2);
    UART_putString(joules);
    UART_putString(activeF_fp3);    
    UART_putString(joules);
    UART_putString(activeF_fTotal);
    UART_putString(joules);

    UART_putString(activeF_rp1);
    UART_putString(joules);
    UART_putString(activeF_rp2);
    UART_putString(joules);
    UART_putString(activeF_rp3);   
    UART_putString(joules);
    UART_putString(activeF_rTotal);
    UART_putString(joules);

    UART_putString(activeH_fp1);
    UART_putString(joules);
    UART_putString(activeH_fp2);
    UART_putString(joules);
    UART_putString(activeH_fp3);
    UART_putString(joules);
    UART_putString(activeH_fTotal);
    UART_putString(joules);

    UART_putString(activeH_rp1);
    UART_putString(joules);
    UART_putString(activeH_rp2);
    UART_putString(joules);
    UART_putString(activeH_rp3);
    UART_putString(joules);
    UART_putString(activeH_rTotal);
    UART_putString(joules);

    UART_putString(subtitle_3);
    
    UART_putString(active_powerP1);
    UART_putString(watts);
    UART_putString(active_powerP2);
    UART_putString(watts);
    UART_putString(active_powerP3);
    UART_putString(watts);
    UART_putString(total_active_power);
    UART_putString(watts);

    UART_putString(reactive_powerP1);
    UART_putString(watts);
    UART_putString(reactive_powerP2);
    UART_putString(watts);
    UART_putString(reactive_powerP3);
    UART_putString(watts);
    UART_putString(total_reactive_power);
    UART_putString(watts);

    UART_putString(apparent_powerP1);
    UART_putString(watts);
    UART_putString(apparent_powerP2); 
    UART_putString(watts);
    UART_putString(apparent_powerP3);
    UART_putString(watts);
    UART_putString(total_apparent_power);
    UART_putString(watts);

    UART_putString(factor_powerP1);
    UART_putString(watts);
    UART_putString(factor_powerP2);  
    UART_putString(watts);
    UART_putString(factor_powerP3);
    UART_putString(watts);
    UART_putString(total_factor_power);
    UART_putString(watts);
    
    UART_putString(subtitle_4);
    
    UART_putString(activeF_powerP1);
    UART_putString(watts);
    UART_putString(activeF_powerP2);    
    UART_putString(watts);
    UART_putString(activeF_powerP3);
    UART_putString(watts);
    UART_putString(activeF_Total_Power);
    UART_putString(watts);

    UART_putString(activeH_powerP1);
    UART_putString(watts);
    UART_putString(activeH_powerP2); 
    UART_putString(watts);
    UART_putString(activeH_powerP3);
    UART_putString(watts);
    UART_putString(activeH_Total_Power);
    UART_putString(watts);
    
    UART_putString(subtitle_5);

    UART_putString(voltage1_RMS);
    UART_putString(voltage);
    UART_putString(voltage2_RMS);
    UART_putString(voltage);
    UART_putString(voltage3_RMS);
    UART_putString(voltage);

    UART_putString(current1_RMS);
    UART_putString(current);
    UART_putString(current2_RMS);
    UART_putString(current);    
    UART_putString(current3_RMS);
    UART_putString(current);
    
    UART_putString(nline_calculated_RMS); 
    UART_putString(current);
    UART_putString(nline_sampled_RMS);
    UART_putString(current);

    UART_putString(subtitle_6);
    
    UART_putString(voltage1_THDN);
    UART_putString(voltage);
    UART_putString(voltage2_THDN);
    UART_putString(voltage);
    UART_putString(voltage3_THDN);
    UART_putString(voltage);

    UART_putString(current1_THDN);
    UART_putString(current);
    UART_putString(current2_THDN);  
    UART_putString(current);
    UART_putString(current3_THDN);
    UART_putString(current);

    UART_putString(frequency);
    UART_putString(hertz);
    
    UART_putString(anglePhase1);
    UART_putString(grades);
    UART_putString(anglePhase2); 
    UART_putString(grades);
    UART_putString(anglePhase3);
    UART_putString(grades);
    
    UART_putString(temperature);
    UART_putString(centigrades);
    
    UART_putString(angle_VoltageP1);
    UART_putString(grades);
    UART_putString(angle_VoltageP2);
    UART_putString(grades);
    UART_putString(angle_VoltageP3);
    UART_putString(grades);
    
	/**Set with the current state and phase**/
	currentMainMenu4.phaseState = GENERAL_VIEW;
    currentMainMenu4.stateMain = MAIN_MENU;

    /**Configurations of SPI**/
	SPI_init(&SPI_Config);
    LCDNokia_init();
	LCDNokia_clear();
    
	return (currentMainMenu4);
}

PhaseEnergy_Type activeEnergy(PhaseEnergy_Type data)
{
    static uint8_t counter = 0;
    const uint8_t maxScreens = 3;
    const uint8_t active_Forward1[] = "PA Forw Act: ";
    const uint8_t active_Forward2[] = "PB Forw Act: ";
    const uint8_t active_Forward3[] = "PC Forw Act: ";
    
    const uint8_t active_Reverse1[] = "PA Rev Act: ";
    const uint8_t active_Reverse2[] = "PB Rev Act: ";
    const uint8_t active_Reverse3[] = "PC Rev Act: ";
    
    const uint8_t active_Forward_Total[] = "Total Forw Act: ";
    const uint8_t active_Reverse_Total[] = "Total Rev Act: ";
    
    /**Create the variable with current data**/
	static PhasePower1_Type currentEnergy1;
    
    /**Set with the current state and phase**/
	currentEnergy1.phaseState = ACTIVE_ENERGY;
	currentEnergy1.stateMain = data.stateMain;

    if(getButton1() == 1)
    {
        currentEnergy1.phaseState = EXIT_ENERGY;
    }
    if(getButton2() == 1)
    {        
        currentEnergy1.phaseState = REACTIVE_ENERGY;
        LCDNokia_clear();
    }
    if(getButton3() == 1)
    {
        counter++;
        LCDNokia_clear();
        if(counter > maxScreens)
        {
            counter = 0;
        }
    }  
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(active_Forward1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(active_Forward2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(active_Forward3);
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(active_Reverse1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(active_Reverse2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(active_Reverse3);
            break;
        case 2:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(active_Forward_Total);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(active_Reverse_Total);
            break;
        default:
            break;
    }

	return (currentEnergy1);
}

PhaseEnergy_Type reactiveEnergy(PhaseEnergy_Type data)
{
    static uint8_t counter = 0;
    const uint8_t maxScreens = 3;
    const uint8_t reactive_Forward1[] = "PA Forw React: ";
    const uint8_t reactive_Forward2[] = "PB Forw Reac: ";
    const uint8_t reactive_Forward3[] = "PC Forw React: ";
    
    const uint8_t reactive_Reverse1[] = "PA Rev React: ";
    const uint8_t reactive_Reverse2[] = "PB Rev React: ";
    const uint8_t reactive_Reverse3[] = "PC Rev React: ";
    
    const uint8_t reactive_Forward_Total[] = "Total Forw React: ";
    const uint8_t reactive_Reverse_Total[] = "Total Rev React: ";
    
    /**Create the variable with current data**/
	static PhasePower1_Type currentEnergy2;
    
    /**Set with the current state and phase**/
	currentEnergy2.phaseState = REACTIVE_ENERGY;
	currentEnergy2.stateMain = data.stateMain;

    if(getButton1() == 1)
    {
        currentEnergy2.phaseState = EXIT_ENERGY;
    }
    if(getButton2() == 1)
    {
        currentEnergy2.phaseState = APPARENT_ENERGY;  
        LCDNokia_clear();
    }
    if(getButton3() == 1)
    {
        counter++;
        LCDNokia_clear();
        if(counter > maxScreens)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(reactive_Forward1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(reactive_Forward2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(reactive_Forward3);
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(reactive_Reverse1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(reactive_Reverse2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(reactive_Reverse3);
            break;
        case 2:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(reactive_Forward_Total);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(reactive_Reverse_Total);
            break;
        default:
            break;
    }

	return (currentEnergy2);
}

PhaseEnergy_Type apparentEnergy(PhaseEnergy_Type data)
{
    static uint8_t counter = 0;
    const uint8_t maxScreens = 1;
    const uint8_t apparent_energyP1[] = "PA App: ";
    const uint8_t apparent_energyP2[] = "PB App: ";
    const uint8_t apparent_energyP3[] = "PC App: ";
    
    const uint8_t apparentAri_energyTotal[] = "Total AriApp En: ";
    const uint8_t apparentVec_energyTotal[] = "Total VecApp En: ";
    const uint8_t apparentVec_powerTotal[] = "Total VectApp Pow: ";

    /**Create the variable with current data**/
	static PhasePower1_Type currentEnergy3;
    
    /**Set with the current state and phase**/
	currentEnergy3.phaseState = APPARENT_ENERGY;
	currentEnergy3.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentEnergy3.phaseState = EXIT_ENERGY;
    }
    if(getButton2() == 1)
    {
      	currentEnergy3.phaseState = FUNDAMENTAL_ENERGY;  
        LCDNokia_clear();
    }
    if(getButton3() == 1)
    {
        counter++;
        LCDNokia_clear();
        if(counter > maxScreens)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(apparent_energyP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(apparent_energyP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(apparent_energyP3);
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(apparentAri_energyTotal);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(apparentVec_energyTotal);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(apparentVec_powerTotal);
            break;
        default:
            break;
    }

	return (currentEnergy3);
}

PhaseEnergy_Type fundamentalEnergy(PhaseEnergy_Type data)
{
    static uint8_t counter = 0;
    const uint8_t maxScreens = 2;
    const uint8_t fund_ForwardP1[] = "PA ForwFund E: ";
    const uint8_t fund_ForwardP2[] = "PB ForwFund E: ";
    const uint8_t fund_ForwardP3[] = "PC ForwFund E: ";
    
    const uint8_t fund_ReverseP1[] = "PA RevFund E: ";
    const uint8_t fund_ReverseP2[] = "PB RevFund E: ";
    const uint8_t fund_ReverseP3[] = "PC RevFund E: ";
    
    const uint8_t fund_ForwardTotal[] = "Total ForwFund E: ";
    const uint8_t fund_ReverseTotal[] = "Total RevFund E: ";
   
    /**Create the variable with current data**/
	static PhasePower1_Type currentEnergy4;
    
    /**Set with the current state and phase**/
	currentEnergy4.phaseState = FUNDAMENTAL_ENERGY;
	currentEnergy4.stateMain = data.stateMain;

    if(getButton1() == 1)
    {
        currentEnergy4.phaseState = EXIT_ENERGY;
    }
    if(getButton2() == 1)
    {
        currentEnergy4.phaseState = HARMONIC_ENERGY;
        LCDNokia_clear();
    }
    if(getButton3() == 1)
    {
        counter++;
        LCDNokia_clear();
        if(counter > maxScreens)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(fund_ForwardP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(fund_ForwardP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(fund_ForwardP3);
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(fund_ReverseP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(fund_ReverseP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(fund_ReverseP3);
            break;
        case 2: 
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(fund_ForwardTotal);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(fund_ReverseTotal);
            break;
        default:
            break;
    }

	return (currentEnergy4);
}
 
PhaseEnergy_Type harmonicEnergy(PhaseEnergy_Type data)
{
    static uint8_t counter = 0;
    const uint8_t maxScreens = 2;
    const uint8_t harmonic_ForwardP1[] = "PA ForwHE: ";
    const uint8_t harmonic_ForwardP2[] = "PB ForwHE: ";
    const uint8_t harmonic_ForwardP3[] = "PC ForwHE: ";
    
    const uint8_t harmonic_ReverseP1[] = "PA RevHE: ";
    const uint8_t harmonic_ReverseP2[] = "PB RevHE: ";
    const uint8_t harmonic_ReverseP3[] = "PC RevHE: ";
  
    const uint8_t harmonic_ForwardTotal[] = "Total ForwHE: ";
    const uint8_t harmonic_ReverseTotal[] = "Total RevHE: ";

    /**Create the variable with current data**/
	static PhasePower1_Type currentEnergy5;

    /**Set with the current state and phase**/
	currentEnergy5.phaseState = HARMONIC_ENERGY;
	currentEnergy5.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentEnergy5.phaseState = EXIT_ENERGY;
    }
    if(getButton2() == 1)
    {
        currentEnergy5.phaseState = EXIT_ENERGY;
    }
    if(getButton3() == 1)
    {
        counter++;
        LCDNokia_clear();
        if(counter > maxScreens)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(harmonic_ForwardP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(harmonic_ForwardP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(harmonic_ForwardP3);
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(harmonic_ReverseP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(harmonic_ReverseP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(harmonic_ReverseP3);
            break;
        case 2: 
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(harmonic_ForwardTotal);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(harmonic_ReverseTotal);
            break;
        default:
            break;
    }
	return (currentEnergy5);
}

PhaseEnergy_Type exitEnergy(PhaseEnergy_Type data)
{
    /**Create the variable with current data**/
	static PhasePower1_Type currentEnergy6;

    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentEnergy6.phaseState = VIEW_MENU;
	currentEnergy6.stateMain = MAIN_MENU;

	return (currentEnergy6);
}

PhasePower1_Type typesPower1(PhasePower1_Type data)
{
    static uint8_t counter = 0;
    const uint8_t maxScreens = 2;
    const uint8_t active_powerP1[] = "PA APow: ";
    const uint8_t active_powerP2[] = "PB APow: ";
    const uint8_t active_powerP3[] = "PC APow: ";;

    const uint8_t reactive_powerP1[] = "PA RPow: ";
    const uint8_t reactive_powerP2[] = "PB RPow: ";
    const uint8_t reactive_powerP3[] = "PC RPow: ";
    
    const uint8_t apparent_powerP1[] = "PA APPow: ";
    const uint8_t apparent_powerP2[] = "PB APPow: ";
    const uint8_t apparent_powerP3[] = "PC APPow: ";

    /**Create the variable with current data**/
	static PhasePower1_Type currentPower1_1;

    /**Set with the current state and phase**/
	currentPower1_1.phaseState = TYPES_POWER1;
	currentPower1_1.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentPower1_1.phaseState = EXIT_POWER1;
    }
    if(getButton2() == 1)
    {
        currentPower1_1.phaseState = PHASES_POWER1;
        LCDNokia_clear();
    }
    if(getButton3() == 1)
    {
        counter++;
        LCDNokia_clear();
        if(counter > maxScreens)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(active_powerP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(active_powerP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(active_powerP3);
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(reactive_powerP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(reactive_powerP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(reactive_powerP3);
            break;
        case 2: 
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(apparent_powerP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(apparent_powerP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(apparent_powerP3);
            break;
        default:
            break;
    }
	return (currentPower1_1);
}

PhasePower1_Type phPower1(PhasePower1_Type data)
{
    const uint8_t total_active_power[] = "Total APow: ";
    const uint8_t total_reactive_power[] = "Total RPow: ";
    const uint8_t total_apparent_power[] = "Total APPow: ";
    
    /**Create the variable with current data**/
	static PhasePower1_Type currentPower1_2;

    /**Set with the current state and phase**/
	currentPower1_2.phaseState = PHASES_POWER1;
	currentPower1_2.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentPower1_2.phaseState = EXIT_POWER1;
    }
    if(getButton2() == 1)
    {
        currentPower1_2.phaseState = VECTOR_POWER1;
        LCDNokia_clear();
    }

    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(total_active_power);
    LCDNokia_gotoXY(0,2);
    LCDNokia_sendString(total_reactive_power);
    LCDNokia_gotoXY(0,3);
    LCDNokia_sendString(total_apparent_power);

	return (currentPower1_2);
}

PhasePower1_Type exitPower1(PhasePower1_Type data)
{
    /**Create the variable with current data**/
	static PhasePower1_Type currentPower1_4;

    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentPower1_4.phaseState = data.phaseState;
	currentPower1_4.stateMain = data.stateMain;

	return (currentPower1_4);
}

PhasePower2_Type fhPower2(PhasePower2_Type data)
{
    static uint8_t counter = 0;
    const uint8_t maxScreens = 1;
    const uint8_t fundamental_PowerP1[] = "PA FPow: ";
    const uint8_t fundamental_PowerP2[] = "PB FPow: ";
    const uint8_t fundamental_PowerP3[] = "PC FPow: ";
 
    const uint8_t harmonic_PowerP1[] = "PA HPow: ";
    const uint8_t harmonic_PowerP2[] = "PB HPow: ";
    const uint8_t harmonic_PowerP3[] = "PC HPow: ";

    /**Create the variable with current data**/
	static PhasePower1_Type currentPower2_1;

    /**Set with the current state and phase**/
	currentPower2_1.phaseState = FH_POWER2;
	currentPower2_1.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentPower2_1.phaseState = EXIT_POWER2;
    }
    if(getButton2() == 1)
    {
        currentPower2_1.phaseState = PHASES_POWER2;
        LCDNokia_clear();
    }
    if(getButton3() == 1)
    {
        counter++;
        LCDNokia_clear();
        if(counter > maxScreens)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(fundamental_PowerP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(fundamental_PowerP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(fundamental_PowerP3);
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(harmonic_PowerP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(harmonic_PowerP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(harmonic_PowerP3);
            break;
        default:
            break;
    }
	return (currentPower2_1);
}

PhasePower2_Type phPower2(PhasePower2_Type data)
{    
    const uint8_t fundamental_Total_Power[] = "Total FPow: ";
    const uint8_t harmonic_Total_Power[] = "Total HPow: ";
  
    /**Create the variable with current data**/
	static PhasePower1_Type currentPower2_2;

	/**Set with the current state and phase**/
	currentPower2_2.phaseState = PHASES_POWER2;
	currentPower2_2.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentPower2_2.phaseState = EXIT_POWER2;
    }
    if(getButton2() == 1)
    {
        currentPower2_2.phaseState = EXIT_POWER2;
    }
    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(fundamental_Total_Power);
    LCDNokia_gotoXY(0,2);
    LCDNokia_sendString(harmonic_Total_Power);
    
	return (currentPower2_2);
}

PhasePower2_Type exitPower2(PhasePower2_Type data)
{
    /**Create the variable with current data**/
	static PhasePower2_Type currentPower2_3;

    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentPower2_3.phaseState = data.phaseState;
	currentPower2_3.stateMain = data.stateMain;

	return (currentPower2_3);
}

PhaseRmsVI_Type phRmsVI(PhaseRmsVI_Type data)
{
    static uint8_t counter = 0;
    const uint8_t maxScreens = 1;
    const uint8_t voltage1_RMS[] = "PA VRMS: ";
    const uint8_t voltage2_RMS[] = "PB VRMS: ";
    const uint8_t voltage3_RMS[] = "PC VRMS: ";

    const uint8_t current1_RMS[] = "PA CRMS: ";
    const uint8_t current2_RMS[] = "PB CRMS: ";
    const uint8_t current3_RMS[] = "PC CRMS: ";
    
    /**Create the variable with current data**/
	static PhasePower1_Type currentRms1;

    /**Set with the current state and phase**/
	currentRms1.phaseState = PHASES_RMSVI;
	currentRms1.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentRms1.phaseState = EXIT_RMSVI;
    }
    if(getButton2() == 1)
    {
        currentRms1.phaseState = NEUTRAL_RMSVI;
        LCDNokia_clear();
    }
    if(getButton3() == 1)
    {
        counter++;
        LCDNokia_clear();
        if(counter > maxScreens)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(voltage1_RMS);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(voltage2_RMS);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(voltage3_RMS);
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(current1_RMS);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(current2_RMS);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(current3_RMS);
            break;
        default:
            break;
    }
	return (currentRms1);
}

PhaseRmsVI_Type neutralRmsVI(PhaseRmsVI_Type data)
{
    const uint8_t nline_calculated_RMS[] = "N CalCRMS: ";
    const uint8_t nline_sampled_RMS[] = "N SamCRMS: ";

    /**Create the variable with current data**/
	static PhasePower1_Type currentRms2;

    /**Set with the current state and phase**/
	currentRms2.phaseState = NEUTRAL_RMSVI;
	currentRms2.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
       currentRms2.phaseState = EXIT_RMSVI;
       
    }
    if(getButton2() == 1)
    {
       currentRms2.phaseState = EXIT_RMSVI;
    }
    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(nline_calculated_RMS);
    LCDNokia_gotoXY(0,2);
    LCDNokia_sendString(nline_sampled_RMS);
    
	return (currentRms2);
}

PhaseRmsVI_Type exitRmsVI(PhaseRmsVI_Type data)
{
    /**Create the variable with current data**/
	static PhaseRmsVI_Type currentRms3;

    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentRms3.phaseState = data.phaseState;
	currentRms3.stateMain = data.stateMain;

	return (currentRms3);
}

PhasePowerFactor_Type phPowerFactor(PhasePowerFactor_Type data)
{
    static uint8_t counter = 0;
    const uint8_t maxScreens = 1;
    const uint8_t factor_powerP1[] = "PA PF: ";
    const uint8_t factor_powerP2[] = "PB PF: ";
    const uint8_t factor_powerP3[] = "PC PF: ";
    
    const uint8_t total_factor_power[] = "Total PF: ";
   
    /**Create the variable with current data**/
	static PhasePower1_Type currentPowerFactor1;

	/**Set with the current state and phase**/
	currentPowerFactor1.phaseState = PHASES_PF;
	currentPowerFactor1.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentPowerFactor1.phaseState = EXIT_PF;
    }
    if(getButton2() == 1)
    {
        currentPowerFactor1.phaseState = EXIT_PF;
    }
    if(getButton3() == 1)
    {
        counter++;
        LCDNokia_clear();
        if(counter > maxScreens)
        {
            counter = 0;
        }
    }
    switch(counter)
    {
        case 0:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(factor_powerP1);
            LCDNokia_gotoXY(0,2);
            LCDNokia_sendString(factor_powerP2);
            LCDNokia_gotoXY(0,3);
            LCDNokia_sendString(factor_powerP3);
            break;
        case 1:
            LCDNokia_gotoXY(0,1);
            LCDNokia_sendString(total_factor_power);
            break;
        default:
            break;
    }
	return (currentPowerFactor1);
}

PhasePowerFactor_Type exitPowerFactor(PhasePowerFactor_Type data)
{
    /**Create the variable with current data**/
	static PhasePowerFactor_Type currentPowerFactor2;

    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentPowerFactor2.phaseState = data.phaseState;
	currentPowerFactor2.stateMain = data.stateMain;

	return (currentPowerFactor2);
}

PhasePhaseAngle_Type phPhaseAngle(PhasePhaseAngle_Type data)
{
    const uint8_t anglePhase1[] = "PA phA: ";
    const uint8_t anglePhase2[] = "PB phA: ";
    const uint8_t anglePhase3[] = "PC phA: ";

    /**Create the variable with current data**/
	static PhasePower1_Type currentPhaseAngle1;

    /**Set with the current state and phase**/
	currentPhaseAngle1.phaseState = PHASES_PA;
	currentPhaseAngle1.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentPhaseAngle1.phaseState = EXIT_PA;
    }
    if(getButton2() == 1)
    {
        currentPhaseAngle1.phaseState = VI_PA;
        LCDNokia_clear();
    }

    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(anglePhase1);
    LCDNokia_gotoXY(0,2);
    LCDNokia_sendString(anglePhase2);
    LCDNokia_gotoXY(0,3);
    LCDNokia_sendString(anglePhase3);

	return (currentPhaseAngle1);
}

PhasePhaseAngle_Type viPhaseAngle(PhasePhaseAngle_Type data)
{
    const uint8_t angle_VoltageP1[] = "PA VphA: ";
    const uint8_t angle_VoltageP2[] = "PB VphA: ";
    const uint8_t angle_VoltageP3[] = "PC VphA: ";
    
    /**Create the variable with current data**/
	static PhasePower1_Type currentPhaseAngle2;

    /**Set with the current state and phase**/
	currentPhaseAngle2.phaseState = VI_PA;
	currentPhaseAngle2.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentPhaseAngle2.phaseState = EXIT_PA;

    }
    if(getButton2() == 1)
    {
       	currentPhaseAngle2.phaseState = EXIT_PA;  
    }
    
    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(angle_VoltageP1);
    LCDNokia_gotoXY(0,2);
    LCDNokia_sendString(angle_VoltageP2);
    LCDNokia_gotoXY(0,3);
    LCDNokia_sendString(angle_VoltageP3);

	return (currentPhaseAngle2); 
}

PhasePhaseAngle_Type exitPhaseAngle(PhasePhaseAngle_Type data)
{
    /**Create the variable with current data**/
	static PhasePhaseAngle_Type currentPhaseAngle3;

    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentPhaseAngle3.phaseState = data.phaseState;
	currentPhaseAngle3.stateMain = data.stateMain;

	return (currentPhaseAngle3);   
}

PhaseFrequency_Type showFrequency(PhaseFrequency_Type data)
{
    const uint8_t frequency[] = "Freq: ";
    /**Create the variable with current data**/
	static PhasePower1_Type currentFrequency1;
    
	/**Set with the current state and phase**/
	currentFrequency1.phaseState = SHOW_FREQUENCY;
	currentFrequency1.stateMain = data.stateMain;
    
    if(getButton1() == 1)
    {
        currentFrequency1.phaseState = EXIT_FREQUENCY;
    }
    if(getButton2() == 1)
    {
        currentFrequency1.phaseState = EXIT_FREQUENCY;
    }
    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(frequency);

	return (currentFrequency1);
}

PhaseFrequency_Type exitFrequency(PhaseFrequency_Type data)
{
    /**Create the variable with current data**/
	static PhaseFrequency_Type currentFrequency2;

    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentFrequency2.phaseState = data.phaseState;
	currentFrequency2.stateMain = data.stateMain;

	return (currentFrequency2);
}

PhaseTemperature_Type showTemperature(PhaseTemperature_Type data)
{
    const uint8_t temperature[] = "Temp: ";
    /**Create the variable with current data**/
	static PhasePower1_Type currentTemperature1;
    
    /**Set with the current state and phase**/
	currentTemperature1.phaseState = SHOW_TEMPERATURE;
	currentTemperature1.stateMain = data.stateMain;

    if(getButton1() == 1)
    {
        currentTemperature1.phaseState = EXIT_TEMPERATURE;
    }
    if(getButton2() == 1)
    {
        currentTemperature1.phaseState = EXIT_TEMPERATURE;
    }

    LCDNokia_gotoXY(0,1);
    LCDNokia_sendString(temperature);
    
	return (currentTemperature1);
}

PhaseTemperature_Type exitTemperature(PhaseTemperature_Type data)
{
    /**Create the variable with current data**/
	static PhaseTemperature_Type currentTemperature2;

    LCDNokia_clear();
	/**Set with the current state and phase**/
	currentTemperature2.phaseState = data.phaseState;
	currentTemperature2.stateMain = data.stateMain;

	return (currentTemperature2);
}