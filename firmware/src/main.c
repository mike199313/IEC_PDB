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
    bool PSU0_previoussetExist = PSU_EXIST;
    bool PSU1_previoussetExist = PSU_EXIST;

    while ( true )
    {
        bool PSU0exist;
        bool PSU1exist;
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        if (TC0_TimerPeriodHasExpired()) {
            PSU0exist = SERCOM0_I2C_WriteRead( PSU0_FRU_ADDR, FRUWriteData,FRUwrLength ,PSU_FRU_Data ,FRUrdLength );
            PSU1exist = SERCOM0_I2C_WriteRead( PSU1_FRU_ADDR, FRUWriteData,FRUwrLength ,PSU_FRU_Data ,FRUrdLength );
            
            //TODO : GPIO present detect instead of I2C
            if ((PSU0exist != PSU0_previoussetExist) || (PSU1exist != PSU1_previoussetExist))
            {
                Change_Mask_ADDR(PSU0exist , PSU1exist);
                PSU0_previoussetExist = PSU0exist;
                PSU1_previoussetExist = PSU1exist;
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

