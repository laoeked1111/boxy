/*******************************************************************************
* File Name: SS4.h  
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

#if !defined(CY_PINS_SS4_H) /* Pins SS4_H */
#define CY_PINS_SS4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SS4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SS4__PORT == 15 && ((SS4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SS4_Write(uint8 value);
void    SS4_SetDriveMode(uint8 mode);
uint8   SS4_ReadDataReg(void);
uint8   SS4_Read(void);
void    SS4_SetInterruptMode(uint16 position, uint16 mode);
uint8   SS4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SS4_SetDriveMode() function.
     *  @{
     */
        #define SS4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SS4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SS4_DM_RES_UP          PIN_DM_RES_UP
        #define SS4_DM_RES_DWN         PIN_DM_RES_DWN
        #define SS4_DM_OD_LO           PIN_DM_OD_LO
        #define SS4_DM_OD_HI           PIN_DM_OD_HI
        #define SS4_DM_STRONG          PIN_DM_STRONG
        #define SS4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SS4_MASK               SS4__MASK
#define SS4_SHIFT              SS4__SHIFT
#define SS4_WIDTH              1u

/* Interrupt constants */
#if defined(SS4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SS4_SetInterruptMode() function.
     *  @{
     */
        #define SS4_INTR_NONE      (uint16)(0x0000u)
        #define SS4_INTR_RISING    (uint16)(0x0001u)
        #define SS4_INTR_FALLING   (uint16)(0x0002u)
        #define SS4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SS4_INTR_MASK      (0x01u) 
#endif /* (SS4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SS4_PS                     (* (reg8 *) SS4__PS)
/* Data Register */
#define SS4_DR                     (* (reg8 *) SS4__DR)
/* Port Number */
#define SS4_PRT_NUM                (* (reg8 *) SS4__PRT) 
/* Connect to Analog Globals */                                                  
#define SS4_AG                     (* (reg8 *) SS4__AG)                       
/* Analog MUX bux enable */
#define SS4_AMUX                   (* (reg8 *) SS4__AMUX) 
/* Bidirectional Enable */                                                        
#define SS4_BIE                    (* (reg8 *) SS4__BIE)
/* Bit-mask for Aliased Register Access */
#define SS4_BIT_MASK               (* (reg8 *) SS4__BIT_MASK)
/* Bypass Enable */
#define SS4_BYP                    (* (reg8 *) SS4__BYP)
/* Port wide control signals */                                                   
#define SS4_CTL                    (* (reg8 *) SS4__CTL)
/* Drive Modes */
#define SS4_DM0                    (* (reg8 *) SS4__DM0) 
#define SS4_DM1                    (* (reg8 *) SS4__DM1)
#define SS4_DM2                    (* (reg8 *) SS4__DM2) 
/* Input Buffer Disable Override */
#define SS4_INP_DIS                (* (reg8 *) SS4__INP_DIS)
/* LCD Common or Segment Drive */
#define SS4_LCD_COM_SEG            (* (reg8 *) SS4__LCD_COM_SEG)
/* Enable Segment LCD */
#define SS4_LCD_EN                 (* (reg8 *) SS4__LCD_EN)
/* Slew Rate Control */
#define SS4_SLW                    (* (reg8 *) SS4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SS4_PRTDSI__CAPS_SEL       (* (reg8 *) SS4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SS4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SS4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SS4_PRTDSI__OE_SEL0        (* (reg8 *) SS4__PRTDSI__OE_SEL0) 
#define SS4_PRTDSI__OE_SEL1        (* (reg8 *) SS4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SS4_PRTDSI__OUT_SEL0       (* (reg8 *) SS4__PRTDSI__OUT_SEL0) 
#define SS4_PRTDSI__OUT_SEL1       (* (reg8 *) SS4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SS4_PRTDSI__SYNC_OUT       (* (reg8 *) SS4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SS4__SIO_CFG)
    #define SS4_SIO_HYST_EN        (* (reg8 *) SS4__SIO_HYST_EN)
    #define SS4_SIO_REG_HIFREQ     (* (reg8 *) SS4__SIO_REG_HIFREQ)
    #define SS4_SIO_CFG            (* (reg8 *) SS4__SIO_CFG)
    #define SS4_SIO_DIFF           (* (reg8 *) SS4__SIO_DIFF)
#endif /* (SS4__SIO_CFG) */

/* Interrupt Registers */
#if defined(SS4__INTSTAT)
    #define SS4_INTSTAT            (* (reg8 *) SS4__INTSTAT)
    #define SS4_SNAP               (* (reg8 *) SS4__SNAP)
    
	#define SS4_0_INTTYPE_REG 		(* (reg8 *) SS4__0__INTTYPE)
#endif /* (SS4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SS4_H */


/* [] END OF FILE */
