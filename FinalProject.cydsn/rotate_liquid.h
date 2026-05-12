#include <project.h>
#include "tft.h"

uint16_t adcToAngle(uint16_t adcVal);
uint16_t screenAtan(uint8_t fracFull_left);                 // determine how to get liquid on screen at a particular angle
void drawLiquid(uint8_t *fracFull, uint16_t *angles);       // draw the liquid on screens given their amount full and angles
