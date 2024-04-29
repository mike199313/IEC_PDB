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
#include "pmbus_command.h"
#include "Purnell_OEM.h"
#include "config/default/peripheral/sercom/i2c_slave/plib_sercom1_i2c_slave.h"
#include "config/default/peripheral/sercom/i2c_slave/plib_sercom2_i2c_slave.h"
#include "config/default/peripheral/sercom/i2c_slave/plib_sercom3_i2c_slave.h"
#include "config/default/peripheral/sercom/i2c_slave/plib_sercom4_i2c_slave.h"


FRU_DATA   pmbusData1;
FRU_DATA   pmbusData2;
FRU_DATA   pmbusData3;
FRU_DATA   pmbusData4;


uint32_t Ms_W_Cmd_length = 0;
uint8_t* OPcode_CMD_MW = NULL;

bool SERCOM1_PMbus_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW )
{
    static uint8_t PMbus_CMD = UN_KONW_STATUS;
    bool isSuccess = true;
    static int CMD_Size = 0;
    
        switch(event)
        {
            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH:
                if (( SERCOM1_ADDR_Match() == SERCOM_I2C_SLAVE_TRANSFER_DIR_WRITE) && (pmbusData1.internalWriteInProgress == true))
                {
                    /* FRU is busy. Send NAK */
                    isSuccess = false;
                }
                else
                {
                    /* Reset the indexes */
                    pmbusData1.addrIndex = 0;
                    pmbusData1.wrBufferIndex = 0;
                    CMD_Size = 0;
                }
                return isSuccess;
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_RX_READY:
                /* Receive request data from BMC */
                if (pmbusData1.addrIndex < CMD_SIZE_BYTE)
                {
                    ((uint8_t*)&pmbusData1.currentAddrPtr)[pmbusData1.addrIndex++] = GET_SERCOM1_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    CMD_Size++;
                    PMbus_CMD = pmbusData1.currentAddrPtr;
                    pmbusData1.currentAddrPtr = PIC_OPCODE_START_ADDR;
                }
                else
                {                      
                    PMbus_CMD = GET_SERCOM1_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    pmbusData1.wrBuffer[(pmbusData1.wrBufferIndex & FRU_SIZE_MASK)] = PMbus_CMD;
                    pmbusData1.wrBufferIndex++;
                }         
                return isSuccess;     
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_TX_READY:
                SERCOM1_PSU_Data_Return(&PSU_Data, 
                                        pmbusData1.currentAddrPtr++ ,  
                                        I2C_Got_Addr_NOW, 
                                        SERCOM_NOW, 
                                        SERCOM1_CMD[0], 
                                        pmbusData1.addrIndex);
                if (pmbusData1.currentAddrPtr >= PIC_OPCODE_SIZE_BYTES)
                {
                    pmbusData1.currentAddrPtr = 0;
                }
                return isSuccess;
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED:              
                if (pmbusData1.wrBufferIndex > 0)
                {
                    if (pmbusData1.wrBufferIndex > FRU_SIZE_BYTES)
                    {
                        pmbusData1.wrBufferIndex = FRU_SIZE_BYTES;
                    }
                    else 
                    {
                        Ms_W_Cmd_length = (uint32_t)pmbusData1.wrBufferIndex;
                        OPcode_CMD_MW = SERCOM1_CMD;
                        PSU_Flag_Ms_W(I2C_Got_Addr_NOW);
                    }
                    pmbusData1.wrAddr = pmbusData1.currentAddrPtr;
                    pmbusData1.nWrBytes = pmbusData1.wrBufferIndex;

                    /* Reset the indexes */
                    pmbusData1.addrIndex = 0;
                    pmbusData1.wrBufferIndex = 0;
                    /* Set busy flag to send NAK for any write requests */
                    pmbusData1.internalWriteInProgress = true;
                    pmbusData1.i2cCommand = I2C_CMD_WRITE;
                    /* FRU is busy. Send NAK Mike Modify*/
                    isSuccess = false;
                }
                else
                {
                    pmbusData1.internalWriteInProgress = false;
                    pmbusData1.i2cCommand = I2C_CMD_IDLE;   /*Mike add write request allow AK to finish STOP BIT event*/                                 
                }
                return isSuccess;
                break;
            default:
                return isSuccess;
                break;
        }
}

bool SERCOM2_PMbus_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW )
{
    static uint8_t PMbus_CMD = UN_KONW_STATUS;
    bool isSuccess = true;
    static int CMD_Size = 0;
    
        switch(event)
        {
            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH:
                if (( SERCOM2_ADDR_Match() == SERCOM_I2C_SLAVE_TRANSFER_DIR_WRITE) && (pmbusData2.internalWriteInProgress == true))
                {
                    /* FRU is busy. Send NAK */
                    isSuccess = false;
                }
                else
                {
                    /* Reset the indexes */
                    pmbusData2.addrIndex = 0;
                    pmbusData2.wrBufferIndex = 0;
                    CMD_Size = 0;
                }
                return isSuccess;
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_RX_READY:
                /* Receive request data from BMC */
                if (pmbusData2.addrIndex < CMD_SIZE_BYTE)
                {
                    ((uint8_t*)&pmbusData2.currentAddrPtr)[pmbusData2.addrIndex++] = GET_SERCOM2_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    CMD_Size++;
                    PMbus_CMD = pmbusData2.currentAddrPtr;
                    pmbusData2.currentAddrPtr = PIC_OPCODE_START_ADDR;
                }
                else
                {                      
                    PMbus_CMD = GET_SERCOM2_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    pmbusData2.wrBuffer[(pmbusData2.wrBufferIndex & FRU_SIZE_MASK)] = PMbus_CMD;
                    pmbusData2.wrBufferIndex++;
                }
                return isSuccess;
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_TX_READY:
                SERCOM2_PSU_Data_Return(&PSU_Data, 
                                        pmbusData2.currentAddrPtr++ ,  
                                        I2C_Got_Addr_NOW, 
                                        SERCOM_NOW, 
                                        SERCOM2_CMD[0], 
                                        pmbusData2.addrIndex);
                if (pmbusData2.currentAddrPtr >= PIC_OPCODE_SIZE_BYTES)
                {
                    pmbusData2.currentAddrPtr = 0;
                }
                return isSuccess;
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED:             
                if (pmbusData2.wrBufferIndex > 0)
                {
                    if (pmbusData2.wrBufferIndex > FRU_SIZE_BYTES)
                    {
                        pmbusData2.wrBufferIndex = FRU_SIZE_BYTES;
                    }
                    else 
                    {
                        Ms_W_Cmd_length = (uint32_t)pmbusData2.wrBufferIndex;
                        OPcode_CMD_MW = SERCOM2_CMD;
                        PSU_Flag_Ms_W(I2C_Got_Addr_NOW);
                    }
                    pmbusData2.wrAddr = pmbusData2.currentAddrPtr;
                    pmbusData2.nWrBytes = pmbusData2.wrBufferIndex;

                    /* Reset the indexes */
                    pmbusData2.addrIndex = 0;
                    pmbusData2.wrBufferIndex = 0;
                    /* Set busy flag to send NAK for any write requests */
                    pmbusData2.internalWriteInProgress = true;
                    pmbusData2.i2cCommand = I2C_CMD_WRITE;
                    /* FRU is busy. Send NAK Mike Modify*/
                    isSuccess = false;
                }
                else
                {
                    pmbusData2.internalWriteInProgress = false;
                    pmbusData2.i2cCommand = I2C_CMD_IDLE;   /*Mike add write request allow AK to finish STOP BIT event*/                                 
                }
                return isSuccess;
                break;
            default:
                return isSuccess;
                break;
        }
}

bool SERCOM3_PMbus_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW )
{
    static uint8_t PMbus_CMD = UN_KONW_STATUS;
    bool isSuccess = true;
    static int CMD_Size = 0;
    
        switch(event)
        {
            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH:
                if (( SERCOM3_ADDR_Match() == SERCOM_I2C_SLAVE_TRANSFER_DIR_WRITE) && (pmbusData3.internalWriteInProgress == true))
                {
                    /* FRU is busy. Send NAK */
                    isSuccess = false;
                }
                else
                {
                    /* Reset the indexes */
                    pmbusData3.addrIndex = 0;
                    pmbusData3.wrBufferIndex = 0;
                    CMD_Size = 0;
                }
                return isSuccess;
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_RX_READY:
                /* Receive request data from BMC */
                if (pmbusData3.addrIndex < CMD_SIZE_BYTE)
                {
                    ((uint8_t*)&pmbusData3.currentAddrPtr)[pmbusData3.addrIndex++] = GET_SERCOM3_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    CMD_Size++;
                    PMbus_CMD = pmbusData3.currentAddrPtr;
                    pmbusData3.currentAddrPtr = PIC_OPCODE_START_ADDR;
                }
                else
                {                      
                    PMbus_CMD = GET_SERCOM3_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    pmbusData3.wrBuffer[(pmbusData3.wrBufferIndex & FRU_SIZE_MASK)] = PMbus_CMD;
                    pmbusData3.wrBufferIndex++;
                }         
                return isSuccess;      
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_TX_READY:
                SERCOM3_PSU_Data_Return(&PSU_Data, 
                                        pmbusData3.currentAddrPtr++ ,  
                                        I2C_Got_Addr_NOW, 
                                        SERCOM_NOW, 
                                        SERCOM3_CMD[0], 
                                        pmbusData3.addrIndex);
                if (pmbusData3.currentAddrPtr >= PIC_OPCODE_SIZE_BYTES)
                {
                    pmbusData3.currentAddrPtr = 0;
                }
                return isSuccess;
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED:
                if (pmbusData3.wrBufferIndex > 0)
                {
                    if (pmbusData3.wrBufferIndex > FRU_SIZE_BYTES)
                    {
                        pmbusData3.wrBufferIndex = FRU_SIZE_BYTES;
                    }
                    else 
                    {
                        Ms_W_Cmd_length = (uint32_t)pmbusData3.wrBufferIndex;
                        OPcode_CMD_MW = SERCOM3_CMD;
                        PSU_Flag_Ms_W(I2C_Got_Addr_NOW);
                    }
                    pmbusData3.wrAddr = pmbusData3.currentAddrPtr;
                    pmbusData3.nWrBytes = pmbusData3.wrBufferIndex;

                    /* Reset the indexes */
                    pmbusData3.addrIndex = 0;
                    pmbusData3.wrBufferIndex = 0;
                    /* Set busy flag to send NAK for any write requests */
                    pmbusData3.internalWriteInProgress = true;
                    pmbusData3.i2cCommand = I2C_CMD_WRITE;
                    /* FRU is busy. Send NAK Mike Modify*/
                    isSuccess = false;
                }
                else
                {
                    pmbusData3.internalWriteInProgress = false;
                    pmbusData3.i2cCommand = I2C_CMD_IDLE;   /*Mike add write request allow AK to finish STOP BIT event*/                                 
                }
                return isSuccess;
                break;
            default:
                return isSuccess;
                break;
        }
    
}

bool SERCOM4_PMbus_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW )
{
    static uint8_t PMbus_CMD = UN_KONW_STATUS;
    bool isSuccess = true;
    static int CMD_Size = 0;
    
        switch(event)
        {
            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH:
                if (( SERCOM4_ADDR_Match() == SERCOM_I2C_SLAVE_TRANSFER_DIR_WRITE) && (pmbusData4.internalWriteInProgress == true))
                {
                    /* FRU is busy. Send NAK */
                    isSuccess = false;
                }
                else
                {
                    /* Reset the indexes */
                    pmbusData4.addrIndex = 0;
                    pmbusData4.wrBufferIndex = 0;
                    CMD_Size = 0;
                }
                return isSuccess;
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_RX_READY:
                /* Receive request data from BMC */
                if (pmbusData4.addrIndex < CMD_SIZE_BYTE)
                {
                    ((uint8_t*)&pmbusData4.currentAddrPtr)[pmbusData4.addrIndex++] = GET_SERCOM4_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    CMD_Size++;
                    PMbus_CMD = pmbusData4.currentAddrPtr;
                    pmbusData4.currentAddrPtr = PIC_OPCODE_START_ADDR;
                }
                else
                {                      
                    PMbus_CMD = GET_SERCOM4_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    pmbusData4.wrBuffer[(pmbusData4.wrBufferIndex & FRU_SIZE_MASK)] = PMbus_CMD;
                    pmbusData4.wrBufferIndex++;
                }
                return isSuccess;             
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_TX_READY:
                SERCOM4_PSU_Data_Return(&PSU_Data, 
                                        pmbusData4.currentAddrPtr++ ,  
                                        I2C_Got_Addr_NOW, 
                                        SERCOM_NOW, 
                                        SERCOM4_CMD[0], 
                                        pmbusData4.addrIndex);
                if (pmbusData4.currentAddrPtr >= PIC_OPCODE_SIZE_BYTES)
                {
                    pmbusData4.currentAddrPtr = 0;
                }
                return isSuccess;
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED:         
                if (pmbusData4.wrBufferIndex > 0)
                {
                    if (pmbusData4.wrBufferIndex > FRU_SIZE_BYTES)
                    {
                        pmbusData4.wrBufferIndex = FRU_SIZE_BYTES;
                    }
                    else 
                    {
                        Ms_W_Cmd_length = (uint32_t)pmbusData4.wrBufferIndex;
                        OPcode_CMD_MW = SERCOM4_CMD;
                        PSU_Flag_Ms_W(I2C_Got_Addr_NOW);
                    }
                    pmbusData4.wrAddr = pmbusData4.currentAddrPtr;
                    pmbusData4.nWrBytes = pmbusData4.wrBufferIndex;

                    /* Reset the indexes */
                    pmbusData4.addrIndex = 0;
                    pmbusData4.wrBufferIndex = 0;
                    /* Set busy flag to send NAK for any write requests */
                    pmbusData4.internalWriteInProgress = true;
                    pmbusData4.i2cCommand = I2C_CMD_WRITE;
                    /* FRU is busy. Send NAK Mike Modify*/
                    isSuccess = false;
                }
                else
                {
                    pmbusData4.internalWriteInProgress = false;
                    pmbusData4.i2cCommand = I2C_CMD_IDLE;   /*Mike add write request allow AK to finish STOP BIT event*/                                 
                }
                return isSuccess;
                break;
            default:
                return isSuccess;
                break;
        }
}
/* *****************************************************************************
 End of File
 */