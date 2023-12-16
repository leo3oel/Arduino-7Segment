#ifndef BASICSEGMENT_H
#define BASICSEGMENT_H

#include <Adafruit_NeoPixel.h>

class rgbColors
{
public:
    unsigned short red = 0;
    unsigned short green = 255;
    unsigned short blue = 0;
    rgbColors();
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
    virtual ~Segment() {}
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
    BasicSegment();
    BasicSegment(Adafruit_NeoPixel& ledArray, short startLed, short segmentLength);
    void turnOn();
    void turnOff();
    void setBrightness(short brightness);
    void setColor(unsigned short red, unsigned short green, unsigned short blue);
};

#endif
