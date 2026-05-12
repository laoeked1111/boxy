/*******************************************************************************
* File Name: MOSI3.h  
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

#if !defined(CY_PINS_MOSI3_H) /* Pins MOSI3_H */
#define CY_PINS_MOSI3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOSI3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOSI3__PORT == 15 && ((MOSI3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MOSI3_Write(uint8 value);
void    MOSI3_SetDriveMode(uint8 mode);
uint8   MOSI3_ReadDataReg(void);
uint8   MOSI3_Read(void);
void    MOSI3_SetInterruptMode(uint16 position, uint16 mode);
uint8   MOSI3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MOSI3_SetDriveMode() function.
     *  @{
     */
        #define MOSI3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MOSI3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MOSI3_DM_RES_UP          PIN_DM_RES_UP
        #define MOSI3_DM_RES_DWN         PIN_DM_RES_DWN
        #define MOSI3_DM_OD_LO           PIN_DM_OD_LO
        #define MOSI3_DM_OD_HI           PIN_DM_OD_HI
        #define MOSI3_DM_STRONG          PIN_DM_STRONG
        #define MOSI3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MOSI3_MASK               MOSI3__MASK
#define MOSI3_SHIFT              MOSI3__SHIFT
#define MOSI3_WIDTH              1u

/* Interrupt constants */
#if defined(MOSI3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MOSI3_SetInterruptMode() function.
     *  @{
     */
        #define MOSI3_INTR_NONE      (uint16)(0x0000u)
        #define MOSI3_INTR_RISING    (uint16)(0x0001u)
        #define MOSI3_INTR_FALLING   (uint16)(0x0002u)
        #define MOSI3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MOSI3_INTR_MASK      (0x01u) 
#endif /* (MOSI3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOSI3_PS                     (* (reg8 *) MOSI3__PS)
/* Data Register */
#define MOSI3_DR                     (* (reg8 *) MOSI3__DR)
/* Port Number */
#define MOSI3_PRT_NUM                (* (reg8 *) MOSI3__PRT) 
/* Connect to Analog Globals */                                                  
#define MOSI3_AG                     (* (reg8 *) MOSI3__AG)                       
/* Analog MUX bux enable */
#define MOSI3_AMUX                   (* (reg8 *) MOSI3__AMUX) 
/* Bidirectional Enable */                                                        
#define MOSI3_BIE                    (* (reg8 *) MOSI3__BIE)
/* Bit-mask for Aliased Register Access */
#define MOSI3_BIT_MASK               (* (reg8 *) MOSI3__BIT_MASK)
/* Bypass Enable */
#define MOSI3_BYP                    (* (reg8 *) MOSI3__BYP)
/* Port wide control signals */                                                   
#define MOSI3_CTL                    (* (reg8 *) MOSI3__CTL)
/* Drive Modes */
#define MOSI3_DM0                    (* (reg8 *) MOSI3__DM0) 
#define MOSI3_DM1                    (* (reg8 *) MOSI3__DM1)
#define MOSI3_DM2                    (* (reg8 *) MOSI3__DM2) 
/* Input Buffer Disable Override */
#define MOSI3_INP_DIS                (* (reg8 *) MOSI3__INP_DIS)
/* LCD Common or Segment Drive */
#define MOSI3_LCD_COM_SEG            (* (reg8 *) MOSI3__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOSI3_LCD_EN                 (* (reg8 *) MOSI3__LCD_EN)
/* Slew Rate Control */
#define MOSI3_SLW                    (* (reg8 *) MOSI3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOSI3_PRTDSI__CAPS_SEL       (* (reg8 *) MOSI3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOSI3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOSI3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOSI3_PRTDSI__OE_SEL0        (* (reg8 *) MOSI3__PRTDSI__OE_SEL0) 
#define MOSI3_PRTDSI__OE_SEL1        (* (reg8 *) MOSI3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOSI3_PRTDSI__OUT_SEL0       (* (reg8 *) MOSI3__PRTDSI__OUT_SEL0) 
#define MOSI3_PRTDSI__OUT_SEL1       (* (reg8 *) MOSI3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOSI3_PRTDSI__SYNC_OUT       (* (reg8 *) MOSI3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MOSI3__SIO_CFG)
    #define MOSI3_SIO_HYST_EN        (* (reg8 *) MOSI3__SIO_HYST_EN)
    #define MOSI3_SIO_REG_HIFREQ     (* (reg8 *) MOSI3__SIO_REG_HIFREQ)
    #define MOSI3_SIO_CFG            (* (reg8 *) MOSI3__SIO_CFG)
    #define MOSI3_SIO_DIFF           (* (reg8 *) MOSI3__SIO_DIFF)
#endif /* (MOSI3__SIO_CFG) */

/* Interrupt Registers */
#if defined(MOSI3__INTSTAT)
    #define MOSI3_INTSTAT            (* (reg8 *) MOSI3__INTSTAT)
    #define MOSI3_SNAP               (* (reg8 *) MOSI3__SNAP)
    
	#define MOSI3_0_INTTYPE_REG 		(* (reg8 *) MOSI3__0__INTTYPE)
#endif /* (MOSI3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOSI3_H */


/* [] END OF FILE */
