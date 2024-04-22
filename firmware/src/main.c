/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <string.h>
#include "definitions.h"                // SYS function prototypes
#include "i2c_address.h"
#include "pmbus_command.h"
#include "Purnell_OEM.h"


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
DataMap PSU_Data;

int main ( void )
{
    /* Initialize all modules */
    int PSU_read_time = 0; 
    int bring_up = 0;
    SYS_Initialize ( NULL );
    
    EIC_Initialize();
    
    TC0_TimerInitialize();
    TC0_TimerStart();
    
    SERCOM1_I2C_CallbackRegister(SERCOM1_I2C_Callback, SERCOM1);
    SERCOM2_I2C_CallbackRegister(SERCOM2_I2C_Callback, SERCOM2);
    SERCOM3_I2C_CallbackRegister(SERCOM3_I2C_Callback, SERCOM3);
    SERCOM4_I2C_CallbackRegister(SERCOM4_I2C_Callback, SERCOM4);
    
    uint8_t FRUWriteData[1] = {0x00};
    uint32_t FRUwrLength = 1;
    uint32_t FRUrdLength = 265;
    uint8_t PSU0_Flag_PMbus_CMD[PIC_OPCODE_SIZE_BYTES];
    uint8_t PSU1_Flag_PMbus_CMD[PIC_OPCODE_SIZE_BYTES];
    static int PSU0_previoussetExist = UN_KONW_STATUS;
    static int PSU1_previoussetExist = UN_KONW_STATUS;
    
    static bool previous_MCU_PA19_FAN_BD_00_PRSNT_N_level = UN_KONW_STATUS;
    static bool previous_MCU_PA15_FAN_BD_01_PRSNT_N_level = UN_KONW_STATUS;
    static bool previous_MCU_PA25_FAN_BD_10_PRSNT_N_level = UN_KONW_STATUS;
    static bool previous_MCU_PB15_FAN_BD_11_PRSNT_N_level = UN_KONW_STATUS;
    
    static bool previous_PSU0_PW_level = UN_KONW_STATUS;
    static bool previous_PSU1_PW_level = UN_KONW_STATUS;
    
    bool MCU_PA19_FAN_BD_00_PRSNT_N_level;
    bool MCU_PA15_FAN_BD_01_PRSNT_N_level;
    bool MCU_PA25_FAN_BD_10_PRSNT_N_level;
    bool MCU_PB15_FAN_BD_11_PRSNT_N_level;
    
    bool PSU0_PW_level;
    bool PSU1_PW_level;
    
    EIC_CallbackRegister(EIC_PIN_0, EIC_Callback_0, MCU_PB00_PSU0_AC_OK_PIN);
    EIC_CallbackRegister(EIC_PIN_1, EIC_Callback_1, MCU_PB01_PSU1_AC_OK_PIN);
    
    while ( true )
    {
        int PSU0_Is_Present;
        int PSU1_Is_Present;
        
        switch(PSU_Flag)
        {
            case 1:
                memcpy(PSU0_Flag_PMbus_CMD, OPcode_CMD_MW, sizeof(Ms_W_Cmd_length));
                SERCOM0_I2C_Write(PSU0_PMBUS_ADDR , PSU0_Flag_PMbus_CMD , Ms_W_Cmd_length);
                while (SERCOM0_I2C_IsBusy( ));  /*Mike add PSU0 Master write busy flag release*/
                PSU_Flag = 0;
                break;
            case 2:           
                memcpy(PSU1_Flag_PMbus_CMD, OPcode_CMD_MW, sizeof(Ms_W_Cmd_length));
                SERCOM0_I2C_Write(PSU1_PMBUS_ADDR , PSU1_Flag_PMbus_CMD , Ms_W_Cmd_length);
                while (SERCOM0_I2C_IsBusy( ));  /*Mike add PSU1 Master write busy flag release*/
                PSU_Flag = 0;
                break;
            default:
                break;
        }

        /* Maintain state machines of all polled MPLAB Harmony modules. */
        if (TC0_TimerPeriodHasExpired()) {
            /*refer http://tao-pdmnet-4:8080/tfs/TAO_BU5_FW5/FW5E/_git/Purnell-DOCS?path=/
            HW_Schematic/Purnell_Schematic/PDB/INTEL_BHS_2U4N_PDB_20230531_decrypted.pdf*/
            //INTEL_BHS_2U4N_PDB_20230531_decrypted.pdf page 9
            //PORT_PIN_PA20 is MCU_PA20_PSU0_PRSNT_N
            //PORT_PIN_PA21 is MCU_PA21_PSU1_PRSNT_N
            
            PSU0_Is_Present = PORT_PinRead(PORT_PIN_PA20);
            PSU1_Is_Present = PORT_PinRead(PORT_PIN_PA21);

            if (PSU_read_time == 30)
            {
                Read_PSU0_PMbus_Data(&PSU_Data);
            }
            else if (PSU_read_time == 60)
            {
                Read_PSU1_PMbus_Data(&PSU_Data);
                PSU_read_time = 0;
            }
            PSU_read_time++;

            MCU_PA19_FAN_BD_00_PRSNT_N_level = MCU_PA19_FAN_BD_00_PRSNT_N_Get();
            MCU_PA15_FAN_BD_01_PRSNT_N_level = MCU_PA15_FAN_BD_01_PRSNT_N_Get();
            MCU_PA25_FAN_BD_10_PRSNT_N_level = MCU_PA25_FAN_BD_10_PRSNT_N_Get();
            MCU_PB15_FAN_BD_11_PRSNT_N_level = MCU_PB15_FAN_BD_11_PRSNT_N_Get();
            
            PSU0_PW_level = MCU_PB30_PSU0_PW_OK_Get();
            PSU1_PW_level = MCU_PB31_PSU1_PW_OK_Get();
            
            if ((previous_MCU_PA19_FAN_BD_00_PRSNT_N_level != MCU_PA19_FAN_BD_00_PRSNT_N_level) ||
                (previous_MCU_PA15_FAN_BD_01_PRSNT_N_level != MCU_PA15_FAN_BD_01_PRSNT_N_level) ||
                (previous_MCU_PA25_FAN_BD_10_PRSNT_N_level != MCU_PA25_FAN_BD_10_PRSNT_N_level) ||
                (previous_MCU_PB15_FAN_BD_11_PRSNT_N_level != MCU_PB15_FAN_BD_11_PRSNT_N_level))
            {
                FAN_PRSNT_to_chang_HOTSWAP(MCU_PA19_FAN_BD_00_PRSNT_N_level,
                                            MCU_PA15_FAN_BD_01_PRSNT_N_level,
                                            MCU_PA25_FAN_BD_10_PRSNT_N_level,
                                            MCU_PB15_FAN_BD_11_PRSNT_N_level);
                
                previous_MCU_PA19_FAN_BD_00_PRSNT_N_level = MCU_PA19_FAN_BD_00_PRSNT_N_level;
                previous_MCU_PA15_FAN_BD_01_PRSNT_N_level = MCU_PA15_FAN_BD_01_PRSNT_N_level;
                previous_MCU_PA25_FAN_BD_10_PRSNT_N_level = MCU_PA25_FAN_BD_10_PRSNT_N_level;
                previous_MCU_PB15_FAN_BD_11_PRSNT_N_level = MCU_PB15_FAN_BD_11_PRSNT_N_level;
            }
            
            if(previous_PSU0_PW_level != PSU0_PW_level)
            {
                PSU0_Power_Good_to_MB_CPLD(PSU0_PW_level);
                previous_PSU0_PW_level = PSU0_PW_level;
            }
            
            if (previous_PSU1_PW_level != PSU1_PW_level)
            {
                PSU1_Power_Good_to_MB_CPLD(PSU1_PW_level);
                previous_PSU1_PW_level = PSU1_PW_level;
            }
            
            if ((PSU0_Is_Present != PSU0_previoussetExist) || 
                (PSU1_Is_Present != PSU1_previoussetExist))
            {
                if(PSU0_Is_Present == true)
                {
                    //PSU0 FRU Update
                    SERCOM0_I2C_WriteRead( PSU0_FRU_ADDR, 
                                           FRUWriteData,
                                           FRUwrLength,
                                           PSU0_FRU_Data,
                                           FRUrdLength );
                    while (SERCOM0_I2C_IsBusy( ));
                }
                if(PSU1_Is_Present == true)
                {
                    //PSU1 FRU Update
                    SERCOM0_I2C_WriteRead( PSU1_FRU_ADDR, 
                                           FRUWriteData,
                                           FRUwrLength,
                                           PSU1_FRU_Data,
                                           FRUrdLength );
                    while (SERCOM0_I2C_IsBusy( ));
                }
                Change_Mask_ADDR(PSU0_Is_Present, 
                                 PSU1_Is_Present);
                PSU0_previoussetExist = PSU0_Is_Present;
                PSU1_previoussetExist = PSU1_Is_Present;
            }
            if (bring_up < 45)
            {
                Read_PSU0_PMbus_Data(&PSU_Data);
                Read_PSU1_PMbus_Data(&PSU_Data);
            }
            bring_up++;
        }
        SYS_Tasks ( );
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

