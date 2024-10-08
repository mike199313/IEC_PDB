/*******************************************************************************
  Serial Communication Interface Inter-Integrated Circuit (SERCOM I2C) Library
  Instance Header File

  Company:
    Microchip Technology Inc.

  File Name:
    plib_sercom4_i2c_slave.h

  Summary:
    SERCOM I2C Slave PLIB Header file

  Description:
    This file defines the interface to the SERCOM I2C peripheral library. This
    library provides access to and control of the associated peripheral
    instance.
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

#ifndef PLIB_SERCOM4_I2C_SLAVE_H
#define PLIB_SERCOM4_I2C_SLAVE_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/* This section lists the other files that are included in this file.
*/

#include "plib_sercom_i2c_slave_common.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END

void SERCOM4_I2C_Initialize(void);
void SERCOM4_I2C_CallbackRegister(SERCOM_I2C_SLAVE_CALLBACK callback, uintptr_t contextHandle);
bool SERCOM4_I2C_IsBusy(void);
uint8_t SERCOM4_I2C_ReadByte(void);
void SERCOM4_I2C_WriteByte(uint8_t wrByte);
SERCOM_I2C_SLAVE_ERROR SERCOM4_I2C_ErrorGet(void);
SERCOM_I2C_SLAVE_TRANSFER_DIR SERCOM4_I2C_TransferDirGet(void);
SERCOM_I2C_SLAVE_ACK_STATUS SERCOM4_I2C_LastByteAckStatusGet(void);
void SERCOM4_I2C_AckActionSet(SERCOM_I2C_SLAVE_ACK_ACTION_SEND ackAction);


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
}
#endif
// DOM-IGNORE-END

#endif /* PLIB_SERCOM4_I2C_SLAVE_H */
