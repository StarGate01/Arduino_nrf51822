#include "SFE_MicroOLED.h"

#define VIBRATE 7
#define BUTTON 4

SPI my_spi(P0_29, NC, P0_30);
MicroOLED my_oled(my_spi, P0_1, P0_0, P0_2);

const int CLOCK_SPEED = 1000;
// Use these variables to set the initial time
int hours = (__TIME__[0] -'0') *10 +( __TIME__[1] -'0') ;
int minutes = (__TIME__[3] -'0') *10 +( __TIME__[4] -'0') ;
int seconds = (__TIME__[7] -'0') *10 +( __TIME__[7] -'0') ;
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
	my_oled.setCursor(0,0);
	my_oled.puts("Its Alive");
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
char txtBuf[9];

  // Check if we need to update seconds, minutes, hours:
  if (lastUpdate + CLOCK_SPEED < millis())
  {
    lastUpdate = millis();
  
    updateTime();  // Add a second, update minutes/hours if necessary:

    my_oled.clear(PAGE);  // Clear the frame buffer

    sprintf(txtBuf,"%02d:%02d:%02d",hours,minutes,seconds);

    my_oled.setCursor(5,12);
    my_oled.puts(txtBuf);

    my_oled.display(); // Draw the memory buffer
  }
}