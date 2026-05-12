/*******************************************************************************
* File Name: DC4.h  
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

#if !defined(CY_PINS_DC4_H) /* Pins DC4_H */
#define CY_PINS_DC4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DC4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DC4__PORT == 15 && ((DC4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DC4_Write(uint8 value);
void    DC4_SetDriveMode(uint8 mode);
uint8   DC4_ReadDataReg(void);
uint8   DC4_Read(void);
void    DC4_SetInterruptMode(uint16 position, uint16 mode);
uint8   DC4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DC4_SetDriveMode() function.
     *  @{
     */
        #define DC4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DC4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DC4_DM_RES_UP          PIN_DM_RES_UP
        #define DC4_DM_RES_DWN         PIN_DM_RES_DWN
        #define DC4_DM_OD_LO           PIN_DM_OD_LO
        #define DC4_DM_OD_HI           PIN_DM_OD_HI
        #define DC4_DM_STRONG          PIN_DM_STRONG
        #define DC4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DC4_MASK               DC4__MASK
#define DC4_SHIFT              DC4__SHIFT
#define DC4_WIDTH              1u

/* Interrupt constants */
#if defined(DC4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DC4_SetInterruptMode() function.
     *  @{
     */
        #define DC4_INTR_NONE      (uint16)(0x0000u)
        #define DC4_INTR_RISING    (uint16)(0x0001u)
        #define DC4_INTR_FALLING   (uint16)(0x0002u)
        #define DC4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DC4_INTR_MASK      (0x01u) 
#endif /* (DC4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DC4_PS                     (* (reg8 *) DC4__PS)
/* Data Register */
#define DC4_DR                     (* (reg8 *) DC4__DR)
/* Port Number */
#define DC4_PRT_NUM                (* (reg8 *) DC4__PRT) 
/* Connect to Analog Globals */                                                  
#define DC4_AG                     (* (reg8 *) DC4__AG)                       
/* Analog MUX bux enable */
#define DC4_AMUX                   (* (reg8 *) DC4__AMUX) 
/* Bidirectional Enable */                                                        
#define DC4_BIE                    (* (reg8 *) DC4__BIE)
/* Bit-mask for Aliased Register Access */
#define DC4_BIT_MASK               (* (reg8 *) DC4__BIT_MASK)
/* Bypass Enable */
#define DC4_BYP                    (* (reg8 *) DC4__BYP)
/* Port wide control signals */                                                   
#define DC4_CTL                    (* (reg8 *) DC4__CTL)
/* Drive Modes */
#define DC4_DM0                    (* (reg8 *) DC4__DM0) 
#define DC4_DM1                    (* (reg8 *) DC4__DM1)
#define DC4_DM2                    (* (reg8 *) DC4__DM2) 
/* Input Buffer Disable Override */
#define DC4_INP_DIS                (* (reg8 *) DC4__INP_DIS)
/* LCD Common or Segment Drive */
#define DC4_LCD_COM_SEG            (* (reg8 *) DC4__LCD_COM_SEG)
/* Enable Segment LCD */
#define DC4_LCD_EN                 (* (reg8 *) DC4__LCD_EN)
/* Slew Rate Control */
#define DC4_SLW                    (* (reg8 *) DC4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DC4_PRTDSI__CAPS_SEL       (* (reg8 *) DC4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DC4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DC4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DC4_PRTDSI__OE_SEL0        (* (reg8 *) DC4__PRTDSI__OE_SEL0) 
#define DC4_PRTDSI__OE_SEL1        (* (reg8 *) DC4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DC4_PRTDSI__OUT_SEL0       (* (reg8 *) DC4__PRTDSI__OUT_SEL0) 
#define DC4_PRTDSI__OUT_SEL1       (* (reg8 *) DC4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DC4_PRTDSI__SYNC_OUT       (* (reg8 *) DC4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DC4__SIO_CFG)
    #define DC4_SIO_HYST_EN        (* (reg8 *) DC4__SIO_HYST_EN)
    #define DC4_SIO_REG_HIFREQ     (* (reg8 *) DC4__SIO_REG_HIFREQ)
    #define DC4_SIO_CFG            (* (reg8 *) DC4__SIO_CFG)
    #define DC4_SIO_DIFF           (* (reg8 *) DC4__SIO_DIFF)
#endif /* (DC4__SIO_CFG) */

/* Interrupt Registers */
#if defined(DC4__INTSTAT)
    #define DC4_INTSTAT            (* (reg8 *) DC4__INTSTAT)
    #define DC4_SNAP               (* (reg8 *) DC4__SNAP)
    
	#define DC4_0_INTTYPE_REG 		(* (reg8 *) DC4__0__INTTYPE)
#endif /* (DC4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DC4_H */


/* [] END OF FILE */
