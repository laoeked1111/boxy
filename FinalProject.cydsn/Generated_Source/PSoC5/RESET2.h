/*******************************************************************************
* File Name: RESET2.h  
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

#if !defined(CY_PINS_RESET2_H) /* Pins RESET2_H */
#define CY_PINS_RESET2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RESET2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RESET2__PORT == 15 && ((RESET2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RESET2_Write(uint8 value);
void    RESET2_SetDriveMode(uint8 mode);
uint8   RESET2_ReadDataReg(void);
uint8   RESET2_Read(void);
void    RESET2_SetInterruptMode(uint16 position, uint16 mode);
uint8   RESET2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RESET2_SetDriveMode() function.
     *  @{
     */
        #define RESET2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RESET2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RESET2_DM_RES_UP          PIN_DM_RES_UP
        #define RESET2_DM_RES_DWN         PIN_DM_RES_DWN
        #define RESET2_DM_OD_LO           PIN_DM_OD_LO
        #define RESET2_DM_OD_HI           PIN_DM_OD_HI
        #define RESET2_DM_STRONG          PIN_DM_STRONG
        #define RESET2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RESET2_MASK               RESET2__MASK
#define RESET2_SHIFT              RESET2__SHIFT
#define RESET2_WIDTH              1u

/* Interrupt constants */
#if defined(RESET2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RESET2_SetInterruptMode() function.
     *  @{
     */
        #define RESET2_INTR_NONE      (uint16)(0x0000u)
        #define RESET2_INTR_RISING    (uint16)(0x0001u)
        #define RESET2_INTR_FALLING   (uint16)(0x0002u)
        #define RESET2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RESET2_INTR_MASK      (0x01u) 
#endif /* (RESET2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RESET2_PS                     (* (reg8 *) RESET2__PS)
/* Data Register */
#define RESET2_DR                     (* (reg8 *) RESET2__DR)
/* Port Number */
#define RESET2_PRT_NUM                (* (reg8 *) RESET2__PRT) 
/* Connect to Analog Globals */                                                  
#define RESET2_AG                     (* (reg8 *) RESET2__AG)                       
/* Analog MUX bux enable */
#define RESET2_AMUX                   (* (reg8 *) RESET2__AMUX) 
/* Bidirectional Enable */                                                        
#define RESET2_BIE                    (* (reg8 *) RESET2__BIE)
/* Bit-mask for Aliased Register Access */
#define RESET2_BIT_MASK               (* (reg8 *) RESET2__BIT_MASK)
/* Bypass Enable */
#define RESET2_BYP                    (* (reg8 *) RESET2__BYP)
/* Port wide control signals */                                                   
#define RESET2_CTL                    (* (reg8 *) RESET2__CTL)
/* Drive Modes */
#define RESET2_DM0                    (* (reg8 *) RESET2__DM0) 
#define RESET2_DM1                    (* (reg8 *) RESET2__DM1)
#define RESET2_DM2                    (* (reg8 *) RESET2__DM2) 
/* Input Buffer Disable Override */
#define RESET2_INP_DIS                (* (reg8 *) RESET2__INP_DIS)
/* LCD Common or Segment Drive */
#define RESET2_LCD_COM_SEG            (* (reg8 *) RESET2__LCD_COM_SEG)
/* Enable Segment LCD */
#define RESET2_LCD_EN                 (* (reg8 *) RESET2__LCD_EN)
/* Slew Rate Control */
#define RESET2_SLW                    (* (reg8 *) RESET2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RESET2_PRTDSI__CAPS_SEL       (* (reg8 *) RESET2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RESET2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RESET2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RESET2_PRTDSI__OE_SEL0        (* (reg8 *) RESET2__PRTDSI__OE_SEL0) 
#define RESET2_PRTDSI__OE_SEL1        (* (reg8 *) RESET2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RESET2_PRTDSI__OUT_SEL0       (* (reg8 *) RESET2__PRTDSI__OUT_SEL0) 
#define RESET2_PRTDSI__OUT_SEL1       (* (reg8 *) RESET2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RESET2_PRTDSI__SYNC_OUT       (* (reg8 *) RESET2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RESET2__SIO_CFG)
    #define RESET2_SIO_HYST_EN        (* (reg8 *) RESET2__SIO_HYST_EN)
    #define RESET2_SIO_REG_HIFREQ     (* (reg8 *) RESET2__SIO_REG_HIFREQ)
    #define RESET2_SIO_CFG            (* (reg8 *) RESET2__SIO_CFG)
    #define RESET2_SIO_DIFF           (* (reg8 *) RESET2__SIO_DIFF)
#endif /* (RESET2__SIO_CFG) */

/* Interrupt Registers */
#if defined(RESET2__INTSTAT)
    #define RESET2_INTSTAT            (* (reg8 *) RESET2__INTSTAT)
    #define RESET2_SNAP               (* (reg8 *) RESET2__SNAP)
    
	#define RESET2_0_INTTYPE_REG 		(* (reg8 *) RESET2__0__INTTYPE)
#endif /* (RESET2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RESET2_H */


/* [] END OF FILE */
