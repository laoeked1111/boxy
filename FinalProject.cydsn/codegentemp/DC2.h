/*******************************************************************************
* File Name: DC2.h  
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

#if !defined(CY_PINS_DC2_H) /* Pins DC2_H */
#define CY_PINS_DC2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DC2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DC2__PORT == 15 && ((DC2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DC2_Write(uint8 value);
void    DC2_SetDriveMode(uint8 mode);
uint8   DC2_ReadDataReg(void);
uint8   DC2_Read(void);
void    DC2_SetInterruptMode(uint16 position, uint16 mode);
uint8   DC2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DC2_SetDriveMode() function.
     *  @{
     */
        #define DC2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DC2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DC2_DM_RES_UP          PIN_DM_RES_UP
        #define DC2_DM_RES_DWN         PIN_DM_RES_DWN
        #define DC2_DM_OD_LO           PIN_DM_OD_LO
        #define DC2_DM_OD_HI           PIN_DM_OD_HI
        #define DC2_DM_STRONG          PIN_DM_STRONG
        #define DC2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DC2_MASK               DC2__MASK
#define DC2_SHIFT              DC2__SHIFT
#define DC2_WIDTH              1u

/* Interrupt constants */
#if defined(DC2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DC2_SetInterruptMode() function.
     *  @{
     */
        #define DC2_INTR_NONE      (uint16)(0x0000u)
        #define DC2_INTR_RISING    (uint16)(0x0001u)
        #define DC2_INTR_FALLING   (uint16)(0x0002u)
        #define DC2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DC2_INTR_MASK      (0x01u) 
#endif /* (DC2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DC2_PS                     (* (reg8 *) DC2__PS)
/* Data Register */
#define DC2_DR                     (* (reg8 *) DC2__DR)
/* Port Number */
#define DC2_PRT_NUM                (* (reg8 *) DC2__PRT) 
/* Connect to Analog Globals */                                                  
#define DC2_AG                     (* (reg8 *) DC2__AG)                       
/* Analog MUX bux enable */
#define DC2_AMUX                   (* (reg8 *) DC2__AMUX) 
/* Bidirectional Enable */                                                        
#define DC2_BIE                    (* (reg8 *) DC2__BIE)
/* Bit-mask for Aliased Register Access */
#define DC2_BIT_MASK               (* (reg8 *) DC2__BIT_MASK)
/* Bypass Enable */
#define DC2_BYP                    (* (reg8 *) DC2__BYP)
/* Port wide control signals */                                                   
#define DC2_CTL                    (* (reg8 *) DC2__CTL)
/* Drive Modes */
#define DC2_DM0                    (* (reg8 *) DC2__DM0) 
#define DC2_DM1                    (* (reg8 *) DC2__DM1)
#define DC2_DM2                    (* (reg8 *) DC2__DM2) 
/* Input Buffer Disable Override */
#define DC2_INP_DIS                (* (reg8 *) DC2__INP_DIS)
/* LCD Common or Segment Drive */
#define DC2_LCD_COM_SEG            (* (reg8 *) DC2__LCD_COM_SEG)
/* Enable Segment LCD */
#define DC2_LCD_EN                 (* (reg8 *) DC2__LCD_EN)
/* Slew Rate Control */
#define DC2_SLW                    (* (reg8 *) DC2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DC2_PRTDSI__CAPS_SEL       (* (reg8 *) DC2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DC2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DC2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DC2_PRTDSI__OE_SEL0        (* (reg8 *) DC2__PRTDSI__OE_SEL0) 
#define DC2_PRTDSI__OE_SEL1        (* (reg8 *) DC2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DC2_PRTDSI__OUT_SEL0       (* (reg8 *) DC2__PRTDSI__OUT_SEL0) 
#define DC2_PRTDSI__OUT_SEL1       (* (reg8 *) DC2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DC2_PRTDSI__SYNC_OUT       (* (reg8 *) DC2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DC2__SIO_CFG)
    #define DC2_SIO_HYST_EN        (* (reg8 *) DC2__SIO_HYST_EN)
    #define DC2_SIO_REG_HIFREQ     (* (reg8 *) DC2__SIO_REG_HIFREQ)
    #define DC2_SIO_CFG            (* (reg8 *) DC2__SIO_CFG)
    #define DC2_SIO_DIFF           (* (reg8 *) DC2__SIO_DIFF)
#endif /* (DC2__SIO_CFG) */

/* Interrupt Registers */
#if defined(DC2__INTSTAT)
    #define DC2_INTSTAT            (* (reg8 *) DC2__INTSTAT)
    #define DC2_SNAP               (* (reg8 *) DC2__SNAP)
    
	#define DC2_0_INTTYPE_REG 		(* (reg8 *) DC2__0__INTTYPE)
#endif /* (DC2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DC2_H */


/* [] END OF FILE */
