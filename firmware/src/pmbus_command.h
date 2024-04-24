/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _PMBUS_COMMAND_H    /* Guard against multiple inclusion */
#define _PMBUS_COMMAND_H
#include "definitions.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#define PMBUS_PAGE              0x00
#define PMBUS_OPERATION			0x01
#define PMBUS_ON_OFF_CONFIG		0x02
#define CLEAR_FAULTS            0x03
#define PMBUS_PHASE             0x04
#define PAGE_PLUS_WRITE         0x05
#define CAPABILITY_Data         0x30

#define PMBUS_WRITE_PROTECT		0x10
        
#define CAPABILITY              0x19
#define PMBUS_QUERY             0x1a
#define	PMBUS_SMBALERT_MASK     0x1b
#define VOUT_MODE               0x20
#define VOUT_COMMAND            0x21
#define VOUT_TRIM               0x22
#define VOUT_CAL_OFFSET         0x23
#define	VOUT_MAX                0x24
#define	VOUT_MARGIN_HIGH        0x25
#define	VOUT_MARGIN_LOW         0x26
#define	VOUT_TRANSITION_RATE   	0x27
#define VOUT_DROOP              0x28
#define VOUT_SCALE_LOOP         0x29
#define	VOUT_SCALE_MONITOR      0x2a

#define	PMBUS_COEFFICIENTS		0x30
#define	POUT_MAX            	0x31

#define FAN_CONFIG_12          0x3a    /*Mike Fixed Command Format Error*/
#define FAN_COMMAND_1           0x3b
#define FAN_COMMAND_2   		0x3c
#define	FAN_CONFIG_34           0x3d
#define	FAN_COMMAND_3           0x3e
#define	FAN_COMMAND_4           0x3f

#define	VOUT_OV_FAULT_LIMIT     0x40
#define	VOUT_OV_FAULT_RESPONSE	0x41
#define	VOUT_OV_WARN_LIMIT      0x42
#define	VOUT_UV_WARN_LIMIT      0x43
#define VOUT_UV_FAULT_LIMIT     0x44
#define	VOUT_UV_FAULT_RESPONSE	0x45
#define IOUT_OC_FAULT_LIMIT     0x46
#define IOUT_OC_FAULT_RESPONSE  0x47
#define IOUT_OC_LV_FAULT_LIMIT	0x48
#define	IOUT_OC_LV_FAULT_RESPONSE   0x49
#define IOUT_OC_WARNING_LIMIT   0x4a
#define IOUT_UC_FAULT_LIMIT     0x4b
#define IOUT_UC_FAULT_RESPONSE	0x4c

#define OT_FAULT_LIMIT          0x4f
#define	OT_FAULT_RESPONSE		0x50
#define OT_WARN_LIMIT           0x51
#define UT_WARN_LIMIT           0x52
#define UT_FAULT_LIMIT          0x53
#define UT_FAULT_RESPONSE		0x54
#define	VIN_OV_FAULT_LIMIT      0x55
#define	VIN_OV_FAULT_RESPONSE	0x56
#define VIN_OV_WARN_LIMIT		0x57
#define	VIN_UV_WARN_LIMIT		0x58
#define VIN_UV_FAULT_LIMIT      0x59
\
#define IIN_OC_FAULT_LIMIT      0x5b
#define IIN_OC_WARN_LIMIT       0x5d   

#define POUT_OP_FAULT_LIMIT     0x68
#define POUT_OP_WARN_LIMIT      0x6a
#define PIN_OP_WARN_LIMIT       0x6b

#define STATUS_BYTE             0x78
#define STATUS_WORD             0x79
#define STATUS_VOUT             0x7a
#define STATUS_IOUT             0x7b
#define STATUS_INPUT            0x7c
#define STATUS_TEMPERATURE      0x7d
#define STATUS_CML              0x7e
#define STATUS_OTHER            0x7f
#define STATUS_MFR_SPECIFIC     0x80
#define STATUS_FANS_1_2         0x81
#define STATUS_FAN_34           0x82

#define READ_EIN                0x86
#define READ_EOUT               0x87

#define READ_VIN                0x88
#define READ_IIN                0x89
#define READ_VCAP               0x8a
#define READ_VOUT               0x8b
#define READ_IOUT               0x8c
#define READ_TEMPERATURE_1      0x8d
#define READ_TEMPERATURE_2_1    0x8e
#define READ_TEMPERATURE_2_2    0x8f
#define READ_FAN_SPEED_1        0x90
#define READ_FAN_SPEED_2		0x91
#define	READ_FAN_SPEED_3		0x92
#define	READ_FAN_SPEED_4		0x93
#define	READ_DUTY_CYCLE     	0x94
#define READ_FREQUENCY      	0x95
#define READ_POUT               0x96
#define READ_PIN                0x97

#define PMBUS_REVISION			0x98
#define	PMBUS_MFR_ID			0x99
#define	PMBUS_MFR_MODEL			0x9a
#define	PMBUS_MFR_REVISION		0x9b
#define	PMBUS_MFR_LOCATION		0x9c
#define	PMBUS_MFR_DATE			0x9d
#define	PMBUS_MFR_SERIAL		0x9e

#define MFR_VIN_MIN             0xa0
#define MFR_VIN_MAX             0xa1
#define MFR_IIN_MAX             0xa2
#define MFR_PIN_MAX             0xa3
#define MFR_VOUT_MIN            0xa4
#define MFR_VOUT_MAX            0xa5
#define MFR_IOUT_MAX            0xa6
#define MFR_POUT_MAX            0xa7

#define IC_DEVICE_ID    		0xad
#define	IC_DEVICE_REV       	0xae

#define MFR_MAX_TEMP_1          0xc0
#define MFR_MAX_TEMP_2          0xc1
#define MFR_MAX_TEMP_3      	0xc2



#define UN_PMBUS_STATUS         0xff

// struct CmdTypeLength {
//     uint8_t cmd;
//     unsigned int length;
// };

// extern struct CmdTypeLength pmbus_psu_length[];
// uint8_t* processCommand(uint16_t PSU_PMBUS_ADDR, uint8_t* CmdArrayPtr, unsigned int PMbuswrLength,unsigned int PMbusrdLength);
// extern unsigned int PMbuswrLength;

extern uint8_t PSU0_PMBUS_PAGE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_CAPABILITY_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_VOUT_MODE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_FAN_CONFIG_12_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_FAN_COMMAND_1_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_IOUT_OC_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_IOUT_OC_WARNING_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_OT_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_IIN_OC_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_POUT_OP_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_PIN_OP_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_STATUS_WORD_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_STATUS_VOUT_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_STATUS_IOUT_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_STATUS_INPUT_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_STATUS_TEMPERATURE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_STATUS_CML_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_STATUS_MFR_SPECIFIC_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_STATUS_FANS_1_2_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_READ_VIN_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_IIN_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_VOUT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_IOUT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_TEMPERATURE_1_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_TEMPERATURE_2_1_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_TEMPERATURE_2_2_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_FAN_SPEED_1_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_POUT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_PIN_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_MFR_VIN_MIN_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_MFR_VIN_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_MFR_IIN_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_MFR_PIN_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_MFR_VOUT_MIN_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_MFR_VOUT_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_MFR_IOUT_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_MFR_POUT_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_MFR_MAX_TEMP_1_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_MFR_MAX_TEMP_2_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_CLEAR_FAULTS_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_OPERATION_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_ON_OFF_CONFIG_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_PHASE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_WRITE_PROTECT_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_QUERY_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_SMBALERT_MASK_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_COMMAND_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_TRIM_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_CAL_OFFSET_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_MARGIN_HIGH_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_MARGIN_LOW_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_TRANSITION_RATE_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_DROOP_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_SCALE_LOOP_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_SCALE_MONITOR_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_COEFFICIENTS_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU0_POUT_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_FAN_COMMAND_2_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_FAN_CONFIG_34_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_FAN_COMMAND_3_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_FAN_COMMAND_4_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_OV_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_OV_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_VOUT_OV_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_UV_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_UV_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VOUT_UV_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_IOUT_OC_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_IOUT_OC_LV_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_IOUT_OC_LV_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_IOUT_UC_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_IOUT_UC_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_OT_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_OT_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_UT_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_UT_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_UT_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_VIN_OV_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VIN_OV_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_VIN_OV_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VIN_UV_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_VIN_UV_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_IIN_OC_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_POUT_OP_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_STATUS_BYTE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_STATUS_OTHER_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_STATUS_FAN_34_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_READ_VCAP_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_FAN_SPEED_2_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_FAN_SPEED_3_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_FAN_SPEED_4_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_DUTY_CYCLE_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_READ_FREQUENCY_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_REVISION_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_MFR_ID_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_MFR_MODEL_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_MFR_REVISION_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_MFR_LOCATION_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_MFR_DATE_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU0_PMBUS_MFR_SERIAL_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU0_IC_DEVICE_ID_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU0_IC_DEVICE_REV_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU0_MFR_MAX_TEMP_3_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU0_PAGE_PLUS_WRITE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU0_READ_EIN_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU0_READ_EOUT_Data[PMBUS_SIX_SIZE_BYTES];

extern uint8_t PSU1_PMBUS_PAGE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_CAPABILITY_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_VOUT_MODE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_FAN_CONFIG_12_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_FAN_COMMAND_1_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_IOUT_OC_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_IOUT_OC_WARNING_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_OT_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_IIN_OC_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_POUT_OP_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_PIN_OP_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_STATUS_WORD_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_STATUS_VOUT_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_STATUS_IOUT_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_STATUS_INPUT_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_STATUS_TEMPERATURE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_STATUS_CML_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_STATUS_MFR_SPECIFIC_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_STATUS_FANS_1_2_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_READ_VIN_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_IIN_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_VOUT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_IOUT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_TEMPERATURE_1_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_TEMPERATURE_2_1_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_TEMPERATURE_2_2_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_FAN_SPEED_1_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_POUT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_PIN_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_MFR_VIN_MIN_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_MFR_VIN_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_MFR_IIN_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_MFR_PIN_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_MFR_VOUT_MIN_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_MFR_VOUT_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_MFR_IOUT_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_MFR_POUT_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_MFR_MAX_TEMP_1_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_MFR_MAX_TEMP_2_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_CLEAR_FAULTS_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_OPERATION_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_ON_OFF_CONFIG_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_PHASE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_WRITE_PROTECT_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_QUERY_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_SMBALERT_MASK_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_COMMAND_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_TRIM_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_CAL_OFFSET_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_MARGIN_HIGH_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_MARGIN_LOW_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_TRANSITION_RATE_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_DROOP_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_SCALE_LOOP_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_SCALE_MONITOR_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_COEFFICIENTS_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU1_POUT_MAX_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_FAN_COMMAND_2_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_FAN_CONFIG_34_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_FAN_COMMAND_3_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_FAN_COMMAND_4_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_OV_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_OV_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_VOUT_OV_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_UV_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_UV_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VOUT_UV_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_IOUT_OC_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_IOUT_OC_LV_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_IOUT_OC_LV_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_IOUT_UC_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_IOUT_UC_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_OT_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_OT_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_UT_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_UT_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_UT_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_VIN_OV_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VIN_OV_FAULT_RESPONSE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_VIN_OV_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VIN_UV_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_VIN_UV_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_IIN_OC_FAULT_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_POUT_OP_WARN_LIMIT_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_STATUS_BYTE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_STATUS_OTHER_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_STATUS_FAN_34_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_READ_VCAP_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_FAN_SPEED_2_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_FAN_SPEED_3_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_FAN_SPEED_4_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_DUTY_CYCLE_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_READ_FREQUENCY_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_REVISION_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_MFR_ID_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_MFR_MODEL_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_MFR_REVISION_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_MFR_LOCATION_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_MFR_DATE_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU1_PMBUS_MFR_SERIAL_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU1_IC_DEVICE_ID_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU1_IC_DEVICE_REV_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU1_MFR_MAX_TEMP_3_Data[PMBUS_THREE_SIZE_BYTES];
extern uint8_t PSU1_PAGE_PLUS_WRITE_Data[PMBUS_TWO_SIZE_BYTES];
extern uint8_t PSU1_READ_EIN_Data[PMBUS_SIX_SIZE_BYTES];
extern uint8_t PSU1_READ_EOUT_Data[PMBUS_SIX_SIZE_BYTES];

typedef struct{
    uint8_t* key;
    unsigned int value;
    uint8_t cmd;
}KeyValue;

typedef struct {
    KeyValue psu0_table[MFR_MAX_TEMP_3 + 1];
    KeyValue psu1_table[MFR_MAX_TEMP_3 + 1];
}DataMap;

extern DataMap PSU_Data;

uint8_t PSU_Data_Return(DataMap *PSU, uint16_t CurrentADDR,  uintptr_t I2C_Got_Addr_NOW, uintptr_t SERCOM_NOW, uint8_t PMbus_CMD, uint8_t PMbus_CMD_Size);
void SERCOM1_PSU_Data_Return(DataMap *PSU, uint16_t CurrentADDR,  uintptr_t I2C_Got_Addr_NOW, uintptr_t SERCOM_NOW, uint8_t PMbus_CMD, uint8_t PMbus_CMD_Size);
void SERCOM2_PSU_Data_Return(DataMap *PSU, uint16_t CurrentADDR,  uintptr_t I2C_Got_Addr_NOW, uintptr_t SERCOM_NOW, uint8_t PMbus_CMD, uint8_t PMbus_CMD_Size);
void SERCOM3_PSU_Data_Return(DataMap *PSU, uint16_t CurrentADDR,  uintptr_t I2C_Got_Addr_NOW, uintptr_t SERCOM_NOW, uint8_t PMbus_CMD, uint8_t PMbus_CMD_Size);
void SERCOM4_PSU_Data_Return(DataMap *PSU, uint16_t CurrentADDR,  uintptr_t I2C_Got_Addr_NOW, uintptr_t SERCOM_NOW, uint8_t PMbus_CMD, uint8_t PMbus_CMD_Size);
void Read_PSU0_PMbus_Data(DataMap *PSU);
void Read_PSU1_PMbus_Data(DataMap *PSU);

#endif /* _PMBUS_COMMAND_H */

/* *****************************************************************************
 End of File
 */
