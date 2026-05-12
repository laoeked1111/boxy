#include <project.h>

#define MPU6050_ADDRESS 0x68
#define ACCEL_XOUT_H    0x3B  // Starting address for accelerometer data
#define GYRO_XOUT_H     0x43  // Starting address for gyro data
#define PWR_MGMT_1      0x6B  // Device power management register

void MPU6050_Start(void);
void Read_Accel_Data(int16 *ax, int16 *ay, int16 *az);
void Read_Gyro_Data(int16 *gx, int16 *gy, int16 *gz);
