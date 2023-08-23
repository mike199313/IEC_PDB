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
#include <stdio.h>
#include "config/default/peripheral/sercom/i2c_slave/plib_sercom1_i2c_slave.h"
#include "config/default/peripheral/sercom/i2c_slave/plib_sercom2_i2c_slave.h"
#include "config/default/peripheral/sercom/i2c_slave/plib_sercom3_i2c_slave.h"
#include "config/default/peripheral/sercom/i2c_slave/plib_sercom4_i2c_slave.h"
#include "config/default/interrupts.h"
#include "i2c_address.h"
#include "Purnell_OEM.h"

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */
int I2C_SLAVE_ADDR_MASK = SLAVE_ADDR_MASK;
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


bool Change_Mask_ADDR(bool PSU0exist , bool PSU1exist)
{
    if ((PSU0exist == PSU_EXIST) && (PSU1exist == PSU_EXIST))
    {
        I2C_SLAVE_ADDR_MASK = SLAVE_ADDR_MASK;
    }
    else if (PSU0exist == PSU_EXIST)
    {
        I2C_SLAVE_ADDR_MASK = PSU0_SLAVE_ADDR_MASK;
    }
    else if (PSU1exist == PSU_EXIST)
    {
        I2C_SLAVE_ADDR_MASK = PSU1_SLAVE_ADDR_MASK;
    }
    SERCOM1_I2C_Initialize();
    SERCOM1_I2C_InterruptHandler();
    SERCOM2_I2C_Initialize();
    SERCOM2_I2C_InterruptHandler();
    SERCOM3_I2C_Initialize();
    SERCOM3_I2C_InterruptHandler();
    SERCOM4_I2C_Initialize();
    SERCOM4_I2C_InterruptHandler();
    return ODM_OK;
}

/* *****************************************************************************
 End of File
 */
