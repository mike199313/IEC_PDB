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
 * PSU0 Power_Good inform to MB CPLD .
 *  Refer to PDB PSU Schematic *1
 *   J1.A25 PSU0_PW_OK -->
 *   U1.59 MCU_PB30_PSU0_PW_OK -->
 *   PIC setting , refer to PSU0_Power_Good_to_MB_CPLD() -->
 *   U1.63 MCU_PB02_PSU0_PDBL_00_PW_OK -->
 *   J3.B2 PSU0_PDB_L_00_PW_OK -->
 *  Refer to FB Schematic *2
 *   J1.B2 PSU0_PDB_L_PW_OK -->
 *   J5.13 PSU0_PDB_PW_OK -->
 *  Refer to MB Schematic *3
 *   J57.13 PSU0_PWOK -->
 *   U79.P19 CPLD_PG_PSU0_P12V
 * @param[in] 
 *      
 * @retval NONE.
 * Addtional remark:
 * 1 http://tao-pdmnet-4:8080/tfs/TAO_BU5_FW5/FW5E/_git/Purnell-DOCS/commit/e31895942d51449846ab8af1d95d013f04723ae5?refName=refs%2Fheads%2Fdocs&path=%2FHW_Schematic%2FPurnell_Schematic%2FPDB%2FINTEL_BHS_2U4N_PDB_20230531_decrypted.pdf&_a=contents 
 * 2 http://tao-pdmnet-4:8080/tfs/TAO_BU5_FW5/FW5E/_git/Purnell-DOCS/commit/994b7c5e9d1dbc9c9e125eed5e0590e4e23c138a?refName=refs%2Fheads%2Fdocs&path=%2FHW_Schematic%2FPurnell_Schematic%2FFAN BD%2FINTEL_BHS_2U4N_FAN BD_20230608_decrypted.pdf&_a=contents 
 * 3 http://tao-pdmnet-4:8080/tfs/TAO_BU5_FW5/FW5E/_git/Purnell-DOCS/commit/2546c72f10bef9a55a4ce5b663a338c9798b3173?refName=refs%2Fheads%2Fdocs&path=%2FHW_Schematic%2FPurnell_Schematic%2FMB%2F2U4N_MLB_20230804.SCH.1.1_decrypted.pdf.7z&_a=contents 
*/
void PSU0_Power_Good_to_MB_CPLD (bool PSU0_PW_level)
{
            
    if (PSU0_PW_level == GPIO_HIGH)
    {
        MCU_PB02_PSU0_PDBL_00_PW_OK_HIGH();
        MCU_PA04_PSU0_PDBL_01_PW_OK_HIGH();
        MCU_PB04_PSU0_PDBR_10_PW_OK_HIGH();
        MCU_PB08_PSU0_PDBR_11_PW_OK_HIGH();
    }
    else
    {
        MCU_PB02_PSU0_PDBL_00_PW_OK_LOW();
        MCU_PA04_PSU0_PDBL_01_PW_OK_LOW();
        MCU_PB04_PSU0_PDBR_10_PW_OK_LOW();
        MCU_PB08_PSU0_PDBR_11_PW_OK_LOW();
    }
}

/**
 * PSU1 Power_Good inform to MB CPLD .
 *  Refer to PDB PSU Schematic *1
 *   J2.A25 PSU1_PW_OK -->
 *   U1.60 MCU_PB31_PSU1_PW_OK -->
 * PIC setting , refer to PSU1_Power_Good_to_MB_CPLD() -->
 *   U1.64 MCU_PB03_PSU1_PDBL_00_PW_OK -->
 *   J3.C2 PSU1_PDB_L_00_PW_OK -->
 *  Refer to FB Schematic *2
 *   J1.C2 PSU1_PDB_L_PW_OK -->
 *   J5.15 PSU1_PDB_PW_OK -->
 *  Refer to MB Schematic *3
 *   J57.15 PSU1_PWOK -->
 *   U79.M20 CPLD_PG_PSU1_P12V
 * @param[in] 
 *      bool PSU1_PW_level
 * @retval NONE.
 * Addtional remark:
 * 1 http://tao-pdmnet-4:8080/tfs/TAO_BU5_FW5/FW5E/_git/Purnell-DOCS/commit/e31895942d51449846ab8af1d95d013f04723ae5?refName=refs%2Fheads%2Fdocs&path=%2FHW_Schematic%2FPurnell_Schematic%2FPDB%2FINTEL_BHS_2U4N_PDB_20230531_decrypted.pdf&_a=contents 
 * 2 http://tao-pdmnet-4:8080/tfs/TAO_BU5_FW5/FW5E/_git/Purnell-DOCS/commit/994b7c5e9d1dbc9c9e125eed5e0590e4e23c138a?refName=refs%2Fheads%2Fdocs&path=%2FHW_Schematic%2FPurnell_Schematic%2FFAN BD%2FINTEL_BHS_2U4N_FAN BD_20230608_decrypted.pdf&_a=contents 
 * 3 http://tao-pdmnet-4:8080/tfs/TAO_BU5_FW5/FW5E/_git/Purnell-DOCS/commit/2546c72f10bef9a55a4ce5b663a338c9798b3173?refName=refs%2Fheads%2Fdocs&path=%2FHW_Schematic%2FPurnell_Schematic%2FMB%2F2U4N_MLB_20230804.SCH.1.1_decrypted.pdf.7z&_a=contents 
*/

void PSU1_Power_Good_to_MB_CPLD (bool PSU1_PW_level)
{
    
    if (PSU1_PW_level == GPIO_HIGH)
    {
        MCU_PB03_PSU1_PDBL_00_PW_OK_HIGH();
        MCU_PA05_PSU1_PDBL_01_PW_OK_HIGH();
        MCU_PB05_PSU1_PDBR_10_PW_OK_HIGH();
        MCU_PB09_PSU1_PDBR_11_PW_OK_HIGH();
    }
    else
    {
        MCU_PB03_PSU1_PDBL_00_PW_OK_LOW();
        MCU_PA05_PSU1_PDBL_01_PW_OK_LOW();
        MCU_PB05_PSU1_PDBR_10_PW_OK_LOW();
        MCU_PB09_PSU1_PDBR_11_PW_OK_LOW();
    }
}

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
    //FAN_BD_INSERT is GPIO_LOW , FAN_BD_NOT_INSERT is GPIO_HIGH
    if (MCU_PA19_FAN_BD_00_PRSNT_N_level == FAN_BD_INSERT)
    {
        MCU_PA27_PDB_BD_00_HOTSWAP_ENABLE_GPIO_HIGH();
    }else if (MCU_PA19_FAN_BD_00_PRSNT_N_level == FAN_BD_NOT_INSERT)
    {
        MCU_PA27_PDB_BD_00_HOTSWAP_DISABLE_GPIO_LOW();
    }

    if (MCU_PA15_FAN_BD_01_PRSNT_N_level == FAN_BD_INSERT)
    {
        MCU_PA28_PDB_BD_01_HOTSWAP_ENABLE_GPIO_HIGH();
    }else if (MCU_PA15_FAN_BD_01_PRSNT_N_level == FAN_BD_NOT_INSERT)
    {
        MCU_PA28_PDB_BD_01_HOTSWAP_DISABLE_GPIO_LOW();
    }

    if (MCU_PA25_FAN_BD_10_PRSNT_N_level == FAN_BD_INSERT)
    {
        MCU_PB22_PDB_BD_10_HOTSWAP_ENABLE_GPIO_HIGH();
    }else if (MCU_PA25_FAN_BD_10_PRSNT_N_level == FAN_BD_NOT_INSERT)
    {
        MCU_PB22_PDB_BD_10_HOTSWAP_DISABLE_GPIO_LOW();
    }
    if (MCU_PB15_FAN_BD_11_PRSNT_N_level == FAN_BD_INSERT)
    {
        MCU_PB23_PDB_BD_11_HOTSWAP_ENABLE_GPIO_HIGH();
    }else if (MCU_PB15_FAN_BD_11_PRSNT_N_level == FAN_BD_NOT_INSERT)
    {
        MCU_PB23_PDB_BD_11_HOTSWAP_DISABLE_GPIO_LOW();
    }
}
/* *****************************************************************************
 End of File
 */