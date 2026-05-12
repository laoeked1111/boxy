/*******************************************************************************
* File Name: RESET4.h  
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

#if !defined(CY_PINS_RESET4_H) /* Pins RESET4_H */
#define CY_PINS_RESET4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RESET4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RESET4__PORT == 15 && ((RESET4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RESET4_Write(uint8 value);
void    RESET4_SetDriveMode(uint8 mode);
uint8   RESET4_ReadDataReg(void);
uint8   RESET4_Read(void);
void    RESET4_SetInterruptMode(uint16 position, uint16 mode);
uint8   RESET4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RESET4_SetDriveMode() function.
     *  @{
     */
        #define RESET4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RESET4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RESET4_DM_RES_UP          PIN_DM_RES_UP
        #define RESET4_DM_RES_DWN         PIN_DM_RES_DWN
        #define RESET4_DM_OD_LO           PIN_DM_OD_LO
        #define RESET4_DM_OD_HI           PIN_DM_OD_HI
        #define RESET4_DM_STRONG          PIN_DM_STRONG
        #define RESET4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RESET4_MASK               RESET4__MASK
#define RESET4_SHIFT              RESET4__SHIFT
#define RESET4_WIDTH              1u

/* Interrupt constants */
#if defined(RESET4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RESET4_SetInterruptMode() function.
     *  @{
     */
        #define RESET4_INTR_NONE      (uint16)(0x0000u)
        #define RESET4_INTR_RISING    (uint16)(0x0001u)
        #define RESET4_INTR_FALLING   (uint16)(0x0002u)
        #define RESET4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RESET4_INTR_MASK      (0x01u) 
#endif /* (RESET4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RESET4_PS                     (* (reg8 *) RESET4__PS)
/* Data Register */
#define RESET4_DR                     (* (reg8 *) RESET4__DR)
/* Port Number */
#define RESET4_PRT_NUM                (* (reg8 *) RESET4__PRT) 
/* Connect to Analog Globals */                                                  
#define RESET4_AG                     (* (reg8 *) RESET4__AG)                       
/* Analog MUX bux enable */
#define RESET4_AMUX                   (* (reg8 *) RESET4__AMUX) 
/* Bidirectional Enable */                                                        
#define RESET4_BIE                    (* (reg8 *) RESET4__BIE)
/* Bit-mask for Aliased Register Access */
#define RESET4_BIT_MASK               (* (reg8 *) RESET4__BIT_MASK)
/* Bypass Enable */
#define RESET4_BYP                    (* (reg8 *) RESET4__BYP)
/* Port wide control signals */                                                   
#define RESET4_CTL                    (* (reg8 *) RESET4__CTL)
/* Drive Modes */
#define RESET4_DM0                    (* (reg8 *) RESET4__DM0) 
#define RESET4_DM1                    (* (reg8 *) RESET4__DM1)
#define RESET4_DM2                    (* (reg8 *) RESET4__DM2) 
/* Input Buffer Disable Override */
#define RESET4_INP_DIS                (* (reg8 *) RESET4__INP_DIS)
/* LCD Common or Segment Drive */
#define RESET4_LCD_COM_SEG            (* (reg8 *) RESET4__LCD_COM_SEG)
/* Enable Segment LCD */
#define RESET4_LCD_EN                 (* (reg8 *) RESET4__LCD_EN)
/* Slew Rate Control */
#define RESET4_SLW                    (* (reg8 *) RESET4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RESET4_PRTDSI__CAPS_SEL       (* (reg8 *) RESET4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RESET4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RESET4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RESET4_PRTDSI__OE_SEL0        (* (reg8 *) RESET4__PRTDSI__OE_SEL0) 
#define RESET4_PRTDSI__OE_SEL1        (* (reg8 *) RESET4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RESET4_PRTDSI__OUT_SEL0       (* (reg8 *) RESET4__PRTDSI__OUT_SEL0) 
#define RESET4_PRTDSI__OUT_SEL1       (* (reg8 *) RESET4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RESET4_PRTDSI__SYNC_OUT       (* (reg8 *) RESET4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RESET4__SIO_CFG)
    #define RESET4_SIO_HYST_EN        (* (reg8 *) RESET4__SIO_HYST_EN)
    #define RESET4_SIO_REG_HIFREQ     (* (reg8 *) RESET4__SIO_REG_HIFREQ)
    #define RESET4_SIO_CFG            (* (reg8 *) RESET4__SIO_CFG)
    #define RESET4_SIO_DIFF           (* (reg8 *) RESET4__SIO_DIFF)
#endif /* (RESET4__SIO_CFG) */

/* Interrupt Registers */
#if defined(RESET4__INTSTAT)
    #define RESET4_INTSTAT            (* (reg8 *) RESET4__INTSTAT)
    #define RESET4_SNAP               (* (reg8 *) RESET4__SNAP)
    
	#define RESET4_0_INTTYPE_REG 		(* (reg8 *) RESET4__0__INTTYPE)
#endif /* (RESET4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RESET4_H */


/* [] END OF FILE */
