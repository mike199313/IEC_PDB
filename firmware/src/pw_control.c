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



/**
 * FAN BD PRSNT to chang PDB HOTSWAP .
 * 
 * PIC setting , refer to FAN_PRSNT_to_chang_HOTSWAP() -->
 *  Refer to FB Schematic *1
 *   J1.C3 FAN_BD_L_PRSNT_N -->
 *  Refer to PDB PSU Schematic *2
 *   J3.C3 FAN_BD_L_00_PRSNT_N -->
 *   U1.38 MCU_PA19_FAN_BD_00_PRSNT_N -->
 *   U1.51 MCU_PA27_PDB_BD_00_HOTSWAP_EN -->
 *   J3.C6 PDB_BD_L_00_HOTSWAP_EN -->
 *  Refer to FB Schematic *1
 *   J1.C6 CT_PDB_BD_L_HOTSWAP_EN -->
 *   PU1.26 CT_HOTSWAP_EN
 * 
 * @param[in] 
 *      bool MCU_PA19_FAN_BD_00_PRSNT_N_level 
 *      bool MCU_PA15_FAN_BD_01_PRSNT_N_level 
 *      bool MCU_PA25_FAN_BD_10_PRSNT_N_level
 *      bool MCU_PB15_FAN_BD_11_PRSNT_N_level
 * @retval NONE.
 * Addtional remark:
 * 1 http://tao-pdmnet-4:8080/tfs/TAO_BU5_FW5/FW5E/_git/Purnell-DOCS/commit/994b7c5e9d1dbc9c9e125eed5e0590e4e23c138a?refName=refs%2Fheads%2Fdocs&path=%2FHW_Schematic%2FPurnell_Schematic%2FFAN BD%2FINTEL_BHS_2U4N_FAN BD_20230608_decrypted.pdf&_a=contents 
 * 2 http://tao-pdmnet-4:8080/tfs/TAO_BU5_FW5/FW5E/_git/Purnell-DOCS/commit/e31895942d51449846ab8af1d95d013f04723ae5?refName=refs%2Fheads%2Fdocs&path=%2FHW_Schematic%2FPurnell_Schematic%2FPDB%2FINTEL_BHS_2U4N_PDB_20230531_decrypted.pdf&_a=contents 
*/

void FAN_PRSNT_to_chang_HOTSWAP(bool MCU_PA19_FAN_BD_00_PRSNT_N_level, 
                                bool MCU_PA15_FAN_BD_01_PRSNT_N_level, 
                                bool MCU_PA25_FAN_BD_10_PRSNT_N_level, 
                                bool MCU_PB15_FAN_BD_11_PRSNT_N_level)
{
    if (MCU_PA19_FAN_BD_00_PRSNT_N_level == HOTSWAP_ENABLE)
    {
        MCU_PA27_PDB_BD_00_HOTSWAP_EN_HIGH();
    }else if (MCU_PA19_FAN_BD_00_PRSNT_N_level == HOTSWAP_DISABLE)
    {
        MCU_PA27_PDB_BD_00_HOTSWAP_EN_LOW();
    }

    if (MCU_PA15_FAN_BD_01_PRSNT_N_level == HOTSWAP_ENABLE)
    {
        MCU_PA28_PDB_BD_01_HOTSWAP_EN_HIGH();
    }else if (MCU_PA15_FAN_BD_01_PRSNT_N_level == HOTSWAP_DISABLE)
    {
        MCU_PA28_PDB_BD_01_HOTSWAP_EN_LOW();
    }

    if (MCU_PA25_FAN_BD_10_PRSNT_N_level == HOTSWAP_ENABLE)
    {
        MCU_PB22_PDB_BD_10_HOTSWAP_EN_HIGH();
    }else if (MCU_PA25_FAN_BD_10_PRSNT_N_level == HOTSWAP_DISABLE)
    {
        MCU_PB22_PDB_BD_10_HOTSWAP_EN_LOW();
    }
    if (MCU_PB15_FAN_BD_11_PRSNT_N_level == HOTSWAP_ENABLE)
    {
        MCU_PB23_PDB_BD_11_HOTSWAP_EN_HIGH();
    }else if (MCU_PB15_FAN_BD_11_PRSNT_N_level == HOTSWAP_DISABLE)
    {
        MCU_PB23_PDB_BD_11_HOTSWAP_EN_LOW();
    }
}
/* *****************************************************************************
 End of File
 */