#ifndef SINGLEDIGIT_H
#define SINGLEDIGIT_H

#include "BasicSegment.h"

class SingleDigitSevenSegment : public Segment
{
private:
    BasicSegment segments[7];
    short segmentPosition[7] = {4,5,0,1,2,3,6}; // [2,5..] = segment a at pos 2 b at pos 5
    Adafruit_NeoPixel ledArray;
    unsigned short currentNumber;

    void initializeSegments(
        Adafruit_NeoPixel& ledArray, 
        unsigned short startLed, 
        unsigned short  segmentLength
        );
    void turnOnSegments(bool segmentList[7]);

public:
    SingleDigitSevenSegment(
        Adafruit_NeoPixel& ledArray, 
        unsigned short startLed, 
        unsigned short segmentLength
        );
    SingleDigitSevenSegment(
        Adafruit_NeoPixel& ledArray, 
        unsigned short startLed, 
        unsigned short segmentLength, 
        short segmentPosition[7]
        );
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
