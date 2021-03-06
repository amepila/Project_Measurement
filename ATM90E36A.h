#ifndef ATM90E36A_H_
#define	ATM90E36A_H_

#include <stdint.h>

typedef enum
{
    ACTIVE_ENERGY_TYPE,
    REACTIVE_ENERGY_TYPE,
    APPARENT_ENERGY_TYPE,
    FUNDAMENTAL_ENERGY_TYPE,
    HARMONIC_ENERGY_TYPE,
    ACTIVE_POWER_TYPE,
    REACTIVE_POWER_TYPE,
    APPARENT_POWER_TYPE,
    POWER_FACTOR_TYPE,
    FUNDAMENTAL_POWER,
    HARMONIC_POWER,
    VOLTAGE_RMS,
    CURRENT_RMS,
    THDN_TYPE,
    FREQUENCY_TYPE,
    PHASE_ANGLE_TYPE,
    TEMPERATURE_TYPE
} ATM_type_t;

typedef enum
{
    TOTAL_FORW_ACTIVE_ENERGY,
    PHASE_A_FORW_ACTIVE_ENERGY,
    PHASE_B_FORW_ACTIVE_ENERGY,
    PHASE_C_FORW_ACTIVE_ENERGY,
    TOTAL_REV_ACTIVE_ENERGY,
    PHASE_A_REV_ACTIVE_ENERGY,
    PHASE_B_REV_ACTIVE_ENERGY,
    PHASE_C_REV_ACTIVE_ENERGY,
    TOTAL_FORW_REACTIVE_ENERGY,
    PHASE_A_FORW_REACTIVE_ENERGY,
    PHASE_B_FORW_REACTIVE_ENERGY,
    PHASE_C_FORW_REACTIVE_ENERGY,
    TOTAL_REVERSE_REACTIVE_ENERGY,
    PHASE_A_REV_REACTIVE_ENERGY,
    PHASE_B_REV_REACTIVE_ENERGY,
    PHASE_C_REV_REACTIVE_ENERGY,
    TOTAL_ARIT_APPARENT_ENERGY,
    PHASE_A_APPARENT_ENERGY,
    PHASE_B_APPARENT_ENERGY,
    PHASE_C_APPARENT_ENERGY,
    TOTAL_VECT_APPARENT_ENERGY,
    TOTAL_FORW_ACTIVE_FUND_ENERGY,
    PHASE_A_FORW_ACTIVE_FUND_ENERGY,
    PHASE_B_FORW_ACTIVE_FUND_ENERGY,
    PHASE_C_FORW_ACTIVE_FUND_ENERGY,
    TOTAL_REV_ACTIVE_FUND_ENERGY,
    PHASE_A_REV_ACTIVE_FUND_ENERGY,
    PHASE_B_REV_ACTIVE_FUND_ENERGY,
    PHASE_C_REV_ACTIVE_FUND_ENERGY,
    TOTAL_FORW_ACTIVE_HARM_ENERGY,
    PHASE_A_FORW_ACTIVE_HARM_ENERGY,
    PHASE_B_FORW_ACTIVE_HARM_ENERGY,
    PHASE_C_FORW_ACTIVE_HARM_ENERGY,
    TOTAL_REV_ACTIVE_HARM_ENERGY,
    PHASE_A_REV_ACTIVE_HARM_ENERGY,
    PHASE_B_REV_ACTIVE_HARM_ENERGY,
    PHASE_C_REV_ACTIVE_HARM_ENERGY,
    TOTAL_ACTIVE_POWER,
    PHASE_A_ACTIVE_POWER,
    PHASE_B_ACTIVE_POWER,
    PHASE_C_ACTIVE_POWER,
    TOTAL_REACTIVE_POWER,
    PHASE_A_REACTIVE_POWER,
    PHASE_B_REACTIVE_POWER,
    PHASE_C_REACTIVE_POWER,
    TOTAL_APPARENT_POWER,
    PHASE_A_APPARENT_POWER,
    PHASE_B_APPARENT_POWER,
    PHASE_C_APPARENT_POWER,
    TOTAL_POWER_FACTOR,
    PHASE_A_POWER_FACTOR,
    PHASE_B_POWER_FACTOR,
    PHASE_C_POWER_FACTOR,
    TOTAL_ACTIVE_FUND_POWER,
    PHASE_A_ACTIVE_FUND_POWER,
    PHASE_B_ACTIVE_FUND_POWER,
    PHASE_C_ACTIVE_FUND_POWER,
    TOTAL_ACTIVE_HARM_POWER,
    PHASE_A_ACTIVE_HARM_POWER,
    PHASE_B_ACTIVE_HARM_POWER,
    PHASE_C_ACTIVE_HARM_POWER,
    NLINE_SAMPLED_CURRENT_RMS,
    PHASE_A_VOLTAGE_RMS,
    PHASE_B_VOLTAGE_RMS,
    PHASE_C_VOLTAGE_RMS,
    NLINE_CALCULATED_CURRENT_RMS,
    PHASE_A_CURRENT_RMS,
    PHASE_B_CURRENT_RMS,
    PHASE_C_CURRENT_RMS,
    PHASE_A_VOLTAGE_THDN,
    PHASE_B_VOLTAGE_THDN,
    PHASE_C_VOLTAGE_THDN,
    PHASE_A_CURRENT_THDN,
    PHASE_B_CURRENT_THDN,
    PHASE_C_CURRENT_THDN,
    FREQUENCY_REG,
    PHASE_A_MEAN_ANGLE_PHASE,
    PHASE_B_MEAN_ANGLE_PHASE,
    PHASE_C_MEAN_ANGLE_PHASE,
    TEMPERATURE_REG,
    PHASE_A_VOLTAGE_ANGLE_PHASE,
    PHASE_B_VOLTAGE_ANGLE_PHASE,
    PHASE_C_VOLTAGE_ANGLE_PHASE
} ATM_reg_t;

void ATM_init(void);

void ATM_calibration(void);

uint16_t ATM_registers(ATM_type_t type, ATM_reg_t reg);

#endif	

