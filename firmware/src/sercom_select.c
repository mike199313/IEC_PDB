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

/*
 * HCD calculation method description:
 *  
 *  first shift 4 bits to the right and multiply by 16 to calculate the decimal, 
 *  keep the right 4 bits to get the unit digit, and then add the two to get the decimal
 * 
 */
//Get the Packing Payload Data
uint8_t Packing_Payload_Data(uint16_t CurrentADDR ,  uintptr_t I2C_Got_Addr_NOW ,uint8_t PIC_CMD ,uint8_t PIC_CMD_Size)
{
    static uint8_t PIC_MAJOR_Data[PIC_OPCODE_SIZE_BYTES] = {CC_SUCCESS , MAJOR_VERSION};
    static uint8_t PIC_MINOR_Data[PIC_OPCODE_SIZE_BYTES] = {CC_SUCCESS , MINOR_VERSION};
    static uint8_t GPIO_STATUS[PIC_OPCODE_SIZE_BYTES];
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
                else if(PIC_CMD == GET_GPIO_STATUS)
                {
                    uint8_t PIN_NUMBER = ((OPcode_CMD[1] >> 4)*16) + (OPcode_CMD[1] & 0x0f);//This is to convert Hex to decimal
                    PIN_NUMBER = PIN_NUMBER - 1;
                    if(PIN_NUMBER < PIN_NUM_MAX)
                    {
                        switch(CurrentADDR)
                        {
                            case 0:
                                GPIO_STATUS[CurrentADDR] = CC_SUCCESS;
                                break;

                            case 1:
                                GPIO_STATUS[CurrentADDR] = PORT_PinDIRRead(PIN_NUMBER);
                                break;        

                            case 2:
                                GPIO_STATUS[CurrentADDR] = PORT_PinLatchRead(PIN_NUMBER);
                                break;
                        }
                        return GPIO_STATUS[CurrentADDR];
                        break;
                    }
                    else
                    {
                        return INVALID_DATA;
                        break;
                    }
                    
                }
                else if(PIC_CMD == SET_GPIO_STATUS)
                {
                    uint8_t PIN_NUMBER = ((OPcode_CMD[1] >> 4)*16) + (OPcode_CMD[1] & 0x0f);//This is to convert Hex to decimal
                    PIN_NUMBER = PIN_NUMBER - 1;
                    
                    if(PIN_NUMBER < PIN_NUM_MAX)
                    {
                        //set input output for GPIO
                        if(OPcode_CMD[2] == GPIO_INPUT )
                        {
                            PORT_PinInputEnable(PIN_NUMBER);
                        }
                        else if(OPcode_CMD[2] == GPIO_OUTPUT  )
                        {
                            PORT_PinOutputEnable(PIN_NUMBER);
                        }
                        else
                        {
                            return INVALID_DATA;
                            break;
                        }
                    
                        //set high low for GPIO
                        if((OPcode_CMD[3] == GPIO_HIGH) || (OPcode_CMD[3] == GPIO_LOW))
                        {
                            PORT_PinWrite(PIN_NUMBER , OPcode_CMD[3]);
                        }
                        else
                        {
                            return INVALID_DATA;
                            break;
                        }
                    }
                    else
                    {
                        return INVALID_DATA;
                        break;
                    }
                    return CC_SUCCESS;
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
            return INVALID_DATA;
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
