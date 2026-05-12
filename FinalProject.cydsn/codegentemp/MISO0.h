/*******************************************************************************
* File Name: MISO0.h  
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

#if !defined(CY_PINS_MISO0_H) /* Pins MISO0_H */
#define CY_PINS_MISO0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MISO0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MISO0__PORT == 15 && ((MISO0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MISO0_Write(uint8 value);
void    MISO0_SetDriveMode(uint8 mode);
uint8   MISO0_ReadDataReg(void);
uint8   MISO0_Read(void);
void    MISO0_SetInterruptMode(uint16 position, uint16 mode);
uint8   MISO0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MISO0_SetDriveMode() function.
     *  @{
     */
        #define MISO0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MISO0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MISO0_DM_RES_UP          PIN_DM_RES_UP
        #define MISO0_DM_RES_DWN         PIN_DM_RES_DWN
        #define MISO0_DM_OD_LO           PIN_DM_OD_LO
        #define MISO0_DM_OD_HI           PIN_DM_OD_HI
        #define MISO0_DM_STRONG          PIN_DM_STRONG
        #define MISO0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MISO0_MASK               MISO0__MASK
#define MISO0_SHIFT              MISO0__SHIFT
#define MISO0_WIDTH              1u

/* Interrupt constants */
#if defined(MISO0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MISO0_SetInterruptMode() function.
     *  @{
     */
        #define MISO0_INTR_NONE      (uint16)(0x0000u)
        #define MISO0_INTR_RISING    (uint16)(0x0001u)
        #define MISO0_INTR_FALLING   (uint16)(0x0002u)
        #define MISO0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MISO0_INTR_MASK      (0x01u) 
#endif /* (MISO0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MISO0_PS                     (* (reg8 *) MISO0__PS)
/* Data Register */
#define MISO0_DR                     (* (reg8 *) MISO0__DR)
/* Port Number */
#define MISO0_PRT_NUM                (* (reg8 *) MISO0__PRT) 
/* Connect to Analog Globals */                                                  
#define MISO0_AG                     (* (reg8 *) MISO0__AG)                       
/* Analog MUX bux enable */
#define MISO0_AMUX                   (* (reg8 *) MISO0__AMUX) 
/* Bidirectional Enable */                                                        
#define MISO0_BIE                    (* (reg8 *) MISO0__BIE)
/* Bit-mask for Aliased Register Access */
#define MISO0_BIT_MASK               (* (reg8 *) MISO0__BIT_MASK)
/* Bypass Enable */
#define MISO0_BYP                    (* (reg8 *) MISO0__BYP)
/* Port wide control signals */                                                   
#define MISO0_CTL                    (* (reg8 *) MISO0__CTL)
/* Drive Modes */
#define MISO0_DM0                    (* (reg8 *) MISO0__DM0) 
#define MISO0_DM1                    (* (reg8 *) MISO0__DM1)
#define MISO0_DM2                    (* (reg8 *) MISO0__DM2) 
/* Input Buffer Disable Override */
#define MISO0_INP_DIS                (* (reg8 *) MISO0__INP_DIS)
/* LCD Common or Segment Drive */
#define MISO0_LCD_COM_SEG            (* (reg8 *) MISO0__LCD_COM_SEG)
/* Enable Segment LCD */
#define MISO0_LCD_EN                 (* (reg8 *) MISO0__LCD_EN)
/* Slew Rate Control */
#define MISO0_SLW                    (* (reg8 *) MISO0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MISO0_PRTDSI__CAPS_SEL       (* (reg8 *) MISO0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MISO0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MISO0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MISO0_PRTDSI__OE_SEL0        (* (reg8 *) MISO0__PRTDSI__OE_SEL0) 
#define MISO0_PRTDSI__OE_SEL1        (* (reg8 *) MISO0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MISO0_PRTDSI__OUT_SEL0       (* (reg8 *) MISO0__PRTDSI__OUT_SEL0) 
#define MISO0_PRTDSI__OUT_SEL1       (* (reg8 *) MISO0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MISO0_PRTDSI__SYNC_OUT       (* (reg8 *) MISO0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MISO0__SIO_CFG)
    #define MISO0_SIO_HYST_EN        (* (reg8 *) MISO0__SIO_HYST_EN)
    #define MISO0_SIO_REG_HIFREQ     (* (reg8 *) MISO0__SIO_REG_HIFREQ)
    #define MISO0_SIO_CFG            (* (reg8 *) MISO0__SIO_CFG)
    #define MISO0_SIO_DIFF           (* (reg8 *) MISO0__SIO_DIFF)
#endif /* (MISO0__SIO_CFG) */

/* Interrupt Registers */
#if defined(MISO0__INTSTAT)
    #define MISO0_INTSTAT            (* (reg8 *) MISO0__INTSTAT)
    #define MISO0_SNAP               (* (reg8 *) MISO0__SNAP)
    
	#define MISO0_0_INTTYPE_REG 		(* (reg8 *) MISO0__0__INTTYPE)
#endif /* (MISO0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MISO0_H */


/* [] END OF FILE */
