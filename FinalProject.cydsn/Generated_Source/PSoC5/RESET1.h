/*******************************************************************************
* File Name: RESET1.h  
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

#if !defined(CY_PINS_RESET1_H) /* Pins RESET1_H */
#define CY_PINS_RESET1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RESET1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RESET1__PORT == 15 && ((RESET1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RESET1_Write(uint8 value);
void    RESET1_SetDriveMode(uint8 mode);
uint8   RESET1_ReadDataReg(void);
uint8   RESET1_Read(void);
void    RESET1_SetInterruptMode(uint16 position, uint16 mode);
uint8   RESET1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RESET1_SetDriveMode() function.
     *  @{
     */
        #define RESET1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RESET1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RESET1_DM_RES_UP          PIN_DM_RES_UP
        #define RESET1_DM_RES_DWN         PIN_DM_RES_DWN
        #define RESET1_DM_OD_LO           PIN_DM_OD_LO
        #define RESET1_DM_OD_HI           PIN_DM_OD_HI
        #define RESET1_DM_STRONG          PIN_DM_STRONG
        #define RESET1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RESET1_MASK               RESET1__MASK
#define RESET1_SHIFT              RESET1__SHIFT
#define RESET1_WIDTH              1u

/* Interrupt constants */
#if defined(RESET1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RESET1_SetInterruptMode() function.
     *  @{
     */
        #define RESET1_INTR_NONE      (uint16)(0x0000u)
        #define RESET1_INTR_RISING    (uint16)(0x0001u)
        #define RESET1_INTR_FALLING   (uint16)(0x0002u)
        #define RESET1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RESET1_INTR_MASK      (0x01u) 
#endif /* (RESET1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RESET1_PS                     (* (reg8 *) RESET1__PS)
/* Data Register */
#define RESET1_DR                     (* (reg8 *) RESET1__DR)
/* Port Number */
#define RESET1_PRT_NUM                (* (reg8 *) RESET1__PRT) 
/* Connect to Analog Globals */                                                  
#define RESET1_AG                     (* (reg8 *) RESET1__AG)                       
/* Analog MUX bux enable */
#define RESET1_AMUX                   (* (reg8 *) RESET1__AMUX) 
/* Bidirectional Enable */                                                        
#define RESET1_BIE                    (* (reg8 *) RESET1__BIE)
/* Bit-mask for Aliased Register Access */
#define RESET1_BIT_MASK               (* (reg8 *) RESET1__BIT_MASK)
/* Bypass Enable */
#define RESET1_BYP                    (* (reg8 *) RESET1__BYP)
/* Port wide control signals */                                                   
#define RESET1_CTL                    (* (reg8 *) RESET1__CTL)
/* Drive Modes */
#define RESET1_DM0                    (* (reg8 *) RESET1__DM0) 
#define RESET1_DM1                    (* (reg8 *) RESET1__DM1)
#define RESET1_DM2                    (* (reg8 *) RESET1__DM2) 
/* Input Buffer Disable Override */
#define RESET1_INP_DIS                (* (reg8 *) RESET1__INP_DIS)
/* LCD Common or Segment Drive */
#define RESET1_LCD_COM_SEG            (* (reg8 *) RESET1__LCD_COM_SEG)
/* Enable Segment LCD */
#define RESET1_LCD_EN                 (* (reg8 *) RESET1__LCD_EN)
/* Slew Rate Control */
#define RESET1_SLW                    (* (reg8 *) RESET1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RESET1_PRTDSI__CAPS_SEL       (* (reg8 *) RESET1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RESET1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RESET1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RESET1_PRTDSI__OE_SEL0        (* (reg8 *) RESET1__PRTDSI__OE_SEL0) 
#define RESET1_PRTDSI__OE_SEL1        (* (reg8 *) RESET1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RESET1_PRTDSI__OUT_SEL0       (* (reg8 *) RESET1__PRTDSI__OUT_SEL0) 
#define RESET1_PRTDSI__OUT_SEL1       (* (reg8 *) RESET1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RESET1_PRTDSI__SYNC_OUT       (* (reg8 *) RESET1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RESET1__SIO_CFG)
    #define RESET1_SIO_HYST_EN        (* (reg8 *) RESET1__SIO_HYST_EN)
    #define RESET1_SIO_REG_HIFREQ     (* (reg8 *) RESET1__SIO_REG_HIFREQ)
    #define RESET1_SIO_CFG            (* (reg8 *) RESET1__SIO_CFG)
    #define RESET1_SIO_DIFF           (* (reg8 *) RESET1__SIO_DIFF)
#endif /* (RESET1__SIO_CFG) */

/* Interrupt Registers */
#if defined(RESET1__INTSTAT)
    #define RESET1_INTSTAT            (* (reg8 *) RESET1__INTSTAT)
    #define RESET1_SNAP               (* (reg8 *) RESET1__SNAP)
    
	#define RESET1_0_INTTYPE_REG 		(* (reg8 *) RESET1__0__INTTYPE)
#endif /* (RESET1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RESET1_H */


/* [] END OF FILE */
