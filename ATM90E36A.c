#include <xc.h>
#include "ATM90E36A.h"
#include "GPIO.h"


#if 0

#define LOW_PART_16BITS     0x0F
#define HIGH_PART_16BITS    0xF0
#define NEXT_FRAME          8
#define NOCONFIG_REG_CS0    10
#define NOCONFIG_REG_CS3    14
#define MOD_CS0             0x100
#define MOD_CS3             0x100
#define AV_SAMPLES_RMS      10
#define SPR_LOW7BITS        7
#define SPR_LOW8BITS        8
#define COMPLEMENTARY_EN    32768
#define GPHASE_50HZ         3763.739F
#define GPHASE_60HZ         3136.449F

/**REFERENCE VOLTAGE/CURRENT */
#define VOLTAGE_REF         220
#define CURRENT_REF         2

#define MC_HIGH             0x0861   /**test value*/
#define MC_LOW              0x4C68  /**test value*/
#define MMODE0_DATA         0x0087
#define MMODE1_DATA         0x0000
#define PSTART_TH           0x0000
#define QSTART_TH           0x0000
#define SSTART_TH           0x0000
#define PPHASE_TH           0x0000
#define QPHASE_TH           0x0000
#define SPHASE_TH           0x0000

/**Startup registers*/
#define CONFIG_START        0x30
#define CAL_START           0x40
#define HARM_START          0x50
#define ADJ_START           0x60

/**Startup register value*/
#define ROWER_UP_STATE      0x6886
#define CALIBRATION         0x5678
#define OPERATION           0x8765

/**Checksum registers*/
#define CHECKSUM_0          0x3B
#define CHECKSUM_1          0x4D
#define CHECKSUM_2          0x57
#define CHECKSUM_3          0x6F

/**Configurations registers*/
#define PL_CONSTH           0x31
#define PL_CONSTL           0x32
#define MMODE_0             0x33
#define MMODE_1             0x34
#define P_START_TH          0x35
#define Q_START_TH          0x36
#define S_START_TH          0x37
#define P_PHASE_TH          0x38
#define Q_PHASE_TH          0x39
#define S_PHASE_TH          0x3A

/**Measurement calibration registers*/
#define UGAIN_A             0x61
#define IGAIN_A             0x62
#define UOFFSET_A           0x63
#define IOFFSET_A           0x64
#define UGAIN_B             0x65
#define IGAIN_B             0x66
#define UOFFSET_B           0x67
#define IOFFSET_B           0x68
#define UGAIN_C             0x69
#define IGAIN_C             0x6A
#define UOFFSET_C           0x6B
#define IOFFSET_C           0x6C
#define IGAIN_N             0x6D
#define IOFFSET_N           0x6E

/**Power Offset registers*/
#define POFFSET_A           0x41
#define QOFFSET_A           0x42
#define POFFSET_B           0x43
#define QOFFSET_B           0x44
#define POFFSET_C           0x45
#define QOFFSET_C           0x46
#define POFFSET_AF          0x51
#define POFFSET_BF          0x52
#define POFFSET_CF          0x53

/**Measurement value registers*/
#define URMS_A              0xD9
#define URMS_B              0xDA
#define URMS_C              0xDB
#define IRMS_A              0xDD
#define IRMS_B              0xDE
#define IRMS_C              0xDF
#define IRMS_N1             0xD8
#define URMS_ALSB           0xE9
#define URMS_BLSB           0xEA
#define URMS_CLSB           0xEB
#define IRMS_ALSB           0xED
#define IRMS_BLSB           0xEE
#define IRMS_CLSB           0xEF

/**Energy metering calibration registers*/
#define GAIN_A              0x47
#define PHI_A               0x48
#define GAIN_B              0x49
#define PHI_B               0x4A
#define GAIN_C              0x4B
#define PHI_C               0x4C

/**************************************************/
const uint8_t tForwActE = 0x80;
const uint8_t pAForwActE = 0x81;
const uint8_t pBForwActE = 0x82;
const uint8_t pCForwActE = 0x83;
const uint8_t tRevActE = 0x84;
const uint8_t pARevActE = 0x85;
const uint8_t PBRevActE = 0x86;
const uint8_t pCRevActE = 0x87;
const uint8_t tForwReaE = 0x88;
const uint8_t pAForwReaE = 0x89;
const uint8_t pBForwReaE = 0x8A;
const uint8_t pCForwReaE = 0x8B;
const uint8_t tRevReaE = 0x8C;
const uint8_t pARevReaE = 0x8D;
const uint8_t pBRevReaE = 0x8E;
const uint8_t pCRevReaE = 0x8F;
const uint8_t tAriAppE = 0x90;
const uint8_t pAAppE = 0x91;
const uint8_t pBAppE = 0x92;
const uint8_t pCAppE = 0x93;
const uint8_t tVecAppE = 0x94;

/**Regular Energy Registers*/
//#define TOTAL_FORW_ACTIVE_ENERGY_ADR        0x80
//#define PHASE_A_FORW_ACTIVE_ENERGY_ADR      0x81
//#define PHASE_B_FORW_ACTIVE_ENERGY_ADR      0x82
//#define PHASE_C_FORW_ACTIVE_ENERGY_ADR      0x83
//#define TOTAL_REV_ACTIVE_ENERGY_ADR         0x84
//#define PHASE_A_REV_ACTIVE_ENERGY_ADR       0x85
//#define PHASE_B_REV_ACTIVE_ENERGY_ADR       0x86
//#define PHASE_C_REV_ACTIVE_ENERGY_ADR       0x87
//#define TOTAL_FORW_REACTIVE_ENERGY_ADR      0x88
//#define PHASE_A_FORW_REACTIVE_ENERGY_ADR    0x89
//#define PHASE_B_FORW_REACTIVE_ENERGY_ADR    0x8A
//#define PHASE_C_FORW_REACTIVE_ENERGY_ADR    0x8B
//#define TOTAL_REVERSE_REACTIVE_ENERGY_ADR   0x8C
//#define PHASE_A_REV_REACTIVE_ENERGY_ADR     0x8D
//#define PHASE_B_REV_REACTIVE_ENERGY_ADR     0x8E
//#define PHASE_C_REV_REACTIVE_ENERGY_ADR     0x8F
//#define TOTAL_ARIT_APPARENT_ENERGY_ADR      0x90
//#define PHASE_A_APPARENT_ENERGY_ADR         0x91
//#define PHASE_B_APPARENT_ENERGY_ADR         0x92
//#define PHASE_C_APPARENT_ENERGY_ADR         0x93
//#define TOTAL_VECT_APPARENT_ENERGY_ADR      0x94

const uint8_t tForwActFE = 0xA0;
const uint8_t pAForwActFE = 0xA1;
const uint8_t pBForwActFE = 0xA2;
const uint8_t pCForwActFE = 0xA3;
const uint8_t tRevActFE = 0xA4;
const uint8_t pARevActFE = 0xA5;
const uint8_t pBRevActFE = 0xA6;
const uint8_t pCRevActFE = 0xA7;
const uint8_t tForwActHE = 0xA8;
const uint8_t pAForwActHE = 0xA9;
const uint8_t pBForwActHE = 0xAA;
const uint8_t pCForwActHE = 0xAB;
const uint8_t tRevActHE = 0xAC;
const uint8_t pARevActHE = 0xAD;
const uint8_t pBRevActHE = 0xAE;
const uint8_t pCRevActHE = 0xAF;

/**Fundamental/Harmonic Energy Register*/
//#define TOTAL_FORW_ACTIVE_FUND_ENERGY_ADR       0xA0
//#define PHASE_A_FORW_ACTIVE_FUND_ENERGY_ADR     0xA1   
//#define PHASE_B_FORW_ACTIVE_FUND_ENERGY_ADR     0xA2
//#define PHASE_C_FORW_ACTIVE_FUND_ENERGY_ADR     0xA3
//#define TOTAL_REV_ACTIVE_FUND_ENERGY_ADR        0xA4
//#define PHASE_A_REV_ACTIVE_FUND_ENERGY_ADR      0xA5
//#define PHASE_B_REV_ACTIVE_FUND_ENERGY_ADR      0xA6
//#define PHASE_C_REV_ACTIVE_FUND_ENERGY_ADR      0xA7
//#define TOTAL_FORW_ACTIVE_HARM_ENERGY_ADR       0xA8
//#define PHASE_A_FORW_ACTIVE_HARM_ENERGY_ADR     0xA9
//#define PHASE_B_FORW_ACTIVE_HARM_ENERGY_ADR     0xAA
//#define PHASE_C_FORW_ACTIVE_HARM_ENERGY_ADR     0xAB
//#define TOTAL_REV_ACTIVE_HARM_ENERGY_ADR        0xAC
//#define PHASE_A_REV_ACTIVE_HARM_ENERGY_ADR      0xAD
//#define PHASE_B_REV_ACTIVE_HARM_ENERGY_ADR      0xAE
//#define PHASE_C_REV_ACTIVE_HARM_ENERGY_ADR      0xAF

const uint8_t tActPow = 0xB0;
const uint8_t pAActPow = 0xB1;
const uint8_t pBActPow = 0xB2;
const uint8_t pCActPow = 0xB3;
const uint8_t tReaPow = 0xB4;
const uint8_t pAReaPow = 0xB5;
const uint8_t pBReaPow = 0xB6;
const uint8_t pCReaPow = 0xB7;
const uint8_t tAppPow = 0xB8;
const uint8_t pAAppPow = 0xB9;
const uint8_t pBAppPow = 0xBA;
const uint8_t pCAppPow = 0xBB;
const uint8_t tPowFact = 0xBC;
const uint8_t pAPowFact = 0xBD;
const uint8_t pBPowFact = 0xBE;
const uint8_t pCPowFact = 0xBF;

/**Power and power factor registers*/
//#define TOTAL_ACTIVE_POWER_ADR      0xB0
//#define PHASE_A_ACTIVE_POWER_ADR    0xB1
//#define PHASE_B_ACTIVE_POWER_ADR    0xB2
//#define PHASE_C_ACTIVE_POWER_ADR    0xB3
//#define TOTAL_REACTIVE_POWER_ADR    0xB4
//#define PHASE_A_REACTIVE_POWER_ADR  0xB5
//#define PHASE_B_REACTIVE_POWER_ADR  0xB6
//#define PHASE_C_REACTIVE_POWER_ADR  0xB7
//#define TOTAL_APPARENT_POWER_ADR    0xB8
//#define PHASE_A_APPARENT_POWER_ADR  0xB9
//#define PHASE_B_APPARENT_POWER_ADR  0xBA
//#define PHASE_C_APPARENT_POWER_ADR  0xBB
//#define TOTAL_POWER_FACTOR_ADR      0xBC
//#define PHASE_A_POWER_FACTOR_ADR    0xBD
//#define PHASE_B_POWER_FACTOR_ADR    0xBE
//#define PHASE_C_POWER_FACTOR_ADR    0xBF

const uint8_t tActFundPow = 0xD0;
const uint8_t pAActFundPow = 0xD1;
const uint8_t pBActFundPow = 0xD2;
const uint8_t pCActFundPow = 0xD3;
const uint8_t tActHPow = 0xD4;
const uint8_t pAActHPow = 0xD5;
const uint8_t pBActHPow = 0xD6;
const uint8_t pCActHPow = 0xD7;
const uint8_t nLineSamCurr = 0xD8;
const uint8_t pAVoltageRMS = 0xD9;
const uint8_t pBVoltageRMS = 0xDA;
const uint8_t pCVoltageRMS = 0xDB;
const uint8_t nLineCalCurr = 0xDC;
const uint8_t pACurrRMS = 0xDD;
const uint8_t pBCurrRMS = 0xDE;
const uint8_t pCCurrRMS = 0xDF;

/**Fundamental/Harmonic Power and Voltage/Current RMS registers*/
//#define TOTAL_ACTIVE_FUND_POWER_ADR         0xD0
//#define PHASE_A_ACTIVE_FUND_POWER_ADR       0xD1
//#define PHASE_B_ACTIVE_FUND_POWER_ADR       0xD2
//#define PHASE_C_ACTIVE_FUND_POWER_ADR       0xD3
//#define TOTAL_ACTIVE_HARM_POWER_ADR         0xD4
//#define PHASE_A_ACTIVE_HARM_POWER_ADR       0xD5
//#define PHASE_B_ACTIVE_HARM_POWER_ADR       0xD6
//#define PHASE_C_ACTIVE_HARM_POWER_ADR       0xD7
//#define NLINE_SAMPLED_CURRENT_RMS_ADR       0xD8
//#define PHASE_A_VOLTAGE_RMS_ADR             0xD9
//#define PHASE_B_VOLTAGE_RMS_ADR             0xDA
//#define PHASE_C_VOLTAGE_RMS_ADR             0xDB
//#define NLINE_CALCULATED_CURRENT_RMS_ADR    0xDC
//#define PHASE_A_CURRENT_RMS_ADR             0xDD
//#define PHASE_B_CURRENT_RMS_ADR             0xDE
//#define PHASE_C_CURRENT_RMS_ADR             0xDF

const uint8_t pAVoltTHDN = 0xF1;
const uint8_t pBVoltTHDN = 0xF2;
const uint8_t pCVoltTHDN = 0xF3;
const uint8_t pACurrTHDN = 0xF5;
const uint8_t pBCurrTHDN = 0xF6;
const uint8_t pCCurrTHDN = 0xF7;
const uint8_t frequencyReg = 0xF8;
const uint8_t pAMeanAngleP = 0xF9;
const uint8_t pBMeanAngleP = 0xFA;
const uint8_t pCMeanAngleP = 0xFB;
const uint8_t temperatureReg = 0xFC;
const uint8_t pAVoltAngleP = 0xFD;
const uint8_t pBVoltAngleP = 0xFE;
const uint8_t pCVoltAngleP = 0xFF;

/**THD+N, FREQUENCY, ANGLE AND TEMPERATURE REGISTERS*/
//#define PHASE_A_VOLTAGE_THDN_ADR        0xF1
//#define PHASE_B_VOLTAGE_THDN_ADR        0xF2
//#define PHASE_C_VOLTAGE_THDN_ADR        0xF3
//#define PHASE_A_CURRENT_THDN_ADR        0xF5
//#define PHASE_B_CURRENT_THDN_ADR        0xF6
//#define PHASE_C_CURRENT_THDN_ADR        0xF7    
//#define FREQUENCY_REG_ADR               0xF8
//#define PHASE_A_MEAN_ANGLE_PHASE_ADR    0xF9
//#define PHASE_B_MEAN_ANGLE_PHASE_ADR    0xFA
//#define PHASE_C_MEAN_ANGLE_PHASE_ADR    0xFB
//#define TEMPERATURE_REG_ADR             0xFC
//#define PHASE_A_VOLTAGE_ANGLE_PHASE_ADR 0xFD
//#define PHASE_B_VOLTAGE_ANGLE_PHASE_ADR 0xFE
//#define PHASE_C_VOLTAGE_ANGLE_PHASE_ADR 0xFF

typedef struct
{
    uint8_t lowPart;
    uint8_t highPart;
    uint16_t dummyLow;
    uint16_t dummyHigh;
} Data_TwoFrames;

typedef struct
{
    uint16_t ugainAvg;
    uint16_t igainAvg;
    float dummy_ugain;
    float dummy_igain;
    uint16_t urmsAvg;
    uint16_t irmsAvg;
    uint16_t urmsLSB;
    uint16_t irmsLSB;
    uint16_t uoffsetAvg;
    uint16_t ioffsetAvg;
} Data_VI_Avg;

typedef struct
{
    uint16_t poffsetAvg;
    uint16_t qoffsetAvg;
    uint16_t pfoffsetAvg;
} Data_Pow_Avg;

typedef struct
{
    uint16_t gain;
    uint16_t phaseAngle;
    float dummy_Gain;
    float dummy_Phi;
} Data_Energy;

static void ATM_write(uint16_t register_add, uint16_t data)
{
    Data_TwoFrames register_To_IC;
    Data_TwoFrames data_To_IC;
    
    register_To_IC.dummyLow = register_add;
    register_To_IC.dummyLow &= LOW_PART_16BITS;
    register_To_IC.dummyHigh = register_add;
    register_To_IC.dummyHigh &= HIGH_PART_16BITS;

    data_To_IC.dummyLow = data;
    data_To_IC.dummyLow &= LOW_PART_16BITS;
    data_To_IC.dummyHigh = data;
    data_To_IC.dummyHigh &= HIGH_PART_16BITS;
    
    register_To_IC.lowPart = (uint8_t)register_To_IC.dummyLow;
    register_To_IC.highPart = (uint8_t)register_To_IC.dummyHigh;
    
    data_To_IC.lowPart = (uint8_t)data_To_IC.dummyLow;
    data_To_IC.highPart = (uint8_t)data_To_IC.dummyHigh;
    
    PORTBbits.RB3 = 0;
    SPI_write(register_To_IC.lowPart);
    SPI_write(register_To_IC.highPart);
    
    SPI_write(data_To_IC.lowPart);
    SPI_write(data_To_IC.highPart);
    PORTBbits.RB3 = 1;
}

static uint16_t ATM_read(uint16_t register_add)
{
    Data_TwoFrames register_To_IC;
    Data_TwoFrames data_From_IC;
    uint16_t data;
    
    register_To_IC.dummyLow = register_add;
    register_To_IC.dummyLow &= LOW_PART_16BITS;
    register_To_IC.dummyHigh = register_add;
    register_To_IC.dummyHigh &= HIGH_PART_16BITS;
    
    register_To_IC.lowPart = (uint8_t)register_To_IC.dummyLow;
    register_To_IC.highPart = (uint8_t)register_To_IC.dummyHigh;
    
    PORTBbits.RB3 = 0;
    SPI_write(register_To_IC.lowPart);
    SPI_write(register_To_IC.highPart);
    
    data_From_IC.dummyLow = SPI_read();
    data_From_IC.dummyHigh = SPI_read();
    
    data_From_IC.lowPart = data_From_IC.dummyLow;
    data_From_IC.highPart = data_From_IC.dummyHigh<<NEXT_FRAME;
    
    //data = (data_From_IC.highPart|data_From_IC.lowPart);
    data = 0;
    PORTBbits.RB3 = 1;
    return (data);
}
void ATM_init(void)
{
    /**CS2 pin*/
    GPIO_dataDirectionPIN(GPIO_B, 3, GPIO_OUTPUT);
    /**DMA Control pin*/
    GPIO_dataDirectionPIN(GPIO_B, 4, GPIO_OUTPUT);
    /**PM0 pin*/
    GPIO_dataDirectionPIN(GPIO_B, 5, GPIO_OUTPUT);
    /**PM1 pin*/
    GPIO_dataDirectionPIN(GPIO_C, 2, GPIO_OUTPUT);
    /**WarnOut pin*/
    //GPIO_dataDirectionPIN(GPIO_B, 7, GPIO_INPUT);
    
    /**ZX0 pin*/
    //GPIO_dataDirectionPIN(GPIO_C, 2, GPIO_INPUT);
    /**ZX1 pin*/
    //GPIO_dataDirectionPIN(GPIO_C, 1, GPIO_INPUT);
    
    /**CF1 pin*/
    GPIO_dataDirectionPIN(GPIO_C, 1, GPIO_INPUT);
    /**CF2 pin*/
    GPIO_dataDirectionPIN(GPIO_C, 0, GPIO_INPUT);
    /**CF3 pin*/
    GPIO_dataDirectionPIN(GPIO_A, 2, GPIO_INPUT);
    ANS2 = 0;
    /**CF4 pin*/
    GPIO_dataDirectionPIN(GPIO_A, 1, GPIO_INPUT);
    ANS1 = 0;
    
    /**Power Mode: Normal*/
    GPIO_setPIN(GPIO_B, 5);
    GPIO_setPIN(GPIO_C, 2);
    
    /**Slave Mode*/
    GPIO_clearPIN(GPIO_B, 3);
}

void ATM_calibration(void)
{
    uint16_t checksum0;
    float energy_error;
    float energy_errorGain;
    float phi_error;
    float phi_errorPH;
    uint8_t counter;
    
    Data_VI_Avg phaseA = {0};
    Data_VI_Avg phaseB = {0};
    Data_VI_Avg phaseC = {0};
    Data_VI_Avg phaseN = {0};
    
    Data_Pow_Avg phaseA_pow = {0};
    Data_Pow_Avg phaseB_pow = {0};
    Data_Pow_Avg phaseC_pow = {0};

    Data_Energy phaseA_En = {0};
    Data_Energy phaseB_En = {0};
    Data_Energy phaseC_En = {0};
    
    do
    {
        /**Start the calibration*/
        ATM_write(CONFIG_START, CALIBRATION);

        /**Start the Meter Constant*/
        ATM_write(PL_CONSTH, MC_HIGH);
        ATM_write(PL_CONSTL, MC_LOW);

        /**Adjust the Meter Metering Config*/
        ATM_write(MMODE_0, MMODE0_DATA);
        ATM_write(MMODE_1, MMODE1_DATA);

        /**Set the thresholds*/
        ATM_write(P_START_TH, PSTART_TH);
        ATM_write(Q_START_TH, QSTART_TH);
        ATM_write(S_START_TH, SSTART_TH);
        ATM_write(P_PHASE_TH, PPHASE_TH);
        ATM_write(Q_PHASE_TH, QPHASE_TH);
        ATM_write(S_PHASE_TH, SPHASE_TH);

        /**Calculate the checksum 0*/
        //checksum0 = calculate_CS0();
        ATM_write(CHECKSUM_0, checksum0);

        /**Enable checksum checking*/
        ATM_write(CONFIG_START, OPERATION);
        
        /**Check if there is a checksum error*/
    }while(0 == PORTBbits.RB7);     
    
    /**Start the measurement calibration registers*/
    ATM_write(ADJ_START, CALIBRATION);
    
    /**Get an average of offset registers of PHASE A*/
    for(counter = 0; counter < AV_SAMPLES_RMS; counter++)
    {
        phaseA.ioffsetAvg += phaseA.ioffsetAvg;
        phaseA.uoffsetAvg += phaseA.uoffsetAvg;
        
        phaseA.ioffsetAvg = ATM_read(IOFFSET_A);    
        phaseA.uoffsetAvg = ATM_read(UOFFSET_A);
    }
    
    /**Calculate the average of registers of PhaseA*/
    phaseA.ioffsetAvg /= AV_SAMPLES_RMS;
    phaseA.uoffsetAvg /= AV_SAMPLES_RMS;
    
    phaseA.ioffsetAvg = phaseA.ioffsetAvg >> SPR_LOW7BITS;
    phaseA.uoffsetAvg = phaseA.uoffsetAvg >> SPR_LOW7BITS;
    
    phaseA.ioffsetAvg = ~phaseA.ioffsetAvg;
    phaseA.uoffsetAvg = ~phaseA.uoffsetAvg;
    
    phaseA.ioffsetAvg += 1;
    phaseA.uoffsetAvg += 1;
    
    ATM_write(IOFFSET_A, phaseA.ioffsetAvg);
    ATM_write(UOFFSET_A, phaseA.uoffsetAvg);
   
    /**VOLTAGE/CURRENT OFFSET CALIBRATION*/
    
    /**Get an average of offset registers of PHASE B*/
    for(counter = 0; counter < AV_SAMPLES_RMS; counter++)
    {
        phaseB.ioffsetAvg += phaseB.ioffsetAvg;
        phaseB.uoffsetAvg += phaseB.uoffsetAvg;
        
        phaseB.ioffsetAvg = ATM_read(IOFFSET_B);    
        phaseB.uoffsetAvg = ATM_read(UOFFSET_B);
    }
    
    /**Calculate the average of registers of PhaseB*/
    phaseB.ioffsetAvg /= AV_SAMPLES_RMS;
    phaseB.uoffsetAvg /= AV_SAMPLES_RMS;
    
    /**Get an average of offset registers of PHASE C*/
    for(counter = 0; counter < AV_SAMPLES_RMS; counter++)
    {
        phaseC.ioffsetAvg += phaseC.ioffsetAvg;
        phaseC.uoffsetAvg += phaseC.uoffsetAvg;
        
        phaseC.ioffsetAvg = ATM_read(IOFFSET_C);    
        phaseC.uoffsetAvg = ATM_read(UOFFSET_C);
    }
    
    /**Calculate the average of registers of PhaseC*/
    phaseC.ioffsetAvg /= AV_SAMPLES_RMS;
    phaseC.uoffsetAvg /= AV_SAMPLES_RMS;
    
    /**Get an average of offset registers of PHASE N*/
    for(counter = 0; counter < AV_SAMPLES_RMS; counter++)
    {
        phaseN.ioffsetAvg += phaseN.ioffsetAvg;

        phaseN.ioffsetAvg = ATM_read(IOFFSET_C);    
    }
    
    /**Calculate the average of registers of PhaseN*/
    phaseN.ioffsetAvg /= AV_SAMPLES_RMS;    
    
    /**VOLTAGE/CURRENT GAIN CALIBRATION*/
 
    /**Current gain calibration*/    
    phaseA.irmsAvg = ATM_read(IRMS_A);
    phaseB.irmsAvg = ATM_read(IRMS_B);
    phaseC.irmsAvg = ATM_read(IRMS_C);
    
    phaseA.irmsLSB = ATM_read(IRMS_ALSB);
    phaseB.irmsLSB = ATM_read(IRMS_BLSB);
    phaseC.irmsLSB = ATM_read(IRMS_CLSB); 
    
    phaseA.irmsLSB = phaseA.irmsLSB >> NEXT_FRAME;
    phaseB.irmsLSB = phaseB.irmsLSB >> NEXT_FRAME;
    phaseC.irmsLSB = phaseC.irmsLSB >> NEXT_FRAME;
    
    /**Calculate the current gain per phase*/
    phaseA.dummy_igain = ((float)phaseA.irmsAvg)*0.01;
    phaseA.dummy_igain += (((float)phaseA.irmsLSB)*0.01)/256;
    phaseA.dummy_igain = (CURRENT_REF/phaseA.dummy_igain)*30000;
    phaseA.igainAvg = (uint16_t)phaseA.dummy_igain;
    ATM_write(IGAIN_A, phaseA.igainAvg);
    
    phaseB.dummy_igain = ((float)phaseB.irmsAvg)*0.01;
    phaseB.dummy_igain += (((float)phaseB.irmsLSB)*0.01)/256;
    phaseB.dummy_igain = (CURRENT_REF/phaseB.dummy_igain)*30000;
    phaseB.igainAvg = (uint16_t)phaseB.dummy_igain;
    ATM_write(IGAIN_B, phaseB.igainAvg);
    
    phaseC.dummy_igain = ((float)phaseC.irmsAvg)*0.01;
    phaseC.dummy_igain += (((float)phaseC.irmsLSB)*0.01)/256;
    phaseC.dummy_igain = (CURRENT_REF/phaseC.dummy_igain)*30000;
    phaseC.igainAvg = (uint16_t)phaseC.dummy_igain;
    ATM_write(IGAIN_C, phaseC.igainAvg);
    
    /**Voltage gain calibration*/    
    phaseA.urmsAvg = ATM_read(URMS_A);
    phaseB.urmsAvg = ATM_read(URMS_B);
    phaseC.urmsAvg = ATM_read(URMS_C);
    
    phaseA.urmsLSB = ATM_read(URMS_ALSB);
    phaseB.urmsLSB = ATM_read(URMS_BLSB);
    phaseC.urmsLSB = ATM_read(URMS_CLSB); 
    
    phaseA.urmsLSB = phaseA.urmsLSB >> NEXT_FRAME;
    phaseB.urmsLSB = phaseB.urmsLSB >> NEXT_FRAME;
    phaseC.urmsLSB = phaseC.urmsLSB >> NEXT_FRAME;
    
    /**Calculate the current gain per phase*/
    phaseA.dummy_ugain = ((float)phaseA.urmsAvg)*0.01;
    phaseA.dummy_ugain += (((float)phaseA.urmsLSB)*0.01)/256;
    phaseA.dummy_ugain = (CURRENT_REF/phaseA.dummy_ugain)*52800;
    phaseA.ugainAvg = (uint16_t)phaseA.dummy_ugain;
    ATM_write(UGAIN_A, phaseA.ugainAvg);
    
    phaseB.dummy_ugain = ((float)phaseB.urmsAvg)*0.01;
    phaseB.dummy_ugain += (((float)phaseB.urmsLSB)*0.01)/256;
    phaseB.dummy_ugain = (CURRENT_REF/phaseB.dummy_ugain)*52800;
    phaseB.ugainAvg = (uint16_t)phaseB.dummy_ugain;
    ATM_write(UGAIN_B, phaseB.ugainAvg);
    
    phaseC.dummy_ugain = ((float)phaseC.urmsAvg)*0.01;
    phaseC.dummy_ugain += (((float)phaseC.urmsLSB)*0.01)/256;
    phaseC.dummy_ugain = (CURRENT_REF/phaseC.dummy_ugain)*52800;
    phaseC.ugainAvg = (uint16_t)phaseC.dummy_ugain;
    ATM_write(UGAIN_C, phaseC.ugainAvg);

    /**POWER OFFSET CALIBRATION*/
    
    /**Get an average of offset registers of PHASE A*/
    for(counter = 0; counter < AV_SAMPLES_RMS; counter++)
    {
        phaseA_pow.poffsetAvg += phaseA_pow.poffsetAvg;
        phaseA_pow.qoffsetAvg += phaseA_pow.qoffsetAvg;
        phaseA_pow.pfoffsetAvg += phaseA_pow.pfoffsetAvg;
        
        phaseA_pow.poffsetAvg = ATM_read(POFFSET_A);
        phaseA_pow.qoffsetAvg = ATM_read(QOFFSET_A);
        phaseA_pow.pfoffsetAvg = ATM_read(POFFSET_AF);
    }
    
    /**Calculate the average of registers of PhaseA*/
    phaseA_pow.poffsetAvg /= AV_SAMPLES_RMS;
    phaseA_pow.qoffsetAvg /= AV_SAMPLES_RMS;
    phaseA_pow.pfoffsetAvg /= AV_SAMPLES_RMS;
    
    /**Calculate the calibration*/
    //phaseA_pow.poffsetAvg *= 100000;
    //phaseA_pow.qoffsetAvg *= 100000;
    //phaseA_pow.pfoffsetAvg *= 100000;
    
    phaseA_pow.poffsetAvg /= 65536;
    phaseA_pow.qoffsetAvg /= 65536;
    phaseA_pow.pfoffsetAvg /= 65536;
    
    /**Two's complement of registers*/
    phaseA_pow.poffsetAvg = phaseA_pow.poffsetAvg >> SPR_LOW8BITS;
    phaseA_pow.qoffsetAvg = phaseA_pow.qoffsetAvg >> SPR_LOW8BITS;
    phaseA_pow.pfoffsetAvg = phaseA_pow.pfoffsetAvg >> SPR_LOW8BITS;
    
    phaseA_pow.poffsetAvg = ~phaseA_pow.poffsetAvg;
    phaseA_pow.qoffsetAvg = ~phaseA_pow.qoffsetAvg;
    phaseA_pow.pfoffsetAvg = ~phaseA_pow.pfoffsetAvg;
    
    phaseA_pow.poffsetAvg += 1;
    phaseA_pow.qoffsetAvg += 1;
    phaseA_pow.pfoffsetAvg += 1;
    
    /**Write the registers*/
    ATM_write(POFFSET_A, phaseA_pow.poffsetAvg);
    ATM_write(QOFFSET_A, phaseA_pow.qoffsetAvg); 
    ATM_write(POFFSET_AF, phaseA_pow.pfoffsetAvg);    
    
    /**Get an average of offset registers of PHASE B*/
    for(counter = 0; counter < AV_SAMPLES_RMS; counter++)
    {
        phaseB_pow.poffsetAvg += phaseB_pow.poffsetAvg;
        phaseB_pow.qoffsetAvg += phaseB_pow.qoffsetAvg;
        phaseB_pow.pfoffsetAvg += phaseB_pow.pfoffsetAvg;
        
        phaseB_pow.poffsetAvg = ATM_read(POFFSET_B);
        phaseB_pow.qoffsetAvg = ATM_read(QOFFSET_B);
        phaseB_pow.pfoffsetAvg = ATM_read(POFFSET_BF);
    }
    
    /**Calculate the average of registers of PhaseA*/
    phaseB_pow.poffsetAvg /= AV_SAMPLES_RMS;
    phaseB_pow.qoffsetAvg /= AV_SAMPLES_RMS;
    phaseB_pow.pfoffsetAvg /= AV_SAMPLES_RMS;
    
    /**Calculate the calibration*/
    //phaseB_pow.poffsetAvg *= 100000;
    //phaseB_pow.qoffsetAvg *= 100000;
    //phaseB_pow.pfoffsetAvg *= 100000;
    
    phaseB_pow.poffsetAvg /= 65536;
    phaseB_pow.qoffsetAvg /= 65536;
    phaseB_pow.pfoffsetAvg /= 65536;
    
    /**Two's complement of registers*/
    phaseB_pow.poffsetAvg = phaseB_pow.poffsetAvg >> SPR_LOW8BITS;
    phaseB_pow.qoffsetAvg = phaseB_pow.qoffsetAvg >> SPR_LOW8BITS;
    phaseB_pow.pfoffsetAvg = phaseB_pow.pfoffsetAvg >> SPR_LOW8BITS;
    
    phaseB_pow.poffsetAvg = ~phaseB_pow.poffsetAvg;
    phaseB_pow.qoffsetAvg = ~phaseB_pow.qoffsetAvg;
    phaseB_pow.pfoffsetAvg = ~phaseB_pow.pfoffsetAvg;
    
    phaseB_pow.poffsetAvg += 1;
    phaseB_pow.qoffsetAvg += 1;
    phaseB_pow.pfoffsetAvg += 1;
    
    /**Write the registers*/
    ATM_write(POFFSET_B, phaseB_pow.poffsetAvg);
    ATM_write(QOFFSET_B, phaseB_pow.qoffsetAvg); 
    ATM_write(POFFSET_BF, phaseB_pow.pfoffsetAvg);    
    
    
    /**Get an average of offset registers of PHASE C*/
    for(counter = 0; counter < AV_SAMPLES_RMS; counter++)
    {
        phaseC_pow.poffsetAvg += phaseC_pow.poffsetAvg;
        phaseC_pow.qoffsetAvg += phaseC_pow.qoffsetAvg;
        phaseC_pow.pfoffsetAvg += phaseC_pow.pfoffsetAvg;
        
        phaseC_pow.poffsetAvg = ATM_read(POFFSET_C);
        phaseC_pow.qoffsetAvg = ATM_read(QOFFSET_C);
        phaseC_pow.pfoffsetAvg = ATM_read(POFFSET_CF);
    }
    
    /**Calculate the average of registers of PhaseA*/
    phaseC_pow.poffsetAvg /= AV_SAMPLES_RMS;
    phaseC_pow.qoffsetAvg /= AV_SAMPLES_RMS;
    phaseC_pow.pfoffsetAvg /= AV_SAMPLES_RMS;
    
    /**Calculate the calibration*/
    //phaseC_pow.poffsetAvg *= 100000;
    //phaseC_pow.qoffsetAvg *= 100000;
    //phaseC_pow.pfoffsetAvg *= 100000;
    
    phaseC_pow.poffsetAvg /= 65536;
    phaseC_pow.qoffsetAvg /= 65536;
    phaseC_pow.pfoffsetAvg /= 65536;
    
    /**Two's complement of registers*/
    phaseC_pow.poffsetAvg = phaseC_pow.poffsetAvg >> SPR_LOW8BITS;
    phaseC_pow.qoffsetAvg = phaseC_pow.qoffsetAvg >> SPR_LOW8BITS;
    phaseC_pow.pfoffsetAvg = phaseC_pow.pfoffsetAvg >> SPR_LOW8BITS;
    
    phaseC_pow.poffsetAvg = ~phaseC_pow.poffsetAvg;
    phaseC_pow.qoffsetAvg = ~phaseC_pow.qoffsetAvg;
    phaseC_pow.pfoffsetAvg = ~phaseC_pow.pfoffsetAvg;
    
    phaseC_pow.poffsetAvg += 1;
    phaseC_pow.qoffsetAvg += 1;
    phaseC_pow.pfoffsetAvg += 1;
    
    /**Write the registers*/
    ATM_write(POFFSET_C, phaseC_pow.poffsetAvg);
    ATM_write(QOFFSET_C, phaseC_pow.qoffsetAvg); 
    ATM_write(POFFSET_CF, phaseC_pow.pfoffsetAvg);    
    
    /**ENERGY GAIN CALIBRATION*/
 
    /**Calculate the energy error*/
    energy_error = 0.1378;
    energy_errorGain = energy_error/(1-energy_error);
    
    /**PHASE A*/
    /**Calculate the gain*/
    phaseA_En.dummy_Gain = energy_errorGain * COMPLEMENTARY_EN;
    phaseA_En.gain = (uint16_t)phaseA_En.dummy_Gain;
    
    /**Write the gain into register*/
    ATM_write(GAIN_A, phaseA_En.gain);
    
    /**PHASE B*/
    
    /**Calculate the gain*/
    phaseB_En.dummy_Gain = energy_errorGain * COMPLEMENTARY_EN;
    phaseB_En.gain = (uint16_t)phaseB_En.dummy_Gain;
    
    /**Write the gain into register*/
    ATM_write(GAIN_B, phaseB_En.gain);
    
    /**PHASE C*/
    
    /**Calculate the gain*/
    phaseC_En.dummy_Gain = energy_errorGain * COMPLEMENTARY_EN;
    phaseC_En.gain = (uint16_t)phaseC_En.dummy_Gain;
    
    /**Write the gain into register*/
    ATM_write(GAIN_C, phaseC_En.gain);
    
    
    /**PHASE ANGLE CALIBRATION*/
    
    /**Calculate the phase angle error*/
    phi_error = 0.0095;
    phi_errorPH = phi_error * GPHASE_50HZ;
    
    /**PHASE A*/
    phaseA_En.phaseAngle = (uint16_t)phi_errorPH;
    /**Write phase angle into register*/
    ATM_write(PHI_A, phaseA_En.phaseAngle);
    
    /**PHASE B*/
    phaseB_En.phaseAngle = (uint16_t)phi_errorPH;
    /**Write phase angle into register*/
    ATM_write(PHI_B, phaseB_En.phaseAngle);
    
    /**PHASE C*/
    phaseC_En.phaseAngle = (uint16_t)phi_errorPH;
    /**Write phase angle into register*/
    ATM_write(PHI_C, phaseC_En.phaseAngle);

}

uint16_t ATM_registers(ATM_type_t type, ATM_reg_t reg)
{
    uint16_t info;
    
    switch(type)
    {
        case ACTIVE_ENERGY_TYPE:
            switch(reg)
            {
                case TOTAL_FORW_ACTIVE_ENERGY:
                    info = ATM_read(TOTAL_FORW_ACTIVE_ENERGY_ADR);
                    break;
                case PHASE_A_FORW_ACTIVE_ENERGY:
                    info = ATM_read(PHASE_A_FORW_ACTIVE_ENERGY_ADR);
                    break;
                case PHASE_B_FORW_ACTIVE_ENERGY:
                    info = ATM_read(PHASE_B_FORW_ACTIVE_ENERGY_ADR);
                    break;
                case PHASE_C_FORW_ACTIVE_ENERGY:
                    info = ATM_read(PHASE_C_FORW_ACTIVE_ENERGY_ADR);
                    break;
                case TOTAL_REV_ACTIVE_ENERGY:
                    info = ATM_read(TOTAL_REV_ACTIVE_ENERGY_ADR);
                    break;
                case PHASE_A_REV_ACTIVE_ENERGY:
                    info = ATM_read(PHASE_A_REV_ACTIVE_ENERGY_ADR);
                    break;
                case PHASE_B_REV_ACTIVE_ENERGY:
                    info = ATM_read(PHASE_B_REV_ACTIVE_ENERGY_ADR);
                    break;
                case PHASE_C_REV_ACTIVE_ENERGY:
                    info = ATM_read(PHASE_C_REV_ACTIVE_ENERGY_ADR);
                    break;
                default:
                    break;
            }
            break;
        case REACTIVE_ENERGY_TYPE:
            switch(reg)
            {
                case TOTAL_FORW_REACTIVE_ENERGY:
                    info = ATM_read(TOTAL_FORW_REACTIVE_ENERGY_ADR);
                    break;
                case PHASE_A_FORW_REACTIVE_ENERGY:
                    info = ATM_read(PHASE_A_FORW_REACTIVE_ENERGY_ADR);
                    break;
                case PHASE_B_FORW_REACTIVE_ENERGY:
                    info = ATM_read(PHASE_B_FORW_REACTIVE_ENERGY_ADR);
                    break;
                case PHASE_C_FORW_REACTIVE_ENERGY:
                    info = ATM_read(PHASE_C_FORW_REACTIVE_ENERGY_ADR);
                    break;
                case TOTAL_REVERSE_REACTIVE_ENERGY:
                    info = ATM_read(TOTAL_REVERSE_REACTIVE_ENERGY_ADR);
                    break;
                case PHASE_A_REV_REACTIVE_ENERGY:
                    info = ATM_read(PHASE_A_REV_REACTIVE_ENERGY_ADR);
                    break;
                case PHASE_B_REV_REACTIVE_ENERGY:
                    info = ATM_read(PHASE_B_REV_REACTIVE_ENERGY_ADR);
                    break;
                case PHASE_C_REV_REACTIVE_ENERGY:
                    info = ATM_read(PHASE_C_REV_REACTIVE_ENERGY_ADR);
                    break;
                default:
                    break;
            }
            break;
        case APPARENT_ENERGY_TYPE:
            switch(reg)
            {
                case TOTAL_ARIT_APPARENT_ENERGY:
                    info = ATM_read(TOTAL_ARIT_APPARENT_ENERGY_ADR);
                    break;
                case PHASE_A_APPARENT_ENERGY:
                    info = ATM_read(PHASE_A_APPARENT_ENERGY_ADR);
                    break;
                case PHASE_B_APPARENT_ENERGY:
                    info = ATM_read(PHASE_B_APPARENT_ENERGY_ADR);
                    break;
                case PHASE_C_APPARENT_ENERGY:
                    info = ATM_read(PHASE_C_APPARENT_ENERGY_ADR);
                    break;
                case TOTAL_VECT_APPARENT_ENERGY:
                    info = ATM_read(TOTAL_VECT_APPARENT_ENERGY_ADR);
                    break;
                default:
                    break;
            }
            break;
        case FUNDAMENTAL_ENERGY_TYPE:
            switch(reg)
            {
                case TOTAL_FORW_ACTIVE_FUND_ENERGY:
                    info = ATM_read(TOTAL_FORW_ACTIVE_FUND_ENERGY_ADR);
                    break;
                case PHASE_A_FORW_ACTIVE_FUND_ENERGY:
                    info = ATM_read(PHASE_A_FORW_ACTIVE_FUND_ENERGY_ADR);
                    break;
                case PHASE_B_FORW_ACTIVE_FUND_ENERGY:
                    info = ATM_read(PHASE_B_FORW_ACTIVE_FUND_ENERGY_ADR);
                    break;
                case PHASE_C_FORW_ACTIVE_FUND_ENERGY:
                    info = ATM_read(PHASE_C_FORW_ACTIVE_FUND_ENERGY_ADR);
                    break;
                case TOTAL_REV_ACTIVE_FUND_ENERGY:
                    info = ATM_read(TOTAL_REV_ACTIVE_FUND_ENERGY_ADR);
                    break;
                case PHASE_A_REV_ACTIVE_FUND_ENERGY:
                    info = ATM_read(PHASE_A_REV_ACTIVE_FUND_ENERGY_ADR);
                    break;
                case PHASE_B_REV_ACTIVE_FUND_ENERGY:
                    info = ATM_read(PHASE_B_REV_ACTIVE_FUND_ENERGY_ADR);
                    break;
                case PHASE_C_REV_ACTIVE_FUND_ENERGY:
                    info = ATM_read(PHASE_C_REV_ACTIVE_FUND_ENERGY_ADR);
                    break;
                default:
                    break;
            }
            break;
        case HARMONIC_ENERGY_TYPE:
            switch(reg)
            {
                case TOTAL_FORW_ACTIVE_HARM_ENERGY:
                    info = ATM_read(TOTAL_FORW_ACTIVE_HARM_ENERGY_ADR);
                    break;
                case PHASE_A_FORW_ACTIVE_HARM_ENERGY:
                    info = ATM_read(PHASE_A_FORW_ACTIVE_HARM_ENERGY_ADR);
                    break;
                case PHASE_B_FORW_ACTIVE_HARM_ENERGY:
                    info = ATM_read(PHASE_B_FORW_ACTIVE_HARM_ENERGY_ADR);
                    break;
                case PHASE_C_FORW_ACTIVE_HARM_ENERGY:
                    info = ATM_read(PHASE_C_FORW_ACTIVE_HARM_ENERGY_ADR);
                    break;
                case TOTAL_REV_ACTIVE_HARM_ENERGY:
                    info = ATM_read(TOTAL_REV_ACTIVE_HARM_ENERGY_ADR);
                    break;
                case PHASE_A_REV_ACTIVE_HARM_ENERGY:
                    info = ATM_read(PHASE_A_REV_ACTIVE_HARM_ENERGY_ADR);
                    break;
                case PHASE_B_REV_ACTIVE_HARM_ENERGY:
                    info = ATM_read(PHASE_B_REV_ACTIVE_HARM_ENERGY_ADR);
                    break;
                case PHASE_C_REV_ACTIVE_HARM_ENERGY:
                    info = ATM_read(PHASE_C_REV_ACTIVE_HARM_ENERGY_ADR);
                    break;
                default:
                    break;
            }
            break;
        case ACTIVE_POWER_TYPE:
            switch(reg)
            {
                case TOTAL_ACTIVE_POWER:
                    info = ATM_read(TOTAL_ACTIVE_POWER_ADR);
                    break;
                case PHASE_A_ACTIVE_POWER:
                    info = ATM_read(PHASE_A_ACTIVE_POWER_ADR);
                    break;
                case PHASE_B_ACTIVE_POWER:
                    info = ATM_read(PHASE_B_ACTIVE_POWER_ADR);
                    break;
                case PHASE_C_ACTIVE_POWER:
                    info = ATM_read(PHASE_C_ACTIVE_POWER_ADR);
                    break;
                default:
                    break;
            }
            break;
        case REACTIVE_POWER_TYPE:
            switch(reg)
            {
                case TOTAL_REACTIVE_POWER:
                    info = ATM_read(TOTAL_REACTIVE_POWER_ADR);
                    break;
                case PHASE_A_REACTIVE_POWER:
                    info = ATM_read(PHASE_A_REACTIVE_POWER_ADR);
                    break;
                case PHASE_B_REACTIVE_POWER:
                    info = ATM_read(PHASE_B_REACTIVE_POWER_ADR);
                    break;
                case PHASE_C_REACTIVE_POWER:
                    info = ATM_read(PHASE_C_REACTIVE_POWER_ADR);
                    break;
                default:
                    break;
            }
            break;
        case APPARENT_POWER_TYPE:
            switch(reg)
            {
                case TOTAL_APPARENT_POWER:
                    info = ATM_read(TOTAL_APPARENT_POWER_ADR);
                    break;
                case PHASE_A_APPARENT_POWER:
                    info = ATM_read(PHASE_A_APPARENT_POWER_ADR);
                    break;
                case PHASE_B_APPARENT_POWER:
                    info = ATM_read(PHASE_B_APPARENT_POWER_ADR);
                    break;
                case PHASE_C_APPARENT_POWER:
                    info = ATM_read(PHASE_C_APPARENT_POWER_ADR);
                    break;
                default:
                    break;
            }
            break;
        case POWER_FACTOR_TYPE:
            switch(reg)
            {
                case TOTAL_POWER_FACTOR:
                    info = ATM_read(TOTAL_POWER_FACTOR_ADR);
                    break;
                case PHASE_A_POWER_FACTOR:
                    info = ATM_read(PHASE_A_POWER_FACTOR_ADR);
                    break;
                case PHASE_B_POWER_FACTOR:
                    info = ATM_read(PHASE_B_POWER_FACTOR_ADR);
                    break;
                case PHASE_C_POWER_FACTOR:
                    info = ATM_read(PHASE_C_POWER_FACTOR_ADR);
                    break;
                default:
                    break;
            }
            break;
        case FUNDAMENTAL_POWER:
            switch(reg)
            {
                case TOTAL_ACTIVE_FUND_POWER:
                    info = ATM_read(TOTAL_ACTIVE_FUND_POWER_ADR);
                    break;
                case PHASE_A_ACTIVE_FUND_POWER:
                    info = ATM_read(PHASE_A_ACTIVE_FUND_POWER_ADR);
                    break;
                case PHASE_B_ACTIVE_FUND_POWER:
                    info = ATM_read(PHASE_B_ACTIVE_FUND_POWER_ADR);
                    break;
                case PHASE_C_ACTIVE_FUND_POWER:
                    info = ATM_read(PHASE_C_ACTIVE_FUND_POWER_ADR);
                    break;
                default:
                    break;
            }
            break;
        case HARMONIC_POWER:
            switch(reg)
            {
                case TOTAL_ACTIVE_HARM_POWER:
                    info = ATM_read(TOTAL_ACTIVE_HARM_POWER_ADR);
                    break;
                case PHASE_A_ACTIVE_HARM_POWER:
                    info = ATM_read(PHASE_A_ACTIVE_HARM_POWER_ADR);
                    break;
                case PHASE_B_ACTIVE_HARM_POWER:
                    info = ATM_read(PHASE_B_ACTIVE_HARM_POWER_ADR);
                    break;
                case PHASE_C_ACTIVE_HARM_POWER:
                    info = ATM_read(PHASE_C_ACTIVE_HARM_POWER_ADR);
                    break;
                default:
                    break;
            }
            break;
        case VOLTAGE_RMS:
            switch(reg)
            {
                case PHASE_A_VOLTAGE_RMS:
                    info = ATM_read(PHASE_A_VOLTAGE_RMS_ADR);
                    break;
                case PHASE_B_VOLTAGE_RMS:
                    info = ATM_read(PHASE_B_VOLTAGE_RMS_ADR);
                    break;
                case PHASE_C_VOLTAGE_RMS:
                    info = ATM_read(PHASE_C_VOLTAGE_RMS_ADR);
                    break;
                default:
                    break;
            }
            break;
        case CURRENT_RMS:
            switch(reg)
            {
                case NLINE_SAMPLED_CURRENT_RMS:
                    info = ATM_read(NLINE_SAMPLED_CURRENT_RMS_ADR);
                    break;
                case NLINE_CALCULATED_CURRENT_RMS:
                    info = ATM_read(NLINE_CALCULATED_CURRENT_RMS_ADR);
                    break;
                case PHASE_A_CURRENT_RMS:
                    info = ATM_read(PHASE_A_CURRENT_RMS_ADR);
                    break;
                case PHASE_B_CURRENT_RMS:
                    info = ATM_read(PHASE_B_CURRENT_RMS_ADR);
                    break;
                case PHASE_C_CURRENT_RMS:
                    info = ATM_read(PHASE_C_CURRENT_RMS_ADR);
                    break;
                default:
                    break;
            }
            break;
        case THDN_TYPE:
            switch(reg)
            {
                case PHASE_A_VOLTAGE_THDN:
                    info = ATM_read(PHASE_A_VOLTAGE_THDN_ADR);
                    break;
                case PHASE_B_VOLTAGE_THDN:
                    info = ATM_read(PHASE_B_VOLTAGE_THDN_ADR);
                    break;
                case PHASE_C_VOLTAGE_THDN:
                    info = ATM_read(PHASE_C_VOLTAGE_THDN_ADR);
                    break;
                case PHASE_A_CURRENT_THDN:
                    info = ATM_read(PHASE_A_CURRENT_THDN_ADR);
                    break;
                case PHASE_B_CURRENT_THDN:
                    info = ATM_read(PHASE_B_CURRENT_THDN_ADR);
                    break;
                case PHASE_C_CURRENT_THDN:
                    info = ATM_read(PHASE_C_CURRENT_THDN_ADR);
                    break;
                default:
                    break;
            }
            break;
        case FREQUENCY_TYPE:
            if(FREQUENCY_REG == reg)
            {
                info = ATM_read(FREQUENCY_REG_ADR);
            }
            break;
        case PHASE_ANGLE_TYPE:
            switch(reg)
            {
                case PHASE_A_MEAN_ANGLE_PHASE:
                    info = ATM_read(PHASE_A_MEAN_ANGLE_PHASE_ADR);
                    break;
                case PHASE_B_MEAN_ANGLE_PHASE:
                    info = ATM_read(PHASE_B_MEAN_ANGLE_PHASE_ADR);
                    break;
                case PHASE_C_MEAN_ANGLE_PHASE:
                    info = ATM_read(PHASE_C_MEAN_ANGLE_PHASE_ADR);
                    break;
                case PHASE_A_VOLTAGE_ANGLE_PHASE:
                    info = ATM_read(PHASE_A_VOLTAGE_ANGLE_PHASE_ADR);
                    break;
                case PHASE_B_VOLTAGE_ANGLE_PHASE:
                    info = ATM_read(PHASE_B_VOLTAGE_ANGLE_PHASE_ADR);
                    break;
                case PHASE_C_VOLTAGE_ANGLE_PHASE:
                    info = ATM_read(PHASE_C_VOLTAGE_ANGLE_PHASE_ADR);
                    break;
                default:
                    break;
            }
            break;
        case TEMPERATURE_TYPE:
            if(TEMPERATURE_REG == reg)
            {
                info = ATM_read(TEMPERATURE_REG_ADR);
            }
            break;
        default:
            break;
    }
    return (info);

}
#endif