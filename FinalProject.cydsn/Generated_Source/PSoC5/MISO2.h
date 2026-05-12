/*******************************************************************************
* File Name: MISO2.h  
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

#if !defined(CY_PINS_MISO2_H) /* Pins MISO2_H */
#define CY_PINS_MISO2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MISO2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MISO2__PORT == 15 && ((MISO2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MISO2_Write(uint8 value);
void    MISO2_SetDriveMode(uint8 mode);
uint8   MISO2_ReadDataReg(void);
uint8   MISO2_Read(void);
void    MISO2_SetInterruptMode(uint16 position, uint16 mode);
uint8   MISO2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MISO2_SetDriveMode() function.
     *  @{
     */
        #define MISO2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MISO2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MISO2_DM_RES_UP          PIN_DM_RES_UP
        #define MISO2_DM_RES_DWN         PIN_DM_RES_DWN
        #define MISO2_DM_OD_LO           PIN_DM_OD_LO
        #define MISO2_DM_OD_HI           PIN_DM_OD_HI
        #define MISO2_DM_STRONG          PIN_DM_STRONG
        #define MISO2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MISO2_MASK               MISO2__MASK
#define MISO2_SHIFT              MISO2__SHIFT
#define MISO2_WIDTH              1u

/* Interrupt constants */
#if defined(MISO2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MISO2_SetInterruptMode() function.
     *  @{
     */
        #define MISO2_INTR_NONE      (uint16)(0x0000u)
        #define MISO2_INTR_RISING    (uint16)(0x0001u)
        #define MISO2_INTR_FALLING   (uint16)(0x0002u)
        #define MISO2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MISO2_INTR_MASK      (0x01u) 
#endif /* (MISO2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MISO2_PS                     (* (reg8 *) MISO2__PS)
/* Data Register */
#define MISO2_DR                     (* (reg8 *) MISO2__DR)
/* Port Number */
#define MISO2_PRT_NUM                (* (reg8 *) MISO2__PRT) 
/* Connect to Analog Globals */                                                  
#define MISO2_AG                     (* (reg8 *) MISO2__AG)                       
/* Analog MUX bux enable */
#define MISO2_AMUX                   (* (reg8 *) MISO2__AMUX) 
/* Bidirectional Enable */                                                        
#define MISO2_BIE                    (* (reg8 *) MISO2__BIE)
/* Bit-mask for Aliased Register Access */
#define MISO2_BIT_MASK               (* (reg8 *) MISO2__BIT_MASK)
/* Bypass Enable */
#define MISO2_BYP                    (* (reg8 *) MISO2__BYP)
/* Port wide control signals */                                                   
#define MISO2_CTL                    (* (reg8 *) MISO2__CTL)
/* Drive Modes */
#define MISO2_DM0                    (* (reg8 *) MISO2__DM0) 
#define MISO2_DM1                    (* (reg8 *) MISO2__DM1)
#define MISO2_DM2                    (* (reg8 *) MISO2__DM2) 
/* Input Buffer Disable Override */
#define MISO2_INP_DIS                (* (reg8 *) MISO2__INP_DIS)
/* LCD Common or Segment Drive */
#define MISO2_LCD_COM_SEG            (* (reg8 *) MISO2__LCD_COM_SEG)
/* Enable Segment LCD */
#define MISO2_LCD_EN                 (* (reg8 *) MISO2__LCD_EN)
/* Slew Rate Control */
#define MISO2_SLW                    (* (reg8 *) MISO2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MISO2_PRTDSI__CAPS_SEL       (* (reg8 *) MISO2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MISO2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MISO2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MISO2_PRTDSI__OE_SEL0        (* (reg8 *) MISO2__PRTDSI__OE_SEL0) 
#define MISO2_PRTDSI__OE_SEL1        (* (reg8 *) MISO2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MISO2_PRTDSI__OUT_SEL0       (* (reg8 *) MISO2__PRTDSI__OUT_SEL0) 
#define MISO2_PRTDSI__OUT_SEL1       (* (reg8 *) MISO2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MISO2_PRTDSI__SYNC_OUT       (* (reg8 *) MISO2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MISO2__SIO_CFG)
    #define MISO2_SIO_HYST_EN        (* (reg8 *) MISO2__SIO_HYST_EN)
    #define MISO2_SIO_REG_HIFREQ     (* (reg8 *) MISO2__SIO_REG_HIFREQ)
    #define MISO2_SIO_CFG            (* (reg8 *) MISO2__SIO_CFG)
    #define MISO2_SIO_DIFF           (* (reg8 *) MISO2__SIO_DIFF)
#endif /* (MISO2__SIO_CFG) */

/* Interrupt Registers */
#if defined(MISO2__INTSTAT)
    #define MISO2_INTSTAT            (* (reg8 *) MISO2__INTSTAT)
    #define MISO2_SNAP               (* (reg8 *) MISO2__SNAP)
    
	#define MISO2_0_INTTYPE_REG 		(* (reg8 *) MISO2__0__INTTYPE)
#endif /* (MISO2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MISO2_H */


/* [] END OF FILE */
