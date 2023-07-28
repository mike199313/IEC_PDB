/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */
#ifndef _I2C_ADDRESS_H
#define _I2C_ADDRESS_H
#include "definitions.h"
#define FLASH_END_ADDR              0x00040000UL

#define FRU_SIZE_BYTES              256  // it must be a multiple of ROW (FLASH_ROW_SIZE_BYTES) 
#define FRU_START_ADDR              (FLASH_END_ADDR-FRU_SIZE_BYTES)
#define FRU_SIZE_MASK               0xFF
#define PSU1_FRU_ADDR               0x52 //Purnell_PDB_PIC_FW_Spec_V0.02.docx page 8
#define PSU1_FRU_Slave_ADDR         0x51 //Purnell_PDB_PIC_FW_Spec_V0.02.docx page 8
#define PIC_FRU_Slave_ADDR          0x55 //Purnell_PDB_PIC_FW_Spec_V0.02.docx page 9
#define PSU0_FRU_ADDR               0x50 //Purnell_PDB_PIC_FW_Spec_V0.02.docx page 9
#define PSU0_FRU_Slave_ADDR         0x50 //Purnell_PDB_PIC_FW_Spec_V0.02.docx page 9

#define PIC_FRU_SIZE_BYTES          128 //at least 1 page(1 page 64byte 2page 128byte)

#define I2C_SLAVE_ADDR_MASK         0x0d

extern uint8_t I2C_Got_Addr_NOW;

typedef enum
{
    I2C_CMD_WRITE,
    I2C_CMD_IDLE,
}I2C_CMD;

typedef struct
{
    /* currentAddrPtr - to allow for sequential read (from the current address) */
    uint16_t                    currentAddrPtr;
    /* addrIndex - used to copy 2 bytes of FRU memory address */
    uint8_t                     addrIndex;
    /* wrBuffer - holds the incoming data from the I2C master */
    uint8_t                     wrBuffer[FRU_SIZE_BYTES];
    /* wrBufferIndex - Index into the wrBuffer[] */
    uint16_t                    wrBufferIndex;
    /* wrAddr - indicates the starting address of the FRU emulation memory to write to */
    volatile uint16_t           wrAddr;
    /* nWrBytes - indicates the number of bytes to write to FRU emulation buffer */
    volatile uint8_t            nWrBytes;
    /* internalWriteInProgress - indicates that FRU is busy with internal writes */
    bool                        internalWriteInProgress;
    /* fruCommand - used to trigger write to the FRU emulation buffer */
    I2C_CMD                     i2cCommand;
}FRU_DATA;

extern FRU_DATA   fruData;

extern uint8_t PSU_FRU_Data[FRU_SIZE_BYTES];

bool SERCOM1_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );
bool SERCOM1_FRU_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );

bool SERCOM2_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );
bool SERCOM2_FRU_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );

bool SERCOM3_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );
bool SERCOM3_FRU_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );

bool SERCOM4_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );
bool SERCOM4_FRU_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );



#endif /* _I2C_ADDRESS_H */

/* *****************************************************************************
 End of File
 */
