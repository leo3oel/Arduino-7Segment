#ifndef BASICSEGMENT_H
#define BASICSEGMENT_H

#ifdef ARDUINO
#include <Adafruit_NeoPixel.h>
#else
#include "test/Placeholders/Adafruit.h"
#endif

#include <stdexcept>

class rgbColors
{
public:
    unsigned short red = 0;
    unsigned short green = 255;
    unsigned short blue = 0;
    rgbColors() = default;
    rgbColors(unsigned short red, unsigned short green, unsigned short blue)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
    };

    bool operator==(const rgbColors& other) const
    {
        return (red == other.red) && (green == other.green) && (blue == other.blue);
    };

    bool operator!=(const rgbColors& other) const
    {
        return !(*this == other);
    };
};

class Segment
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Segment() {};
};

class BasicSegment : public Segment
{
private:
    short segmentLength;
    short startLed;
    bool state;
    Adafruit_NeoPixel ledArray;
    rgbColors colors;
    short brightness = 200;

public:
    BasicSegment() = default;
    BasicSegment(Adafruit_NeoPixel& ledArray, short startLed, short segmentLength);
    ~BasicSegment() {};
    void turnOn();
    void turnOff();
    void setBrightness(short brightness);
    void setColors(unsigned short red, unsigned short green, unsigned short blue);
    bool getState();
    int getBrightness();
    rgbColors getColors();
};

#endif
