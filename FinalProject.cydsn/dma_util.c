
#include <project.h>
#include "dma_util.h"

//==============================================================
// Setup
//==============================================================

// declare the DMA channels and TDs
static uint8 DMA_Chan_0;
static uint8 DMA_TD_0;
static uint8 DMA_Chan_1;
static uint8 DMA_TD_1;
static uint8 DMA_Chan_2;
static uint8 DMA_TD_2;
static uint8 DMA_Chan_3;
static uint8 DMA_TD_3;

// declare DMA interrupt service routines
CY_ISR_PROTO(DMA_0_Complete_Handler);
CY_ISR_PROTO(DMA_1_Complete_Handler);
CY_ISR_PROTO(DMA_2_Complete_Handler);
CY_ISR_PROTO(DMA_3_Complete_Handler);

// define DMA ping-pong buffers (extern-declared in dma_util.h)
uint8 bufferA_0[BUF_SIZE];
uint8 bufferB_0[BUF_SIZE];
uint8 bufferA_1[BUF_SIZE];
uint8 bufferB_1[BUF_SIZE];
uint8 bufferA_2[BUF_SIZE];
uint8 bufferB_2[BUF_SIZE];
uint8 bufferA_3[BUF_SIZE];
uint8 bufferB_3[BUF_SIZE];

// define DMA busy flags (extern-declared in dma_util.h)
volatile uint8 isDmaBusy_0 = 0;
volatile uint8 isDmaBusy_1 = 0;
volatile uint8 isDmaBusy_2 = 0;
volatile uint8 isDmaBusy_3 = 0;

// define interrupt service routines
CY_ISR(DMA_0_Complete_Handler)
{
    isDmaBusy_0 = 0; 
}

CY_ISR(DMA_1_Complete_Handler)
{
    isDmaBusy_1 = 0; 
}

CY_ISR(DMA_2_Complete_Handler)
{
    isDmaBusy_2 = 0; 
}

CY_ISR(DMA_3_Complete_Handler)
{
    isDmaBusy_3 = 0; 
}



//==============================================================
// Init_DMA_SPI
// initialize DMA for talking to SPI
//==============================================================
void Init_DMA_SPI(uint8 disp)
{
    switch (disp) 
    {
        case 0:
            DMA_Chan_0 = DMA_0_DmaInitialize(1, 1, HI16(CYDEV_SRAM_BASE), HI16(CYDEV_PERIPH_BASE));
            DMA_TD_0 = CyDmaTdAllocate();
            CyDmaTdSetConfiguration(DMA_TD_0,
                1,
                CY_DMA_DISABLE_TD, 
                CY_DMA_TD_INC_SRC_ADR | DMA_0__TD_TERMOUT_EN);
            CyDmaTdSetAddress(DMA_TD_0, 0, LO16((uint32)SPIM_0_TXDATA_PTR));
            DMA_Complete_ISR_0_StartEx(DMA_0_Complete_Handler);
            break;
        case 1:
            DMA_Chan_1 = DMA_1_DmaInitialize(1, 1, HI16(CYDEV_SRAM_BASE), HI16(CYDEV_PERIPH_BASE));
            DMA_TD_1 = CyDmaTdAllocate();
            CyDmaTdSetConfiguration(DMA_TD_1, 
                1,
                CY_DMA_DISABLE_TD, 
                CY_DMA_TD_INC_SRC_ADR | DMA_1__TD_TERMOUT_EN);
            CyDmaTdSetAddress(DMA_TD_1, 0, LO16((uint32)SPIM_1_TXDATA_PTR));
            DMA_Complete_ISR_1_StartEx(DMA_1_Complete_Handler);
            break;
        case 2:
            DMA_Chan_2 = DMA_2_DmaInitialize(1, 1, HI16(CYDEV_SRAM_BASE), HI16(CYDEV_PERIPH_BASE));
            DMA_TD_2 = CyDmaTdAllocate();
            CyDmaTdSetConfiguration(DMA_TD_2,
                1,
                CY_DMA_DISABLE_TD, 
                CY_DMA_TD_INC_SRC_ADR | DMA_2__TD_TERMOUT_EN);
            CyDmaTdSetAddress(DMA_TD_2, 0, LO16((uint32)SPIM_2_TXDATA_PTR));
            DMA_Complete_ISR_2_StartEx(DMA_2_Complete_Handler);
            break;
        case 3:
            DMA_Chan_3 = DMA_3_DmaInitialize(1, 1, HI16(CYDEV_SRAM_BASE), HI16(CYDEV_PERIPH_BASE));
            DMA_TD_3 = CyDmaTdAllocate();
            CyDmaTdSetConfiguration(DMA_TD_3, 
                1,
                CY_DMA_DISABLE_TD, 
                CY_DMA_TD_INC_SRC_ADR | DMA_3__TD_TERMOUT_EN);
            CyDmaTdSetAddress(DMA_TD_3, 0, LO16((uint32)SPIM_3_TXDATA_PTR));
            DMA_Complete_ISR_3_StartEx(DMA_3_Complete_Handler);
            break;
    }
}


//==============================================================
// DMA_Feed_SPI_Async
// feed data into DMA to load into SPI
//==============================================================
void DMA_Feed_SPI_Async(uint8 disp, uint8 *pData, uint16 length)
{
    switch (disp)
    {
        case 0:
            isDmaBusy_0 = 1;
            CyDmaTdSetConfiguration(DMA_TD_0, length, CY_DMA_DISABLE_TD, 
                CY_DMA_TD_INC_SRC_ADR | DMA_0__TD_TERMOUT_EN);
            CyDmaTdSetAddress(DMA_TD_0, LO16((uint32)pData), LO16((uint32)SPIM_0_TXDATA_PTR));
            CyDmaChSetInitialTd(DMA_Chan_0, DMA_TD_0);
            CyDmaChEnable(DMA_Chan_0, 1);
            break;
        case 1:
            isDmaBusy_1 = 1;
            CyDmaTdSetConfiguration(DMA_TD_1, length, CY_DMA_DISABLE_TD, 
                CY_DMA_TD_INC_SRC_ADR | DMA_1__TD_TERMOUT_EN);
            CyDmaTdSetAddress(DMA_TD_1, LO16((uint32)pData), LO16((uint32)SPIM_1_TXDATA_PTR));
            CyDmaChSetInitialTd(DMA_Chan_1, DMA_TD_1);
            CyDmaChEnable(DMA_Chan_1, 1);
            break;
        case 2:
            isDmaBusy_2 = 1;
            CyDmaTdSetConfiguration(DMA_TD_2, length, CY_DMA_DISABLE_TD, 
                CY_DMA_TD_INC_SRC_ADR | DMA_2__TD_TERMOUT_EN);
            CyDmaTdSetAddress(DMA_TD_2, LO16((uint32)pData), LO16((uint32)SPIM_2_TXDATA_PTR));
            CyDmaChSetInitialTd(DMA_Chan_2, DMA_TD_2);
            CyDmaChEnable(DMA_Chan_2, 1);
            break;
        case 3:
            isDmaBusy_3 = 1;
            CyDmaTdSetConfiguration(DMA_TD_3, length, CY_DMA_DISABLE_TD, 
                CY_DMA_TD_INC_SRC_ADR | DMA_3__TD_TERMOUT_EN);
            CyDmaTdSetAddress(DMA_TD_3, LO16((uint32)pData), LO16((uint32)SPIM_3_TXDATA_PTR));
            CyDmaChSetInitialTd(DMA_Chan_3, DMA_TD_3);
            CyDmaChEnable(DMA_Chan_3, 1);
            break;
    }
}


//==============================================================
// DMA_Wait_For_Completion
// blocking DMA delay
//==============================================================
void DMA_Wait_For_Completion(uint8 disp) {
    uint8 currentTd = 0;
    uint8 state = 0;
    
    switch (disp)
    {
        case 0:
            if (isDmaBusy_0 == 0) return;
            do {
                CyDmaChStatus(DMA_Chan_0, &currentTd, &state);
            } while ((state & (CY_DMA_STATUS_TD_ACTIVE | CY_DMA_STATUS_CHAIN_ACTIVE)) != 0);
            isDmaBusy_0 = 0;
            break;
        case 1:
            if (isDmaBusy_1 == 0) return;
            do {
                CyDmaChStatus(DMA_Chan_1, &currentTd, &state);
            } while ((state & (CY_DMA_STATUS_TD_ACTIVE | CY_DMA_STATUS_CHAIN_ACTIVE)) != 0);
            isDmaBusy_1 = 0;
            break;
        case 2:
            if (isDmaBusy_2 == 0) return;
            do {
                CyDmaChStatus(DMA_Chan_2, &currentTd, &state);
            } while ((state & (CY_DMA_STATUS_TD_ACTIVE | CY_DMA_STATUS_CHAIN_ACTIVE)) != 0);
            isDmaBusy_2 = 0;
            break;
        case 3:
            if (isDmaBusy_3 == 0) return;
            do {
                CyDmaChStatus(DMA_Chan_3, &currentTd, &state);
            } while ((state & (CY_DMA_STATUS_TD_ACTIVE | CY_DMA_STATUS_CHAIN_ACTIVE)) != 0);
            isDmaBusy_3 = 0;
            break;
    }
}
