#include "TwoDigitSevenSegment.h"

TwoDigitSevenSegment::TwoDigitSevenSegment(unsigned short dataPin, short segmentLength)
    : dataPin(dataPin), segmentLength(segmentLength)
{
    short ledLength = segmentLength * 7 * 2;
    ledPixels = Adafruit_NeoPixel(ledLength, dataPin, NEO_GRB + NEO_KHZ800); // LED Array
    digits[0] = SingleDigitSevenSegment(ledPixels,0,segmentLength);
    digits[1] = SingleDigitSevenSegment(ledPixels,segmentLength*7,segmentLength);
}

void TwoDigitSevenSegment::setNumber(unsigned short number)
{
    digits[1].setNumber(int(number/10));
    digits[0].setNumber(number%10);
}

void TwoDigitSevenSegment::turnOn()
{
    for (int i=0; i<2; i++)
        digits[i].turnOn();
}

void TwoDigitSevenSegment::turnOff()
{
    for (int i=0; i<2; i++)
        digits[i].turnOff();
}

void TwoDigitSevenSegment::setLedSettings(
    unsigned short red, 
    unsigned short green, 
    unsigned short blue, 
    unsigned short brightness
    )
{
    for (int i=0; i<2; i++)
        digits[i].setLedSettings(red, green, blue,  brightness);
}