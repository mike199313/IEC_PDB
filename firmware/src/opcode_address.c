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

#include "i2c_address.h"
#include "Purnell_OEM.h"


FRU_DATA   picData;

uint8_t PIC_MAJOR_Data[PIC_OPCODE_SIZE_BYTES] = {CC_SUCCESS , MAJOR_VERSION};
uint8_t PIC_MINOR_Data[PIC_OPCODE_SIZE_BYTES] = {CC_SUCCESS , MINOR_VERSION};



bool SERCOM_PIC_OPcode_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW )
{
    static uint8_t PIC_CMD = UN_KONW_STATUS;
    bool isSuccess = true;
    
        switch(event)
        {
            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH:
                if (( Event_ADDR_Match( SERCOM_NOW ) == SERCOM_I2C_SLAVE_TRANSFER_DIR_WRITE) && (picData.internalWriteInProgress == true))
                {
                    /* FRU is busy. Send NAK */
                    isSuccess = false;
                }
                else
                {
                    /* Reset the indexes */
                    picData.addrIndex = 0;
                    picData.wrBufferIndex = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_RX_READY:
                /* Receive request data from BMC */
                
                if (picData.addrIndex < ADDR_BYTE)
                {
                   
                    ((uint8_t*)&picData.currentAddrPtr)[picData.addrIndex++] = GET_SERCOM_I2C_OFFSET(SERCOM_NOW);
                    PIC_CMD = picData.currentAddrPtr;
                    picData.currentAddrPtr = PIC_OPCODE_START_ADDR;
                    
                }
                else
                {   
                    
                    PIC_CMD = GET_SERCOM_I2C_OFFSET(SERCOM_NOW);
                    picData.wrBuffer[(picData.wrBufferIndex & FRU_SIZE_MASK)] = PIC_CMD;
                    picData.wrBufferIndex++;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_TX_READY:
                /* Provide response data to BMC */
                Select_SERCOM(picData.currentAddrPtr++ , I2C_Got_Addr_NOW , SERCOM_NOW , PIC_CMD , picData.addrIndex); 
                if (picData.currentAddrPtr >= PIC_OPCODE_SIZE_BYTES)
                {
                    picData.currentAddrPtr = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED:
                if (picData.wrBufferIndex > 0)
                {
                    if (picData.wrBufferIndex > FRU_SIZE_BYTES)
                    {
                        picData.wrBufferIndex = FRU_SIZE_BYTES;
                    }
                    picData.wrAddr = picData.currentAddrPtr;
                    picData.nWrBytes = picData.wrBufferIndex;

                    /* Update the current address pointer to allow for sequential read */
                    picData.currentAddrPtr += picData.wrBufferIndex;

                    /* Reset the indexes */
                    picData.addrIndex = 0;
                    picData.wrBufferIndex = 0;

                    /* Set busy flag to send NAK for any write requests */
                    picData.internalWriteInProgress = true;
                    picData.i2cCommand = I2C_CMD_WRITE;
                }
                break;
            default:
                break;
        }
    
    
    return isSuccess;
}


/* *****************************************************************************
 End of File
 */