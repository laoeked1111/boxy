/*******************************************************************************
* File Name: MISO3.h  
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

#if !defined(CY_PINS_MISO3_H) /* Pins MISO3_H */
#define CY_PINS_MISO3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MISO3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MISO3__PORT == 15 && ((MISO3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MISO3_Write(uint8 value);
void    MISO3_SetDriveMode(uint8 mode);
uint8   MISO3_ReadDataReg(void);
uint8   MISO3_Read(void);
void    MISO3_SetInterruptMode(uint16 position, uint16 mode);
uint8   MISO3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MISO3_SetDriveMode() function.
     *  @{
     */
        #define MISO3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MISO3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MISO3_DM_RES_UP          PIN_DM_RES_UP
        #define MISO3_DM_RES_DWN         PIN_DM_RES_DWN
        #define MISO3_DM_OD_LO           PIN_DM_OD_LO
        #define MISO3_DM_OD_HI           PIN_DM_OD_HI
        #define MISO3_DM_STRONG          PIN_DM_STRONG
        #define MISO3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MISO3_MASK               MISO3__MASK
#define MISO3_SHIFT              MISO3__SHIFT
#define MISO3_WIDTH              1u

/* Interrupt constants */
#if defined(MISO3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MISO3_SetInterruptMode() function.
     *  @{
     */
        #define MISO3_INTR_NONE      (uint16)(0x0000u)
        #define MISO3_INTR_RISING    (uint16)(0x0001u)
        #define MISO3_INTR_FALLING   (uint16)(0x0002u)
        #define MISO3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MISO3_INTR_MASK      (0x01u) 
#endif /* (MISO3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MISO3_PS                     (* (reg8 *) MISO3__PS)
/* Data Register */
#define MISO3_DR                     (* (reg8 *) MISO3__DR)
/* Port Number */
#define MISO3_PRT_NUM                (* (reg8 *) MISO3__PRT) 
/* Connect to Analog Globals */                                                  
#define MISO3_AG                     (* (reg8 *) MISO3__AG)                       
/* Analog MUX bux enable */
#define MISO3_AMUX                   (* (reg8 *) MISO3__AMUX) 
/* Bidirectional Enable */                                                        
#define MISO3_BIE                    (* (reg8 *) MISO3__BIE)
/* Bit-mask for Aliased Register Access */
#define MISO3_BIT_MASK               (* (reg8 *) MISO3__BIT_MASK)
/* Bypass Enable */
#define MISO3_BYP                    (* (reg8 *) MISO3__BYP)
/* Port wide control signals */                                                   
#define MISO3_CTL                    (* (reg8 *) MISO3__CTL)
/* Drive Modes */
#define MISO3_DM0                    (* (reg8 *) MISO3__DM0) 
#define MISO3_DM1                    (* (reg8 *) MISO3__DM1)
#define MISO3_DM2                    (* (reg8 *) MISO3__DM2) 
/* Input Buffer Disable Override */
#define MISO3_INP_DIS                (* (reg8 *) MISO3__INP_DIS)
/* LCD Common or Segment Drive */
#define MISO3_LCD_COM_SEG            (* (reg8 *) MISO3__LCD_COM_SEG)
/* Enable Segment LCD */
#define MISO3_LCD_EN                 (* (reg8 *) MISO3__LCD_EN)
/* Slew Rate Control */
#define MISO3_SLW                    (* (reg8 *) MISO3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MISO3_PRTDSI__CAPS_SEL       (* (reg8 *) MISO3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MISO3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MISO3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MISO3_PRTDSI__OE_SEL0        (* (reg8 *) MISO3__PRTDSI__OE_SEL0) 
#define MISO3_PRTDSI__OE_SEL1        (* (reg8 *) MISO3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MISO3_PRTDSI__OUT_SEL0       (* (reg8 *) MISO3__PRTDSI__OUT_SEL0) 
#define MISO3_PRTDSI__OUT_SEL1       (* (reg8 *) MISO3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MISO3_PRTDSI__SYNC_OUT       (* (reg8 *) MISO3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MISO3__SIO_CFG)
    #define MISO3_SIO_HYST_EN        (* (reg8 *) MISO3__SIO_HYST_EN)
    #define MISO3_SIO_REG_HIFREQ     (* (reg8 *) MISO3__SIO_REG_HIFREQ)
    #define MISO3_SIO_CFG            (* (reg8 *) MISO3__SIO_CFG)
    #define MISO3_SIO_DIFF           (* (reg8 *) MISO3__SIO_DIFF)
#endif /* (MISO3__SIO_CFG) */

/* Interrupt Registers */
#if defined(MISO3__INTSTAT)
    #define MISO3_INTSTAT            (* (reg8 *) MISO3__INTSTAT)
    #define MISO3_SNAP               (* (reg8 *) MISO3__SNAP)
    
	#define MISO3_0_INTTYPE_REG 		(* (reg8 *) MISO3__0__INTTYPE)
#endif /* (MISO3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MISO3_H */


/* [] END OF FILE */
