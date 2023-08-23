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

#ifndef _PURNELL_OEM_H    /* Guard against multiple inclusion */
#define _PURNELL_OEM_H
#include "definitions.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
//VERSION Data
#define MAJOR_VERSION               0x00
#define MINOR_VERSION               0x01

//i2c address
#define PSU0_FRU_ADDR               0x50 //Purnell_PDB_PIC_FW_Spec_V0.07.docx page 8
#define PSU0_PMBUS_ADDR             0x58 //Purnell_PDB_PIC_FW_Spec_V0.07.docx page 8
#define PSU0_FRU_BMC_SIDE_ADDR      0x50 //Purnell_PDB_PIC_FW_Spec_V0.07.docx page 9
#define PSU0_PMBUS_BMC_SIDE_ADDR    0x58 //Purnell_PDB_PIC_FW_Spec_V0.07.docx page 9
#define PSU1_FRU_ADDR               0x53 //Purnell_PDB_PIC_FW_Spec_V0.07.docx page 8
#define PSU1_PMBUS_ADDR             0x5b //Purnell_PDB_PIC_FW_Spec_V0.07.docx page 8
#define PSU1_FRU_BMC_SIDE_ADDR      0x53 //Purnell_PDB_PIC_FW_Spec_V0.07.docx page 9
#define PSU1_PMBUS_BMC_SIDE_ADDR    0x5b //Purnell_PDB_PIC_FW_Spec_V0.07.docx page 9
#define PIC_FRU_BMC_SIDE_ADDR       0x55 //Purnell_PDB_PIC_FW_Spec_V0.07.docx page 9
#define PIC_OPCODE_BMC_SIDE_ADDR    0x5d //Purnell_PDB_PIC_FW_Spec_V0.07.docx page 9

//opcode command
#define GET_PIC_MAJOR               0x01//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 13
#define GET_PIC_MINOR               0x02//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 13
#define GET_GPIO_STATUS             0x10//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 13
#define SET_GPIO_STATUS             0x11//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 13
#define GPIO_INPUT                  0x00//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 14
#define GPIO_OUTPUT                 0x01//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 14
#define GPIO_LOW                    0x00//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 14
#define GPIO_HIGH                   0x01//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 14

//complete code
#define DATA_LENGTH_INVALID         0xC7//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 13
#define INVALID_COMMAND             0xc1//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 13
#define INVALID_DATA             0xcc//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 13
#define CC_SUCCESS                  0x00//Purnell_PDB_PIC_FW_Spec_V0.07.docx page 13


#endif /* _PURNELL_OEM_H */

/* *****************************************************************************
 End of File
 */
