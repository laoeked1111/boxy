/*******************************************************************************
* File Name: SCLK0.h  
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

#if !defined(CY_PINS_SCLK0_H) /* Pins SCLK0_H */
#define CY_PINS_SCLK0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SCLK0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SCLK0__PORT == 15 && ((SCLK0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SCLK0_Write(uint8 value);
void    SCLK0_SetDriveMode(uint8 mode);
uint8   SCLK0_ReadDataReg(void);
uint8   SCLK0_Read(void);
void    SCLK0_SetInterruptMode(uint16 position, uint16 mode);
uint8   SCLK0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SCLK0_SetDriveMode() function.
     *  @{
     */
        #define SCLK0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SCLK0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SCLK0_DM_RES_UP          PIN_DM_RES_UP
        #define SCLK0_DM_RES_DWN         PIN_DM_RES_DWN
        #define SCLK0_DM_OD_LO           PIN_DM_OD_LO
        #define SCLK0_DM_OD_HI           PIN_DM_OD_HI
        #define SCLK0_DM_STRONG          PIN_DM_STRONG
        #define SCLK0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SCLK0_MASK               SCLK0__MASK
#define SCLK0_SHIFT              SCLK0__SHIFT
#define SCLK0_WIDTH              1u

/* Interrupt constants */
#if defined(SCLK0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SCLK0_SetInterruptMode() function.
     *  @{
     */
        #define SCLK0_INTR_NONE      (uint16)(0x0000u)
        #define SCLK0_INTR_RISING    (uint16)(0x0001u)
        #define SCLK0_INTR_FALLING   (uint16)(0x0002u)
        #define SCLK0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SCLK0_INTR_MASK      (0x01u) 
#endif /* (SCLK0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SCLK0_PS                     (* (reg8 *) SCLK0__PS)
/* Data Register */
#define SCLK0_DR                     (* (reg8 *) SCLK0__DR)
/* Port Number */
#define SCLK0_PRT_NUM                (* (reg8 *) SCLK0__PRT) 
/* Connect to Analog Globals */                                                  
#define SCLK0_AG                     (* (reg8 *) SCLK0__AG)                       
/* Analog MUX bux enable */
#define SCLK0_AMUX                   (* (reg8 *) SCLK0__AMUX) 
/* Bidirectional Enable */                                                        
#define SCLK0_BIE                    (* (reg8 *) SCLK0__BIE)
/* Bit-mask for Aliased Register Access */
#define SCLK0_BIT_MASK               (* (reg8 *) SCLK0__BIT_MASK)
/* Bypass Enable */
#define SCLK0_BYP                    (* (reg8 *) SCLK0__BYP)
/* Port wide control signals */                                                   
#define SCLK0_CTL                    (* (reg8 *) SCLK0__CTL)
/* Drive Modes */
#define SCLK0_DM0                    (* (reg8 *) SCLK0__DM0) 
#define SCLK0_DM1                    (* (reg8 *) SCLK0__DM1)
#define SCLK0_DM2                    (* (reg8 *) SCLK0__DM2) 
/* Input Buffer Disable Override */
#define SCLK0_INP_DIS                (* (reg8 *) SCLK0__INP_DIS)
/* LCD Common or Segment Drive */
#define SCLK0_LCD_COM_SEG            (* (reg8 *) SCLK0__LCD_COM_SEG)
/* Enable Segment LCD */
#define SCLK0_LCD_EN                 (* (reg8 *) SCLK0__LCD_EN)
/* Slew Rate Control */
#define SCLK0_SLW                    (* (reg8 *) SCLK0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SCLK0_PRTDSI__CAPS_SEL       (* (reg8 *) SCLK0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SCLK0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SCLK0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SCLK0_PRTDSI__OE_SEL0        (* (reg8 *) SCLK0__PRTDSI__OE_SEL0) 
#define SCLK0_PRTDSI__OE_SEL1        (* (reg8 *) SCLK0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SCLK0_PRTDSI__OUT_SEL0       (* (reg8 *) SCLK0__PRTDSI__OUT_SEL0) 
#define SCLK0_PRTDSI__OUT_SEL1       (* (reg8 *) SCLK0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SCLK0_PRTDSI__SYNC_OUT       (* (reg8 *) SCLK0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SCLK0__SIO_CFG)
    #define SCLK0_SIO_HYST_EN        (* (reg8 *) SCLK0__SIO_HYST_EN)
    #define SCLK0_SIO_REG_HIFREQ     (* (reg8 *) SCLK0__SIO_REG_HIFREQ)
    #define SCLK0_SIO_CFG            (* (reg8 *) SCLK0__SIO_CFG)
    #define SCLK0_SIO_DIFF           (* (reg8 *) SCLK0__SIO_DIFF)
#endif /* (SCLK0__SIO_CFG) */

/* Interrupt Registers */
#if defined(SCLK0__INTSTAT)
    #define SCLK0_INTSTAT            (* (reg8 *) SCLK0__INTSTAT)
    #define SCLK0_SNAP               (* (reg8 *) SCLK0__SNAP)
    
	#define SCLK0_0_INTTYPE_REG 		(* (reg8 *) SCLK0__0__INTTYPE)
#endif /* (SCLK0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SCLK0_H */


/* [] END OF FILE */
