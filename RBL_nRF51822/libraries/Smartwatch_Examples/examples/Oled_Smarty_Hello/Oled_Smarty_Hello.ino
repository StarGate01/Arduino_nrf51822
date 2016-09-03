#include "SFE_MicroOLED.h"
#define VIBRATE 7
#define BUTTON 4

SPI my_spi(P0_29, NC, P0_30);
MicroOLED my_oled(my_spi, P0_1, P0_0, P0_2);

void setup() {
// put your setup code here, to run once:
my_oled.init(0, 8000000);
my_oled.clear(ALL);
my_oled.puts("Smarty");
my_oled.display();
pinMode(VIBRATE,OUTPUT);
pinMode(BUTTON,INPUT_PULLUP);
Serial.begin(9600);
Serial.println("Smarty");
}
void loop()
{
digitalWrite(VIBRATE,!digitalRead(BUTTON));
}
