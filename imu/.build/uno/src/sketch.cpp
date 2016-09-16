#include <Arduino.h>
#include <Wire.h>
void setup();
void loop();
void MPU9250_setupCompass();
int MPU9250_readSensor(int addrL, int addrH);
int MPU9250_readSensor(int addr);
int MPU9250_writeSensor(int addr, int data);
#line 1 "src/sketch.ino"
//#include <Wire.h>

#define MPU9250_SELF_TEST_X 0x0D        // RW
#define MPU9250_SELF_TEST_Y 0x0E        // RW
#define MPU9250_SELF_TEST_Z 0x0F        // RW
#define MPU9250_SELF_TEST_A 0x10        // RW
#define MPU9250_SMPLRT_DIV 0x19         // RW
#define MPU9250_CONFIG 0x1A             // RW
#define MPU9250_GYRO_CONFIG 0x1B        // RW
#define MPU9250_ACCEL_CONFIG 0x1C       // RW
#define MPU9250_FF_THR 0x1D             // RW
#define MPU9250_FF_DUR 0x1E             // RW
#define MPU9250_MOT_THR 0x1F            // RW
#define MPU9250_MOT_DUR 0x20            // RW
#define MPU9250_ZRMOT_THR 0x21          // RW
#define MPU9250_ZRMOT_DUR 0x22          // RW
#define MPU9250_FIFO_EN 0x23            // RW
#define MPU9250_I2C_MST_CTRL 0x24       // RW
#define MPU9250_I2C_SLV0_ADDR 0x25      // RW
#define MPU9250_I2C_SLV0_REG 0x26       // RW
#define MPU9250_I2C_SLV0_CTRL 0x27      // RW
#define MPU9250_I2C_SLV1_ADDR 0x28      // RW
#define MPU9250_I2C_SLV1_REG 0x29       // RW
#define MPU9250_I2C_SLV1_CTRL 0x2A      // RW
#define MPU9250_I2C_SLV2_ADDR 0x2B      // RW
#define MPU9250_I2C_SLV2_REG 0x2C       // RW
#define MPU9250_I2C_SLV2_CTRL 0x2D      // RW
#define MPU9250_I2C_SLV3_ADDR 0x2E      // RW
#define MPU9250_I2C_SLV3_REG 0x2F       // RW
#define MPU9250_I2C_SLV3_CTRL 0x30      // RW
#define MPU9250_I2C_SLV4_ADDR 0x31      // RW
#define MPU9250_I2C_SLV4_REG 0x32       // RW
#define MPU9250_I2C_SLV4_DO 0x33        // RW
#define MPU9250_I2C_SLV4_CTRL 0x34      // RW
#define MPU9250_I2C_SLV4_DI 0x35        // R
#define MPU9250_I2C_MST_STATUS 0x36     // R 
#define MPU9250_INT_PIN_CFG 0x37        // RW
#define MPU9250_INT_ENABLE 0x38         // RW
#define MPU9250_INT_STATUS 0x3A         // R
#define MPU9250_ACCEL_XOUT_H 0x3B       // R
#define MPU9250_ACCEL_XOUT_L 0x3C       // R
#define MPU9250_ACCEL_YOUT_H 0x3D       // R
#define MPU9250_ACCEL_YOUT_L 0x3E       // R
#define MPU9250_ACCEL_ZOUT_H 0x3F       // R
#define MPU9250_ACCEL_ZOUT_L 0x40       // R
#define MPU9250_TEMP_OUT_H 0x41         // R
#define MPU9250_TEMP_OUT_L 0x42         // R
#define MPU9250_GYRO_XOUT_H 0x43        // R
#define MPU9250_GYRO_XOUT_L 0x44        // R
#define MPU9250_GYRO_YOUT_H 0x45        // R
#define MPU9250_GYRO_YOUT_L 0x46        // R
#define MPU9250_GYRO_ZOUT_H 0x47        // R
#define MPU9250_GYRO_ZOUT_L 0x48        // R
#define MPU9250_EXT_SENS_DATA_00 0x49   // R
#define MPU9250_EXT_SENS_DATA_01 0x4A   // R
#define MPU9250_EXT_SENS_DATA_02 0x4B   // R
#define MPU9250_EXT_SENS_DATA_03 0x4C   // R
#define MPU9250_EXT_SENS_DATA_04 0x4D   // R
#define MPU9250_EXT_SENS_DATA_05 0x4E   // R
#define MPU9250_EXT_SENS_DATA_06 0x4F   // R
#define MPU9250_EXT_SENS_DATA_07 0x50   // R
#define MPU9250_EXT_SENS_DATA_08 0x51   // R
#define MPU9250_EXT_SENS_DATA_09 0x52   // R
#define MPU9250_EXT_SENS_DATA_10 0x53   // R
#define MPU9250_EXT_SENS_DATA_11 0x54   // R
#define MPU9250_EXT_SENS_DATA_12 0x55   // R
#define MPU9250_EXT_SENS_DATA_13 0x56   // R
#define MPU9250_EXT_SENS_DATA_14 0x57   // R
#define MPU9250_EXT_SENS_DATA_15 0x58   // R
#define MPU9250_EXT_SENS_DATA_16 0x59   // R
#define MPU9250_EXT_SENS_DATA_17 0x5A   // R
#define MPU9250_EXT_SENS_DATA_18 0x5B   // R
#define MPU9250_EXT_SENS_DATA_19 0x5C   // R
#define MPU9250_EXT_SENS_DATA_20 0x5D   // R
#define MPU9250_EXT_SENS_DATA_21 0x5E   // R
#define MPU9250_EXT_SENS_DATA_22 0x5F   // R
#define MPU9250_EXT_SENS_DATA_22 0x60   // R
#define MPU9250_MOT_DETECT_STATUS 0x61  // R
#define MPU9250_I2C_SLV0_DO 0x63        // RW
#define MPU9250_I2C_SLV1_DO 0x64        // RW
#define MPU9250_I2C_SLV2_DO 0x65        // RW
#define MPU9250_I2C_SLV3_DO 0x66        // RW
#define MPU9250_I2C_MST_DELAY_CTRL 0x67 // RW
#define MPU9250_SIGNAL_PATH_RESET 0x68  // RW
#define MPU9250_MOT_DETECT_CTRL 0x69    // RW
#define MPU9250_USER_CTRL 0x6A          // RW
#define MPU9250_PWR_MGMT_1 0x6B         // RW
#define MPU9250_PWR_MGMT_2 0x6C         // RW
#define MPU9250_FIFO_COUNTH 0x72        // RW
#define MPU9250_FIFO_COUNTL 0x73        // RW
#define MPU9250_FIFO_R_W 0x74           // RW
#define MPU9250_WHO_AM_I 0x75           // R

// MPU9250 Compass
#define MPU9250_CMPS_XOUT_L 0x4A // R
#define MPU9250_CMPS_XOUT_H 0x4B // R
#define MPU9250_CMPS_YOUT_L 0x4C // R
#define MPU9250_CMPS_YOUT_H 0x4D // R
#define MPU9250_CMPS_ZOUT_L 0x4E // R
#define MPU9250_CMPS_ZOUT_H 0x4F // R

// I2C address 0x69 could be 0x68 depends on your wiring.
int MPU9250_I2C_ADDRESS = 0x69;

// Variables where our values can be stored
double cmps[3];
double accl[3];
double gyro[3];
double temp;


void setup()
{
  // Initialize the Serial Bus for printing data.
  Serial.begin(9600);
  
  // Initialize the 'Wire' class for I2C-bus.
  Wire.begin();
  
  // Clear the 'sleep' bit to start the sensor.
  MPU9250_writeSensor(MPU9250_PWR_MGMT_1, 0);
  
  MPU9250_setupCompass();
}


void loop()
{
  temp = ((double)
MPU9250_readSensor(MPU9250_TEMP_OUT_L, MPU9250_TEMP_OUT_H) + 12412.0) / 340.0;
  Serial.print(temp);
  Serial.print(" ");
  
  cmps[0] = MPU9250_readSensor(MPU9250_CMPS_XOUT_L, MPU9250_CMPS_XOUT_H);
  cmps[1] = MPU9250_readSensor(MPU9250_CMPS_YOUT_L, MPU9250_CMPS_YOUT_H);
  cmps[2] = MPU9250_readSensor(MPU9250_CMPS_ZOUT_L, MPU9250_CMPS_ZOUT_H);
  Serial.print(cmps[0]);
  Serial.print(",");
  Serial.print(cmps[1]);
  Serial.print(",");
  Serial.print(cmps[2]);
  Serial.print(" ");
  
  gyro[0] = MPU9250_readSensor(MPU9250_GYRO_XOUT_L, MPU9250_GYRO_XOUT_H);
  gyro[1] = MPU9250_readSensor(MPU9250_GYRO_YOUT_L, MPU9250_GYRO_YOUT_H);
  gyro[2] = MPU9250_readSensor(MPU9250_GYRO_ZOUT_L, MPU9250_GYRO_ZOUT_H);
  Serial.print(gyro[0]);
  Serial.print(",");
  Serial.print(gyro[1]);
  Serial.print(",");
  Serial.print(gyro[2]);
  Serial.print(" ");
    
  accl[0] = MPU9250_readSensor(MPU9250_ACCEL_XOUT_L, MPU9250_ACCEL_XOUT_H);
  accl[1] = MPU9250_readSensor(MPU9250_ACCEL_YOUT_L, MPU9250_ACCEL_YOUT_H);
  accl[2] = MPU9250_readSensor(MPU9250_ACCEL_ZOUT_L, MPU9250_ACCEL_ZOUT_H);
  Serial.print(accl[0]);
  Serial.print(",");
  Serial.print(accl[1]);
  Serial.print(",");
  Serial.print(accl[2]);
  Serial.print(" ");

  Serial.print("\n");
  delay(100);
}



void MPU9250_setupCompass() {
  MPU9250_I2C_ADDRESS = 0x0C;      // change Address to Compass
  
  MPU9250_writeSensor(0x0A, 0x00); // PowerDownMode
  MPU9250_writeSensor(0x0A, 0x0F); // SelfTest
  MPU9250_writeSensor(0x0A, 0x00); // PowerDownMode
  
  MPU9250_I2C_ADDRESS = 0x69;      // change Address to MPU
  
  MPU9250_writeSensor(0x24, 0x40); // Wait for Data at Slave0
  MPU9250_writeSensor(0x25, 0x8C); // Set i2c address at slave0 at 0x0C
  MPU9250_writeSensor(0x26, 0x02); // Set where reading at slave 0 starts
  MPU9250_writeSensor(0x27, 0x88); // Set offset at start reading and enable
  MPU9250_writeSensor(0x28, 0x0C); // Set i2c address at slave1 at 0x0C
  MPU9250_writeSensor(0x29, 0x0A); // Set where reading at slave 1 starts
  MPU9250_writeSensor(0x2A, 0x81); // Enable at set length to 1
  MPU9250_writeSensor(0x64, 0x01); // Overvride register
  MPU9250_writeSensor(0x67, 0x03); // Set delay rate
  MPU9250_writeSensor(0x01, 0x80);
  
  MPU9250_writeSensor(0x34, 0x04); // Set i2c slave 4 delay
  MPU9250_writeSensor(0x64, 0x00); // Override register
  MPU9250_writeSensor(0x6A, 0x00); // Clear usr setting
  MPU9250_writeSensor(0x64, 0x01); // Override register
  MPU9250_writeSensor(0x6A, 0x20); // Enable master i2c mode
  MPU9250_writeSensor(0x34, 0x13); // disable slave 4
}


////////////////////////////////////////////
// I2C functions to get easier all values //
////////////////////////////////////////////

int MPU9250_readSensor(int addrL, int addrH) {
  Wire.beginTransmission(MPU9250_I2C_ADDRESS);
  Wire.write(addrL);
  Wire.endTransmission(false);
  
  Wire.requestFrom(MPU9250_I2C_ADDRESS, 1, true);
  byte L = Wire.read();
  
  Wire.beginTransmission(MPU9250_I2C_ADDRESS);
  Wire.write(addrH);
  Wire.endTransmission(false);
  
  Wire.requestFrom(MPU9250_I2C_ADDRESS, 1, true);
  byte H = Wire.read();
  
  return (int16_t)((H<<8)+L);
}


int MPU9250_readSensor(int addr) {
  Wire.beginTransmission(MPU9250_I2C_ADDRESS);
  Wire.write(addr);
  Wire.endTransmission(false);
  
  Wire.requestFrom(MPU9250_I2C_ADDRESS, 1, true);
  return Wire.read();
}


int MPU9250_writeSensor(int addr, int data) {
  Wire.beginTransmission(MPU9250_I2C_ADDRESS);
  Wire.write(addr);
  Wire.write(data);
  Wire.endTransmission(true);
  
  return 1;
}
