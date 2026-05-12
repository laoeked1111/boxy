#include <project.h>
#include <stdlib.h>
#include "tft.h"
#include "rotate_liquid.h"
#include "trig.h"
#include "dma_util.h"

//==============================================================
// adcToAngle
// convert a 16 bit ADC measurement to an angle from 0 to 360 (degrees)
//==============================================================
uint16_t adcToAngle(uint16_t adcVal)
{
    return (uint16_t) ((((uint32_t) adcVal) * 360UL) >> 16);
}


//==============================================================
// screenAtan
// convert a difference in fracFull on two screens into the angle 
// for the screens on the sides 
//==============================================================

const uint16_t atan_lut[] = {
    323, 323, 324, 324, 324, 324, 324, 325, 325, 325, 325, 326, 326, 326, 326, 326,
    327, 327, 327, 327, 328, 328, 328, 328, 329, 329, 329, 329, 330, 330, 330, 330,
    331, 331, 331, 331, 332, 332, 332, 332, 333, 333, 333, 334, 334, 334, 334, 335,
    335, 335, 335, 336, 336, 336, 337, 337, 337, 337, 338, 338, 338, 339, 339, 339,
    339, 340, 340, 340, 341, 341, 341, 342, 342, 342, 342, 343, 343, 343, 344, 344,
    344, 345, 345, 345, 346, 346, 346, 346, 347, 347, 347, 348, 348, 348, 349, 349,
    349, 350, 350, 350, 351, 351, 351, 352, 352, 352, 353, 353, 353, 354, 354, 354,
    355, 355, 355, 356, 356, 356, 357, 357, 357, 358, 358, 358, 359, 359, 359, 0,
    0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9,
    9, 9, 10, 10, 10, 11, 11, 11, 12, 12, 12, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15,
    16, 16, 16, 17, 17, 17, 18, 18, 18, 18, 19, 19, 19, 20, 20, 20, 21, 21, 21, 21, 22,
    22, 22, 23, 23, 23, 23, 24, 24, 24, 25, 25, 25, 25, 26, 26, 26, 26, 27, 27, 27, 28,
    28, 28, 28, 29, 29, 29, 29, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 32, 33, 33,
    33, 33, 34, 34, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 36, 36, 37
};

uint16_t screenAtan(uint8_t fracFull_left) {
    return atan_lut[fracFull_left];
}


//==============================================================
// drawLiquid
// draw the liquid which can move around in the cup
//==============================================================
void drawLiquid(uint8_t *fracFull, uint16_t *angles)
{
    int32_t sinV[NUM_SCREENS], cosV[NUM_SCREENS];
    int32_t fillRow[NUM_SCREENS];
    int liquidLeft[NUM_SCREENS];
    int disp;

    for (disp = 0; disp < NUM_SCREENS; disp++) {
        
        // determine the orientation of the liquid on each screen
        sinV[disp] = getSinQ15(angles[disp]);
        cosV[disp] = getCosQ15(angles[disp]);
        liquidLeft[disp] = (sinV[disp] > 0);
        
        fillRow[disp] = (int32_t)SCREEN_HEIGHT - (((int32_t)fracFull[disp] * SCREEN_HEIGHT) >> 8);
        
        setRowCol(disp, 0, SCREEN_WIDTH - 1, 0, SCREEN_HEIGHT - 1);     // set drawing window to full screen on all screens
        write8_a0(disp, 0x2C);                                          // prepare to send data to each pixel on the screens
    }

    // set each screen to receive data
    DC0_Write(1u);
    DC1_Write(1u);
    DC2_Write(1u);
    DC3_Write(1u);

    // ping pong pointers for DMA buffers
    uint8_t *fillBuf_0 = bufferA_0, *sendBuf_0 = bufferB_0;
    uint8_t *fillBuf_1 = bufferA_1, *sendBuf_1 = bufferB_1;
    uint8_t *fillBuf_2 = bufferA_2, *sendBuf_2 = bufferB_2;
    uint8_t *fillBuf_3 = bufferA_3, *sendBuf_3 = bufferB_3;
    
    uint8_t *tmp;
    int i, y;

    
    // write one line to each of the screens at a time, then write the next line
    for (y = 0; y < SCREEN_HEIGHT; y++) {

        int32_t x_bound;
        uint8_t leftHi, leftLo, rightHi, rightLo;

        // ================== Display 0 ==================
        if (sinV[0] == 0) {
            int isLiq = (cosV[0] < 0) ? (y >= fillRow[0]) : (y < (SCREEN_HEIGHT - fillRow[0]));
            x_bound = isLiq ? 0 : SCREEN_WIDTH;
        } else {
            int32_t dY2 = 2 * y - SCREEN_HEIGHT;
            x_bound = (SCREEN_WIDTH * sinV[0] + dY2 * cosV[0]) / (2 * sinV[0]);
            if (x_bound < 0) x_bound = 0;
            if (x_bound > SCREEN_WIDTH) x_bound = SCREEN_WIDTH;
        }
        if (liquidLeft[0]) { leftHi=0xFF; leftLo=0xFF; rightHi=0x00; rightLo=0x00; }
        else               { leftHi=0x00; leftLo=0x00; rightHi=0xFF; rightLo=0xFF; }

        DMA_Wait_For_Completion(0);
        for (i = 0; i < x_bound; i++)
            { fillBuf_0[i*2]=leftHi; fillBuf_0[i*2+1]=leftLo; }
        for (i = x_bound; i < SCREEN_WIDTH; i++)
            { fillBuf_0[i*2]=rightHi; fillBuf_0[i*2+1]=rightLo; }

        DMA_Feed_SPI_Async(0, fillBuf_0, (uint16)(SCREEN_WIDTH * 2));
        tmp=fillBuf_0; fillBuf_0=sendBuf_0; sendBuf_0=tmp;

        
        // ================== Display 1 ==================
        if (sinV[1] == 0) {
            int isLiq = (cosV[1] < 0) ? (y >= fillRow[1]) : (y < (SCREEN_HEIGHT - fillRow[1]));
            x_bound = isLiq ? 0 : SCREEN_WIDTH;
        } else {
            int32_t dY2 = 2 * y - SCREEN_HEIGHT;
            x_bound = (SCREEN_WIDTH * sinV[1] + dY2 * cosV[1]) / (2 * sinV[1]);
            if (x_bound < 0) x_bound = 0;
            if (x_bound > SCREEN_WIDTH) x_bound = SCREEN_WIDTH;
        }
        if (liquidLeft[1]) { leftHi=0xFF; leftLo=0xFF; rightHi=0x00; rightLo=0x00; }
        else               { leftHi=0x00; leftLo=0x00; rightHi=0xFF; rightLo=0xFF; }

        DMA_Wait_For_Completion(1);
        for (i = 0; i < x_bound; i++)
            { fillBuf_1[i*2]=leftHi; fillBuf_1[i*2+1]=leftLo; }
        for (i = x_bound; i < SCREEN_WIDTH; i++)
            { fillBuf_1[i*2]=rightHi; fillBuf_1[i*2+1]=rightLo; }

        DMA_Feed_SPI_Async(1, fillBuf_1, (uint16)(SCREEN_WIDTH * 2));
        tmp=fillBuf_1; fillBuf_1=sendBuf_1; sendBuf_1=tmp;

        
        // ================== Display 2 ==================
        if (sinV[2] == 0) {
            int isLiq = (cosV[2] < 0) ? (y >= fillRow[2]) : (y < (SCREEN_HEIGHT - fillRow[2]));
            x_bound = isLiq ? 0 : SCREEN_WIDTH;
        } else {
            int32_t dY2 = 2 * y - SCREEN_HEIGHT;
            x_bound = (SCREEN_WIDTH * sinV[2] + dY2 * cosV[2]) / (2 * sinV[2]);
            if (x_bound < 0) x_bound = 0;
            if (x_bound > SCREEN_WIDTH) x_bound = SCREEN_WIDTH;
        }
        if (liquidLeft[2]) { leftHi=0xFF; leftLo=0xFF; rightHi=0x00; rightLo=0x00; }
        else               { leftHi=0x00; leftLo=0x00; rightHi=0xFF; rightLo=0xFF; }

        DMA_Wait_For_Completion(2);
        for (i = 0; i < x_bound; i++)
            { fillBuf_2[i*2]=leftHi; fillBuf_2[i*2+1]=leftLo; }
        for (i = x_bound; i < SCREEN_WIDTH; i++)
            { fillBuf_2[i*2]=rightHi; fillBuf_2[i*2+1]=rightLo; }

        DMA_Feed_SPI_Async(2, fillBuf_2, (uint16)(SCREEN_WIDTH * 2));
        tmp=fillBuf_2; fillBuf_2=sendBuf_2; sendBuf_2=tmp;

        
        // ================== Display 3 ==================
        if (sinV[3] == 0) {
            int isLiq = (cosV[3] < 0) ? (y >= fillRow[3]) : (y < (SCREEN_HEIGHT - fillRow[3]));
            x_bound = isLiq ? 0 : SCREEN_WIDTH;
        } else {
            int32_t dY2 = 2 * y - SCREEN_HEIGHT;
            x_bound = (SCREEN_WIDTH * sinV[3] + dY2 * cosV[3]) / (2 * sinV[3]);
            if (x_bound < 0) x_bound = 0;
            if (x_bound > SCREEN_WIDTH) x_bound = SCREEN_WIDTH;
        }
        if (liquidLeft[3]) { leftHi=0xFF; leftLo=0xFF; rightHi=0x00; rightLo=0x00; }
        else               { leftHi=0x00; leftLo=0x00; rightHi=0xFF; rightLo=0xFF; }

        DMA_Wait_For_Completion(3);
        for (i = 0; i < x_bound; i++)
            { fillBuf_3[i*2]=leftHi; fillBuf_3[i*2+1]=leftLo; }
        for (i = x_bound; i < SCREEN_WIDTH; i++)
            { fillBuf_3[i*2]=rightHi; fillBuf_3[i*2+1]=rightLo; }

        DMA_Feed_SPI_Async(3, fillBuf_3, (uint16)(SCREEN_WIDTH * 2));
        tmp=fillBuf_3; fillBuf_3=sendBuf_3; sendBuf_3=tmp;
           
    }

    // wait for all DMAs to finish before returning
    DMA_Wait_For_Completion(0);
    DMA_Wait_For_Completion(1);
    DMA_Wait_For_Completion(2);
    DMA_Wait_For_Completion(3);
}