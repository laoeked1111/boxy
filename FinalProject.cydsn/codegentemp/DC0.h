/*******************************************************************************
* File Name: DC0.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DC0_H) /* Pins DC0_H */
#define CY_PINS_DC0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DC0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DC0__PORT == 15 && ((DC0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DC0_Write(uint8 value);
void    DC0_SetDriveMode(uint8 mode);
uint8   DC0_ReadDataReg(void);
uint8   DC0_Read(void);
void    DC0_SetInterruptMode(uint16 position, uint16 mode);
uint8   DC0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DC0_SetDriveMode() function.
     *  @{
     */
        #define DC0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DC0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DC0_DM_RES_UP          PIN_DM_RES_UP
        #define DC0_DM_RES_DWN         PIN_DM_RES_DWN
        #define DC0_DM_OD_LO           PIN_DM_OD_LO
        #define DC0_DM_OD_HI           PIN_DM_OD_HI
        #define DC0_DM_STRONG          PIN_DM_STRONG
        #define DC0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DC0_MASK               DC0__MASK
#define DC0_SHIFT              DC0__SHIFT
#define DC0_WIDTH              1u

/* Interrupt constants */
#if defined(DC0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DC0_SetInterruptMode() function.
     *  @{
     */
        #define DC0_INTR_NONE      (uint16)(0x0000u)
        #define DC0_INTR_RISING    (uint16)(0x0001u)
        #define DC0_INTR_FALLING   (uint16)(0x0002u)
        #define DC0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DC0_INTR_MASK      (0x01u) 
#endif /* (DC0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DC0_PS                     (* (reg8 *) DC0__PS)
/* Data Register */
#define DC0_DR                     (* (reg8 *) DC0__DR)
/* Port Number */
#define DC0_PRT_NUM                (* (reg8 *) DC0__PRT) 
/* Connect to Analog Globals */                                                  
#define DC0_AG                     (* (reg8 *) DC0__AG)                       
/* Analog MUX bux enable */
#define DC0_AMUX                   (* (reg8 *) DC0__AMUX) 
/* Bidirectional Enable */                                                        
#define DC0_BIE                    (* (reg8 *) DC0__BIE)
/* Bit-mask for Aliased Register Access */
#define DC0_BIT_MASK               (* (reg8 *) DC0__BIT_MASK)
/* Bypass Enable */
#define DC0_BYP                    (* (reg8 *) DC0__BYP)
/* Port wide control signals */                                                   
#define DC0_CTL                    (* (reg8 *) DC0__CTL)
/* Drive Modes */
#define DC0_DM0                    (* (reg8 *) DC0__DM0) 
#define DC0_DM1                    (* (reg8 *) DC0__DM1)
#define DC0_DM2                    (* (reg8 *) DC0__DM2) 
/* Input Buffer Disable Override */
#define DC0_INP_DIS                (* (reg8 *) DC0__INP_DIS)
/* LCD Common or Segment Drive */
#define DC0_LCD_COM_SEG            (* (reg8 *) DC0__LCD_COM_SEG)
/* Enable Segment LCD */
#define DC0_LCD_EN                 (* (reg8 *) DC0__LCD_EN)
/* Slew Rate Control */
#define DC0_SLW                    (* (reg8 *) DC0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DC0_PRTDSI__CAPS_SEL       (* (reg8 *) DC0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DC0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DC0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DC0_PRTDSI__OE_SEL0        (* (reg8 *) DC0__PRTDSI__OE_SEL0) 
#define DC0_PRTDSI__OE_SEL1        (* (reg8 *) DC0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DC0_PRTDSI__OUT_SEL0       (* (reg8 *) DC0__PRTDSI__OUT_SEL0) 
#define DC0_PRTDSI__OUT_SEL1       (* (reg8 *) DC0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DC0_PRTDSI__SYNC_OUT       (* (reg8 *) DC0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DC0__SIO_CFG)
    #define DC0_SIO_HYST_EN        (* (reg8 *) DC0__SIO_HYST_EN)
    #define DC0_SIO_REG_HIFREQ     (* (reg8 *) DC0__SIO_REG_HIFREQ)
    #define DC0_SIO_CFG            (* (reg8 *) DC0__SIO_CFG)
    #define DC0_SIO_DIFF           (* (reg8 *) DC0__SIO_DIFF)
#endif /* (DC0__SIO_CFG) */

/* Interrupt Registers */
#if defined(DC0__INTSTAT)
    #define DC0_INTSTAT            (* (reg8 *) DC0__INTSTAT)
    #define DC0_SNAP               (* (reg8 *) DC0__SNAP)
    
	#define DC0_0_INTTYPE_REG 		(* (reg8 *) DC0__0__INTTYPE)
#endif /* (DC0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DC0_H */


/* [] END OF FILE */
