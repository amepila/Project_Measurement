#include <xc.h>
#include "ATM90E36A.h"
#include "GPIO.h"
#include "SPI.h"

#define LOW_PART_16BITS     0x0F
#define HIGH_PART_16BITS    0xF0
#define NEXT_FRAME          8
#define NUMBER_CONFIG_REG   10
#define MOD_CS0             0x100

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

typedef struct
{
    uint8_t lowPart;
    uint8_t highPart;
    uint16_t dummyLow;
    uint16_t dummyHigh;
} Data_TwoFrames;

static uint16_t calculate_CS0(void)
{
    uint8_t counter;
    uint8_t lowCS0 = 0;
    uint8_t highCS0 = 0;
    uint16_t totalCS0 = 0;
    uint16_t dummyLow[10];
    uint16_t dummyHigh[10];
    uint8_t lowPart[10];
    uint8_t highPart[10];
    
    for(counter = 0; counter < NUMBER_CONFIG_REG; counter++)
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

    for(counter = 0; counter < (2*NUMBER_CONFIG_REG); counter++)
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
    GPIO_dataDirectionPIN(GPIO_A, 6, GPIO_INPUT);
    /**ZX2 pin*/
    GPIO_dataDirectionPIN(GPIO_A, 7, GPIO_INPUT);
    
    /**Power Mode: Normal*/
    GPIO_setPIN(GPIO_B, 5);
    GPIO_setPIN(GPIO_B, 6);
    
    /**Slave Mode*/
    GPIO_clearPIN(GPIO_B, 3);
}

void ATM_calibration(void)
{
    uint16_t checksum0;
    
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
  
}

