/*******************************************************************************
* File Name: .h
* Version 2.50
*
* Description:
*  This private header file contains internal definitions for the SPIM
*  component. Do not use these definitions directly in your application.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SPIM_PVT_SPIM_4_H)
#define CY_SPIM_PVT_SPIM_4_H

#include "SPIM_4.h"


/**********************************
*   Functions with external linkage
**********************************/


/**********************************
*   Variables with external linkage
**********************************/

extern volatile uint8 SPIM_4_swStatusTx;
extern volatile uint8 SPIM_4_swStatusRx;

#if(SPIM_4_TX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_4_txBuffer[SPIM_4_TX_BUFFER_SIZE];
    extern volatile uint8 SPIM_4_txBufferRead;
    extern volatile uint8 SPIM_4_txBufferWrite;
    extern volatile uint8 SPIM_4_txBufferFull;
#endif /* (SPIM_4_TX_SOFTWARE_BUF_ENABLED) */

#if(SPIM_4_RX_SOFTWARE_BUF_ENABLED)
    extern volatile uint8 SPIM_4_rxBuffer[SPIM_4_RX_BUFFER_SIZE];
    extern volatile uint8 SPIM_4_rxBufferRead;
    extern volatile uint8 SPIM_4_rxBufferWrite;
    extern volatile uint8 SPIM_4_rxBufferFull;
#endif /* (SPIM_4_RX_SOFTWARE_BUF_ENABLED) */

#endif /* CY_SPIM_PVT_SPIM_4_H */


/* [] END OF FILE */
