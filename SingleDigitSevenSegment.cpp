#include "SingleDigitSevenSegment.h"

SingleDigitSevenSegment::SingleDigitSevenSegment(
    Adafruit_NeoPixel& ledArray, 
    unsigned short startLed, 
    unsigned short segmentLength
    )
{
    initializeSegments(ledArray, startLed, segmentLength);
}

SingleDigitSevenSegment::SingleDigitSevenSegment(
    Adafruit_NeoPixel& ledArray, 
    unsigned short startLed, 
    unsigned short segmentLength, 
    short segmentPosition[7]
    )
{   
    initializeSegments(ledArray,startLed, segmentLength);
    for (short i=0; i<7; i++)
        this->segmentPosition[i] = segmentPosition[i];
}

void SingleDigitSevenSegment::initializeSegments(
    Adafruit_NeoPixel& ledArray, 
    unsigned short startLed, 
    unsigned short segmentLength
    )
{
    for (short i=0; i<7; i++)
    {
        unsigned short currentStartLed = startLed + (i+1)*segmentLength;
        segments[i] = BasicSegment(ledArray, currentStartLed, segmentLength);
    }
}

void SingleDigitSevenSegment::turnOff()
{
    for (short i=0; i<7; i++)
        segments[i].turnOff();
}

void SingleDigitSevenSegment::turnOn()
{
    for (short i=0; i<7; i++)
        segments[i].turnOn();
}

void SingleDigitSevenSegment::setNumber(unsigned short number)
{
    if (number>9 || number<0)
        throw std::invalid_argument("value must be in range 0..9");
    if (currentNumber != number)
    {
        currentNumber = number;
        bool segmentsToTurnOn[7] = {true, true, true, true, true, true, true};
        switch(number) {
            case 0: 
                segmentsToTurnOn[6] = false;
                break;
            case 1:
                segmentsToTurnOn[0] = false;
                segmentsToTurnOn[3] = false;
                segmentsToTurnOn[4] = false;
                segmentsToTurnOn[5] = false;
                segmentsToTurnOn[6] = false;
                break;
            case 2:
                segmentsToTurnOn[2] = false;
                segmentsToTurnOn[5] = false;
                break;
            case 3:
                segmentsToTurnOn[4] = false;
                segmentsToTurnOn[5] = false;
                break;
            case 4:
                segmentsToTurnOn[0] = false;
                segmentsToTurnOn[3] = false;
                segmentsToTurnOn[4] = false;
                break;
            case 5:
                segmentsToTurnOn[1] = false;
                segmentsToTurnOn[4] = false;
                break;
            case 6:
                segmentsToTurnOn[0] = false;
                segmentsToTurnOn[1] = false;
                break;
            case 7:
                segmentsToTurnOn[3] = false;
                segmentsToTurnOn[4] = false;
                segmentsToTurnOn[5] = false;
                segmentsToTurnOn[6] = false;
            case 8:
                break;
            case 9:
                segmentsToTurnOn[3] = false;
                segmentsToTurnOn[4] = false;
                break;
        }
        turnOnSegments(segmentsToTurnOn);
    }
    ledArray.show();
}

void SingleDigitSevenSegment::turnOnSegments(bool segmentList[7])
{
    for (short i=0; i<7; i++)
    {
        if (segmentList[i])
            segments[segmentPosition[i]].turnOn();
        else
            segments[segmentPosition[i]].turnOff();
    }
}

void SingleDigitSevenSegment::setLedSettings(unsigned short red, unsigned short green, unsigned short blue, unsigned short brightness)
{
    ledArray.setBrightness(brightness);
    for (int i=0; i<7; i++)
    {
        segments[i].setColors(red, green, blue);
        segments[i].setBrightness(brightness);
    }
}

int SingleDigitSevenSegment::getNumber()
{
    return currentNumber;
}

BasicSegment* SingleDigitSevenSegment::getSegments()
{
    return segments;
}
