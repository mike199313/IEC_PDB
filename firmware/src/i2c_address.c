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

uint8_t I2C_Got_Addr_NOW;


bool SERCOM1_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t SERCOM_NOW )
{
    bool isSuccess = true;
    
    switch (I2C_Got_Addr_NOW) {
        case PSU1_FRU_BMC_SIDE_ADDR:
        case PSU0_FRU_BMC_SIDE_ADDR:
        case PIC_FRU_BMC_SIDE_ADDR:
            SERCOM1_FRU_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;

        case PIC_OPCODE_BMC_SIDE_ADDR:
            SERCOM1_PIC_OPcode_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;

        case PSU1_PMBUS_BMC_SIDE_ADDR:
        case PSU0_PMBUS_BMC_SIDE_ADDR:
            SERCOM1_PMbus_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;
    }

    return isSuccess;
}

bool SERCOM2_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t SERCOM_NOW )
{
    bool isSuccess = true;
    
    switch (I2C_Got_Addr_NOW) {
        case PSU1_FRU_BMC_SIDE_ADDR:
        case PSU0_FRU_BMC_SIDE_ADDR:
        case PIC_FRU_BMC_SIDE_ADDR:
            SERCOM2_FRU_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;

        case PIC_OPCODE_BMC_SIDE_ADDR:
            SERCOM2_PIC_OPcode_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;

        case PSU1_PMBUS_BMC_SIDE_ADDR:
        case PSU0_PMBUS_BMC_SIDE_ADDR:
            SERCOM2_PMbus_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;
    }

    return isSuccess;
}

bool SERCOM3_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t SERCOM_NOW )
{
    bool isSuccess = true;
    
    switch (I2C_Got_Addr_NOW) {
        case PSU1_FRU_BMC_SIDE_ADDR:
        case PSU0_FRU_BMC_SIDE_ADDR:
        case PIC_FRU_BMC_SIDE_ADDR:
            SERCOM3_FRU_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;

        case PIC_OPCODE_BMC_SIDE_ADDR:
            SERCOM3_PIC_OPcode_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;

        case PSU1_PMBUS_BMC_SIDE_ADDR:
        case PSU0_PMBUS_BMC_SIDE_ADDR:
            SERCOM3_PMbus_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;
    }
   
    return isSuccess;
}

bool SERCOM4_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t SERCOM_NOW )
{
    bool isSuccess = true;
    
    switch (I2C_Got_Addr_NOW) {
        case PSU1_FRU_BMC_SIDE_ADDR:
        case PSU0_FRU_BMC_SIDE_ADDR:
        case PIC_FRU_BMC_SIDE_ADDR:
            SERCOM4_FRU_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;

        case PIC_OPCODE_BMC_SIDE_ADDR:
            SERCOM4_PIC_OPcode_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;

        case PSU1_PMBUS_BMC_SIDE_ADDR:
        case PSU0_PMBUS_BMC_SIDE_ADDR:
            SERCOM4_PMbus_Callback(event, I2C_Got_Addr_NOW, SERCOM_NOW);
            break;
    }
  
    return isSuccess;
}
/* *****************************************************************************
 End of File
 */
