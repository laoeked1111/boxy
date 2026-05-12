/*******************************************************************************
* File Name: SPIM_0_PM.c
* Version 2.50
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIM_0_PVT.h"

static SPIM_0_BACKUP_STRUCT SPIM_0_backup =
{
    SPIM_0_DISABLED,
    SPIM_0_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIM_0_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIM_0_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_0_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPIM_0_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_0_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIM_0_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_0_Sleep(void) 
{
    /* Save components enable state */
    SPIM_0_backup.enableState = ((uint8) SPIM_0_IS_ENABLED);

    SPIM_0_Stop();
}


/*******************************************************************************
* Function Name: SPIM_0_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPIM_0_backup - used when non-retention registers are restored.
*  SPIM_0_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_0_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_0_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_0_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_0_Wakeup(void) 
{
    #if(SPIM_0_RX_SOFTWARE_BUF_ENABLED)
        SPIM_0_rxBufferFull  = 0u;
        SPIM_0_rxBufferRead  = 0u;
        SPIM_0_rxBufferWrite = 0u;
    #endif /* (SPIM_0_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_0_TX_SOFTWARE_BUF_ENABLED)
        SPIM_0_txBufferFull  = 0u;
        SPIM_0_txBufferRead  = 0u;
        SPIM_0_txBufferWrite = 0u;
    #endif /* (SPIM_0_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_0_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_0_backup.enableState)
    {
        SPIM_0_Enable();
    }
}


/* [] END OF FILE */
