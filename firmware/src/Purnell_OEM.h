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
//i2c address
#define PSU1_FRU_ADDR               0x52 //Purnell_PDB_PIC_FW_Spec_V0.06.docx page 8
#define PSU1_FRU_SLAVE_ADDR         0x51 //Purnell_PDB_PIC_FW_Spec_V0.06.docx page 9
#define PSU0_FRU_ADDR               0x50 //Purnell_PDB_PIC_FW_Spec_V0.06.docx page 8
#define PSU0_FRU_SLAVE_ADDR         0x50 //Purnell_PDB_PIC_FW_Spec_V0.06.docx page 9
#define PIC_FRU_SLAVE_ADDR          0x55 //Purnell_PDB_PIC_FW_Spec_V0.06.docx page 9
#define PIC_OPCODE_SLAVE_ADDR       0x5d //Purnell_PDB_PIC_FW_Spec_V0.06.docx page 9

//opcode command
#define GET_PIC_MAJOR               0x01//Purnell_PDB_PIC_FW_Spec_V0.06.docx page 13
#define GET_PIC_MINOR               0x02//Purnell_PDB_PIC_FW_Spec_V0.06.docx page 13

//complete code
#define DATA_LENGTH_INVALID         0xC7//Purnell_PDB_PIC_FW_Spec_V0.06.docx page 13
#define INVALID_COMMAND             0xc1//Purnell_PDB_PIC_FW_Spec_V0.06.docx page 13
#define INVALID_ADDRESS             0xcc//Purnell_PDB_PIC_FW_Spec_V0.06.docx page 13



#endif /* _PURNELL_OEM_H */

/* *****************************************************************************
 End of File
 */
