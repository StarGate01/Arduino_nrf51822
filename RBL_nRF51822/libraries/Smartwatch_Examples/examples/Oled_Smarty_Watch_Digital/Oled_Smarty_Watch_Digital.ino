#include "SFE_MicroOLED.h"

#define VIBRATE 7
#define BUTTON 4

SPI my_spi(P0_29, NC, P0_30);
MicroOLED my_oled(my_spi, P0_1, P0_0, P0_2);

const int CLOCK_SPEED = 500;
// Use these variables to set the initial time
int hours = 21;
int minutes = 28;
int seconds = 30;
unsigned long lastUpdate = 0;


// Simple function to increment seconds and then increment minutes
// and hours if necessary.
void updateTime()
{
  seconds++;  // Increment seconds
  if (seconds >= 60)  // If seconds overflows (>=60)
  {
    seconds = 0;  // Set seconds back to 0
    minutes++;    // Increment minutes
    if (minutes >= 60)  // If minutes overflows (>=60)
    {
      minutes = 0;  // Set minutes back to 0
      hours++;      // Increment hours
      if (hours >= 12)  // If hours overflows (>=12)
      {
        hours = 0;  // Set hours back to 0
      }
    }
  }
}

void setup() {
// put your setup code here, to run once:
my_oled.init(0, 8000000);
my_oled.clear(PAGE);
my_oled.setCursor(1,16);
my_oled.puts("Smarty");
my_oled.display();
pinMode(VIBRATE,OUTPUT);
pinMode(BUTTON,INPUT_PULLUP);
Serial.begin(9600);
Serial.println("Smarty");
delay(2000);
}
void loop()
{
digitalWrite(VIBRATE,!digitalRead(BUTTON));

  // Check if we need to update seconds, minutes, hours:
  if (lastUpdate + CLOCK_SPEED < millis())
  {
    lastUpdate = millis();
    // Add a second, update minutes/hours if necessary:
    updateTime();
    // Draw the clock:
    my_oled.clear(PAGE);  // Clear the buffer
    my_oled.scrollStop();
    char charBuf[3];
    String h = String(hours);
    String m = String(minutes);
    String s = String(seconds);
    
    h.toCharArray(charBuf, 3);
    my_oled.setCursor(1,16);
    my_oled.puts(charBuf);

    my_oled.setCursor(14,16);
    my_oled.puts("-");
      
    m.toCharArray(charBuf, 3);
    my_oled.setCursor(18,16); 
    my_oled.puts(charBuf);
 
    my_oled.setCursor(31,16);
    my_oled.puts("-");

    s.toCharArray(charBuf, 3);
    my_oled.setCursor(35,16); 
    my_oled.puts(charBuf);
    my_oled.display(); // Draw the memory buffer
  }
}
