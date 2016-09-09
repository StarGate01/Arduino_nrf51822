
#ifndef PINS_ARDUINO_H_
#define PINS_ARDUINO_H_

#define RBL_NRF51822

//PIN Define
#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define D8 8
#define D9 9
#define D10 10
#define D11 11
#define D12 12
#define D13 13
#define D14 14
#define D15 15
#define D16 16
#define D17 17
#define D18 18
#define D19 19
#define D20 20
#define D21 21
#define D22 22
#define D23 23
#define D24 24
#define D25 25
#define D26 26
#define D27 27
#define D28 28
#define D29 29
#define D30 30

#define CS   30
#define SPI_CS	30
#define SCK  25
#define MISO 23
#define MOSI 24


// Note I2C (Wire) has not been tested. Its unclear why there are two sets of pins defined for I2C which are used in different places in the mbed code
// So I've set them both to the pins connected to the I2C header on the BLE400
#define SDA0  0
#define SCL0  1

#define SDA1  0
#define SCL1  1


// Note. These "analog" pins are meaningless for the Waveshare BLE400
#define A0 D19
#define A1 D20
#define A2 D21
#define A3 D22
#define A4 D23
#define A5 D24

#define DEFAULT_RX_PIN 11 
#define DEFAULT_TX_PIN 9

#define SERIAL1_RX_PIN 5 
#define SERIAL1_TX_PIN 6
#define SERIAL1_CTX_PIN 7 
#define SERIAL1_RTS_PIN 8

#define TWI_SDA SDA1
#define TWI_SCL SCL1

#define LED D18
#define LED1 D18
#define LED2 D19
#define LED3 D20
#define LED4 D21
#define LED5 D22

#define KEY1 16
#define KEY2 17

#endif

