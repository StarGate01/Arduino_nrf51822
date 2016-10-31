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

#define DATA_OUT_BASE 0x06

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

float getAccel(int channelNum)
{
  return ((int16_t)((getByte(DATA_OUT_BASE+1 + 2*channelNum)<<8) | (getByte(DATA_OUT_BASE + 2*channelNum)))) / 16384.0;  
}

void setup() 
{
  // put your setup code here, to run once:
    Wire.begin(SCL, SDA, TWI_FREQUENCY_100K);
    Serial.begin(9600);
    pinMode (VIBRATE, OUTPUT);
    pinMode(BUTTON,INPUT_PULLUP); 
    initSensor();
}

void loop()
{ 

  Serial.print(getAccel(0)*10);
  Serial.print("\t");
  Serial.print(getAccel(1)*10);
  Serial.print("\t");
  Serial.println(getAccel(2)*10);
  delay(50);

}