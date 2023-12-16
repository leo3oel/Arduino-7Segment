#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include <Arduino.h>
#include "Import/Arduino-Pin/pin.h"
#include "SingleDigitSevenSegment.h"
// #include "SingleDigitSevenSegment.cpp"

class TwoDigitSevenSegment
{
private:
    short segmentLength;
    unsigned short dataPin;
    SingleDigitSevenSegment digits[2];
    Adafruit_NeoPixel ledPixels;


public:
    TwoDigitSevenSegment(unsigned short dataPin, short segmentLength);
    void setNumber(unsigned short number);
    void turnOff();
    void turnOn();
    void setLedSettings(
        unsigned short red, 
        unsigned short green, 
        unsigned short blue, 
        unsigned short brightness
        );
};

#endif
