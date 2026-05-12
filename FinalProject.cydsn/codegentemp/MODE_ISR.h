/*******************************************************************************
* File Name: MODE_ISR.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_MODE_ISR_H)
#define CY_ISR_MODE_ISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void MODE_ISR_Start(void);
void MODE_ISR_StartEx(cyisraddress address);
void MODE_ISR_Stop(void);

CY_ISR_PROTO(MODE_ISR_Interrupt);

void MODE_ISR_SetVector(cyisraddress address);
cyisraddress MODE_ISR_GetVector(void);

void MODE_ISR_SetPriority(uint8 priority);
uint8 MODE_ISR_GetPriority(void);

void MODE_ISR_Enable(void);
uint8 MODE_ISR_GetState(void);
void MODE_ISR_Disable(void);

void MODE_ISR_SetPending(void);
void MODE_ISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the MODE_ISR ISR. */
#define MODE_ISR_INTC_VECTOR            ((reg32 *) MODE_ISR__INTC_VECT)

/* Address of the MODE_ISR ISR priority. */
#define MODE_ISR_INTC_PRIOR             ((reg8 *) MODE_ISR__INTC_PRIOR_REG)

/* Priority of the MODE_ISR interrupt. */
#define MODE_ISR_INTC_PRIOR_NUMBER      MODE_ISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable MODE_ISR interrupt. */
#define MODE_ISR_INTC_SET_EN            ((reg32 *) MODE_ISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the MODE_ISR interrupt. */
#define MODE_ISR_INTC_CLR_EN            ((reg32 *) MODE_ISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the MODE_ISR interrupt state to pending. */
#define MODE_ISR_INTC_SET_PD            ((reg32 *) MODE_ISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the MODE_ISR interrupt. */
#define MODE_ISR_INTC_CLR_PD            ((reg32 *) MODE_ISR__INTC_CLR_PD_REG)


#endif /* CY_ISR_MODE_ISR_H */


/* [] END OF FILE */
