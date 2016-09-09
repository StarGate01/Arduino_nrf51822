/*
 * Copyright (c) 2016 RedBear
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#include <SPI_Master.h>

void setup() {
  Serial.begin(115200);
  Serial.println("SPI Master example");
  // put your setup code here, to run once
  pinMode(SPI_CS, OUTPUT);
  digitalWrite(SPI_CS, HIGH);
  delay(500);
  SPI_Master.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Sending SPI Data 0x53,0x00,0x00,0x00");
  digitalWrite(SPI_CS, LOW);
  SPI_Master.transfer(0x53);
  SPI_Master.transfer(0x00);
  SPI_Master.transfer(0x00);
  SPI_Master.transfer(0x00);
  digitalWrite(SPI_CS, HIGH);
  delay(1000);
}
