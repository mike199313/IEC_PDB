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
#define PSU1_FRU_SLAVE_ADDR         0x51 //Purnell_PDB_PIC_FW_Spec_V0.02.docx page 8
#define PSU0_FRU_ADDR               0x50 //Purnell_PDB_PIC_FW_Spec_V0.02.docx page 9
#define PSU0_FRU_SLAVE_ADDR         0x50 //Purnell_PDB_PIC_FW_Spec_V0.02.docx page 9
#define PIC_FRU_SLAVE_ADDR          0x55 //Purnell_PDB_PIC_FW_Spec_V0.02.docx page 9
#define PIC_OPCODE_SLAVE_ADDR       0x5d //Purnell_PDB_PIC_FW_Spec_V0.02.docx page 9

#define PIC_OPCODE_SIZE_BYTES       5  //at least 1 page(1 page 64byte 2page 128byte)
#define PIC_FRU_SIZE_BYTES          128 //at least 1 page(1 page 64byte 2page 128byte)
#define PIC_FRU_START_ADDR          (FRU_START_ADDR-PIC_FRU_SIZE_BYTES)
#define I2C_SLAVE_ADDR_MASK         0x0d
#define SERCOM1                     1
#define SERCOM2                     2
#define SERCOM3                     3
#define SERCOM4                     4
#define DATA_LENGTH_INVALID         0xC7
#define INVALID_COMMAND             0xc1
#define ADDR_BYTE                   2

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
extern FRU_DATA   picData;

extern uint8_t PIC_MAJOR_Data[PIC_OPCODE_SIZE_BYTES];
extern uint8_t PIC_MINOR_Data[PIC_OPCODE_SIZE_BYTES];

extern uint8_t PSU_FRU_Data[FRU_SIZE_BYTES];
extern const uint8_t PIC_FRU_Data[PIC_FRU_SIZE_BYTES];

bool Event_ADDR_Match( uintptr_t SERCOM_NOW );
uint8_t Select_FRU_Data(uint16_t CurrentADDR ,  uintptr_t I2C_Got_Addr_NOW ,uint8_t PIC_CMD ,uint8_t PIC_CMD_Size);
bool SERCOM_Select_Data(uint16_t CurrentADDR, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW,uint8_t PIC_CMD ,uint8_t PIC_CMD_Size);
uint8_t SERCOM_PIC_CMD(uintptr_t SERCOM_NOW);

bool SERCOM_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );
bool SERCOM_FRU_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle, uintptr_t SERCOM_NOW );
bool SERCOM_PIC_OPcode_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle, uintptr_t SERCOM_NOW );

#endif /* _I2C_ADDRESS_H */

/* *****************************************************************************
 End of File
 */
