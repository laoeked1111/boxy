/*******************************************************************************
* File Name: RESET0.h  
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

#if !defined(CY_PINS_RESET0_H) /* Pins RESET0_H */
#define CY_PINS_RESET0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RESET0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RESET0__PORT == 15 && ((RESET0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RESET0_Write(uint8 value);
void    RESET0_SetDriveMode(uint8 mode);
uint8   RESET0_ReadDataReg(void);
uint8   RESET0_Read(void);
void    RESET0_SetInterruptMode(uint16 position, uint16 mode);
uint8   RESET0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RESET0_SetDriveMode() function.
     *  @{
     */
        #define RESET0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RESET0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RESET0_DM_RES_UP          PIN_DM_RES_UP
        #define RESET0_DM_RES_DWN         PIN_DM_RES_DWN
        #define RESET0_DM_OD_LO           PIN_DM_OD_LO
        #define RESET0_DM_OD_HI           PIN_DM_OD_HI
        #define RESET0_DM_STRONG          PIN_DM_STRONG
        #define RESET0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RESET0_MASK               RESET0__MASK
#define RESET0_SHIFT              RESET0__SHIFT
#define RESET0_WIDTH              1u

/* Interrupt constants */
#if defined(RESET0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RESET0_SetInterruptMode() function.
     *  @{
     */
        #define RESET0_INTR_NONE      (uint16)(0x0000u)
        #define RESET0_INTR_RISING    (uint16)(0x0001u)
        #define RESET0_INTR_FALLING   (uint16)(0x0002u)
        #define RESET0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RESET0_INTR_MASK      (0x01u) 
#endif /* (RESET0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RESET0_PS                     (* (reg8 *) RESET0__PS)
/* Data Register */
#define RESET0_DR                     (* (reg8 *) RESET0__DR)
/* Port Number */
#define RESET0_PRT_NUM                (* (reg8 *) RESET0__PRT) 
/* Connect to Analog Globals */                                                  
#define RESET0_AG                     (* (reg8 *) RESET0__AG)                       
/* Analog MUX bux enable */
#define RESET0_AMUX                   (* (reg8 *) RESET0__AMUX) 
/* Bidirectional Enable */                                                        
#define RESET0_BIE                    (* (reg8 *) RESET0__BIE)
/* Bit-mask for Aliased Register Access */
#define RESET0_BIT_MASK               (* (reg8 *) RESET0__BIT_MASK)
/* Bypass Enable */
#define RESET0_BYP                    (* (reg8 *) RESET0__BYP)
/* Port wide control signals */                                                   
#define RESET0_CTL                    (* (reg8 *) RESET0__CTL)
/* Drive Modes */
#define RESET0_DM0                    (* (reg8 *) RESET0__DM0) 
#define RESET0_DM1                    (* (reg8 *) RESET0__DM1)
#define RESET0_DM2                    (* (reg8 *) RESET0__DM2) 
/* Input Buffer Disable Override */
#define RESET0_INP_DIS                (* (reg8 *) RESET0__INP_DIS)
/* LCD Common or Segment Drive */
#define RESET0_LCD_COM_SEG            (* (reg8 *) RESET0__LCD_COM_SEG)
/* Enable Segment LCD */
#define RESET0_LCD_EN                 (* (reg8 *) RESET0__LCD_EN)
/* Slew Rate Control */
#define RESET0_SLW                    (* (reg8 *) RESET0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RESET0_PRTDSI__CAPS_SEL       (* (reg8 *) RESET0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RESET0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RESET0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RESET0_PRTDSI__OE_SEL0        (* (reg8 *) RESET0__PRTDSI__OE_SEL0) 
#define RESET0_PRTDSI__OE_SEL1        (* (reg8 *) RESET0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RESET0_PRTDSI__OUT_SEL0       (* (reg8 *) RESET0__PRTDSI__OUT_SEL0) 
#define RESET0_PRTDSI__OUT_SEL1       (* (reg8 *) RESET0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RESET0_PRTDSI__SYNC_OUT       (* (reg8 *) RESET0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RESET0__SIO_CFG)
    #define RESET0_SIO_HYST_EN        (* (reg8 *) RESET0__SIO_HYST_EN)
    #define RESET0_SIO_REG_HIFREQ     (* (reg8 *) RESET0__SIO_REG_HIFREQ)
    #define RESET0_SIO_CFG            (* (reg8 *) RESET0__SIO_CFG)
    #define RESET0_SIO_DIFF           (* (reg8 *) RESET0__SIO_DIFF)
#endif /* (RESET0__SIO_CFG) */

/* Interrupt Registers */
#if defined(RESET0__INTSTAT)
    #define RESET0_INTSTAT            (* (reg8 *) RESET0__INTSTAT)
    #define RESET0_SNAP               (* (reg8 *) RESET0__SNAP)
    
	#define RESET0_0_INTTYPE_REG 		(* (reg8 *) RESET0__0__INTTYPE)
#endif /* (RESET0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RESET0_H */


/* [] END OF FILE */
