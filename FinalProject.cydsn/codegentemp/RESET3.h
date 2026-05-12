/*******************************************************************************
* File Name: RESET3.h  
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

#if !defined(CY_PINS_RESET3_H) /* Pins RESET3_H */
#define CY_PINS_RESET3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RESET3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RESET3__PORT == 15 && ((RESET3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RESET3_Write(uint8 value);
void    RESET3_SetDriveMode(uint8 mode);
uint8   RESET3_ReadDataReg(void);
uint8   RESET3_Read(void);
void    RESET3_SetInterruptMode(uint16 position, uint16 mode);
uint8   RESET3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RESET3_SetDriveMode() function.
     *  @{
     */
        #define RESET3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RESET3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RESET3_DM_RES_UP          PIN_DM_RES_UP
        #define RESET3_DM_RES_DWN         PIN_DM_RES_DWN
        #define RESET3_DM_OD_LO           PIN_DM_OD_LO
        #define RESET3_DM_OD_HI           PIN_DM_OD_HI
        #define RESET3_DM_STRONG          PIN_DM_STRONG
        #define RESET3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RESET3_MASK               RESET3__MASK
#define RESET3_SHIFT              RESET3__SHIFT
#define RESET3_WIDTH              1u

/* Interrupt constants */
#if defined(RESET3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RESET3_SetInterruptMode() function.
     *  @{
     */
        #define RESET3_INTR_NONE      (uint16)(0x0000u)
        #define RESET3_INTR_RISING    (uint16)(0x0001u)
        #define RESET3_INTR_FALLING   (uint16)(0x0002u)
        #define RESET3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RESET3_INTR_MASK      (0x01u) 
#endif /* (RESET3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RESET3_PS                     (* (reg8 *) RESET3__PS)
/* Data Register */
#define RESET3_DR                     (* (reg8 *) RESET3__DR)
/* Port Number */
#define RESET3_PRT_NUM                (* (reg8 *) RESET3__PRT) 
/* Connect to Analog Globals */                                                  
#define RESET3_AG                     (* (reg8 *) RESET3__AG)                       
/* Analog MUX bux enable */
#define RESET3_AMUX                   (* (reg8 *) RESET3__AMUX) 
/* Bidirectional Enable */                                                        
#define RESET3_BIE                    (* (reg8 *) RESET3__BIE)
/* Bit-mask for Aliased Register Access */
#define RESET3_BIT_MASK               (* (reg8 *) RESET3__BIT_MASK)
/* Bypass Enable */
#define RESET3_BYP                    (* (reg8 *) RESET3__BYP)
/* Port wide control signals */                                                   
#define RESET3_CTL                    (* (reg8 *) RESET3__CTL)
/* Drive Modes */
#define RESET3_DM0                    (* (reg8 *) RESET3__DM0) 
#define RESET3_DM1                    (* (reg8 *) RESET3__DM1)
#define RESET3_DM2                    (* (reg8 *) RESET3__DM2) 
/* Input Buffer Disable Override */
#define RESET3_INP_DIS                (* (reg8 *) RESET3__INP_DIS)
/* LCD Common or Segment Drive */
#define RESET3_LCD_COM_SEG            (* (reg8 *) RESET3__LCD_COM_SEG)
/* Enable Segment LCD */
#define RESET3_LCD_EN                 (* (reg8 *) RESET3__LCD_EN)
/* Slew Rate Control */
#define RESET3_SLW                    (* (reg8 *) RESET3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RESET3_PRTDSI__CAPS_SEL       (* (reg8 *) RESET3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RESET3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RESET3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RESET3_PRTDSI__OE_SEL0        (* (reg8 *) RESET3__PRTDSI__OE_SEL0) 
#define RESET3_PRTDSI__OE_SEL1        (* (reg8 *) RESET3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RESET3_PRTDSI__OUT_SEL0       (* (reg8 *) RESET3__PRTDSI__OUT_SEL0) 
#define RESET3_PRTDSI__OUT_SEL1       (* (reg8 *) RESET3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RESET3_PRTDSI__SYNC_OUT       (* (reg8 *) RESET3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RESET3__SIO_CFG)
    #define RESET3_SIO_HYST_EN        (* (reg8 *) RESET3__SIO_HYST_EN)
    #define RESET3_SIO_REG_HIFREQ     (* (reg8 *) RESET3__SIO_REG_HIFREQ)
    #define RESET3_SIO_CFG            (* (reg8 *) RESET3__SIO_CFG)
    #define RESET3_SIO_DIFF           (* (reg8 *) RESET3__SIO_DIFF)
#endif /* (RESET3__SIO_CFG) */

/* Interrupt Registers */
#if defined(RESET3__INTSTAT)
    #define RESET3_INTSTAT            (* (reg8 *) RESET3__INTSTAT)
    #define RESET3_SNAP               (* (reg8 *) RESET3__SNAP)
    
	#define RESET3_0_INTTYPE_REG 		(* (reg8 *) RESET3__0__INTTYPE)
#endif /* (RESET3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RESET3_H */


/* [] END OF FILE */
