#include <xc.h>
#include "ATM90E36A.h"
#include "GPIO.h"
#include "SPI.h"

#define LOW_PART_16BITS     0x0F
#define HIGH_PART_16BITS    0xF0
#define NEXT_FRAME          8

/**Startup registers*/
#define CONFIG_START        0x30
#define CAL_START           0x40
#define HARM_START          0x50
#define ADJ_START           0x60

/**Startup register value*/
#define ROWER_UP_STATE      0x6886
#define CALIBRATION        0x5678
#define OPERATION           0x8765

typedef struct
{
    uint8_t lowPart;
    uint8_t highPart;
    uint16_t dummyLow;
    uint16_t dummyHigh;
} Data_TwoFrames;

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
    ATM_write(CONFIG_START, CALIBRATION);
}

