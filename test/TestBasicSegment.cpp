#include <gtest/gtest.h>
#include "../BasicSegment.h"

struct defaultBasicSegment : BasicSegment
{

    defaultBasicSegment() : BasicSegment(
        Adafruit_NeoPixel(10, 1, NEO_GRB + NEO_KHZ800), 4,5
        )
    {
    }
};

TEST(BasicSegment, TurnOnTest)
{
    defaultBasicSegment segment = defaultBasicSegment();
    segment.turnOn();
    EXPECT_TRUE(segment.getState());
}

TEST(BasicSegment, TurnOffTest)
{
    defaultBasicSegment segment = defaultBasicSegment();
    segment.turnOn();
    EXPECT_TRUE(segment.getState());
    segment.turnOff();
    EXPECT_FALSE(segment.getState());
}

TEST(BasicSegment, SetBrightness)
{
    defaultBasicSegment segment = defaultBasicSegment();
    segment.setBrightness(5);
    EXPECT_EQ(segment.getBrightness(), 5);
    segment.setBrightness(255);
    EXPECT_EQ(segment.getBrightness(), 255);
}

TEST(BasicSegment, setColors)
{
    defaultBasicSegment segment = defaultBasicSegment();
    rgbColors maxColors = rgbColors(255,255,255);
    segment.setColors(255,255,255);
    EXPECT_EQ(segment.getColors(), maxColors);
    rgbColors minColors = rgbColors(0,0,0);
    segment.setColors(0,0,0);
    EXPECT_EQ(segment.getColors(), minColors);
}
