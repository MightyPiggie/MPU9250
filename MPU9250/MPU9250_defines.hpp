#ifndef MPU9250_defines_H_
#define MPU9520_defines_H_

#define MPU6050_ADDRESS 0x68
#define AK8963_ADDRESS 0x0C

// AK8963_ADDRESS
#define REG_MAG_XOUT_L 0x03  
#define REG_MAG_XOUT_H 0x04
#define REG_MAG_YOUT_L 0x05
#define REG_MAG_YOUT_H 0x06
#define REG_MAG_ZOUT_L 0x07
#define REG_MAG_ZOUT_H 0x08
#define REG_MAG_STATUS2 0x09
#define REG_MAG_CONTROL1 0x0A


// SELF TEST REGISTERS
#define REG_SELF_TEST_X_GYRO 0x00
#define REG_SELF_TEST_Y_GYRO 0x01
#define REG_SELF_TEST_Z_GYRO 0x02
#define REG_SELF_TEST_X_ACCEL 0x0D
#define REG_SELF_TEST_Y_ACCEL 0x0E
#define REG_SELF_TEST_Z_ACCEL 0x0F

// OFFSET REGISTERS
#define REG_XG_OFFSET_H 0x13
#define REG_XG_OFFSET_L 0x14
#define REG_YG_OFFSET_H 0x15
#define REG_YG_OFFSET_L 0x16
#define REG_ZG_OFFSET_H 0x17
#define REG_ZG_OFFSET_L 0x18

// CONFIG REGISTERS
#define REG_SMPLRT_DIV 0x19
#define REG_CONFIG 0x1A
#define REG_GYRO_CONFIG 0x1B
#define REG_ACCEL_CONFIG 0x1C
#define REG_ACCEL_CONFIG2 0x1D
#define REG_LP_ACCEL_ODR 0x1E
#define REG_WOM_THR 0x1F
#define REG_FIFO_EN 0x23
#define REG_I2C_MST_CTRL 0x24
#define REG_I2C_SLV0_ADDR 0x25
#define REG_I2C_SLV0_REG 0x26
#define REG_I2C_SLV0_CTRL 0x27
#define REG_I2C_SLV1_ADDR 0x28
#define REG_I2C_SLV1_REG 0x29
#define REG_I2C_SLV1_CTRL 0x2A
#define REG_I2C_SLV2_ADDR 0x2B
#define REG_I2C_SLV2_REG 0x2C
#define REG_I2C_SLV2_CTRL 0x2D
#define REG_I2C_SLV3_ADDR 0x2E
#define REG_I2C_SLV3_REG 0x2F
#define REG_I2C_SLV3_CTRL 0x30
#define REG_I2C_SLV4_ADDR 0x31
#define REG_I2C_SLV4_REG 0x32
#define REG_I2C_SLV4_DO 0x33
#define REG_I2C_SLV4_CTRL 0x34
#define REG_I2C_SLV4_DI 0x35
#define REG_I2C_MST_STATUS 0x36
#define REG_INT_PIN_CFG 0x37
#define REG_INT_ENABLE 0x38
#define REG_INT_STATUS 0x3A

// ACCEL DATA REGISTERS
#define REG_ACCEL_XOUT_H 0x3B
#define REG_ACCEL_XOUT_L 0x3C
#define REG_ACCEL_YOUT_H 0x3D
#define REG_ACCEL_YOUT_L 0x3E
#define REG_ACCEL_ZOUT_H 0x3F
#define REG_ACCEL_ZOUT_L 0x40

// TEMP DATA REGISTERS
#define REG_TEMP_OUT_H 0x41
#define REG_TEMP_OUT_L 0x42

// GYRO DATA REGISTERS
#define REG_GYRO_XOUT_H 0x43
#define REG_GYRO_XOUT_L 0x44
#define REG_GYRO_YOUT_H 0x45
#define REG_GYRO_YOUT_L 0x46
#define REG_GYRO_ZOUT_H 0x47
#define REG_GYRO_ZOUT_L 0x48

// EXTERNAL SENSOR DATA REGISTERS
#define REG_EXT_SENS_DATA_00 0x49
#define REG_EXT_SENS_DATA_01 0x4A
#define REG_EXT_SENS_DATA_02 0x4B
#define REG_EXT_SENS_DATA_03 0x4C
#define REG_EXT_SENS_DATA_04 0x4D
#define REG_EXT_SENS_DATA_05 0x4E
#define REG_EXT_SENS_DATA_06 0x4F
#define REG_EXT_SENS_DATA_07 0x50
#define REG_EXT_SENS_DATA_08 0x51
#define REG_EXT_SENS_DATA_09 0x52
#define REG_EXT_SENS_DATA_10 0x53
#define REG_EXT_SENS_DATA_11 0x54
#define REG_EXT_SENS_DATA_12 0x55
#define REG_EXT_SENS_DATA_13 0x56
#define REG_EXT_SENS_DATA_14 0x57
#define REG_EXT_SENS_DATA_15 0x58
#define REG_EXT_SENS_DATA_16 0x59
#define REG_EXT_SENS_DATA_17 0x5A
#define REG_EXT_SENS_DATA_18 0x5B
#define REG_EXT_SENS_DATA_19 0x5C
#define REG_EXT_SENS_DATA_20 0x5D
#define REG_EXT_SENS_DATA_21 0x5E
#define REG_EXT_SENS_DATA_22 0x5F
#define REG_EXT_SENS_DATA_23 0x60

//
#define REG_I2C_SLV0_DO 0x63
#define REG_I2C_SLV1_DO 0x64
#define REG_I2C_SLV2_DO 0x65
#define REG_I2C_SLV3_DO 0x66
#define REG_I2C_MST_DELAY_CTRL 0x67
#define REG_SIGNAL_PATH_RESET 0x68
#define REG_MOT_DETECT_CTRL 0x69
#define REG_USER_CTRL 0x6A
#define REG_PWR_MGMT_1 0x6B
#define REG_PWR_MGMT_2 0x6C
#define REG_FIFO_COUNTH 0x72
#define REG_FIFO_COUNTL 0x73
#define REG_FIFO_R_W 0x74
#define REG_WHO_AM_I 0x75 //Should return 0x68
#define REG_XA_OFFSET_H 0x77
#define REG_XA_OFFSET_L 0x78
#define REG_YA_OFFSET_H 0x7A
#define REG_YA_OFFSET_L 0x7B
#define REG_ZA_OFFSET_H 0x7D
#define REG_ZA_OFFSET_L 0x7E

#endif