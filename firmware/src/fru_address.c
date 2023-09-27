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

uint8_t FRU_ADDR;

FRU_DATA   fruData;

const uint8_t PIC_FRU_Data[PIC_FRU_SIZE_BYTES] __attribute__((address(PIC_FRU_START_ADDR)))=        
{
    0x01,0x00,0x00,0x01,0x00,0x00,0x00,0xfe,0x01,0x08,0x19,0x32,0x44,0xdd,0xce,0x49,
    0x6e,0x76,0x65,0x6e,0x74,0x65,0x63,0x20,0x43,0x6f,0x72,0x70,0x2e,0xcb,0x50,0x75,
    0x72,0x6e,0x65,0x6c,0x6c,0x20,0x50,0x44,0x42,0xc6,0x31,0x32,0x33,0x34,0x35,0x36,
    0xcb,0x31,0x33,0x39,0x35,0x41,0x33,0x35,0x32,0x33,0x37,0x30,0xc3,0x50,0x44,0x42,
    0xc3,0x50,0x44,0x42,0xc1,0x00,0x00,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff        
};

uint8_t PSU0_FRU_Data[FRU_SIZE_BYTES]=   //data from trn_ac-dc_csu2400ap_release_1_1581520397_techref page48~54     
{
    0x01,0x00,0x00,0x00,0x04,0x14,0x00,0xe7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x01,0x10,0x19,0xcc,0x41,0x72,0x74,0x65,0x73,0x79,0x6e,0x20,0x20,0x20,0x20,0x20,
    0xe4,0x43,0x52,0x50,0x53,0x3a,0x20,0x43,0x6f,0x6d,0x6d,0x6f,0x6e,0x20,0x52,0x65,
    0x64,0x75,0x6e,0x64,0x61,0x6e,0x74,0x20,0x50,0x6f,0x77,0x65,0x72,0x20,0x53,0x75,
    0x70,0x70,0x6c,0x79,0x00,0xd0,0x43,0x53,0x55,0x32,0x34,0x30,0x30,0x41,0x50,0x2d,
    0x33,0x2d,0x31,0x30,0x30,0x20,0xd0,0x52,0x65,0x6c,0x65,0x61,0x73,0x65,0x20,0x2d,
    0x30,0x30,0x32,0x33,0x00,0x20,0x20,0xce,0x4e,0x32,0x38,0x39,0x32,0x57,0x30,0x30,
    0x48,0x4c,0x4b,0x50,0x5a,0x20,0x00,0x00,0xc1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc1,
    0x00,0x02,0x18,0x0c,0xda,0x60,0x09,0x8b,0x08,0x23,0xff,0x50,0x46,0xc0,0x5d,0x00,
    0x00,0x00,0x00,0x00,0x3c,0x01,0x0b,0xac,0xfa,0xcc,0x60,0x09,0x00,0x01,0x02,0x0d,
    0x47,0xa9,0x00,0xc4,0x04,0x9c,0x04,0xec,0x04,0x78,0x00,0xe8,0x03,0xff,0xff,0x01,
    0x82,0x0d,0x32,0x3e,0x81,0xb0,0x04,0x74,0x04,0xec,0x04,0x78,0x00,0x00,0x00,0xac,
    0x0d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
            
};

uint8_t PSU1_FRU_Data[FRU_SIZE_BYTES]=   //data from trn_ac-dc_csu2400ap_release_1_1581520397_techref page48~54     
{
    0x01,0x00,0x00,0x00,0x04,0x14,0x00,0xe7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x01,0x10,0x19,0xcc,0x41,0x72,0x74,0x65,0x73,0x79,0x6e,0x20,0x20,0x20,0x20,0x20,
    0xe4,0x43,0x52,0x50,0x53,0x3a,0x20,0x43,0x6f,0x6d,0x6d,0x6f,0x6e,0x20,0x52,0x65,
    0x64,0x75,0x6e,0x64,0x61,0x6e,0x74,0x20,0x50,0x6f,0x77,0x65,0x72,0x20,0x53,0x75,
    0x70,0x70,0x6c,0x79,0x00,0xd0,0x43,0x53,0x55,0x32,0x34,0x30,0x30,0x41,0x50,0x2d,
    0x33,0x2d,0x31,0x30,0x30,0x20,0xd0,0x52,0x65,0x6c,0x65,0x61,0x73,0x65,0x20,0x2d,
    0x30,0x30,0x32,0x33,0x00,0x20,0x20,0xce,0x4e,0x32,0x38,0x39,0x32,0x57,0x30,0x30,
    0x48,0x4c,0x4b,0x50,0x5a,0x20,0x00,0x00,0xc1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc1,
    0x00,0x02,0x18,0x0c,0xda,0x60,0x09,0x8b,0x08,0x23,0xff,0x50,0x46,0xc0,0x5d,0x00,
    0x00,0x00,0x00,0x00,0x3c,0x01,0x0b,0xac,0xfa,0xcc,0x60,0x09,0x00,0x01,0x02,0x0d,
    0x47,0xa9,0x00,0xc4,0x04,0x9c,0x04,0xec,0x04,0x78,0x00,0xe8,0x03,0xff,0xff,0x01,
    0x82,0x0d,0x32,0x3e,0x81,0xb0,0x04,0x74,0x04,0xec,0x04,0x78,0x00,0x00,0x00,0xac,
    0x0d,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
            
};

bool SERCOM_FRU_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW )
{
    bool isSuccess = true;
    static int CMD_Size = 0;
        switch(event)
        {
            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_ADDR_MATCH:
                if (( Event_ADDR_Match( SERCOM_NOW ) == SERCOM_I2C_SLAVE_TRANSFER_DIR_WRITE) && (fruData.internalWriteInProgress == true))
                {
                    /* FRU is busy. Send NAK */
                    isSuccess = false;
                }
                else
                {
                    /* Reset the indexes */
                    fruData.addrIndex = 0;
                    fruData.wrBufferIndex = 0;
                    CMD_Size = 0;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_RX_READY:
                /* Receive request data from BMC*/
                
                if (fruData.addrIndex < CMD_SIZE_BYTE)
                {
                    FRU_ADDR = GET_SERCOM_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    ((uint8_t*)&fruData.currentAddrPtr)[fruData.addrIndex++] = FRU_ADDR;
                    CMD_Size++;
                }
                else
                {
                    FRU_ADDR = GET_SERCOM_I2C_OFFSET(SERCOM_NOW , CMD_Size);
                    fruData.wrBuffer[(fruData.wrBufferIndex & FRU_SIZE_MASK)] = FRU_ADDR;
                    CMD_Size++;
                    fruData.wrBufferIndex++;
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_TX_READY:
                /* Provide response data to BMC */
                if ((I2C_Got_Addr_NOW == PSU0_FRU_BMC_SIDE_ADDR) ||
                    (I2C_Got_Addr_NOW == PSU1_FRU_BMC_SIDE_ADDR))
                {
                    Select_SERCOM(fruData.currentAddrPtr++ , I2C_Got_Addr_NOW , SERCOM_NOW , FRU_ADDR , fruData.addrIndex);
                    if (fruData.currentAddrPtr >= FRU_SIZE_BYTES)
                    {
                        fruData.currentAddrPtr = 0;
                    }
                }
                else if(I2C_Got_Addr_NOW == PIC_FRU_BMC_SIDE_ADDR)
                {
                    Select_SERCOM(fruData.currentAddrPtr++ , I2C_Got_Addr_NOW , SERCOM_NOW , FRU_ADDR , fruData.addrIndex);
                    if (fruData.currentAddrPtr >= PIC_FRU_SIZE_BYTES)
                    {
                        fruData.currentAddrPtr = 0;
                    }
                }
                break;

            case SERCOM_I2C_SLAVE_TRANSFER_EVENT_STOP_BIT_RECEIVED:
                if (fruData.wrBufferIndex > 0)
                {
                    if (fruData.wrBufferIndex > FRU_SIZE_BYTES)
                    {
                        fruData.wrBufferIndex = FRU_SIZE_BYTES;
                    }
                    fruData.wrAddr = fruData.currentAddrPtr;
                    fruData.nWrBytes = fruData.wrBufferIndex;

                    /* Update the current address pointer to allow for sequential read */
                    fruData.currentAddrPtr += fruData.wrBufferIndex;

                    /* Reset the indexes */
                    fruData.addrIndex = 0;
                    fruData.wrBufferIndex = 0;

                    /* Set busy flag to send NAK for any write requests */
                    fruData.internalWriteInProgress = true;
                    fruData.i2cCommand = I2C_CMD_WRITE;
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
