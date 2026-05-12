/*******************************************************************************
* File Name: SPIM_4_PM.c
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

#include "SPIM_4_PVT.h"

static SPIM_4_BACKUP_STRUCT SPIM_4_backup =
{
    SPIM_4_DISABLED,
    SPIM_4_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPIM_4_SaveConfig
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
void SPIM_4_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_4_RestoreConfig
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
void SPIM_4_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPIM_4_Sleep
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
*  SPIM_4_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_4_Sleep(void) 
{
    /* Save components enable state */
    SPIM_4_backup.enableState = ((uint8) SPIM_4_IS_ENABLED);

    SPIM_4_Stop();
}


/*******************************************************************************
* Function Name: SPIM_4_Wakeup
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
*  SPIM_4_backup - used when non-retention registers are restored.
*  SPIM_4_txBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_4_txBufferRead - modified every function call - resets to
*  zero.
*  SPIM_4_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPIM_4_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPIM_4_Wakeup(void) 
{
    #if(SPIM_4_RX_SOFTWARE_BUF_ENABLED)
        SPIM_4_rxBufferFull  = 0u;
        SPIM_4_rxBufferRead  = 0u;
        SPIM_4_rxBufferWrite = 0u;
    #endif /* (SPIM_4_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPIM_4_TX_SOFTWARE_BUF_ENABLED)
        SPIM_4_txBufferFull  = 0u;
        SPIM_4_txBufferRead  = 0u;
        SPIM_4_txBufferWrite = 0u;
    #endif /* (SPIM_4_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPIM_4_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPIM_4_backup.enableState)
    {
        SPIM_4_Enable();
    }
}


/* [] END OF FILE */
