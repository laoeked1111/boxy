/*******************************************************************************
* File Name: DC3.h  
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

#if !defined(CY_PINS_DC3_H) /* Pins DC3_H */
#define CY_PINS_DC3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DC3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DC3__PORT == 15 && ((DC3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DC3_Write(uint8 value);
void    DC3_SetDriveMode(uint8 mode);
uint8   DC3_ReadDataReg(void);
uint8   DC3_Read(void);
void    DC3_SetInterruptMode(uint16 position, uint16 mode);
uint8   DC3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DC3_SetDriveMode() function.
     *  @{
     */
        #define DC3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DC3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DC3_DM_RES_UP          PIN_DM_RES_UP
        #define DC3_DM_RES_DWN         PIN_DM_RES_DWN
        #define DC3_DM_OD_LO           PIN_DM_OD_LO
        #define DC3_DM_OD_HI           PIN_DM_OD_HI
        #define DC3_DM_STRONG          PIN_DM_STRONG
        #define DC3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DC3_MASK               DC3__MASK
#define DC3_SHIFT              DC3__SHIFT
#define DC3_WIDTH              1u

/* Interrupt constants */
#if defined(DC3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DC3_SetInterruptMode() function.
     *  @{
     */
        #define DC3_INTR_NONE      (uint16)(0x0000u)
        #define DC3_INTR_RISING    (uint16)(0x0001u)
        #define DC3_INTR_FALLING   (uint16)(0x0002u)
        #define DC3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DC3_INTR_MASK      (0x01u) 
#endif /* (DC3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DC3_PS                     (* (reg8 *) DC3__PS)
/* Data Register */
#define DC3_DR                     (* (reg8 *) DC3__DR)
/* Port Number */
#define DC3_PRT_NUM                (* (reg8 *) DC3__PRT) 
/* Connect to Analog Globals */                                                  
#define DC3_AG                     (* (reg8 *) DC3__AG)                       
/* Analog MUX bux enable */
#define DC3_AMUX                   (* (reg8 *) DC3__AMUX) 
/* Bidirectional Enable */                                                        
#define DC3_BIE                    (* (reg8 *) DC3__BIE)
/* Bit-mask for Aliased Register Access */
#define DC3_BIT_MASK               (* (reg8 *) DC3__BIT_MASK)
/* Bypass Enable */
#define DC3_BYP                    (* (reg8 *) DC3__BYP)
/* Port wide control signals */                                                   
#define DC3_CTL                    (* (reg8 *) DC3__CTL)
/* Drive Modes */
#define DC3_DM0                    (* (reg8 *) DC3__DM0) 
#define DC3_DM1                    (* (reg8 *) DC3__DM1)
#define DC3_DM2                    (* (reg8 *) DC3__DM2) 
/* Input Buffer Disable Override */
#define DC3_INP_DIS                (* (reg8 *) DC3__INP_DIS)
/* LCD Common or Segment Drive */
#define DC3_LCD_COM_SEG            (* (reg8 *) DC3__LCD_COM_SEG)
/* Enable Segment LCD */
#define DC3_LCD_EN                 (* (reg8 *) DC3__LCD_EN)
/* Slew Rate Control */
#define DC3_SLW                    (* (reg8 *) DC3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DC3_PRTDSI__CAPS_SEL       (* (reg8 *) DC3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DC3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DC3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DC3_PRTDSI__OE_SEL0        (* (reg8 *) DC3__PRTDSI__OE_SEL0) 
#define DC3_PRTDSI__OE_SEL1        (* (reg8 *) DC3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DC3_PRTDSI__OUT_SEL0       (* (reg8 *) DC3__PRTDSI__OUT_SEL0) 
#define DC3_PRTDSI__OUT_SEL1       (* (reg8 *) DC3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DC3_PRTDSI__SYNC_OUT       (* (reg8 *) DC3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DC3__SIO_CFG)
    #define DC3_SIO_HYST_EN        (* (reg8 *) DC3__SIO_HYST_EN)
    #define DC3_SIO_REG_HIFREQ     (* (reg8 *) DC3__SIO_REG_HIFREQ)
    #define DC3_SIO_CFG            (* (reg8 *) DC3__SIO_CFG)
    #define DC3_SIO_DIFF           (* (reg8 *) DC3__SIO_DIFF)
#endif /* (DC3__SIO_CFG) */

/* Interrupt Registers */
#if defined(DC3__INTSTAT)
    #define DC3_INTSTAT            (* (reg8 *) DC3__INTSTAT)
    #define DC3_SNAP               (* (reg8 *) DC3__SNAP)
    
	#define DC3_0_INTTYPE_REG 		(* (reg8 *) DC3__0__INTTYPE)
#endif /* (DC3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DC3_H */


/* [] END OF FILE */
