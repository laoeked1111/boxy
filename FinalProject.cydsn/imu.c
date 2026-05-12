#include <project.h>
#include "imu.h"

// initialize the MPU6050
void MPU6050_Start(void) {
    I2C_1_MasterSendStart(MPU6050_ADDRESS, I2C_1_WRITE_XFER_MODE);
    I2C_1_MasterWriteByte(PWR_MGMT_1);
    I2C_1_MasterWriteByte(0x01);
    I2C_1_MasterSendStop();
}

// get data from accelerometer
void Read_Accel_Data(int16 *ax, int16 *ay, int16 *az) {
    uint8 data[6];

    I2C_1_MasterSendStart(MPU6050_ADDRESS, I2C_1_WRITE_XFER_MODE);
    I2C_1_MasterWriteByte(ACCEL_XOUT_H);

    // read 6 bytes of accelerometer data
    I2C_1_MasterSendRestart(MPU6050_ADDRESS, I2C_1_READ_XFER_MODE);
    
    int i;
    for(i = 0; i < 5; i++) {
        data[i] = I2C_1_MasterReadByte(I2C_1_ACK_DATA);
    }
    data[5] = I2C_1_MasterReadByte(I2C_1_NAK_DATA); 
    I2C_1_MasterSendStop();

    // store accelerometer data
    *ax = (int16)((data[0] << 8) | data[1]);
    *ay = (int16)((data[2] << 8) | data[3]);
    *az = (int16)((data[4] << 8) | data[5]);   
}

// get data from gyro
void Read_Gyro_Data(int16 *gx, int16 *gy, int16 *gz) {
    uint8 data[6];
    
    I2C_1_MasterSendStart(MPU6050_ADDRESS, I2C_1_WRITE_XFER_MODE);
    I2C_1_MasterWriteByte(GYRO_XOUT_H);
    
    // read 6 bytes of gyroscope data
    I2C_1_MasterSendRestart(MPU6050_ADDRESS, I2C_1_READ_XFER_MODE);
    
    int i;
    for (i = 0; i < 5; i ++) {
        data[i] = I2C_1_MasterReadByte(I2C_1_ACK_DATA);
    }
    data[5] = I2C_1_MasterReadByte(I2C_1_NAK_DATA);
    I2C_1_MasterSendStop();
    
    // store gyroscope data
    *gx = (int16)((data[0] << 8) | data[1]);
    *gy = (int16)((data[2] << 8) | data[3]);
    *gz = (int16)((data[4] << 8) | data[5]);
}
