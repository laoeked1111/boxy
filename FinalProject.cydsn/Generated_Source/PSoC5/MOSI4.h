/*******************************************************************************
* File Name: MOSI4.h  
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

#if !defined(CY_PINS_MOSI4_H) /* Pins MOSI4_H */
#define CY_PINS_MOSI4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOSI4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOSI4__PORT == 15 && ((MOSI4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MOSI4_Write(uint8 value);
void    MOSI4_SetDriveMode(uint8 mode);
uint8   MOSI4_ReadDataReg(void);
uint8   MOSI4_Read(void);
void    MOSI4_SetInterruptMode(uint16 position, uint16 mode);
uint8   MOSI4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MOSI4_SetDriveMode() function.
     *  @{
     */
        #define MOSI4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MOSI4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MOSI4_DM_RES_UP          PIN_DM_RES_UP
        #define MOSI4_DM_RES_DWN         PIN_DM_RES_DWN
        #define MOSI4_DM_OD_LO           PIN_DM_OD_LO
        #define MOSI4_DM_OD_HI           PIN_DM_OD_HI
        #define MOSI4_DM_STRONG          PIN_DM_STRONG
        #define MOSI4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MOSI4_MASK               MOSI4__MASK
#define MOSI4_SHIFT              MOSI4__SHIFT
#define MOSI4_WIDTH              1u

/* Interrupt constants */
#if defined(MOSI4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MOSI4_SetInterruptMode() function.
     *  @{
     */
        #define MOSI4_INTR_NONE      (uint16)(0x0000u)
        #define MOSI4_INTR_RISING    (uint16)(0x0001u)
        #define MOSI4_INTR_FALLING   (uint16)(0x0002u)
        #define MOSI4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MOSI4_INTR_MASK      (0x01u) 
#endif /* (MOSI4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOSI4_PS                     (* (reg8 *) MOSI4__PS)
/* Data Register */
#define MOSI4_DR                     (* (reg8 *) MOSI4__DR)
/* Port Number */
#define MOSI4_PRT_NUM                (* (reg8 *) MOSI4__PRT) 
/* Connect to Analog Globals */                                                  
#define MOSI4_AG                     (* (reg8 *) MOSI4__AG)                       
/* Analog MUX bux enable */
#define MOSI4_AMUX                   (* (reg8 *) MOSI4__AMUX) 
/* Bidirectional Enable */                                                        
#define MOSI4_BIE                    (* (reg8 *) MOSI4__BIE)
/* Bit-mask for Aliased Register Access */
#define MOSI4_BIT_MASK               (* (reg8 *) MOSI4__BIT_MASK)
/* Bypass Enable */
#define MOSI4_BYP                    (* (reg8 *) MOSI4__BYP)
/* Port wide control signals */                                                   
#define MOSI4_CTL                    (* (reg8 *) MOSI4__CTL)
/* Drive Modes */
#define MOSI4_DM0                    (* (reg8 *) MOSI4__DM0) 
#define MOSI4_DM1                    (* (reg8 *) MOSI4__DM1)
#define MOSI4_DM2                    (* (reg8 *) MOSI4__DM2) 
/* Input Buffer Disable Override */
#define MOSI4_INP_DIS                (* (reg8 *) MOSI4__INP_DIS)
/* LCD Common or Segment Drive */
#define MOSI4_LCD_COM_SEG            (* (reg8 *) MOSI4__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOSI4_LCD_EN                 (* (reg8 *) MOSI4__LCD_EN)
/* Slew Rate Control */
#define MOSI4_SLW                    (* (reg8 *) MOSI4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOSI4_PRTDSI__CAPS_SEL       (* (reg8 *) MOSI4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOSI4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOSI4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOSI4_PRTDSI__OE_SEL0        (* (reg8 *) MOSI4__PRTDSI__OE_SEL0) 
#define MOSI4_PRTDSI__OE_SEL1        (* (reg8 *) MOSI4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOSI4_PRTDSI__OUT_SEL0       (* (reg8 *) MOSI4__PRTDSI__OUT_SEL0) 
#define MOSI4_PRTDSI__OUT_SEL1       (* (reg8 *) MOSI4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOSI4_PRTDSI__SYNC_OUT       (* (reg8 *) MOSI4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MOSI4__SIO_CFG)
    #define MOSI4_SIO_HYST_EN        (* (reg8 *) MOSI4__SIO_HYST_EN)
    #define MOSI4_SIO_REG_HIFREQ     (* (reg8 *) MOSI4__SIO_REG_HIFREQ)
    #define MOSI4_SIO_CFG            (* (reg8 *) MOSI4__SIO_CFG)
    #define MOSI4_SIO_DIFF           (* (reg8 *) MOSI4__SIO_DIFF)
#endif /* (MOSI4__SIO_CFG) */

/* Interrupt Registers */
#if defined(MOSI4__INTSTAT)
    #define MOSI4_INTSTAT            (* (reg8 *) MOSI4__INTSTAT)
    #define MOSI4_SNAP               (* (reg8 *) MOSI4__SNAP)
    
	#define MOSI4_0_INTTYPE_REG 		(* (reg8 *) MOSI4__0__INTTYPE)
#endif /* (MOSI4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOSI4_H */


/* [] END OF FILE */
