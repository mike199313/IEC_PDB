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


FRU_DATA   picData1;
FRU_DATA   picData2;
FRU_DATA   picData3;
FRU_DATA   picData4;




bool SERCOM1_PIC_OPcode_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW )
{
    static uint8_t PIC_CMD = UN_KONW_STATUS;
    bool isSuccess = true;
    static int CMD_Size = 0;
        switch(event)
        {
            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH:
                if (( Event_ADDR_Match( SERCOM_NOW ) == SERCOM_I2C_SLAVE_TRANSFER_DIR_WRITE) && (picData1.internalWriteInProgress == true))
                {
                    /* FRU is busy. Send NAK */
                    isSuccess = false;
                }
                else
                {
                    /* Reset the indexes */
                    picData1.addrIndex = 0;
                    picData1.wrBufferIndex = 0;
                    CMD_Size = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_RX_READY:
                /* Receive request data from BMC */
                
                if (picData1.addrIndex < CMD_SIZE_BYTE)
                {
                   
                    ((uint8_t*)&picData1.currentAddrPtr)[picData1.addrIndex++] = GET_SERCOM1_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    picData1.currentAddrPtr = PIC_OPCODE_START_ADDR;
                    CMD_Size++;
                    
                }
                else
                {   
                    
                    PIC_CMD = GET_SERCOM1_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    picData1.wrBuffer[(picData1.wrBufferIndex & FRU_SIZE_MASK)] = PIC_CMD;
                    CMD_Size++;
                    picData1.wrBufferIndex++;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_TX_READY:
                /* Provide response data to BMC */
                Select_SERCOM(picData1.currentAddrPtr++ , I2C_Got_Addr_NOW , SERCOM_NOW , SERCOM1_CMD[0] , picData1.addrIndex); 
                if (picData1.currentAddrPtr >= PIC_OPCODE_SIZE_BYTES)
                {
                    picData1.currentAddrPtr = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED:
                if (picData1.wrBufferIndex > 0)
                {
                    if (picData1.wrBufferIndex > FRU_SIZE_BYTES)
                    {
                        picData1.wrBufferIndex = FRU_SIZE_BYTES;
                    }
                    picData1.wrAddr = picData1.currentAddrPtr;
                    picData1.nWrBytes = picData1.wrBufferIndex;

                    /* Update the current address pointer to allow for sequential read */
                    picData1.currentAddrPtr += picData1.wrBufferIndex;

                    /* Reset the indexes */
                    picData1.addrIndex = 0;
                    picData1.wrBufferIndex = 0;

                    /* Set busy flag to send NAK for any write requests */
                    picData1.internalWriteInProgress = true;
                    picData1.i2cCommand = I2C_CMD_WRITE;
                }
                break;
            default:
                break;
        }
    
    
    return isSuccess;
}

bool SERCOM2_PIC_OPcode_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW )
{
    static uint8_t PIC_CMD = UN_KONW_STATUS;
    bool isSuccess = true;
    static int CMD_Size = 0;
        switch(event)
        {
            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH:
                if (( Event_ADDR_Match( SERCOM_NOW ) == SERCOM_I2C_SLAVE_TRANSFER_DIR_WRITE) && (picData2.internalWriteInProgress == true))
                {
                    /* FRU is busy. Send NAK */
                    isSuccess = false;
                }
                else
                {
                    /* Reset the indexes */
                    picData2.addrIndex = 0;
                    picData2.wrBufferIndex = 0;
                    CMD_Size = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_RX_READY:
                /* Receive request data from BMC */
                
                if (picData2.addrIndex < CMD_SIZE_BYTE)
                {
                   
                    ((uint8_t*)&picData2.currentAddrPtr)[picData2.addrIndex++] = GET_SERCOM2_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    picData2.currentAddrPtr = PIC_OPCODE_START_ADDR;
                    CMD_Size++;
                    
                }
                else
                {   
                    
                    PIC_CMD = GET_SERCOM2_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    picData2.wrBuffer[(picData2.wrBufferIndex & FRU_SIZE_MASK)] = PIC_CMD;
                    CMD_Size++;
                    picData2.wrBufferIndex++;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_TX_READY:
                /* Provide response data to BMC */
                Select_SERCOM(picData2.currentAddrPtr++ , I2C_Got_Addr_NOW , SERCOM_NOW , SERCOM2_CMD[0] , picData2.addrIndex); 
                if (picData2.currentAddrPtr >= PIC_OPCODE_SIZE_BYTES)
                {
                    picData2.currentAddrPtr = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED:
                if (picData2.wrBufferIndex > 0)
                {
                    if (picData2.wrBufferIndex > FRU_SIZE_BYTES)
                    {
                        picData2.wrBufferIndex = FRU_SIZE_BYTES;
                    }
                    picData2.wrAddr = picData2.currentAddrPtr;
                    picData2.nWrBytes = picData2.wrBufferIndex;

                    /* Update the current address pointer to allow for sequential read */
                    picData2.currentAddrPtr += picData2.wrBufferIndex;

                    /* Reset the indexes */
                    picData2.addrIndex = 0;
                    picData2.wrBufferIndex = 0;

                    /* Set busy flag to send NAK for any write requests */
                    picData2.internalWriteInProgress = true;
                    picData2.i2cCommand = I2C_CMD_WRITE;
                }
                break;
            default:
                break;
        }
    
    
    return isSuccess;
}

bool SERCOM3_PIC_OPcode_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW )
{
    static uint8_t PIC_CMD = UN_KONW_STATUS;
    bool isSuccess = true;
    static int CMD_Size = 0;
        switch(event)
        {
            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH:
                if (( Event_ADDR_Match( SERCOM_NOW ) == SERCOM_I2C_SLAVE_TRANSFER_DIR_WRITE) && (picData3.internalWriteInProgress == true))
                {
                    /* FRU is busy. Send NAK */
                    isSuccess = false;
                }
                else
                {
                    /* Reset the indexes */
                    picData3.addrIndex = 0;
                    picData3.wrBufferIndex = 0;
                    CMD_Size = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_RX_READY:
                /* Receive request data from BMC */
                
                if (picData3.addrIndex < CMD_SIZE_BYTE)
                {
                   
                    ((uint8_t*)&picData3.currentAddrPtr)[picData3.addrIndex++] = GET_SERCOM3_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    picData3.currentAddrPtr = PIC_OPCODE_START_ADDR;
                    CMD_Size++;
                    
                }
                else
                {   
                    
                    PIC_CMD = GET_SERCOM3_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    picData3.wrBuffer[(picData3.wrBufferIndex & FRU_SIZE_MASK)] = PIC_CMD;
                    CMD_Size++;
                    picData3.wrBufferIndex++;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_TX_READY:
                /* Provide response data to BMC */
                Select_SERCOM(picData3.currentAddrPtr++ , I2C_Got_Addr_NOW , SERCOM_NOW , SERCOM3_CMD[0] , picData3.addrIndex); 
                if (picData3.currentAddrPtr >= PIC_OPCODE_SIZE_BYTES)
                {
                    picData3.currentAddrPtr = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED:
                if (picData3.wrBufferIndex > 0)
                {
                    if (picData3.wrBufferIndex > FRU_SIZE_BYTES)
                    {
                        picData3.wrBufferIndex = FRU_SIZE_BYTES;
                    }
                    picData3.wrAddr = picData3.currentAddrPtr;
                    picData3.nWrBytes = picData3.wrBufferIndex;

                    /* Update the current address pointer to allow for sequential read */
                    picData3.currentAddrPtr += picData3.wrBufferIndex;

                    /* Reset the indexes */
                    picData3.addrIndex = 0;
                    picData3.wrBufferIndex = 0;

                    /* Set busy flag to send NAK for any write requests */
                    picData3.internalWriteInProgress = true;
                    picData3.i2cCommand = I2C_CMD_WRITE;
                }
                break;
            default:
                break;
        }
    
    
    return isSuccess;
}

bool SERCOM4_PIC_OPcode_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW )
{
    static uint8_t PIC_CMD = UN_KONW_STATUS;
    bool isSuccess = true;
    static int CMD_Size = 0;
        switch(event)
        {
            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH:
                if (( Event_ADDR_Match( SERCOM_NOW ) == SERCOM_I2C_SLAVE_TRANSFER_DIR_WRITE) && (picData4.internalWriteInProgress == true))
                {
                    /* FRU is busy. Send NAK */
                    isSuccess = false;
                }
                else
                {
                    /* Reset the indexes */
                    picData4.addrIndex = 0;
                    picData4.wrBufferIndex = 0;
                    CMD_Size = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_RX_READY:
                /* Receive request data from BMC */
                
                if (picData4.addrIndex < CMD_SIZE_BYTE)
                {
                   
                    ((uint8_t*)&picData4.currentAddrPtr)[picData4.addrIndex++] = GET_SERCOM4_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    picData4.currentAddrPtr = PIC_OPCODE_START_ADDR;
                    CMD_Size++;
                    
                }
                else
                {   
                    
                    PIC_CMD = GET_SERCOM4_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    picData4.wrBuffer[(picData4.wrBufferIndex & FRU_SIZE_MASK)] = PIC_CMD;
                    CMD_Size++;
                    picData4.wrBufferIndex++;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_TX_READY:
                /* Provide response data to BMC */
                Select_SERCOM(picData4.currentAddrPtr++ , I2C_Got_Addr_NOW , SERCOM_NOW , SERCOM4_CMD[0] , picData4.addrIndex); 
                if (picData4.currentAddrPtr >= PIC_OPCODE_SIZE_BYTES)
                {
                    picData4.currentAddrPtr = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED:
                if (picData4.wrBufferIndex > 0)
                {
                    if (picData4.wrBufferIndex > FRU_SIZE_BYTES)
                    {
                        picData4.wrBufferIndex = FRU_SIZE_BYTES;
                    }
                    picData4.wrAddr = picData4.currentAddrPtr;
                    picData4.nWrBytes = picData4.wrBufferIndex;

                    /* Update the current address pointer to allow for sequential read */
                    picData4.currentAddrPtr += picData4.wrBufferIndex;

                    /* Reset the indexes */
                    picData4.addrIndex = 0;
                    picData4.wrBufferIndex = 0;

                    /* Set busy flag to send NAK for any write requests */
                    picData4.internalWriteInProgress = true;
                    picData4.i2cCommand = I2C_CMD_WRITE;
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