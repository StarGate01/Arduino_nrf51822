#include "wire.h"

#define SCL  16  
#define SDA  14

TwoWire Wire = TwoWire(NRF_TWI1);

#define  VIBRATE P0_7
#define  BUTTON P0_4 

#define KX022_addr_w              0x3E
#define KX022_addr_r              0x3F
#define KX022_Accel_CNTL1_1       0x18
#define KX022_Accel_CNTL1_2       0x41
#define KX022_Accel_ODCNTL_1      0x1B
#define KX022_Accel_ODCNTL_2      0x02
#define KX022_Accel_CNTL3_1       0x1A
#define KX022_Accel_CNTL3_2       0xD8
#define KX022_Accel_TILT_TIMER_1  0x22
#define KX022_Accel_TILT_TIMER_2  0x01
#define KX022_Accel_CNTL2_1       0x18
#define KX022_Accel_CNTL2_2       0xC1  

#define XOUT_L 0x06
#define XOUT_H 0x07
#define YOUT_L 0x08
#define YOUT_H 0x09
#define ZOUT_L 0x0A
#define ZOUT_H 0x0B

uint8_t        KX022_Content_ReadData[6];
#define KX022_Addr_Accel_ReadData 0x06    

float       KX022_Accel_X;
float       KX022_Accel_Y;                               
float       KX022_Accel_Z;

short int   KX022_Accel_X_RawOUT = 0;
short int   KX022_Accel_Y_RawOUT = 0;
short int   KX022_Accel_Z_RawOUT = 0;

int         KX022_Accel_X_LB = 0;
int         KX022_Accel_X_HB = 0;
int         KX022_Accel_Y_LB = 0;
int         KX022_Accel_Y_HB = 0;
int         KX022_Accel_Z_LB = 0;
int         KX022_Accel_Z_HB = 0;
float       KX022_Accel_X_OUT = 0;
float       KX022_Accel_Y_OUT = 0;
float       KX022_Accel_Z_OUT = 0;



void initSensor(){
    writeTwoBytes(KX022_Accel_CNTL1_1,KX022_Accel_CNTL1_2);
    writeTwoBytes(KX022_Accel_ODCNTL_1,KX022_Accel_ODCNTL_2);
    writeTwoBytes(KX022_Accel_CNTL3_1,KX022_Accel_CNTL3_2);
    writeTwoBytes(KX022_Accel_TILT_TIMER_1,KX022_Accel_TILT_TIMER_2);
    writeTwoBytes(KX022_Accel_CNTL2_1,KX022_Accel_CNTL2_2);
}

void writeTwoBytes (int one, int two)
{
    Wire.beginTransmission(KX022_addr_w);
    Wire.write(one);
    Wire.write(two);
    Wire.endTransmission();
}

int getByte (int address)
{
  int readedValue;
  Wire.beginTransmission(KX022_addr_w);
  Wire.write(address);
  Wire.endTransmission();
  Wire.requestFrom(KX022_addr_r , 1);  // Or-ed with "1" for read bit
  if(1 <= Wire.available())    // if two bytes were received
    {
  readedValue = Wire.read();
  }
  return readedValue;
}

float getAccelX(){
  KX022_Accel_X_LB = getByte(XOUT_L);
  KX022_Accel_X_HB = getByte(XOUT_H);
  KX022_Accel_X_RawOUT = (KX022_Accel_X_HB<<8) | (KX022_Accel_X_LB);
  KX022_Accel_X_OUT = (float)KX022_Accel_X_RawOUT / 16384;
  return KX022_Accel_X_OUT;
}
float getAccelY(){
  KX022_Accel_Y_LB = getByte(YOUT_L); 
  KX022_Accel_Y_HB = getByte(YOUT_H);
  KX022_Accel_Y_RawOUT = (KX022_Accel_Y_HB<<8) | (KX022_Accel_Y_LB);
  KX022_Accel_Y_OUT = (float)KX022_Accel_Y_RawOUT / 16384;
  return KX022_Accel_X_OUT;
}
float getAccelZ(){
   KX022_Accel_Z_LB = getByte(ZOUT_L); 
  KX022_Accel_Z_HB = getByte(ZOUT_H); 
   KX022_Accel_Z_RawOUT = (KX022_Accel_Z_HB<<8) | (KX022_Accel_Z_LB);
   KX022_Accel_Z_OUT = (float)KX022_Accel_Z_RawOUT / 16384;
   return KX022_Accel_Z_OUT;
}

void setup() {
  // put your setup code here, to run once:
    Wire.begin(SCL, SDA, TWI_FREQUENCY_100K);
    Serial.begin(9600);
    pinMode (VIBRATE, OUTPUT);
    pinMode(BUTTON,INPUT_PULLUP); 
    initSensor();
}

void loop()
{ 
delay(500);
  Serial.write("KX022 (X) = ");
  Serial.print(getAccelX());
  Serial.write(" g");
  Serial.write(0x0A);  //Print Line Feed
  Serial.write(0x0D);  //Print Carrage Return
  Serial.write("KX022 (Y) = ");
  Serial.print(getAccelY());
  Serial.write(" g");
  Serial.write(0x0A);  //Print Line Feed
  Serial.write(0x0D);  //Print Carrage Return
  Serial.write("KX022 (Z) = ");
  Serial.print(getAccelZ());
  Serial.write(" g");
  Serial.write(0x0A);  //Print Line Feed
  Serial.write(0x0D);  //Print Carrage Return
}
