#include <project.h>

// TFT screen parameters
#define NUM_SCREENS 4
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 480
#define LINE_BUFFER_SIZE (SCREEN_WIDTH)

// general helper function
uint16 constrain(uint16 min, uint16 max, uint16 var);

void write8_a0(uint8 disp, uint8 data);
void write8_a1(uint8 disp, uint8 data);
void setRowCol(uint8 disp, uint16 x1, uint16 x2, uint16 y1, uint16 y2);
void drawRect(uint8 disp, uint16 x1, uint16 x2, uint16 y1, uint16 y2, uint16_t color);
void drawPixel(uint8 disp, int16 x, int16 y, uint16_t color);
void drawLine(uint8 disp, int16 x0, int16 y0, int16 x1, int16 y1, uint16_t color);
void clearScreen(uint8 disp, uint16_t color);
void tftStart(uint8 disp);