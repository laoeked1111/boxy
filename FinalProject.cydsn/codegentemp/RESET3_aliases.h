/*******************************************************************************
* File Name: RESET3.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RESET3_ALIASES_H) /* Pins RESET3_ALIASES_H */
#define CY_PINS_RESET3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define RESET3_0			(RESET3__0__PC)
#define RESET3_0_INTR	((uint16)((uint16)0x0001u << RESET3__0__SHIFT))

#define RESET3_INTR_ALL	 ((uint16)(RESET3_0_INTR))

#endif /* End Pins RESET3_ALIASES_H */


/* [] END OF FILE */
