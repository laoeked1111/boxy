
#include <project.h>

// general DMA parameters
#define BUF_SIZE (2 * 320)

// buffers and status for DMA 0
extern uint8 bufferA_0[BUF_SIZE];
extern uint8 bufferB_0[BUF_SIZE];
extern volatile uint8 isDmaBusy_0;

// buffers and status for DMA 1
extern uint8 bufferA_1[BUF_SIZE];
extern uint8 bufferB_1[BUF_SIZE];
extern volatile uint8 isDmaBusy_1;

// buffers and status for DMA 2
extern uint8 bufferA_2[BUF_SIZE];
extern uint8 bufferB_2[BUF_SIZE];
extern volatile uint8 isDmaBusy_2;

// buffers and status for DMA 3
extern uint8 bufferA_3[BUF_SIZE];
extern uint8 bufferB_3[BUF_SIZE];
extern volatile uint8 isDmaBusy_3;

// functions for using DMAs
void Init_DMA_SPI(uint8 disp);
void DMA_Feed_SPI_Async(uint8 disp, uint8 *pData, uint16 length);
void DMA_Wait_For_Completion(uint8 disp);
