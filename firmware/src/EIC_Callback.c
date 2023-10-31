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
bool EIC_Channal0_level = 0;
bool EIC_Channal1_level = 0;
void EIC_Callback_0 ( uintptr_t EIC_Channal )
{
        EIC_Channal0_level = PORT_PinLatchRead(MCU_PB00_PSU0_AC_OK_PIN);
        if (EIC_Channal0_level == GPIO_HIGH)
        {
            MCU_PA02_PSU0_PDBL_00_AC_OK_HIGH();
            MCU_PA06_PSU0_PDBL_01_AC_OK_HIGH();
            MCU_PB06_PSU0_PDBR_10_AC_OK_HIGH();
            MCU_PB10_PSU0_PDBR_11_AC_OK_HIGH();
        }
        else
        {
            MCU_PA02_PSU0_PDBL_00_AC_OK_LOW();
            MCU_PA06_PSU0_PDBL_01_AC_OK_LOW();
            MCU_PB06_PSU0_PDBR_10_AC_OK_LOW();
            MCU_PB10_PSU0_PDBR_11_AC_OK_LOW();
        }
}

void EIC_Callback_1 ( uintptr_t EIC_Channal )
{
        EIC_Channal1_level = PORT_PinLatchRead(MCU_PB01_PSU1_AC_OK_PIN);
        if (EIC_Channal1_level == GPIO_HIGH)
        {
            MCU_PA03_PSU1_PDBL_00_AC_OK_HIGH();
            MCU_PA07_PSU1_PDBL_01_AC_OK_HIGH();
            MCU_PB07_PSU1_PDBR_10_AC_OK_HIGH();
            MCU_PB11_PSU1_PDBR_11_AC_OK_HIGH();
        }
        else
        {
            MCU_PA03_PSU1_PDBL_00_AC_OK_LOW();
            MCU_PA07_PSU1_PDBL_01_AC_OK_LOW();
            MCU_PB07_PSU1_PDBR_10_AC_OK_LOW();
            MCU_PB11_PSU1_PDBR_11_AC_OK_LOW();
        }
}

/* *****************************************************************************
 End of File
 */
