/*******************************************************************************
* File Name: TOGGLE_LANTERN.h  
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

#if !defined(CY_PINS_TOGGLE_LANTERN_H) /* Pins TOGGLE_LANTERN_H */
#define CY_PINS_TOGGLE_LANTERN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TOGGLE_LANTERN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TOGGLE_LANTERN__PORT == 15 && ((TOGGLE_LANTERN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    TOGGLE_LANTERN_Write(uint8 value);
void    TOGGLE_LANTERN_SetDriveMode(uint8 mode);
uint8   TOGGLE_LANTERN_ReadDataReg(void);
uint8   TOGGLE_LANTERN_Read(void);
void    TOGGLE_LANTERN_SetInterruptMode(uint16 position, uint16 mode);
uint8   TOGGLE_LANTERN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the TOGGLE_LANTERN_SetDriveMode() function.
     *  @{
     */
        #define TOGGLE_LANTERN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define TOGGLE_LANTERN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define TOGGLE_LANTERN_DM_RES_UP          PIN_DM_RES_UP
        #define TOGGLE_LANTERN_DM_RES_DWN         PIN_DM_RES_DWN
        #define TOGGLE_LANTERN_DM_OD_LO           PIN_DM_OD_LO
        #define TOGGLE_LANTERN_DM_OD_HI           PIN_DM_OD_HI
        #define TOGGLE_LANTERN_DM_STRONG          PIN_DM_STRONG
        #define TOGGLE_LANTERN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define TOGGLE_LANTERN_MASK               TOGGLE_LANTERN__MASK
#define TOGGLE_LANTERN_SHIFT              TOGGLE_LANTERN__SHIFT
#define TOGGLE_LANTERN_WIDTH              1u

/* Interrupt constants */
#if defined(TOGGLE_LANTERN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in TOGGLE_LANTERN_SetInterruptMode() function.
     *  @{
     */
        #define TOGGLE_LANTERN_INTR_NONE      (uint16)(0x0000u)
        #define TOGGLE_LANTERN_INTR_RISING    (uint16)(0x0001u)
        #define TOGGLE_LANTERN_INTR_FALLING   (uint16)(0x0002u)
        #define TOGGLE_LANTERN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define TOGGLE_LANTERN_INTR_MASK      (0x01u) 
#endif /* (TOGGLE_LANTERN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TOGGLE_LANTERN_PS                     (* (reg8 *) TOGGLE_LANTERN__PS)
/* Data Register */
#define TOGGLE_LANTERN_DR                     (* (reg8 *) TOGGLE_LANTERN__DR)
/* Port Number */
#define TOGGLE_LANTERN_PRT_NUM                (* (reg8 *) TOGGLE_LANTERN__PRT) 
/* Connect to Analog Globals */                                                  
#define TOGGLE_LANTERN_AG                     (* (reg8 *) TOGGLE_LANTERN__AG)                       
/* Analog MUX bux enable */
#define TOGGLE_LANTERN_AMUX                   (* (reg8 *) TOGGLE_LANTERN__AMUX) 
/* Bidirectional Enable */                                                        
#define TOGGLE_LANTERN_BIE                    (* (reg8 *) TOGGLE_LANTERN__BIE)
/* Bit-mask for Aliased Register Access */
#define TOGGLE_LANTERN_BIT_MASK               (* (reg8 *) TOGGLE_LANTERN__BIT_MASK)
/* Bypass Enable */
#define TOGGLE_LANTERN_BYP                    (* (reg8 *) TOGGLE_LANTERN__BYP)
/* Port wide control signals */                                                   
#define TOGGLE_LANTERN_CTL                    (* (reg8 *) TOGGLE_LANTERN__CTL)
/* Drive Modes */
#define TOGGLE_LANTERN_DM0                    (* (reg8 *) TOGGLE_LANTERN__DM0) 
#define TOGGLE_LANTERN_DM1                    (* (reg8 *) TOGGLE_LANTERN__DM1)
#define TOGGLE_LANTERN_DM2                    (* (reg8 *) TOGGLE_LANTERN__DM2) 
/* Input Buffer Disable Override */
#define TOGGLE_LANTERN_INP_DIS                (* (reg8 *) TOGGLE_LANTERN__INP_DIS)
/* LCD Common or Segment Drive */
#define TOGGLE_LANTERN_LCD_COM_SEG            (* (reg8 *) TOGGLE_LANTERN__LCD_COM_SEG)
/* Enable Segment LCD */
#define TOGGLE_LANTERN_LCD_EN                 (* (reg8 *) TOGGLE_LANTERN__LCD_EN)
/* Slew Rate Control */
#define TOGGLE_LANTERN_SLW                    (* (reg8 *) TOGGLE_LANTERN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TOGGLE_LANTERN_PRTDSI__CAPS_SEL       (* (reg8 *) TOGGLE_LANTERN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TOGGLE_LANTERN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TOGGLE_LANTERN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TOGGLE_LANTERN_PRTDSI__OE_SEL0        (* (reg8 *) TOGGLE_LANTERN__PRTDSI__OE_SEL0) 
#define TOGGLE_LANTERN_PRTDSI__OE_SEL1        (* (reg8 *) TOGGLE_LANTERN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TOGGLE_LANTERN_PRTDSI__OUT_SEL0       (* (reg8 *) TOGGLE_LANTERN__PRTDSI__OUT_SEL0) 
#define TOGGLE_LANTERN_PRTDSI__OUT_SEL1       (* (reg8 *) TOGGLE_LANTERN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TOGGLE_LANTERN_PRTDSI__SYNC_OUT       (* (reg8 *) TOGGLE_LANTERN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(TOGGLE_LANTERN__SIO_CFG)
    #define TOGGLE_LANTERN_SIO_HYST_EN        (* (reg8 *) TOGGLE_LANTERN__SIO_HYST_EN)
    #define TOGGLE_LANTERN_SIO_REG_HIFREQ     (* (reg8 *) TOGGLE_LANTERN__SIO_REG_HIFREQ)
    #define TOGGLE_LANTERN_SIO_CFG            (* (reg8 *) TOGGLE_LANTERN__SIO_CFG)
    #define TOGGLE_LANTERN_SIO_DIFF           (* (reg8 *) TOGGLE_LANTERN__SIO_DIFF)
#endif /* (TOGGLE_LANTERN__SIO_CFG) */

/* Interrupt Registers */
#if defined(TOGGLE_LANTERN__INTSTAT)
    #define TOGGLE_LANTERN_INTSTAT            (* (reg8 *) TOGGLE_LANTERN__INTSTAT)
    #define TOGGLE_LANTERN_SNAP               (* (reg8 *) TOGGLE_LANTERN__SNAP)
    
	#define TOGGLE_LANTERN_0_INTTYPE_REG 		(* (reg8 *) TOGGLE_LANTERN__0__INTTYPE)
#endif /* (TOGGLE_LANTERN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TOGGLE_LANTERN_H */


/* [] END OF FILE */
