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
#include "Purnell_OEM.h"

uint8_t OPcode_CMD[PIC_OPCODE_SIZE_BYTES] = {0x00};

//Confirm the I2C transfer direction
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
            return ODM_FAIL;
            break;
    }   
}

//Get the Offset or CMD
uint8_t GET_SERCOM_I2C_OFFSET( uintptr_t SERCOM_NOW , int CMD_Size)
{
    if(SERCOM_NOW == SERCOM1)
    {
        OPcode_CMD[CMD_Size] = SERCOM1_I2C_ReadByte();
    }
    else if(SERCOM_NOW == SERCOM2)
    {
        OPcode_CMD[CMD_Size] = SERCOM2_I2C_ReadByte();
    }
    else if(SERCOM_NOW == SERCOM3)
    {
        OPcode_CMD[CMD_Size] = SERCOM3_I2C_ReadByte();
    }
    else if(SERCOM_NOW == SERCOM4)
    {
        OPcode_CMD[CMD_Size] = SERCOM4_I2C_ReadByte();
    }
    return OPcode_CMD[CMD_Size];
}

//Get the Packing Payload Data
uint8_t Packing_Payload_Data(uint16_t CurrentADDR ,  uintptr_t I2C_Got_Addr_NOW ,uint8_t PIC_CMD ,uint8_t PIC_CMD_Size)
{
    switch(I2C_Got_Addr_NOW)
    {
        case PSU0_FRU_BMC_SIDE_ADDR:
            return PSU_FRU_Data[CurrentADDR];
            break;
        
        case PSU1_FRU_BMC_SIDE_ADDR:
            return PSU_FRU_Data[CurrentADDR];
            break;
            
        case PIC_FRU_BMC_SIDE_ADDR:
            return PIC_FRU_Data[CurrentADDR];
            break;
            
        case PIC_OPCODE_BMC_SIDE_ADDR:
            if(PIC_CMD_Size < CMD_SIZE_ONE_BYTE ) //PIC CMD Size is 0 base 
            {
                if(PIC_CMD == GET_PIC_MAJOR)
                {
                    return PIC_MAJOR_Data[CurrentADDR];
                    break;
                }
                else if(PIC_CMD == GET_PIC_MINOR)
                {
                    return PIC_MINOR_Data[CurrentADDR];
                    break;
                }
                else
                {
                    //TODO debug message
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
            return INVALID_ADDRESS;
            break;
    }   
}

bool Select_SERCOM(uint16_t CurrentADDR, uintptr_t I2C_Got_Addr_NOW , uintptr_t SERCOM_NOW ,uint8_t PIC_CMD ,uint8_t PIC_CMD_Size)
{
    bool isSuccess = false;
    if(SERCOM_NOW == SERCOM1)
    {
        //sercom1 response Data to BMC
        SERCOM1_I2C_WriteByte(Packing_Payload_Data(CurrentADDR , I2C_Got_Addr_NOW ,PIC_CMD ,PIC_CMD_Size));
    }
    else if(SERCOM_NOW == SERCOM2)
    {
        //sercom2 response Data to BMC
        SERCOM2_I2C_WriteByte(Packing_Payload_Data(CurrentADDR , I2C_Got_Addr_NOW ,PIC_CMD ,PIC_CMD_Size));
    }
    else if(SERCOM_NOW == SERCOM3)
    {
        //sercom3 response Data to BMC
        SERCOM3_I2C_WriteByte(Packing_Payload_Data(CurrentADDR , I2C_Got_Addr_NOW ,PIC_CMD ,PIC_CMD_Size));
    }
    else if(SERCOM_NOW == SERCOM4)
    {
        //sercom4 response Data to BMC
        SERCOM4_I2C_WriteByte(Packing_Payload_Data(CurrentADDR , I2C_Got_Addr_NOW ,PIC_CMD ,PIC_CMD_Size));
    }
    return isSuccess;
}



/* *****************************************************************************
 End of File
 */
