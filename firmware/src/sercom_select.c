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


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */
#include "i2c_address.h"



bool Event_ADDR_Match( uintptr_t SERCOM_NOW )
{
    switch(SERCOM_NOW)
    {
        case SERCOM1:
            return SERCOM1_I2C_TransferDirGet();
            break;
        
        case SERCOM2:
            return SERCOM2_I2C_TransferDirGet();
            break;
            
        case SERCOM3:
            return SERCOM3_I2C_TransferDirGet();
            break;
            
        case SERCOM4:
            return SERCOM4_I2C_TransferDirGet();
            break;
        default:
            return 0;
            break;
    }   
}

uint8_t SERCOM_PIC_CMD( uintptr_t SERCOM)
{
    uint8_t PIC_CMD_NOW = 1;
    if(SERCOM == SERCOM1)
    {
        PIC_CMD_NOW = SERCOM1_I2C_ReadByte();
    }
    else if(SERCOM == SERCOM2)
    {
        PIC_CMD_NOW = SERCOM2_I2C_ReadByte();
    }
    else if(SERCOM == SERCOM3)
    {
        PIC_CMD_NOW = SERCOM3_I2C_ReadByte();
    }
    else if(SERCOM == SERCOM4)
    {
        PIC_CMD_NOW = SERCOM4_I2C_ReadByte();
    }
    return PIC_CMD_NOW;
}

uint8_t Select_FRU_Data(uint16_t CurrentADDR ,  uintptr_t I2C_Got_Addr_NOW ,uint8_t PIC_CMD ,uint8_t PIC_CMD_Size)
{
    switch(I2C_Got_Addr_NOW)
    {
        case PSU1_FRU_SLAVE_ADDR:
            return PSU_FRU_Data[CurrentADDR];
            break;
        
        case PSU0_FRU_SLAVE_ADDR:
            return PSU_FRU_Data[CurrentADDR];
            break;
            
        case PIC_FRU_SLAVE_ADDR:
            return PIC_FRU_Data[CurrentADDR];
            break;
            
        case PIC_OPCODE_SLAVE_ADDR:
            if(PIC_CMD_Size < 2 )
            {
                if(PIC_CMD == 0x01)
                {
                    return PIC_MAJOR_Data[CurrentADDR];
                    break;
                }
                else if(PIC_CMD == 0x02)
                {
                    return PIC_MINOR_Data[CurrentADDR];
                    break;
                }
                else
                {
                    return INVALID_COMMAND;
                    break;
                }
            }
            else
            {
                return DATA_LENGTH_INVALID;
                break;
            }
                
        default:
            return 0;
            break;
    }   
}

bool SERCOM_Select_Data(uint16_t CurrentADDR, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW ,uint8_t PIC_CMD ,uint8_t PIC_CMD_Size)
{
    bool isSuccess = true;
    if(SERCOM_NOW == SERCOM1)
    {
        SERCOM1_I2C_WriteByte(Select_FRU_Data(CurrentADDR , I2C_Got_Addr_NOW ,PIC_CMD ,PIC_CMD_Size));
    }
    else if(SERCOM_NOW == SERCOM2)
    {
        SERCOM2_I2C_WriteByte(Select_FRU_Data(CurrentADDR , I2C_Got_Addr_NOW ,PIC_CMD ,PIC_CMD_Size));
    }
    else if(SERCOM_NOW == SERCOM3)
    {
        SERCOM3_I2C_WriteByte(Select_FRU_Data(CurrentADDR , I2C_Got_Addr_NOW ,PIC_CMD ,PIC_CMD_Size));
    }
    else if(SERCOM_NOW == SERCOM4)
    {
        SERCOM4_I2C_WriteByte(Select_FRU_Data(CurrentADDR , I2C_Got_Addr_NOW ,PIC_CMD ,PIC_CMD_Size));
    }
    return isSuccess;
}



/* *****************************************************************************
 End of File
 */
