
#include <project.h>
#include <stdlib.h>
#include "tft.h"
#include "dma_util.h"
#include "imu.h"
#include "rotate_liquid.h"
#include "snowglobe.h"
#include "lantern.h"

// handle which display mode to use
volatile uint8_t mode = 0;
volatile uint8_t mode_changed = 0; // flag
CY_ISR(Mode_Handler) {
    mode = (mode + 1) % 3;
    mode_changed = 1;
}

// automatic brightness adjustment for lantern
volatile uint8_t brightIdx = 0;
volatile uint8_t brightness = 255;
volatile uint8_t brightnessChanged = 0;
CY_ISR(Bright_Handler) {
    if (mode == 2) {
        brightnessChanged = 1;
        brightIdx += 1;
        brightness = sineBrightness[brightIdx];
    }
}

// changing between orange and blue lantern
volatile uint8_t lanternMode = 0;
volatile uint8_t lanternModeChanged = 0;
CY_ISR(LanternToggle_Handler) {
    lanternMode = (lanternMode == 0) ? 1 : 0;
    lanternModeChanged = 1;
}

int main() {
    
    // enable global interrupts
    CyGlobalIntEnable;
    
    // start SPI
    SPIM_0_Start();
    SPIM_1_Start();
    SPIM_2_Start();
    SPIM_3_Start();
    
    // start DMAs
    Init_DMA_SPI(0);
    Init_DMA_SPI(1);
    Init_DMA_SPI(2);
    Init_DMA_SPI(3);
    
    // initialize TFT screens
    tftStart(0);
    tftStart(1);
    tftStart(2);
    tftStart(3);
    
    // get ADC data
    ADC_DelSig_1_Start();
    ADC_DelSig_1_StartConvert();
    
    // start IMU
    I2C_1_Start();
    MPU6050_Start();
    
    int16_t ax, ay, az; // accelerometer values
    int16_t gx, gy, gz; // gyroscope values
    
    // ensure DMAs are done
    DMA_Wait_For_Completion(0);
    DMA_Wait_For_Completion(1);
    DMA_Wait_For_Completion(2);
    DMA_Wait_For_Completion(3);
    
    // mode switching ISR
    MODE_ISR_StartEx(Mode_Handler);
        
    // variables for mode 0 (fluid display)
    uint8_t fracFull[] = {128, 128, 128, 128};
    uint16_t angles[NUM_SCREENS] = {0};
    
    // brightness ISR for mode 2 (lantern)
    BRIGHT_ISR_StartEx(Bright_Handler);
    
    // lantern mode ISR
    LANTERN_TOGGLE_ISR_StartEx(LanternToggle_Handler);
    
    PWM_1_Start();
    
    // main loop
    for (;;) {
        
        // =============================================
        // Change mode if button was pressed
        // =============================================
        if (mode_changed) {
            mode_changed = 0;
            LED_MODE_1_Write(mode & 0x01);                  // change the mode indicator LEDs
            LED_MODE_2_Write((mode >> 1) & 0x01);
            
            if (mode == 1) snowglobeInit();
            if (mode == 2) lightLantern(lanternMode);
        }
        
        if (brightnessChanged) {
            brightnessChanged = 0;
            PWM_1_WriteCompare(brightness);
        }
        
        // =============================================
        // Mode 0: tilt-sensitive fluid display
        // =============================================
        if (mode == 0) {
            Read_Accel_Data(&ax, &ay, &az);
            
            if (abs(ax) >= abs(ay)) {                       // tilting along one axis
                fracFull[0] = 128;
                fracFull[2] = 128;
                fracFull[1] = 128 - (uint8_t) (ax >> 8);
                fracFull[3] = 128 + (uint8_t) (ax >> 8);
                
                angles[1] = (az >= 0) ? 0 : 180;
                angles[3] = (az >= 0) ? 0 : 180;
                angles[0] = screenAtan(fracFull[3]);
                angles[2] = screenAtan(fracFull[1]);
            } else {                                        // tilting along the other axis
                fracFull[1] = 128;
                fracFull[3] = 128;
                fracFull[0] = 128 + (uint8_t) (ay >> 8);
                fracFull[2] = 128 - (uint8_t) (ay >> 8);
                
                angles[0] = (az >= 0) ? 0 : 180;
                angles[2] = (az >= 0) ? 0 : 180;
                angles[1] = screenAtan(fracFull[0]);
                angles[3] = screenAtan(fracFull[2]);
            }
            
            drawLiquid(fracFull, angles);
            
        // =============================================
        // Mode 1: snow globe
        // =============================================
        } else if (mode == 1) {
            Read_Accel_Data(&ax, &ay, &az);
            snowglobeUpdate(ax, ay, az);
            
        // =============================================
        // Mode 2: lantern mode
        // =============================================     
        } else if (mode == 2) {
            if (lanternModeChanged) {
                lanternModeChanged = 0;
                lightLantern(lanternMode);
            }
        }
    }
}
