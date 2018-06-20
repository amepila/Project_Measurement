#include <xc.h>
#include "ATM90E36A.h"
#include "GPIO.h"
#include "SPI.h"

#define LOW_PART_16BITS     0x0F
#define HIGH_PART_16BITS    0xF0
#define NEXT_FRAME          8
#define NOCONFIG_REG_CS0    10
#define NOCONFIG_REG_CS3    14
#define MOD_CS0             0x100
#define MOD_CS3             0x00
#define AV_SAMPLES_RMS      10
#define SPR_LOW7BITS        7

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
    uint16_t uoffsetAvg;
    uint16_t ioffsetAvg;
} Data_VI_Avg;

typedef struct
{
    uint16_t poffsetAvg;
    uint16_t qoffsetAvg;
    uint16_t pfoffsetAvg;
} Data_Pow_Avg;

static uint16_t calculate_CS0(void)
{
    uint8_t counter;
    uint8_t lowCS0 = 0;
    uint8_t highCS0 = 0;
    uint16_t totalCS0 = 0;
    uint16_t dummyLow[NOCONFIG_REG_CS0];
    uint16_t dummyHigh[NOCONFIG_REG_CS0];
    uint8_t lowPart[NOCONFIG_REG_CS0];
    uint8_t highPart[NOCONFIG_REG_CS0];
    
    for(counter = 0; counter < NOCONFIG_REG_CS0; counter++)
    {
        switch(counter)
        {
            case 0:
                dummyLow[counter] = MC_HIGH;
                dummyHigh[counter] = MC_HIGH;
                break;
            case 1: 
                dummyLow[counter] = MC_LOW;
                dummyHigh[counter] = MC_LOW;
                break;
            case 2: 
                dummyLow[counter] = MMODE0_DATA;
                dummyHigh[counter] = MMODE0_DATA;
                break;
            case 3:
                dummyLow[counter] = MMODE1_DATA;
                dummyHigh[counter] = MMODE1_DATA;
                break;
            case 4:
                dummyLow[counter] = PSTART_TH;
                dummyHigh[counter] = PSTART_TH;
                break;
            case 5:
                dummyLow[counter] = QSTART_TH;
                dummyHigh[counter] = QSTART_TH;
                break;
            case 6:
                dummyLow[counter] = SSTART_TH;
                dummyHigh[counter] = SSTART_TH;
                break;
            case 7:
                dummyLow[counter] = PPHASE_TH;
                dummyHigh[counter] = PPHASE_TH;
                break;
            case 8:
                dummyLow[counter] = QPHASE_TH;
                dummyHigh[counter] = QPHASE_TH;
                break;
            case 9:
                dummyLow[counter] = SPHASE_TH;
                dummyHigh[counter] = SPHASE_TH;
                break;
            default:
                break;
        }
        
        dummyLow[counter] &= LOW_PART_16BITS;
        dummyHigh[counter] &= HIGH_PART_16BITS;
        
        lowPart[counter] = (uint8_t)dummyLow[counter];
        highPart[counter] = (uint8_t)dummyHigh[counter];
    }

    for(counter = 0; counter < (2*NOCONFIG_REG_CS0); counter++)
    {
        if(counter < 10)
        {
            lowCS0 += highPart[counter];
            highCS0 ^= highPart[counter];
        }
        else
        {
            lowCS0 += lowPart[counter];
            highCS0 ^= lowPart[counter];
        }
    }
    lowCS0 = lowCS0 % MOD_CS0;
    totalCS0 |= (highCS0 << NEXT_FRAME);
    totalCS0 |= lowCS0;

    return (totalCS0);    
}

static uint16_t calculate_CS3(void)
{
    uint8_t counter;
    uint8_t lowCS3 = 0;
    uint8_t highCS3 = 0;
    uint16_t totalCS3 = 0;
    uint16_t dummyLow[NOCONFIG_REG_CS3];
    uint16_t dummyHigh[NOCONFIG_REG_CS3];
    uint8_t lowPart[NOCONFIG_REG_CS3];
    uint8_t highPart[NOCONFIG_REG_CS3];
    
    for(counter = 0; counter < NOCONFIG_REG_CS3; counter++)
    {
        switch(counter)
        {
            case 0:
                dummyLow[counter] = MC_HIGH;
                dummyHigh[counter] = MC_HIGH;
                break;
            case 1: 
                dummyLow[counter] = MC_LOW;
                dummyHigh[counter] = MC_LOW;
                break;
            case 2: 
                dummyLow[counter] = MMODE0_DATA;
                dummyHigh[counter] = MMODE0_DATA;
                break;
            case 3:
                dummyLow[counter] = MMODE1_DATA;
                dummyHigh[counter] = MMODE1_DATA;
                break;
            case 4:
                dummyLow[counter] = PSTART_TH;
                dummyHigh[counter] = PSTART_TH;
                break;
            case 5:
                dummyLow[counter] = QSTART_TH;
                dummyHigh[counter] = QSTART_TH;
                break;
            case 6:
                dummyLow[counter] = SSTART_TH;
                dummyHigh[counter] = SSTART_TH;
                break;
            case 7:
                dummyLow[counter] = PPHASE_TH;
                dummyHigh[counter] = PPHASE_TH;
                break;
            case 8:
                dummyLow[counter] = QPHASE_TH;
                dummyHigh[counter] = QPHASE_TH;
                break;
            case 9:
                dummyLow[counter] = SPHASE_TH;
                dummyHigh[counter] = SPHASE_TH;
                break;
            default:
                break;
        }
        
        dummyLow[counter] &= LOW_PART_16BITS;
        dummyHigh[counter] &= HIGH_PART_16BITS;
        
        lowPart[counter] = (uint8_t)dummyLow[counter];
        highPart[counter] = (uint8_t)dummyHigh[counter];
    }

    for(counter = 0; counter < (2*NOCONFIG_REG_CS3); counter++)
    {
        if(counter < 10)
        {
            lowCS3 += highPart[counter];
            highCS3 ^= highPart[counter];
        }
        else
        {
            lowCS3 += lowPart[counter];
            highCS3 ^= lowPart[counter];
        }
    }
    lowCS3 = lowCS3 % MOD_CS3;
    totalCS3 |= (highCS3 << NEXT_FRAME);
    totalCS3 |= lowCS3;

    return (totalCS3);    
}
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
    
    SPI_write(register_To_IC.lowPart);
    SPI_write(register_To_IC.highPart);
    
    SPI_write(data_To_IC.lowPart);
    SPI_write(data_To_IC.highPart);
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
    
    SPI_write(register_To_IC.lowPart);
    SPI_write(register_To_IC.highPart);
    
    data_From_IC.dummyLow = SPI_read();
    data_From_IC.dummyHigh = SPI_read();
    
    data_From_IC.lowPart = data_From_IC.dummyLow;
    data_From_IC.highPart = data_From_IC.dummyHigh<<NEXT_FRAME;
    
    data = (data_From_IC.highPart|data_From_IC.lowPart);
    
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
    GPIO_dataDirectionPIN(GPIO_B, 6, GPIO_OUTPUT);
    /**WarnOut pin*/
    GPIO_dataDirectionPIN(GPIO_B, 7, GPIO_INPUT);
    
    /**IRQ0 pin*/
    GPIO_dataDirectionPIN(GPIO_C, 2, GPIO_INPUT);
    /**IRQ1 pin*/
    GPIO_dataDirectionPIN(GPIO_C, 1, GPIO_INPUT);
    /**ZX0 pin*/
    GPIO_dataDirectionPIN(GPIO_C, 0, GPIO_INPUT);
    
    /**ZX1 pin*/
    GPIO_dataDirectionPIN(GPIO_A, 2, GPIO_INPUT);
    ANS2 = 0;
    /**ZX2 pin*/
    GPIO_dataDirectionPIN(GPIO_A, 1, GPIO_INPUT);
    ANS1 = 0;
    
    /**Power Mode: Normal*/
    GPIO_setPIN(GPIO_B, 5);
    GPIO_setPIN(GPIO_B, 6);
    
    /**Slave Mode*/
    GPIO_clearPIN(GPIO_B, 3);
}

void ATM_calibration(void)
{
    uint16_t checksum0;
    uint16_t checksum3;
    uint8_t counter;
    
    Data_VI_Avg phaseA = {0};
    Data_VI_Avg phaseB = {0};
    Data_VI_Avg phaseC = {0};
    Data_VI_Avg phaseN = {0};
    
    Data_Pow_Avg phaseA_pow = {0};
    Data_Pow_Avg phaseB_pow = {0};
    Data_Pow_Avg phaseC_pow = {0};

          
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
        checksum0 = calculate_CS0();
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
    
    /**Two's complement of registers*/
    phaseA_pow.poffsetAvg = phaseA_pow.poffsetAvg >> SPR_LOW7BITS;
    phaseA_pow.qoffsetAvg = phaseA_pow.qoffsetAvg >> SPR_LOW7BITS;
    phaseA_pow.pfoffsetAvg = phaseA_pow.pfoffsetAvg >> SPR_LOW7BITS;
    
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
    
    /**Two's complement of registers*/
    phaseB_pow.poffsetAvg = phaseB_pow.poffsetAvg >> SPR_LOW7BITS;
    phaseB_pow.qoffsetAvg = phaseB_pow.qoffsetAvg >> SPR_LOW7BITS;
    phaseB_pow.pfoffsetAvg = phaseB_pow.pfoffsetAvg >> SPR_LOW7BITS;
    
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
    
    /**Two's complement of registers*/
    phaseC_pow.poffsetAvg = phaseC_pow.poffsetAvg >> SPR_LOW7BITS;
    phaseC_pow.qoffsetAvg = phaseC_pow.qoffsetAvg >> SPR_LOW7BITS;
    phaseC_pow.pfoffsetAvg = phaseC_pow.pfoffsetAvg >> SPR_LOW7BITS;
    
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
    
}

