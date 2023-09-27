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
#define PIN_NUM_MAX                 64
#define FRU_START_ADDR              (FLASH_END_ADDR-FRU_SIZE_BYTES)
#define FRU_SIZE_MASK               0xFF
#define PIC_OPCODE_SIZE_BYTES       5  //at least 1 page(1 page 64byte 2page 128byte)
#define PIC_FRU_SIZE_BYTES          128 //at least 1 page(1 page 64byte 2page 128byte)
#define PIC_FRU_START_ADDR          (FRU_START_ADDR-PIC_FRU_SIZE_BYTES)
#define PIC_OPCODE_START_ADDR       0x00
#define SLAVE_ADDR_MASK             0x0f //all PSU exist
#define PSU0_SLAVE_ADDR_MASK        0x0e //only PSU0 exist
#define PSU1_SLAVE_ADDR_MASK        0x0d //only PSU1 exist

#define SERCOM1                     1
#define SERCOM2                     2
#define SERCOM3                     3
#define SERCOM4                     4

#define UN_KONW_STATUS              -1
#define ODM_OK                      0
#define ODM_FAIL                    -1
#define CMD_SIZE_BYTE               10  //The maximum size of the CMD that can be used
#define CMD_SIZE_ONE_BYTE           1

extern uint8_t I2C_Got_Addr_NOW;
extern int I2C_SLAVE_ADDR_MASK;
extern uint8_t PIN_NUMBER;

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
    /* i2cCommand - used to trigger write to the FRU emulation buffer */
    I2C_CMD                     i2cCommand;
}FRU_DATA;


extern FRU_DATA   fruData;
extern FRU_DATA   picData;

extern uint8_t OPcode_CMD[PIC_OPCODE_SIZE_BYTES];

extern uint8_t PSU0_FRU_Data[FRU_SIZE_BYTES];
extern uint8_t PSU1_FRU_Data[FRU_SIZE_BYTES];
extern const uint8_t PIC_FRU_Data[PIC_FRU_SIZE_BYTES];

uint8_t GET_SERCOM_I2C_OFFSET(uintptr_t SERCOM_NOW , int CMD_Size);
uint8_t Packing_Payload_Data(uint16_t CurrentADDR ,  uintptr_t I2C_Got_Addr_NOW ,uint8_t PIC_CMD ,uint8_t PIC_CMD_Size);

bool Change_Mask_ADDR(int PSU0exist , int PSU1exist);
bool Event_ADDR_Match( uintptr_t SERCOM_NOW );
bool Select_SERCOM(uint16_t CurrentADDR, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW,uint8_t PIC_CMD ,uint8_t PIC_CMD_Size);
bool SERCOM_I2C_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle );
bool SERCOM_FRU_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle, uintptr_t SERCOM_NOW );
bool SERCOM_PIC_OPcode_Callback ( SERCOM_I2C_SLAVE_TRANSFER_EVENT event, uintptr_t contextHandle, uintptr_t SERCOM_NOW );

#endif /* _I2C_ADDRESS_H */

/* *****************************************************************************
 End of File
 */
