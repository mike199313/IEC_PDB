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
#include <stdio.h>

uint8_t OPcode_CMD[PIC_OPCODE_SIZE_BYTES] = {0x00};
uint8_t SERCOM1_CMD[PIC_OPCODE_SIZE_BYTES] = {0x00};
uint8_t SERCOM2_CMD[PIC_OPCODE_SIZE_BYTES] = {0x00};
uint8_t SERCOM3_CMD[PIC_OPCODE_SIZE_BYTES] = {0x00};
uint8_t SERCOM4_CMD[PIC_OPCODE_SIZE_BYTES] = {0x00};


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

bool SERCOM1_ADDR_Match()
{

    return SERCOM1_I2C_TransferDirGet();
}

bool SERCOM2_ADDR_Match()
{

    return SERCOM2_I2C_TransferDirGet();

}

bool SERCOM3_ADDR_Match()
{

    return SERCOM3_I2C_TransferDirGet();

}

bool SERCOM4_ADDR_Match()
{
 
    return SERCOM4_I2C_TransferDirGet();

}

//Get the Offset or CMD
uint8_t GET_SERCOM_I2C_OFFSET( uintptr_t SERCOM_NOW , int CMD_Size)
{

    switch(SERCOM_NOW)
    {
        case SERCOM1:
            OPcode_CMD[CMD_Size] = SERCOM1_I2C_ReadByte();
            break;
        case SERCOM2:
            OPcode_CMD[CMD_Size] = SERCOM2_I2C_ReadByte();
            break;
        case SERCOM3:
            OPcode_CMD[CMD_Size] = SERCOM3_I2C_ReadByte();
            break;
        case SERCOM4:
            OPcode_CMD[CMD_Size] = SERCOM4_I2C_ReadByte();
            break;
    }
    return OPcode_CMD[CMD_Size];
}

uint8_t GET_SERCOM1_I2C_OFFSET( uintptr_t SERCOM_NOW , int CMD_Size)
{


    SERCOM1_CMD[CMD_Size] = SERCOM1_I2C_ReadByte();

    return SERCOM1_CMD[CMD_Size];
}

uint8_t GET_SERCOM2_I2C_OFFSET( uintptr_t SERCOM_NOW , int CMD_Size)
{

    SERCOM2_CMD[CMD_Size] = SERCOM2_I2C_ReadByte();

    return SERCOM2_CMD[CMD_Size];
}

uint8_t GET_SERCOM3_I2C_OFFSET( uintptr_t SERCOM_NOW , int CMD_Size)
{


    SERCOM3_CMD[CMD_Size] = SERCOM3_I2C_ReadByte();

    return SERCOM3_CMD[CMD_Size];
}

uint8_t GET_SERCOM4_I2C_OFFSET( uintptr_t SERCOM_NOW , int CMD_Size)
{

    SERCOM4_CMD[CMD_Size] = SERCOM4_I2C_ReadByte();

    return SERCOM4_CMD[CMD_Size];
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
    static uint8_t PIN_NUMBER;
    switch(I2C_Got_Addr_NOW)
    {
        case PSU0_FRU_BMC_SIDE_ADDR:
            switch(CurrentADDR)//read PSU0 FRU Data(256 byte) 
            {
                    case 0:
                        return PSU0_FRU_Data[0];
                        break;
                    case 1:
                        return PSU0_FRU_Data[1]; 
                        break;
                    case 2:
                        return PSU0_FRU_Data[2];
                        break;
                    case 3:
                        return PSU0_FRU_Data[3];
                        break;
                    case 4:
                        return PSU0_FRU_Data[4];  
                        break;
                    case 5:
                        return PSU0_FRU_Data[5];
                        break;
                    case 6:
                        return PSU0_FRU_Data[6];
                        break;
                    case 7:
                        return PSU0_FRU_Data[7];
                        break;
                    case 8:
                        return PSU0_FRU_Data[8];
                        break;
                    case 9:
                        return PSU0_FRU_Data[9];
                        break;
                    case 10:
                        return PSU0_FRU_Data[10];  
                        break;
                    case 11:
                        return PSU0_FRU_Data[11];       
                        break;
                    case 12:
                        return PSU0_FRU_Data[12];
                        break;
                    case 13:
                        return PSU0_FRU_Data[13];
                        break;
                    case 14:
                        return PSU0_FRU_Data[14];
                        break;
                    case 15:
                        return PSU0_FRU_Data[15];
                        break;
                    case 16:
                        return PSU0_FRU_Data[16];  
                        break;
                    case 17:
                        return PSU0_FRU_Data[17];     
                        break;  
                    case 18:
                        return PSU0_FRU_Data[18];
                        break;
                    case 19:
                        return PSU0_FRU_Data[19];
                        break;
                    case 20:
                        return PSU0_FRU_Data[20];
                        break;
                    case 21:
                        return PSU0_FRU_Data[21];
                        break;
                    case 22:
                        return PSU0_FRU_Data[22];
                        break;
                    case 23:
                        return PSU0_FRU_Data[23];
                        break;
                    case 24:
                        return PSU0_FRU_Data[24];
                        break;
                    case 25:
                        return PSU0_FRU_Data[25]; 
                        break;
                    case 26:
                        return PSU0_FRU_Data[26];
                        break;
                    case 27:
                        return PSU0_FRU_Data[27];
                        break;
                    case 28:
                        return PSU0_FRU_Data[28];  
                        break;
                    case 29:
                        return PSU0_FRU_Data[29];
                        break;
                    case 30:
                        return PSU0_FRU_Data[30];
                        break;
                    case 31:
                        return PSU0_FRU_Data[31];
                        break;
                    case 32:
                        return PSU0_FRU_Data[32];
                        break;
                    case 33:
                        return PSU0_FRU_Data[33];
                        break;
                    case 34:
                        return PSU0_FRU_Data[34];  
                        break;
                    case 35:
                        return PSU0_FRU_Data[35];       
                        break;
                    case 36:
                        return PSU0_FRU_Data[36];
                        break;
                    case 37:
                        return PSU0_FRU_Data[37];
                        break;
                    case 38:
                        return PSU0_FRU_Data[38];
                        break;
                    case 39:
                        return PSU0_FRU_Data[39];
                        break;
                    case 40:
                        return PSU0_FRU_Data[40];  
                        break;
                    case 41:
                        return PSU0_FRU_Data[41];     
                        break;  
                    case 42:
                        return PSU0_FRU_Data[42];
                        break;
                    case 43:
                        return PSU0_FRU_Data[43];
                        break;
                    case 44:
                        return PSU0_FRU_Data[44];
                        break;
                    case 45:
                        return PSU0_FRU_Data[45];
                        break;
                    case 46:
                        return PSU0_FRU_Data[46];
                        break;
                    case 47:
                        return PSU0_FRU_Data[47];
                        break;
                    case 48:
                        return PSU0_FRU_Data[48];
                        break;
                    case 49:
                        return PSU0_FRU_Data[49]; 
                        break;
                    case 50:
                        return PSU0_FRU_Data[50];
                        break;
                    case 51:
                        return PSU0_FRU_Data[51];
                        break;
                    case 52:
                        return PSU0_FRU_Data[52];  
                        break;
                    case 53:
                        return PSU0_FRU_Data[53];
                        break;
                    case 54:
                        return PSU0_FRU_Data[54];
                        break;
                    case 55:
                        return PSU0_FRU_Data[55];
                        break;
                    case 56:
                        return PSU0_FRU_Data[56];
                        break;
                    case 57:
                        return PSU0_FRU_Data[57];
                        break;
                    case 58:
                        return PSU0_FRU_Data[58];  
                        break;
                    case 59:
                        return PSU0_FRU_Data[59];       
                        break;
                    case 60:
                        return PSU0_FRU_Data[60];
                        break;
                    case 61:
                        return PSU0_FRU_Data[61];
                        break;
                    case 62:
                        return PSU0_FRU_Data[62];
                        break;
                    case 63:
                        return PSU0_FRU_Data[63];
                        break;
                    case 64:
                        return PSU0_FRU_Data[64];
                        break;
                    case 65:
                        return PSU0_FRU_Data[65]; 
                        break;
                    case 66:
                        return PSU0_FRU_Data[66];
                        break;
                    case 67:
                        return PSU0_FRU_Data[67];
                        break;
                    case 68:
                        return PSU0_FRU_Data[68];  
                        break;
                    case 69:
                        return PSU0_FRU_Data[69];
                        break;
                    case 70:
                        return PSU0_FRU_Data[70];
                        break;
                    case 71:
                        return PSU0_FRU_Data[71];
                        break;
                    case 72:
                        return PSU0_FRU_Data[72];
                        break;
                    case 73:
                        return PSU0_FRU_Data[73];
                        break;
                    case 74:
                        return PSU0_FRU_Data[74];  
                        break;
                    case 75:
                        return PSU0_FRU_Data[75];       
                        break;
                    case 76:
                        return PSU0_FRU_Data[76];
                        break;
                    case 77:
                        return PSU0_FRU_Data[77];
                        break;
                    case 78:
                        return PSU0_FRU_Data[78];
                        break;
                    case 79:
                        return PSU0_FRU_Data[79];
                        break;
                    case 80:
                        return PSU0_FRU_Data[80];  
                        break;
                    case 81:
                        return PSU0_FRU_Data[81];     
                        break;  
                    case 82:
                        return PSU0_FRU_Data[82];
                        break;
                    case 83:
                        return PSU0_FRU_Data[83];
                        break;
                    case 84:
                        return PSU0_FRU_Data[84];
                        break;
                    case 85:
                        return PSU0_FRU_Data[85];
                        break;
                    case 86:
                        return PSU0_FRU_Data[86];
                        break;
                    case 87:
                        return PSU0_FRU_Data[87];
                        break;
                    case 88:
                        return PSU0_FRU_Data[88];
                        break;
                    case 89:
                        return PSU0_FRU_Data[89]; 
                        break;
                    case 90:
                        return PSU0_FRU_Data[90];
                        break;
                    case 91:
                        return PSU0_FRU_Data[91];
                        break;
                    case 92:
                        return PSU0_FRU_Data[92];  
                        break;
                    case 93:
                        return PSU0_FRU_Data[93];
                        break;
                    case 94:
                        return PSU0_FRU_Data[94];
                        break;
                    case 95:
                        return PSU0_FRU_Data[95];
                        break;
                    case 96:
                        return PSU0_FRU_Data[96];
                        break;
                    case 97:
                        return PSU0_FRU_Data[97];
                        break;
                    case 98:
                        return PSU0_FRU_Data[98];  
                        break;
                    case 99:
                        return PSU0_FRU_Data[99];       
                        break;
                    case 100:
                        return PSU0_FRU_Data[100];
                        break;
                    case 101:
                        return PSU0_FRU_Data[101];
                        break;
                    case 102:
                        return PSU0_FRU_Data[102];
                        break;
                    case 103:
                        return PSU0_FRU_Data[103];
                        break;
                    case 104:
                        return PSU0_FRU_Data[104];  
                        break;
                    case 105:
                        return PSU0_FRU_Data[105];     
                        break;  
                    case 106:
                        return PSU0_FRU_Data[106];
                        break;
                    case 107:
                        return PSU0_FRU_Data[107];
                        break;
                    case 108:
                        return PSU0_FRU_Data[108];
                        break;
                    case 109:
                        return PSU0_FRU_Data[109];
                        break;
                    case 110:
                        return PSU0_FRU_Data[110];
                        break;
                    case 111:
                        return PSU0_FRU_Data[111];
                        break;
                    case 112:
                        return PSU0_FRU_Data[112];
                        break;
                    case 113:
                        return PSU0_FRU_Data[113]; 
                        break;
                    case 114:
                        return PSU0_FRU_Data[114];
                        break;
                    case 115:
                        return PSU0_FRU_Data[115];
                        break;
                    case 116:
                        return PSU0_FRU_Data[116];  
                        break;
                    case 117:
                        return PSU0_FRU_Data[117];
                        break;
                    case 118:
                        return PSU0_FRU_Data[118];
                        break;
                    case 119:
                        return PSU0_FRU_Data[119];
                        break;
                    case 120:
                        return PSU0_FRU_Data[120];
                        break;
                    case 121:
                        return PSU0_FRU_Data[121];
                        break;
                    case 122:
                        return PSU0_FRU_Data[122];  
                        break;
                    case 123:
                        return PSU0_FRU_Data[123];       
                        break;
                    case 124:
                        return PSU0_FRU_Data[124];
                        break;
                    case 125:
                        return PSU0_FRU_Data[125];
                        break;
                    case 126:
                        return PSU0_FRU_Data[126];
                        break;
                    case 127:
                        return PSU0_FRU_Data[127];
                        break;
                    case 128:
                        return PSU0_FRU_Data[128];
                        break;
                    case 129:
                        return PSU0_FRU_Data[129]; 
                        break;
                    case 130:
                        return PSU0_FRU_Data[130];
                        break;
                    case 131:
                        return PSU0_FRU_Data[131];
                        break;
                    case 132:
                        return PSU0_FRU_Data[132];  
                        break;
                    case 133:
                        return PSU0_FRU_Data[133];
                        break;
                    case 134:
                        return PSU0_FRU_Data[134];
                        break;
                    case 135:
                        return PSU0_FRU_Data[135];
                        break;
                    case 136:
                        return PSU0_FRU_Data[136];
                        break;
                    case 137:
                        return PSU0_FRU_Data[137];
                        break;
                    case 138:
                        return PSU0_FRU_Data[138];  
                        break;
                    case 139:
                        return PSU0_FRU_Data[139];       
                        break;
                    case 140:
                        return PSU0_FRU_Data[140];
                        break;
                    case 141:
                        return PSU0_FRU_Data[141];
                        break;
                    case 142:
                        return PSU0_FRU_Data[142];
                        break;
                    case 143:
                        return PSU0_FRU_Data[143];
                        break;
                    case 144:
                        return PSU0_FRU_Data[144];  
                        break;
                    case 145:
                        return PSU0_FRU_Data[145];     
                        break;  
                    case 146:
                        return PSU0_FRU_Data[146];
                        break;
                    case 147:
                        return PSU0_FRU_Data[147];
                        break;
                    case 148:
                        return PSU0_FRU_Data[148];
                        break;
                    case 149:
                        return PSU0_FRU_Data[149];
                        break;
                    case 150:
                        return PSU0_FRU_Data[150];
                        break;
                    case 151:
                        return PSU0_FRU_Data[151];
                        break;
                    case 152:
                        return PSU0_FRU_Data[152];
                        break;
                    case 153:
                        return PSU0_FRU_Data[153]; 
                        break;
                    case 154:
                        return PSU0_FRU_Data[154];
                        break;
                    case 155:
                        return PSU0_FRU_Data[155];
                        break;
                    case 156:
                        return PSU0_FRU_Data[156];  
                        break;
                    case 157:
                        return PSU0_FRU_Data[157];
                        break;
                    case 158:
                        return PSU0_FRU_Data[158];
                        break;
                    case 159:
                        return PSU0_FRU_Data[159];
                        break;
                    case 160:
                        return PSU0_FRU_Data[160];
                        break;
                    case 161:
                        return PSU0_FRU_Data[161];
                        break;
                    case 162:
                        return PSU0_FRU_Data[162];  
                        break;
                    case 163:
                        return PSU0_FRU_Data[163];       
                        break;
                    case 164:
                        return PSU0_FRU_Data[164];
                        break;
                    case 165:
                        return PSU0_FRU_Data[165];
                        break;
                    case 166:
                        return PSU0_FRU_Data[166];
                        break;
                    case 167:
                        return PSU0_FRU_Data[167];
                        break;
                    case 168:
                        return PSU0_FRU_Data[168];  
                        break;
                    case 169:
                        return PSU0_FRU_Data[169];     
                        break;  
                    case 170:
                        return PSU0_FRU_Data[170];
                        break;
                    case 171:
                        return PSU0_FRU_Data[171];
                        break;
                    case 172:
                        return PSU0_FRU_Data[172];
                        break;
                    case 173:
                        return PSU0_FRU_Data[173];
                        break;
                    case 174:
                        return PSU0_FRU_Data[174];
                        break;
                    case 175:
                        return PSU0_FRU_Data[175];
                        break;
                    case 176:
                        return PSU0_FRU_Data[176];
                        break;
                    case 177:
                        return PSU0_FRU_Data[177]; 
                        break;
                    case 178:
                        return PSU0_FRU_Data[178];
                        break;
                    case 179:
                        return PSU0_FRU_Data[179];
                        break;
                    case 180:
                        return PSU0_FRU_Data[180];  
                        break;
                    case 181:
                        return PSU0_FRU_Data[181];
                        break;
                    case 182:
                        return PSU0_FRU_Data[182];
                        break;
                    case 183:
                        return PSU0_FRU_Data[183];
                        break;
                    case 184:
                        return PSU0_FRU_Data[184];
                        break;
                    case 185:
                        return PSU0_FRU_Data[185];
                        break;
                    case 186:
                        return PSU0_FRU_Data[186];  
                        break;
                    case 187:
                        return PSU0_FRU_Data[187];       
                        break;
                    case 188:
                        return PSU0_FRU_Data[188];
                        break;
                    case 189:
                        return PSU0_FRU_Data[189];
                        break;
                    case 190:
                        return PSU0_FRU_Data[190];
                        break;
                    case 191:
                        return PSU0_FRU_Data[191];
                        break;
                    case 192:
                        return PSU0_FRU_Data[192];
                        break;
                    case 193:
                        return PSU0_FRU_Data[193]; 
                        break;
                    case 194:
                        return PSU0_FRU_Data[194];
                        break;
                    case 195:
                        return PSU0_FRU_Data[195];
                        break;
                    case 196:
                        return PSU0_FRU_Data[196];  
                        break;
                    case 197:
                        return PSU0_FRU_Data[197];
                        break;
                    case 198:
                        return PSU0_FRU_Data[198];
                        break;
                    case 199:
                        return PSU0_FRU_Data[199];
                        break;
                    case 200:
                        return PSU0_FRU_Data[200];
                        break;
                    case 201:
                        return PSU0_FRU_Data[201];
                        break;
                    case 202:
                        return PSU0_FRU_Data[202];  
                        break;
                    case 203:
                        return PSU0_FRU_Data[203];       
                        break;
                    case 204:
                        return PSU0_FRU_Data[204];
                        break;
                    case 205:
                        return PSU0_FRU_Data[205];
                        break;
                    case 206:
                        return PSU0_FRU_Data[206];
                        break;
                    case 207:
                        return PSU0_FRU_Data[207];
                        break;
                    case 208:
                        return PSU0_FRU_Data[208];  
                        break;
                    case 209:
                        return PSU0_FRU_Data[209];     
                        break;  
                    case 210:
                        return PSU0_FRU_Data[210];
                        break;
                    case 211:
                        return PSU0_FRU_Data[211];
                        break;
                    case 212:
                        return PSU0_FRU_Data[212];
                        break;
                    case 213:
                        return PSU0_FRU_Data[213];
                        break;
                    case 214:
                        return PSU0_FRU_Data[214];
                        break;
                    case 215:
                        return PSU0_FRU_Data[215];
                        break;
                    case 216:
                        return PSU0_FRU_Data[216];
                        break;
                    case 217:
                        return PSU0_FRU_Data[217]; 
                        break;
                    case 218:
                        return PSU0_FRU_Data[218];
                        break;
                    case 219:
                        return PSU0_FRU_Data[219];
                        break;
                    case 220:
                        return PSU0_FRU_Data[220];  
                        break;
                    case 221:
                        return PSU0_FRU_Data[221];
                        break;
                    case 222:
                        return PSU0_FRU_Data[222];
                        break;
                    case 223:
                        return PSU0_FRU_Data[223];
                        break;
                    case 224:
                        return PSU0_FRU_Data[224];
                        break;
                    case 225:
                        return PSU0_FRU_Data[225];
                        break;
                    case 226:
                        return PSU0_FRU_Data[226];  
                        break;
                    case 227:
                        return PSU0_FRU_Data[227];       
                        break;
                    case 228:
                        return PSU0_FRU_Data[228];
                        break;
                    case 229:
                        return PSU0_FRU_Data[229];
                        break;
                    case 230:
                        return PSU0_FRU_Data[230];
                        break;
                    case 231:
                        return PSU0_FRU_Data[231];
                        break;
                    case 232:
                        return PSU0_FRU_Data[232];  
                        break;
                    case 233:
                        return PSU0_FRU_Data[233];     
                        break;  
                    case 234:
                        return PSU0_FRU_Data[234];
                        break;
                    case 235:
                        return PSU0_FRU_Data[235];
                        break;
                    case 236:
                        return PSU0_FRU_Data[236];
                        break;
                    case 237:
                        return PSU0_FRU_Data[237];
                        break;
                    case 238:
                        return PSU0_FRU_Data[238];
                        break;
                    case 239:
                        return PSU0_FRU_Data[239];
                        break;
                    case 240:
                        return PSU0_FRU_Data[240];
                        break;
                    case 241:
                        return PSU0_FRU_Data[241]; 
                        break;
                    case 242:
                        return PSU0_FRU_Data[242];
                        break;
                    case 243:
                        return PSU0_FRU_Data[243];
                        break;
                    case 244:
                        return PSU0_FRU_Data[244];  
                        break;
                    case 245:
                        return PSU0_FRU_Data[245];
                        break;
                    case 246:
                        return PSU0_FRU_Data[246];
                        break;
                    case 247:
                        return PSU0_FRU_Data[247];
                        break;
                    case 248:
                        return PSU0_FRU_Data[248];
                        break;
                    case 249:
                        return PSU0_FRU_Data[249];
                        break;
                    case 250:
                        return PSU0_FRU_Data[250];  
                        break;
                    case 251:
                        return PSU0_FRU_Data[251];       
                        break;
                    case 252:
                        return PSU0_FRU_Data[252];
                        break;
                    case 253:
                        return PSU0_FRU_Data[253];
                        break;
                    case 254:
                        return PSU0_FRU_Data[254];
                        break;
                    case 255:
                        return PSU0_FRU_Data[255];
                        break;
                    
                        
                    default:
                        return INVALID_DATA;
                        break;
                        
            }
            break;
        
        case PSU1_FRU_BMC_SIDE_ADDR:
            switch(CurrentADDR)//read PSU1 FRU Data(256 byte) 
            {
                    case 0:
                        return PSU1_FRU_Data[0];
                        break;
                    case 1:
                        return PSU1_FRU_Data[1]; 
                        break;
                    case 2:
                        return PSU1_FRU_Data[2];
                        break;
                    case 3:
                        return PSU1_FRU_Data[3];
                        break;
                    case 4:
                        return PSU1_FRU_Data[4];  
                        break;
                    case 5:
                        return PSU1_FRU_Data[5];
                        break;
                    case 6:
                        return PSU1_FRU_Data[6];
                        break;
                    case 7:
                        return PSU1_FRU_Data[7];
                        break;
                    case 8:
                        return PSU1_FRU_Data[8];
                        break;
                    case 9:
                        return PSU1_FRU_Data[9];
                        break;
                    case 10:
                        return PSU1_FRU_Data[10];  
                        break;
                    case 11:
                        return PSU1_FRU_Data[11];       
                        break;
                    case 12:
                        return PSU1_FRU_Data[12];
                        break;
                    case 13:
                        return PSU1_FRU_Data[13];
                        break;
                    case 14:
                        return PSU1_FRU_Data[14];
                        break;
                    case 15:
                        return PSU1_FRU_Data[15];
                        break;
                    case 16:
                        return PSU1_FRU_Data[16];  
                        break;
                    case 17:
                        return PSU1_FRU_Data[17];     
                        break;  
                    case 18:
                        return PSU1_FRU_Data[18];
                        break;
                    case 19:
                        return PSU1_FRU_Data[19];
                        break;
                    case 20:
                        return PSU1_FRU_Data[20];
                        break;
                    case 21:
                        return PSU1_FRU_Data[21];
                        break;
                    case 22:
                        return PSU1_FRU_Data[22];
                        break;
                    case 23:
                        return PSU1_FRU_Data[23];
                        break;
                    case 24:
                        return PSU1_FRU_Data[24];
                        break;
                    case 25:
                        return PSU1_FRU_Data[25]; 
                        break;
                    case 26:
                        return PSU1_FRU_Data[26];
                        break;
                    case 27:
                        return PSU1_FRU_Data[27];
                        break;
                    case 28:
                        return PSU1_FRU_Data[28];  
                        break;
                    case 29:
                        return PSU1_FRU_Data[29];
                        break;
                    case 30:
                        return PSU1_FRU_Data[30];
                        break;
                    case 31:
                        return PSU1_FRU_Data[31];
                        break;
                    case 32:
                        return PSU1_FRU_Data[32];
                        break;
                    case 33:
                        return PSU1_FRU_Data[33];
                        break;
                    case 34:
                        return PSU1_FRU_Data[34];  
                        break;
                    case 35:
                        return PSU1_FRU_Data[35];       
                        break;
                    case 36:
                        return PSU1_FRU_Data[36];
                        break;
                    case 37:
                        return PSU1_FRU_Data[37];
                        break;
                    case 38:
                        return PSU1_FRU_Data[38];
                        break;
                    case 39:
                        return PSU1_FRU_Data[39];
                        break;
                    case 40:
                        return PSU1_FRU_Data[40];  
                        break;
                    case 41:
                        return PSU1_FRU_Data[41];     
                        break;  
                    case 42:
                        return PSU1_FRU_Data[42];
                        break;
                    case 43:
                        return PSU1_FRU_Data[43];
                        break;
                    case 44:
                        return PSU1_FRU_Data[44];
                        break;
                    case 45:
                        return PSU1_FRU_Data[45];
                        break;
                    case 46:
                        return PSU1_FRU_Data[46];
                        break;
                    case 47:
                        return PSU1_FRU_Data[47];
                        break;
                    case 48:
                        return PSU1_FRU_Data[48];
                        break;
                    case 49:
                        return PSU1_FRU_Data[49]; 
                        break;
                    case 50:
                        return PSU1_FRU_Data[50];
                        break;
                    case 51:
                        return PSU1_FRU_Data[51];
                        break;
                    case 52:
                        return PSU1_FRU_Data[52];  
                        break;
                    case 53:
                        return PSU1_FRU_Data[53];
                        break;
                    case 54:
                        return PSU1_FRU_Data[54];
                        break;
                    case 55:
                        return PSU1_FRU_Data[55];
                        break;
                    case 56:
                        return PSU1_FRU_Data[56];
                        break;
                    case 57:
                        return PSU1_FRU_Data[57];
                        break;
                    case 58:
                        return PSU1_FRU_Data[58];  
                        break;
                    case 59:
                        return PSU1_FRU_Data[59];       
                        break;
                    case 60:
                        return PSU1_FRU_Data[60];
                        break;
                    case 61:
                        return PSU1_FRU_Data[61];
                        break;
                    case 62:
                        return PSU1_FRU_Data[62];
                        break;
                    case 63:
                        return PSU1_FRU_Data[63];
                        break;
                    case 64:
                        return PSU1_FRU_Data[64];
                        break;
                    case 65:
                        return PSU1_FRU_Data[65]; 
                        break;
                    case 66:
                        return PSU1_FRU_Data[66];
                        break;
                    case 67:
                        return PSU1_FRU_Data[67];
                        break;
                    case 68:
                        return PSU1_FRU_Data[68];  
                        break;
                    case 69:
                        return PSU1_FRU_Data[69];
                        break;
                    case 70:
                        return PSU1_FRU_Data[70];
                        break;
                    case 71:
                        return PSU1_FRU_Data[71];
                        break;
                    case 72:
                        return PSU1_FRU_Data[72];
                        break;
                    case 73:
                        return PSU1_FRU_Data[73];
                        break;
                    case 74:
                        return PSU1_FRU_Data[74];  
                        break;
                    case 75:
                        return PSU1_FRU_Data[75];       
                        break;
                    case 76:
                        return PSU1_FRU_Data[76];
                        break;
                    case 77:
                        return PSU1_FRU_Data[77];
                        break;
                    case 78:
                        return PSU1_FRU_Data[78];
                        break;
                    case 79:
                        return PSU1_FRU_Data[79];
                        break;
                    case 80:
                        return PSU1_FRU_Data[80];  
                        break;
                    case 81:
                        return PSU1_FRU_Data[81];     
                        break;  
                    case 82:
                        return PSU1_FRU_Data[82];
                        break;
                    case 83:
                        return PSU1_FRU_Data[83];
                        break;
                    case 84:
                        return PSU1_FRU_Data[84];
                        break;
                    case 85:
                        return PSU1_FRU_Data[85];
                        break;
                    case 86:
                        return PSU1_FRU_Data[86];
                        break;
                    case 87:
                        return PSU1_FRU_Data[87];
                        break;
                    case 88:
                        return PSU1_FRU_Data[88];
                        break;
                    case 89:
                        return PSU1_FRU_Data[89]; 
                        break;
                    case 90:
                        return PSU1_FRU_Data[90];
                        break;
                    case 91:
                        return PSU1_FRU_Data[91];
                        break;
                    case 92:
                        return PSU1_FRU_Data[92];  
                        break;
                    case 93:
                        return PSU1_FRU_Data[93];
                        break;
                    case 94:
                        return PSU1_FRU_Data[94];
                        break;
                    case 95:
                        return PSU1_FRU_Data[95];
                        break;
                    case 96:
                        return PSU1_FRU_Data[96];
                        break;
                    case 97:
                        return PSU1_FRU_Data[97];
                        break;
                    case 98:
                        return PSU1_FRU_Data[98];  
                        break;
                    case 99:
                        return PSU1_FRU_Data[99];       
                        break;
                    case 100:
                        return PSU1_FRU_Data[100];
                        break;
                    case 101:
                        return PSU1_FRU_Data[101];
                        break;
                    case 102:
                        return PSU1_FRU_Data[102];
                        break;
                    case 103:
                        return PSU1_FRU_Data[103];
                        break;
                    case 104:
                        return PSU1_FRU_Data[104];  
                        break;
                    case 105:
                        return PSU1_FRU_Data[105];     
                        break;  
                    case 106:
                        return PSU1_FRU_Data[106];
                        break;
                    case 107:
                        return PSU1_FRU_Data[107];
                        break;
                    case 108:
                        return PSU1_FRU_Data[108];
                        break;
                    case 109:
                        return PSU1_FRU_Data[109];
                        break;
                    case 110:
                        return PSU1_FRU_Data[110];
                        break;
                    case 111:
                        return PSU1_FRU_Data[111];
                        break;
                    case 112:
                        return PSU1_FRU_Data[112];
                        break;
                    case 113:
                        return PSU1_FRU_Data[113]; 
                        break;
                    case 114:
                        return PSU1_FRU_Data[114];
                        break;
                    case 115:
                        return PSU1_FRU_Data[115];
                        break;
                    case 116:
                        return PSU1_FRU_Data[116];  
                        break;
                    case 117:
                        return PSU1_FRU_Data[117];
                        break;
                    case 118:
                        return PSU1_FRU_Data[118];
                        break;
                    case 119:
                        return PSU1_FRU_Data[119];
                        break;
                    case 120:
                        return PSU1_FRU_Data[120];
                        break;
                    case 121:
                        return PSU1_FRU_Data[121];
                        break;
                    case 122:
                        return PSU1_FRU_Data[122];  
                        break;
                    case 123:
                        return PSU1_FRU_Data[123];       
                        break;
                    case 124:
                        return PSU1_FRU_Data[124];
                        break;
                    case 125:
                        return PSU1_FRU_Data[125];
                        break;
                    case 126:
                        return PSU1_FRU_Data[126];
                        break;
                    case 127:
                        return PSU1_FRU_Data[127];
                        break;
                    case 128:
                        return PSU1_FRU_Data[128];
                        break;
                    case 129:
                        return PSU1_FRU_Data[129]; 
                        break;
                    case 130:
                        return PSU1_FRU_Data[130];
                        break;
                    case 131:
                        return PSU1_FRU_Data[131];
                        break;
                    case 132:
                        return PSU1_FRU_Data[132];  
                        break;
                    case 133:
                        return PSU1_FRU_Data[133];
                        break;
                    case 134:
                        return PSU1_FRU_Data[134];
                        break;
                    case 135:
                        return PSU1_FRU_Data[135];
                        break;
                    case 136:
                        return PSU1_FRU_Data[136];
                        break;
                    case 137:
                        return PSU1_FRU_Data[137];
                        break;
                    case 138:
                        return PSU1_FRU_Data[138];  
                        break;
                    case 139:
                        return PSU1_FRU_Data[139];       
                        break;
                    case 140:
                        return PSU1_FRU_Data[140];
                        break;
                    case 141:
                        return PSU1_FRU_Data[141];
                        break;
                    case 142:
                        return PSU1_FRU_Data[142];
                        break;
                    case 143:
                        return PSU1_FRU_Data[143];
                        break;
                    case 144:
                        return PSU1_FRU_Data[144];  
                        break;
                    case 145:
                        return PSU1_FRU_Data[145];     
                        break;  
                    case 146:
                        return PSU1_FRU_Data[146];
                        break;
                    case 147:
                        return PSU1_FRU_Data[147];
                        break;
                    case 148:
                        return PSU1_FRU_Data[148];
                        break;
                    case 149:
                        return PSU1_FRU_Data[149];
                        break;
                    case 150:
                        return PSU1_FRU_Data[150];
                        break;
                    case 151:
                        return PSU1_FRU_Data[151];
                        break;
                    case 152:
                        return PSU1_FRU_Data[152];
                        break;
                    case 153:
                        return PSU1_FRU_Data[153]; 
                        break;
                    case 154:
                        return PSU1_FRU_Data[154];
                        break;
                    case 155:
                        return PSU1_FRU_Data[155];
                        break;
                    case 156:
                        return PSU1_FRU_Data[156];  
                        break;
                    case 157:
                        return PSU1_FRU_Data[157];
                        break;
                    case 158:
                        return PSU1_FRU_Data[158];
                        break;
                    case 159:
                        return PSU1_FRU_Data[159];
                        break;
                    case 160:
                        return PSU1_FRU_Data[160];
                        break;
                    case 161:
                        return PSU1_FRU_Data[161];
                        break;
                    case 162:
                        return PSU1_FRU_Data[162];  
                        break;
                    case 163:
                        return PSU1_FRU_Data[163];       
                        break;
                    case 164:
                        return PSU1_FRU_Data[164];
                        break;
                    case 165:
                        return PSU1_FRU_Data[165];
                        break;
                    case 166:
                        return PSU1_FRU_Data[166];
                        break;
                    case 167:
                        return PSU1_FRU_Data[167];
                        break;
                    case 168:
                        return PSU1_FRU_Data[168];  
                        break;
                    case 169:
                        return PSU1_FRU_Data[169];     
                        break;  
                    case 170:
                        return PSU1_FRU_Data[170];
                        break;
                    case 171:
                        return PSU1_FRU_Data[171];
                        break;
                    case 172:
                        return PSU1_FRU_Data[172];
                        break;
                    case 173:
                        return PSU1_FRU_Data[173];
                        break;
                    case 174:
                        return PSU1_FRU_Data[174];
                        break;
                    case 175:
                        return PSU1_FRU_Data[175];
                        break;
                    case 176:
                        return PSU1_FRU_Data[176];
                        break;
                    case 177:
                        return PSU1_FRU_Data[177]; 
                        break;
                    case 178:
                        return PSU1_FRU_Data[178];
                        break;
                    case 179:
                        return PSU1_FRU_Data[179];
                        break;
                    case 180:
                        return PSU1_FRU_Data[180];  
                        break;
                    case 181:
                        return PSU1_FRU_Data[181];
                        break;
                    case 182:
                        return PSU1_FRU_Data[182];
                        break;
                    case 183:
                        return PSU1_FRU_Data[183];
                        break;
                    case 184:
                        return PSU1_FRU_Data[184];
                        break;
                    case 185:
                        return PSU1_FRU_Data[185];
                        break;
                    case 186:
                        return PSU1_FRU_Data[186];  
                        break;
                    case 187:
                        return PSU1_FRU_Data[187];       
                        break;
                    case 188:
                        return PSU1_FRU_Data[188];
                        break;
                    case 189:
                        return PSU1_FRU_Data[189];
                        break;
                    case 190:
                        return PSU1_FRU_Data[190];
                        break;
                    case 191:
                        return PSU1_FRU_Data[191];
                        break;
                    case 192:
                        return PSU1_FRU_Data[192];
                        break;
                    case 193:
                        return PSU1_FRU_Data[193]; 
                        break;
                    case 194:
                        return PSU1_FRU_Data[194];
                        break;
                    case 195:
                        return PSU1_FRU_Data[195];
                        break;
                    case 196:
                        return PSU1_FRU_Data[196];  
                        break;
                    case 197:
                        return PSU1_FRU_Data[197];
                        break;
                    case 198:
                        return PSU1_FRU_Data[198];
                        break;
                    case 199:
                        return PSU1_FRU_Data[199];
                        break;
                    case 200:
                        return PSU1_FRU_Data[200];
                        break;
                    case 201:
                        return PSU1_FRU_Data[201];
                        break;
                    case 202:
                        return PSU1_FRU_Data[202];  
                        break;
                    case 203:
                        return PSU1_FRU_Data[203];       
                        break;
                    case 204:
                        return PSU1_FRU_Data[204];
                        break;
                    case 205:
                        return PSU1_FRU_Data[205];
                        break;
                    case 206:
                        return PSU1_FRU_Data[206];
                        break;
                    case 207:
                        return PSU1_FRU_Data[207];
                        break;
                    case 208:
                        return PSU1_FRU_Data[208];  
                        break;
                    case 209:
                        return PSU1_FRU_Data[209];     
                        break;  
                    case 210:
                        return PSU1_FRU_Data[210];
                        break;
                    case 211:
                        return PSU1_FRU_Data[211];
                        break;
                    case 212:
                        return PSU1_FRU_Data[212];
                        break;
                    case 213:
                        return PSU1_FRU_Data[213];
                        break;
                    case 214:
                        return PSU1_FRU_Data[214];
                        break;
                    case 215:
                        return PSU1_FRU_Data[215];
                        break;
                    case 216:
                        return PSU1_FRU_Data[216];
                        break;
                    case 217:
                        return PSU1_FRU_Data[217]; 
                        break;
                    case 218:
                        return PSU1_FRU_Data[218];
                        break;
                    case 219:
                        return PSU1_FRU_Data[219];
                        break;
                    case 220:
                        return PSU1_FRU_Data[220];  
                        break;
                    case 221:
                        return PSU1_FRU_Data[221];
                        break;
                    case 222:
                        return PSU1_FRU_Data[222];
                        break;
                    case 223:
                        return PSU1_FRU_Data[223];
                        break;
                    case 224:
                        return PSU1_FRU_Data[224];
                        break;
                    case 225:
                        return PSU1_FRU_Data[225];
                        break;
                    case 226:
                        return PSU1_FRU_Data[226];  
                        break;
                    case 227:
                        return PSU1_FRU_Data[227];       
                        break;
                    case 228:
                        return PSU1_FRU_Data[228];
                        break;
                    case 229:
                        return PSU1_FRU_Data[229];
                        break;
                    case 230:
                        return PSU1_FRU_Data[230];
                        break;
                    case 231:
                        return PSU1_FRU_Data[231];
                        break;
                    case 232:
                        return PSU1_FRU_Data[232];  
                        break;
                    case 233:
                        return PSU1_FRU_Data[233];     
                        break;  
                    case 234:
                        return PSU1_FRU_Data[234];
                        break;
                    case 235:
                        return PSU1_FRU_Data[235];
                        break;
                    case 236:
                        return PSU1_FRU_Data[236];
                        break;
                    case 237:
                        return PSU1_FRU_Data[237];
                        break;
                    case 238:
                        return PSU1_FRU_Data[238];
                        break;
                    case 239:
                        return PSU1_FRU_Data[239];
                        break;
                    case 240:
                        return PSU1_FRU_Data[240];
                        break;
                    case 241:
                        return PSU1_FRU_Data[241]; 
                        break;
                    case 242:
                        return PSU1_FRU_Data[242];
                        break;
                    case 243:
                        return PSU1_FRU_Data[243];
                        break;
                    case 244:
                        return PSU1_FRU_Data[244];  
                        break;
                    case 245:
                        return PSU1_FRU_Data[245];
                        break;
                    case 246:
                        return PSU1_FRU_Data[246];
                        break;
                    case 247:
                        return PSU1_FRU_Data[247];
                        break;
                    case 248:
                        return PSU1_FRU_Data[248];
                        break;
                    case 249:
                        return PSU1_FRU_Data[249];
                        break;
                    case 250:
                        return PSU1_FRU_Data[250];  
                        break;
                    case 251:
                        return PSU1_FRU_Data[251];       
                        break;
                    case 252:
                        return PSU1_FRU_Data[252];
                        break;
                    case 253:
                        return PSU1_FRU_Data[253];
                        break;
                    case 254:
                        return PSU1_FRU_Data[254];
                        break;
                    case 255:
                        return PSU1_FRU_Data[255];
                        break;
                    
                        
                    default:
                        return INVALID_DATA;
                        break;
                        
            }
            break;
            
        case PIC_FRU_BMC_SIDE_ADDR:
            switch(CurrentADDR)//read PIC FRU Data(128 byte) 
            {
                    case 0:
                        return PIC_FRU_Data[0];
                        break;
                    case 1:
                        return PIC_FRU_Data[1]; 
                        break;
                    case 2:
                        return PIC_FRU_Data[2];
                        break;
                    case 3:
                        return PIC_FRU_Data[3];
                        break;
                    case 4:
                        return PIC_FRU_Data[4];  
                        break;
                    case 5:
                        return PIC_FRU_Data[5];
                        break;
                    case 6:
                        return PIC_FRU_Data[6];
                        break;
                    case 7:
                        return PIC_FRU_Data[7];
                        break;
                    case 8:
                        return PIC_FRU_Data[8];
                        break;
                    case 9:
                        return PIC_FRU_Data[9];
                        break;
                    case 10:
                        return PIC_FRU_Data[10];  
                        break;
                    case 11:
                        return PIC_FRU_Data[11];       
                        break;
                    case 12:
                        return PIC_FRU_Data[12];
                        break;
                    case 13:
                        return PIC_FRU_Data[13];
                        break;
                    case 14:
                        return PIC_FRU_Data[14];
                        break;
                    case 15:
                        return PIC_FRU_Data[15];
                        break;
                    case 16:
                        return PIC_FRU_Data[16];  
                        break;
                    case 17:
                        return PIC_FRU_Data[17];     
                        break;  
                    case 18:
                        return PIC_FRU_Data[18];
                        break;
                    case 19:
                        return PIC_FRU_Data[19];
                        break;
                    case 20:
                        return PIC_FRU_Data[20];
                        break;
                    case 21:
                        return PIC_FRU_Data[21];
                        break;
                    case 22:
                        return PIC_FRU_Data[22];
                        break;
                    case 23:
                        return PIC_FRU_Data[23];
                        break;
                    case 24:
                        return PIC_FRU_Data[24];
                        break;
                    case 25:
                        return PIC_FRU_Data[25]; 
                        break;
                    case 26:
                        return PIC_FRU_Data[26];
                        break;
                    case 27:
                        return PIC_FRU_Data[27];
                        break;
                    case 28:
                        return PIC_FRU_Data[28];  
                        break;
                    case 29:
                        return PIC_FRU_Data[29];
                        break;
                    case 30:
                        return PIC_FRU_Data[30];
                        break;
                    case 31:
                        return PIC_FRU_Data[31];
                        break;
                    case 32:
                        return PIC_FRU_Data[32];
                        break;
                    case 33:
                        return PIC_FRU_Data[33];
                        break;
                    case 34:
                        return PIC_FRU_Data[34];  
                        break;
                    case 35:
                        return PIC_FRU_Data[35];       
                        break;
                    case 36:
                        return PIC_FRU_Data[36];
                        break;
                    case 37:
                        return PIC_FRU_Data[37];
                        break;
                    case 38:
                        return PIC_FRU_Data[38];
                        break;
                    case 39:
                        return PIC_FRU_Data[39];
                        break;
                    case 40:
                        return PIC_FRU_Data[40];  
                        break;
                    case 41:
                        return PIC_FRU_Data[41];     
                        break;  
                    case 42:
                        return PIC_FRU_Data[42];
                        break;
                    case 43:
                        return PIC_FRU_Data[43];
                        break;
                    case 44:
                        return PIC_FRU_Data[44];
                        break;
                    case 45:
                        return PIC_FRU_Data[45];
                        break;
                    case 46:
                        return PIC_FRU_Data[46];
                        break;
                    case 47:
                        return PIC_FRU_Data[47];
                        break;
                    case 48:
                        return PIC_FRU_Data[48];
                        break;
                    case 49:
                        return PIC_FRU_Data[49]; 
                        break;
                    case 50:
                        return PIC_FRU_Data[50];
                        break;
                    case 51:
                        return PIC_FRU_Data[51];
                        break;
                    case 52:
                        return PIC_FRU_Data[52];  
                        break;
                    case 53:
                        return PIC_FRU_Data[53];
                        break;
                    case 54:
                        return PIC_FRU_Data[54];
                        break;
                    case 55:
                        return PIC_FRU_Data[55];
                        break;
                    case 56:
                        return PIC_FRU_Data[56];
                        break;
                    case 57:
                        return PIC_FRU_Data[57];
                        break;
                    case 58:
                        return PIC_FRU_Data[58];  
                        break;
                    case 59:
                        return PIC_FRU_Data[59];       
                        break;
                    case 60:
                        return PIC_FRU_Data[60];
                        break;
                    case 61:
                        return PIC_FRU_Data[61];
                        break;
                    case 62:
                        return PIC_FRU_Data[62];
                        break;
                    case 63:
                        return PIC_FRU_Data[63];
                        break;
                    case 64:
                        return PIC_FRU_Data[64];
                        break;
                    case 65:
                        return PIC_FRU_Data[65]; 
                        break;
                    case 66:
                        return PIC_FRU_Data[66];
                        break;
                    case 67:
                        return PIC_FRU_Data[67];
                        break;
                    case 68:
                        return PIC_FRU_Data[68];  
                        break;
                    case 69:
                        return PIC_FRU_Data[69];
                        break;
                    case 70:
                        return PIC_FRU_Data[70];
                        break;
                    case 71:
                        return PIC_FRU_Data[71];
                        break;
                    case 72:
                        return PIC_FRU_Data[72];
                        break;
                    case 73:
                        return PIC_FRU_Data[73];
                        break;
                    case 74:
                        return PIC_FRU_Data[74];  
                        break;
                    case 75:
                        return PIC_FRU_Data[75];       
                        break;
                    case 76:
                        return PIC_FRU_Data[76];
                        break;
                    case 77:
                        return PIC_FRU_Data[77];
                        break;
                    case 78:
                        return PIC_FRU_Data[78];
                        break;
                    case 79:
                        return PIC_FRU_Data[79];
                        break;
                    case 80:
                        return PIC_FRU_Data[80];  
                        break;
                    case 81:
                        return PIC_FRU_Data[81];     
                        break;  
                    case 82:
                        return PIC_FRU_Data[82];
                        break;
                    case 83:
                        return PIC_FRU_Data[83];
                        break;
                    case 84:
                        return PIC_FRU_Data[84];
                        break;
                    case 85:
                        return PIC_FRU_Data[85];
                        break;
                    case 86:
                        return PIC_FRU_Data[86];
                        break;
                    case 87:
                        return PIC_FRU_Data[87];
                        break;
                    case 88:
                        return PIC_FRU_Data[88];
                        break;
                    case 89:
                        return PIC_FRU_Data[89]; 
                        break;
                    case 90:
                        return PIC_FRU_Data[90];
                        break;
                    case 91:
                        return PIC_FRU_Data[91];
                        break;
                    case 92:
                        return PIC_FRU_Data[92];  
                        break;
                    case 93:
                        return PIC_FRU_Data[93];
                        break;
                    case 94:
                        return PIC_FRU_Data[94];
                        break;
                    case 95:
                        return PIC_FRU_Data[95];
                        break;
                    case 96:
                        return PIC_FRU_Data[96];
                        break;
                    case 97:
                        return PIC_FRU_Data[97];
                        break;
                    case 98:
                        return PIC_FRU_Data[98];  
                        break;
                    case 99:
                        return PIC_FRU_Data[99];       
                        break;
                    case 100:
                        return PIC_FRU_Data[100];
                        break;
                    case 101:
                        return PIC_FRU_Data[101];
                        break;
                    case 102:
                        return PIC_FRU_Data[102];
                        break;
                    case 103:
                        return PIC_FRU_Data[103];
                        break;
                    case 104:
                        return PIC_FRU_Data[104];  
                        break;
                    case 105:
                        return PIC_FRU_Data[105];     
                        break;  
                    case 106:
                        return PIC_FRU_Data[106];
                        break;
                    case 107:
                        return PIC_FRU_Data[107];
                        break;
                    case 108:
                        return PIC_FRU_Data[108];
                        break;
                    case 109:
                        return PIC_FRU_Data[109];
                        break;
                    case 110:
                        return PIC_FRU_Data[110];
                        break;
                    case 111:
                        return PIC_FRU_Data[111];
                        break;
                    case 112:
                        return PIC_FRU_Data[112];
                        break;
                    case 113:
                        return PIC_FRU_Data[113]; 
                        break;
                    case 114:
                        return PIC_FRU_Data[114];
                        break;
                    case 115:
                        return PIC_FRU_Data[115];
                        break;
                    case 116:
                        return PIC_FRU_Data[116];  
                        break;
                    case 117:
                        return PIC_FRU_Data[117];
                        break;
                    case 118:
                        return PIC_FRU_Data[118];
                        break;
                    case 119:
                        return PIC_FRU_Data[119];
                        break;
                    case 120:
                        return PIC_FRU_Data[120];
                        break;
                    case 121:
                        return PIC_FRU_Data[121];
                        break;
                    case 122:
                        return PIC_FRU_Data[122];  
                        break;
                    case 123:
                        return PIC_FRU_Data[123];       
                        break;
                    case 124:
                        return PIC_FRU_Data[124];
                        break;
                    case 125:
                        return PIC_FRU_Data[125];
                        break;
                    case 126:
                        return PIC_FRU_Data[126];
                        break;
                    case 127:
                        return PIC_FRU_Data[127];
                        break;
                    
                        
                    default:
                        return INVALID_DATA;
                        break;
                        
            }
            break;
            
        case PIC_OPCODE_BMC_SIDE_ADDR:
            if(PIC_CMD_Size < CMD_SIZE_ONE_BYTE ) //PIC CMD Size is 0 base 
            {
                switch(PIC_CMD)
                {
                        case GET_PIC_MAJOR:
                            return PIC_MAJOR_Data[CurrentADDR];
                            break; 
                            
                        case GET_PIC_MINOR:
                            return PIC_MINOR_Data[CurrentADDR];
                            break;
                            
                        case GET_GPIO_STATUS:
                            PIN_NUMBER = ((OPcode_CMD[1] >> 4)*16) + (OPcode_CMD[1] & 0x0f);//This is to convert Hex to decimal
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
                            
                        case SET_GPIO_STATUS:
                            PIN_NUMBER = ((OPcode_CMD[1] >> 4)*16) + (OPcode_CMD[1] & 0x0f);//This is to convert Hex to decimal
                            //set high low for GPIOif (PIN_NUMBER == 55)
                            
                            if ((PIN_NUMBER == MCU_PA27_PDB_BD_00_HOTSWAP_EN_PIN && OPcode_CMD[3] == GPIO_LOW) ||
                                (PIN_NUMBER == MCU_PA28_PDB_BD_01_HOTSWAP_EN_PIN && OPcode_CMD[3] == GPIO_LOW) ||
                                (PIN_NUMBER == MCU_PB22_PDB_BD_10_HOTSWAP_EN_PIN && OPcode_CMD[3] == GPIO_LOW) ||
                                (PIN_NUMBER == MCU_PB23_PDB_BD_11_HOTSWAP_EN_PIN && OPcode_CMD[3] == GPIO_LOW))
                            {
                                PORT_PinWrite(PIN_NUMBER , GPIO_LOW);
                            }
                            printf("HWP_OK");//workaround HWP
                            if (OPcode_CMD[3] == GPIO_LOW)
                            {
                                PORT_PinWrite(PIN_NUMBER , GPIO_LOW);
                            }
                            if (OPcode_CMD[3] == GPIO_HIGH)
                            {
                                PORT_PinWrite(PIN_NUMBER , GPIO_HIGH);
                            }
                            
                            //set input output for GPIO
                            if(OPcode_CMD[2] == GPIO_INPUT )
                            {
                                PORT_PinInputEnable(PIN_NUMBER);
                            }
                            
                            if(OPcode_CMD[2] == GPIO_OUTPUT  )
                            {
                                PORT_PinOutputEnable(PIN_NUMBER);
                            }

                            
                            
                            return CC_SUCCESS;
                            break;
                            
                    default:
                         return INVALID_DATA;
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

bool Select_SERCOM(uint16_t CurrentADDR, uintptr_t I2C_Got_Addr_NOW, uintptr_t SERCOM_NOW, uint8_t PIC_CMD, uint8_t PIC_CMD_Size) {
    bool isSuccess = false;

    switch (SERCOM_NOW) {
        case SERCOM1:
            //sercom1 response Data to BMC
            SERCOM1_I2C_WriteByte(Packing_Payload_Data(CurrentADDR, I2C_Got_Addr_NOW, PIC_CMD, PIC_CMD_Size));
            isSuccess = true;
            break;
        case SERCOM2:
            //sercom2 response Data to BMC
            SERCOM2_I2C_WriteByte(Packing_Payload_Data(CurrentADDR, I2C_Got_Addr_NOW, PIC_CMD, PIC_CMD_Size));
            isSuccess = true;
            break;
        case SERCOM3:
            //sercom3 response Data to BMC
            SERCOM3_I2C_WriteByte(Packing_Payload_Data(CurrentADDR, I2C_Got_Addr_NOW, PIC_CMD, PIC_CMD_Size));
            isSuccess = true;
            break;
        case SERCOM4:
            //sercom4 response Data to BMC
            SERCOM4_I2C_WriteByte(Packing_Payload_Data(CurrentADDR, I2C_Got_Addr_NOW, PIC_CMD, PIC_CMD_Size));
            isSuccess = true;
            break;
        default:
            // Handle unsupported SERCOM
            break;
    }

    return isSuccess;
}




/* *****************************************************************************
 End of File
 */
