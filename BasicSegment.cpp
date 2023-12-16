#include "BasicSegment.h"

BasicSegment::BasicSegment(Adafruit_NeoPixel& ledArray, short startLed, short segmentLength)
{
    this->startLed = startLed;
    this->segmentLength = segmentLength;
    this->ledArray = ledArray;
}

void BasicSegment::turnOff()
{
    if(state)
    {
        state = false;
        for (short i = startLed; i < (startLed + segmentLength); i++)
        {
            ledArray.setPixelColor(i, ledArray.Color(0,0,0));
        }
    }
}

void BasicSegment::turnOn()
{   
    if(!state)
    {
        state = true;
        for (short i = startLed; i < (startLed + segmentLength); i++)
        {
            ledArray.setPixelColor(i, 
                ledArray.Color(
                    colors.red,
                    colors.green,
                    colors.blue
                )
            );
        }
        ledArray.setBrightness(brightness);
    }
}

void BasicSegment::setBrightness(short brightness)
{
    if (this->brightness != brightness)
    {
        this->brightness = brightness;
        ledArray.setBrightness(brightness);
    }
}

void BasicSegment::setColor(unsigned short red, unsigned short green, unsigned short blue)
{
    rgbColors newColor = rgbColors(red, green, blue);
    if (colors != newColor)
    {
        colors = newColor;
        for (short i = startLed; i < (startLed + segmentLength); i++)
        {
            ledArray.setPixelColor(i, 
                ledArray.Color(
                    colors.red,
                    colors.green,
                    colors.blue
                )
            );
        }
    }
}
