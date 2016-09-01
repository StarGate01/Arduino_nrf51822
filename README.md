# Arduino_nrf51822
Updated version of Arduino for nRF51822 based loosely on RBL's latest repo

#IMPORTANT

You must install use the Boards Manager to install one of the Arduino boards which uses an ARM processor, this includes the Arduino Zero or Arduino Due

You must also flash the S130 SoftDevice which is part of the Nordic V9 SDK, onto your device first, as the IDE only compiles the sketch code and it uploads into flash above the location of the S130 SD


#Notable changes from the RBL repo

All mbed and BLE files have been moved to the System folder, this was done because otherwise the IDE compiles every mbed and BLE (SDK) file every time you upload

The files in the System folder are compiled into a static libraru which is linked when you upload

If you need to change any files in the system folder, please run the make file to reboild the static library

Pin mapping is now generic e.g. P0.0 is Pin 0

TX and RX pins are the same as for RBL's repo but because of their strange pin mapping, I had to change them to the new (generic) mapping