
#include <project.h>
#include "tft.h"
#include "dma_util.h"

// Initialization sequence for the TFT driver
const uint8_t ST7796S_Init_Sequence[] = {
    0xF0, 1, 0xC3,
    0xF0, 1, 0x96, 
    0x36, 1, 0x68,
    0x3A, 1, 0x55,
    0xB0, 1, 0x80, 
    0xB6, 2, 0x00, 0x02,
    0xB5, 4, 0x02, 0x03, 0x00, 0x04,
    0xB1, 2, 0x80, 0x10, 
    0xB4, 1, 0x00,
    0xB7, 1, 0xC6,
    0xC5, 1, 0x24,
    0xE4, 1, 0x31,
    0xE8, 8, 0x40, 0x8A, 0x00, 0x00, 0x29, 0x19, 0xA5, 0x33,
    0xC2, 0,
    0xA7, 0,
    0xE0, 14, 0xF0, 0x09, 0x13, 0x12, 0x12, 0x2B, 0x3C, 0x44, 0x4B, 0x1B, 0x18, 0x17, 0x1D, 0x21,
    0xE1, 14, 0xF0, 0x09, 0x13, 0x0C, 0x0D, 0x27, 0x3B, 0x44, 0x4D, 0x0B, 0x17 ,0x17, 0x1D, 0x21,          
    0x36, 1, 0x48,
    0xF0, 1, 0xC3,
    0xF0, 1, 0x69, 
    0x13, 0,
    0x11, 0,
    0x36, 1, 0x88,
    0x29, 0
};


//==============================================================
// constrain
// constrain a variable's value to a particular range
//==============================================================
uint16 constrain(uint16 min, uint16 max, uint16 var)
{
    if (var < min) return min;
    if (var > max) return max;
    return var;
}

//==============================================================
// write8_a0()
// writes an 8-bit value to the TFT with the D/C line low (commands)
//
// Arguments:
//      data - 8-bit value
//==============================================================
void write8_a0(uint8 disp, uint8 data)
{
    /*
    Steps:
        1. Set DC line low
        2. Send data to the SPI transmit buffer
        3. Wait for data to be sent
    */
    switch (disp)
    {
        case 0:
            DC0_Write(0x00);
            SPIM_0_WriteTxData(data);
            while (!(SPIM_0_ReadTxStatus() & 0x01)){};
            break;
        case 1:
        	DC1_Write(0x00);
            SPIM_1_WriteTxData(data);
            while (!(SPIM_1_ReadTxStatus() & 0x01)){};
            break;
        case 2:
            DC2_Write(0x00);
            SPIM_2_WriteTxData(data);
            while (!(SPIM_2_ReadTxStatus() & 0x01)){};
            break;
        case 3:
        	DC3_Write(0x00);
            SPIM_3_WriteTxData(data);
            while (!(SPIM_3_ReadTxStatus() & 0x01)){};
            break;
    }
}

//==============================================================
// write8_a1()
// writes an 8-bit value to the TFT with the D/C line high (data)
//
// Arguments:
//      data - 8-bit value
//==============================================================
void write8_a1(uint8 disp, uint8 data)
{
    /*
    Steps:
        1. Set DC line high
        2. Send data to the SPI transmit buffer
        3. Wait for data to be sent
    */
    switch (disp)
    {
        case 0:
            DC0_Write(0x01);
            SPIM_0_WriteTxData(data);
            while (!(SPIM_0_ReadTxStatus() & 0x01)){};
            break;
        case 1:
        	DC1_Write(0x01);
            SPIM_1_WriteTxData(data);
            while (!(SPIM_1_ReadTxStatus() & 0x01)){};
            break;
        case 2:
            DC2_Write(0x01);
            SPIM_2_WriteTxData(data);
            while (!(SPIM_2_ReadTxStatus() & 0x01)){};
            break;
        case 3:
        	DC3_Write(0x01);
            SPIM_3_WriteTxData(data);
            while (!(SPIM_3_ReadTxStatus() & 0x01)){};
            break;
    }
}


//==============================================================
// setRowCol
// this function sets the region that the TFT will draw in
//==============================================================
void setRowCol(uint8 disp, uint16 x1, uint16 x2, uint16 y1, uint16 y2)
{
    // constrain to size of TFT screen
    x1 = constrain(0, SCREEN_WIDTH-1, x1);
    x2 = constrain(x1, SCREEN_WIDTH-1, x2);    
    y1 = constrain(0, SCREEN_HEIGHT-1, y1);
    y2 = constrain(y1, SCREEN_HEIGHT-1, y2);
        
    // define column bounds
    write8_a0(disp, 0x2A);
    write8_a1(disp, (uint8) (x1 >> 8));
    write8_a1(disp, (uint8) (x1 & 0xff));
    write8_a1(disp, (uint8) (x2 >> 8));
    write8_a1(disp, (uint8) (x2 & 0xff));
    
    // define row bounds
    write8_a0(disp, 0x2B);
    write8_a1(disp, (uint8) (y1 >> 8));
    write8_a1(disp, (uint8) (y1 & 0xff));
    write8_a1(disp, (uint8) (y2 >> 8));
    write8_a1(disp, (uint8) (y2 & 0xff));
}


//==============================================================
// drawRect
// fill in a rectangle in given bounds with a certain color
//==============================================================
void drawRect(uint8 disp, uint16 x1, uint16 x2, uint16 y1, uint16 y2, uint16_t color)
{
    int i;
    uint8* pFillBuffer;
    
    uint8_t hi = (uint8_t)(color >> 8);
    uint8_t lo = (uint8_t)(color & 0xFF);
    
    x1 = constrain(0, SCREEN_WIDTH-1, x1);
    x2 = constrain(x1, SCREEN_WIDTH-1, x2);    
    y1 = constrain(0, SCREEN_HEIGHT-1, y1);
    y2 = constrain(y1, SCREEN_HEIGHT-1, y2);
    
    setRowCol(disp, x1, x2, y1, y2);
    write8_a0(disp, 0x2C);
    
    switch (disp) 
    {
        case 0:
            DC0_Write(1u);
    
            for (i = 0; i < (x2 - x1 + 1); i++)
            {
                uint16_t idx = i * 2;
                bufferA_0[idx] = hi;
                bufferA_0[idx+1] = lo;
            }
            
            pFillBuffer = bufferA_0;
            
            for (i = y1; i < y2+1; i++) {
                DMA_Wait_For_Completion(disp);
                DMA_Feed_SPI_Async(disp, pFillBuffer, (x2-x1+1) * 2);
            }
            break;
        case 1:
            DC1_Write(1u);

            for (i = 0; i < (x2 - x1 + 1); i++)
            {
                uint16_t idx = i * 2;
                bufferA_1[idx] = hi;
                bufferA_1[idx+1] = lo;
            }
            
            pFillBuffer = bufferA_1;
            
            for (i = y1; i < y2+1; i++) {
                DMA_Wait_For_Completion(disp);
                DMA_Feed_SPI_Async(disp, pFillBuffer, (x2-x1+1) * 2);
            }
            break;
            
        case 2:
            DC2_Write(1u);
    
            for (i = 0; i < (x2 - x1 + 1); i++)
            {
                uint16_t idx = i * 2;
                bufferA_2[idx] = hi;
                bufferA_2[idx+1] = lo;
            }
            
            pFillBuffer = bufferA_2;
            
            for (i = y1; i < y2+1; i++) {
                DMA_Wait_For_Completion(disp);
                DMA_Feed_SPI_Async(disp, pFillBuffer, (x2-x1+1) * 2);
            }
            break;
            
        case 3:
            DC3_Write(1u);
    
            for (i = 0; i < (x2 - x1 + 1); i++)
            {
                uint16_t idx = i * 2;
                bufferA_3[idx] = hi;
                bufferA_3[idx+1] = lo;
            }
            
            pFillBuffer = bufferA_3;
            
            for (i = y1; i < y2+1; i++) {
                DMA_Wait_For_Completion(disp);
                DMA_Feed_SPI_Async(disp, pFillBuffer, (x2-x1+1) * 2);
            }
            break;
    }
}

//==============================================================
// drawPixel
// write one RGB565 pixel at (x, y)
//==============================================================
void drawPixel(uint8 disp, int16 x, int16 y, uint16_t color)
{
    // ignore if pixel out of bounds
    if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) return;
    
    setRowCol(disp, (uint16)x, (uint16)x, (uint16)y, (uint16)y);
    write8_a0(disp, 0x2C);
    write8_a1(disp, (uint8_t)(color >> 8));
    write8_a1(disp, (uint8_t)(color & 0xFF));
}

//==============================================================
// drawLine
// draw a line on the screen
//==============================================================
void drawLine(uint8 disp, int16 x0, int16 y0, int16 x1, int16 y1, uint16_t color)
{
    int16 dx =  (x1 > x0) ? (x1 - x0) : (x0 - x1);
    int16 dy =  (y1 > y0) ? (y1 - y0) : (y0 - y1);
    int16 sx =  (x0 < x1) ? 1 : -1;                         // direction for x
    int16 sy =  (y0 < y1) ? 1 : -1;                         // direction for y
    int16 err = dx - dy;

    while (1) {
        drawPixel(disp, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int16 e2 = err << 1;
        if (e2 >  -dy) { err -= dy; x0 += sx; }
        if (e2 <   dx) { err += dx; y0 += sy; }
    }
}


//==============================================================
// clearScreen
// fill in the whole screen with a color 
//==============================================================
void clearScreen(uint8 disp, uint16_t color) {
    drawRect(disp, 0, SCREEN_WIDTH-1, 0, SCREEN_HEIGHT-1, color);
}

//==============================================================
// tftStart()
// this function must be called to initializes the TFT
//==============================================================
void tftStart(uint8 disp)
{
    PWM_1_Stop();
    switch (disp)
    {
        case 0:
            RESET0_Write(0); // hardware reset
            CyDelay(10);
            RESET0_Write(1);
            break;
        case 1:
            RESET1_Write(0); // hardware reset
            CyDelay(10);
            RESET1_Write(1);
            break;
        case 2:
            RESET2_Write(0); // hardware reset
            CyDelay(10);
            RESET2_Write(1);
            break;
        case 3:
            RESET3_Write(0); // hardware reset
            CyDelay(10);
            RESET3_Write(1);
            break;
    }
    
    write8_a0(disp, 0x01); // perform software reset
    CyDelay(120); // delay 120 ms
    
    // send the initialization sequence for the ST7796S LCD driver
    uint32_t i = 0;
    while (i < sizeof(ST7796S_Init_Sequence)) {
        uint8_t cmd = ST7796S_Init_Sequence[i++];
        uint8_t count = ST7796S_Init_Sequence[i++];
        write8_a0(disp, cmd); // send command
        
        // send data bytes
        while (count > 0) {
            write8_a1(disp, ST7796S_Init_Sequence[i++]);
            count--;
        }

        // delay for sleep out
        if (cmd == 0x11) { // sleep Out
            CyDelay(120); 
        }
    }
    
    PWM_1_Start();
    clearScreen(disp, 0); // make everything black
}
