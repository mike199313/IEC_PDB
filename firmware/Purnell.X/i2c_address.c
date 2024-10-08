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

uint8_t I2C_Got_Addr_NOW;


bool SERCOM_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t SERCOM_NOW )
{
    bool isSuccess = true;

    if((I2C_Got_Addr_NOW == PSU1_FRU_SLAVE_ADDR) || (I2C_Got_Addr_NOW == PSU0_FRU_SLAVE_ADDR) || (I2C_Got_Addr_NOW == PIC_FRU_SLAVE_ADDR))
    {   
        SERCOM_FRU_Callback(event , I2C_Got_Addr_NOW , SERCOM_NOW);
                
    }else if(I2C_Got_Addr_NOW == PIC_OPCODE_SLAVE_ADDR)
    {
        SERCOM_PIC_OPcode_Callback(event , I2C_Got_Addr_NOW , SERCOM_NOW);
    }
    
    return isSuccess;
}

/* *****************************************************************************
 End of File
 */
