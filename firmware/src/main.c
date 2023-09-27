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
#include "definitions.h"                // SYS function prototypes
#include "i2c_address.h"
#include "Purnell_OEM.h"


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    TC0_TimerInitialize();
    TC0_TimerStart();
    
    SERCOM1_I2C_CallbackRegister(SERCOM_I2C_Callback, SERCOM1);
    SERCOM2_I2C_CallbackRegister(SERCOM_I2C_Callback, SERCOM2);
    SERCOM3_I2C_CallbackRegister(SERCOM_I2C_Callback, SERCOM3);
    SERCOM4_I2C_CallbackRegister(SERCOM_I2C_Callback, SERCOM4);
    
    uint8_t FRUWriteData[1] = {0x00};
    uint32_t FRUwrLength = 1;
    uint32_t FRUrdLength = 265;
    static int PSU0_previoussetExist = UN_KONW_STATUS;
    static int PSU1_previoussetExist = UN_KONW_STATUS;

    while ( true )
    {
        int PSU0_Is_Present;
        int PSU1_Is_Present;
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        if (TC0_TimerPeriodHasExpired()) {
            
            /*refer http://tao-pdmnet-4:8080/tfs/TAO_BU5_FW5/FW5E/_git/Purnell-DOCS?path=/
            HW_Schematic/Purnell_Schematic/PDB/INTEL_BHS_2U4N_PDB_20230531_decrypted.pdf*/
            //INTEL_BHS_2U4N_PDB_20230531_decrypted.pdf page 9
            //PORT_PIN_PA20 is MCU_PA20_PSU0_PRSNT_N
            //PORT_PIN_PA21 is MCU_PA21_PSU1_PRSNT_N
            
            PSU0_Is_Present = PORT_PinRead(PORT_PIN_PA20);
            PSU1_Is_Present = PORT_PinRead(PORT_PIN_PA21);
            
            if ((PSU0_Is_Present != PSU0_previoussetExist) || 
                (PSU1_Is_Present != PSU1_previoussetExist))
            {
                if(PSU0_Is_Present == true)
                {
                    //PSU0 FRU Update
                    SERCOM0_I2C_WriteRead( PSU0_FRU_ADDR, 
                                           FRUWriteData,
                                           FRUwrLength,
                                           PSU_FRU_Data,
                                           FRUrdLength );
                    while (SERCOM0_I2C_IsBusy( ));
                }
                if(PSU1_Is_Present == true)
                {
                    //PSU1 FRU Update
                    SERCOM0_I2C_WriteRead( PSU1_FRU_ADDR, 
                                           FRUWriteData,
                                           FRUwrLength,
                                           PSU_FRU_Data,
                                           FRUrdLength );
                    while (SERCOM0_I2C_IsBusy( ));
                }
                Change_Mask_ADDR(PSU0_Is_Present, 
                                 PSU1_Is_Present);
                PSU0_previoussetExist = PSU0_Is_Present;
                PSU1_previoussetExist = PSU1_Is_Present;
            }
        }
        SYS_Tasks ( );
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

