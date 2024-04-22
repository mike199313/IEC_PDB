/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */
#include "i2c_address.h"
#include "Purnell_OEM.h"
#include "pmbus_command.h"
#include "definitions.h"                // SYS function prototypes
#include <string.h>
#include <stdio.h>


int PSU_Flag = 0;

//Get the Packing Payload Data
void SERCOM1_PSU_Data_Return(DataMap *PSU, uint16_t CurrentADDR,  uintptr_t I2C_Got_Addr_NOW, uintptr_t SERCOM_NOW, uint8_t PMbus_CMD, uint8_t PMbus_CMD_Size)
{
    if(PMbus_CMD_Size < CMD_SIZE_ONE_BYTE ) //PMbus CMD Size is 0 base
    {
        switch(I2C_Got_Addr_NOW)
            {       
            case PSU0_PMBUS_BMC_SIDE_ADDR:
                if (PSU->psu1_table[PMbus_CMD].cmd == PMbus_CMD)
                {
                    SERCOM1_I2C_WriteByte(PSU->psu1_table[PMbus_CMD].key[CurrentADDR]);
                    break;
                }
                else
                {
                    SERCOM1_I2C_WriteByte(UN_PMBUS_STATUS);
                    break;
                }
            case PSU1_PMBUS_BMC_SIDE_ADDR:
                if (PSU->psu2_table[PMbus_CMD].cmd == PMbus_CMD)
                {
                    SERCOM1_I2C_WriteByte(PSU->psu2_table[PMbus_CMD].key[CurrentADDR]);
                    break;
                }
                else
                {
                    SERCOM1_I2C_WriteByte(UN_PMBUS_STATUS);
                    break;                   
                }
            default:
                SERCOM1_I2C_WriteByte(INVALID_DATA);
                break;
            }
    }
    else
    {
        SERCOM1_I2C_WriteByte(DATA_LENGTH_INVALID);
        return;
    }

}

void SERCOM2_PSU_Data_Return(DataMap *PSU, uint16_t CurrentADDR,  uintptr_t I2C_Got_Addr_NOW, uintptr_t SERCOM_NOW, uint8_t PMbus_CMD, uint8_t PMbus_CMD_Size)
{
    if(PMbus_CMD_Size < CMD_SIZE_ONE_BYTE ) //PMbus CMD Size is 0 base
    {
        switch(I2C_Got_Addr_NOW)
            {       
            case PSU0_PMBUS_BMC_SIDE_ADDR:
                if (PSU->psu1_table[PMbus_CMD].cmd == PMbus_CMD)
                {
                    SERCOM2_I2C_WriteByte(PSU->psu1_table[PMbus_CMD].key[CurrentADDR]);
                    break;
                }
                else
                {
                    SERCOM2_I2C_WriteByte(UN_PMBUS_STATUS);
                    break;
                }
            case PSU1_PMBUS_BMC_SIDE_ADDR:
                if (PSU->psu2_table[PMbus_CMD].cmd == PMbus_CMD)
                {
                    SERCOM2_I2C_WriteByte(PSU->psu2_table[PMbus_CMD].key[CurrentADDR]);
                    break;
                }
                else
                {
                    SERCOM2_I2C_WriteByte(UN_PMBUS_STATUS);
                    break;                   
                }
            default:
                SERCOM2_I2C_WriteByte(INVALID_DATA);
                break;
            }
    }
    else
    {
        SERCOM2_I2C_WriteByte(DATA_LENGTH_INVALID);
    }

}

void SERCOM3_PSU_Data_Return(DataMap *PSU, uint16_t CurrentADDR,  uintptr_t I2C_Got_Addr_NOW, uintptr_t SERCOM_NOW, uint8_t PMbus_CMD, uint8_t PMbus_CMD_Size)
{
    if(PMbus_CMD_Size < CMD_SIZE_ONE_BYTE ) //PMbus CMD Size is 0 base
    {
        switch(I2C_Got_Addr_NOW)
            {       
            case PSU0_PMBUS_BMC_SIDE_ADDR:
                if (PSU->psu1_table[PMbus_CMD].cmd == PMbus_CMD)
                {
                    SERCOM3_I2C_WriteByte(PSU->psu1_table[PMbus_CMD].key[CurrentADDR]);
                    break;
                }
                else
                {
                    SERCOM3_I2C_WriteByte(UN_PMBUS_STATUS);
                    break;
                }
            case PSU1_PMBUS_BMC_SIDE_ADDR:
                if (PSU->psu2_table[PMbus_CMD].cmd == PMbus_CMD)
                {
                    SERCOM3_I2C_WriteByte(PSU->psu2_table[PMbus_CMD].key[CurrentADDR]);
                    break;
                }
                else
                {
                    SERCOM3_I2C_WriteByte(UN_PMBUS_STATUS);
                    break;                   
                }
            default:
                SERCOM3_I2C_WriteByte(INVALID_DATA);
                break;
            }
    }
    else
    {
        SERCOM3_I2C_WriteByte(DATA_LENGTH_INVALID);
    }

}

void SERCOM4_PSU_Data_Return(DataMap *PSU, uint16_t CurrentADDR,  uintptr_t I2C_Got_Addr_NOW, uintptr_t SERCOM_NOW, uint8_t PMbus_CMD, uint8_t PMbus_CMD_Size)
{
    if(PMbus_CMD_Size < CMD_SIZE_ONE_BYTE ) //PMbus CMD Size is 0 base
    {
        switch(I2C_Got_Addr_NOW)
            {       
            case PSU0_PMBUS_BMC_SIDE_ADDR:
                if (PSU->psu1_table[PMbus_CMD].cmd == PMbus_CMD)
                {
                    SERCOM4_I2C_WriteByte(PSU->psu1_table[PMbus_CMD].key[CurrentADDR]);
                    break;
                }
                else
                {
                    SERCOM4_I2C_WriteByte(UN_PMBUS_STATUS);
                    break;
                }
            case PSU1_PMBUS_BMC_SIDE_ADDR:
                if (PSU->psu2_table[PMbus_CMD].cmd == PMbus_CMD)
                {
                    SERCOM4_I2C_WriteByte(PSU->psu2_table[PMbus_CMD].key[CurrentADDR]);
                    break;
                }
                else
                {
                    SERCOM4_I2C_WriteByte(UN_PMBUS_STATUS);
                    break;                   
                }
            default:
                SERCOM4_I2C_WriteByte(INVALID_DATA);
                break;
            }
    }
    else
    {
        SERCOM4_I2C_WriteByte(DATA_LENGTH_INVALID);
    }

}

void PSU_Flag_Ms_W(uintptr_t I2C_Got_Addr_NOW) /*Mike modify PSU0/1 Check master write during i2cset event*/
{
    switch(I2C_Got_Addr_NOW)
    {       
        case PSU0_PMBUS_BMC_SIDE_ADDR:
            PSU_Flag = 1;
            break;
        case PSU1_PMBUS_BMC_SIDE_ADDR:
            PSU_Flag = 2;
            break;
    }
}

/* *****************************************************************************
 End of File
 */
