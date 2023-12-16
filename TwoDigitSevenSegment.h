#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

#include "Import/Arduino-Pin/pin.h"
#include "SingleDigitSevenSegment.h"

class TwoDigitSevenSegment
{
private:
    short segmentLength;
    Pin dataPin;
    SingleDigitSevenSegment digits[2];
    Adafruit_NeoPixel ledPixels;


public:
    TwoDigitSevenSegment(Pin dataPin, short segmentLength);
    void setNumber(short number);
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
