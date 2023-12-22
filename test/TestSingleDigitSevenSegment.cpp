#include <gtest/gtest.h>
#include "../SingleDigitSevenSegment.h"
#include "../BasicSegment.h"

struct defaultSingleDigit : SingleDigitSevenSegment
{
    defaultSingleDigit() : SingleDigitSevenSegment(
        Adafruit_NeoPixel(10, 1, NEO_GRB + NEO_KHZ800), 1,1
    )
    {
    }
};

TEST(SingleDigitSevenSegmentTest, SetNumberTest) {
    defaultSingleDigit singleDigit = defaultSingleDigit();
    singleDigit.setNumber(5);
    EXPECT_EQ(singleDigit.getNumber(), 5);
    singleDigit.setNumber(9);
    EXPECT_EQ(singleDigit.getNumber(), 9);
}

TEST(SingleDigitSevenSegmentTest, TurnOnTest) {
    defaultSingleDigit singleDigit = defaultSingleDigit();
    singleDigit.turnOff();
    singleDigit.turnOn();
    BasicSegment* segments = singleDigit.getSegments();
    EXPECT_TRUE(segments[0].getState());
    EXPECT_TRUE(segments[1].getState());
    EXPECT_TRUE(segments[2].getState());
    EXPECT_TRUE(segments[3].getState());
    EXPECT_TRUE(segments[4].getState());
    EXPECT_TRUE(segments[5].getState());
    EXPECT_TRUE(segments[6].getState());
}

TEST(SingleDigitSevenSegmentTest, TurnOffTest) {
    defaultSingleDigit singleDigit = defaultSingleDigit();
    singleDigit.turnOn();
    singleDigit.turnOff();
    BasicSegment* segments = singleDigit.getSegments();
    EXPECT_FALSE(segments[0].getState());
    EXPECT_FALSE(segments[1].getState());
    EXPECT_FALSE(segments[2].getState());
    EXPECT_FALSE(segments[3].getState());
    EXPECT_FALSE(segments[4].getState());
    EXPECT_FALSE(segments[5].getState());
    EXPECT_FALSE(segments[6].getState());
}

TEST(SingleDigitSevenSegmentTest, SetLedSettingsTest) {
    defaultSingleDigit singleDigit = defaultSingleDigit();
    singleDigit.setLedSettings(255, 255, 255, 255);
    BasicSegment* segments = singleDigit.getSegments();
    rgbColors maxColors = rgbColors(255,255,255);
    EXPECT_EQ(segments[0].getColors(), maxColors);
    EXPECT_EQ(segments[6].getColors(), maxColors);
    EXPECT_EQ(segments[6].getBrightness(), 255);
    singleDigit.setLedSettings(0, 0, 0, 0);
    segments = singleDigit.getSegments();
    rgbColors minColors = rgbColors(0,0,0);
    EXPECT_EQ(segments[0].getColors(), minColors);
    EXPECT_EQ(segments[6].getColors(), minColors);
    EXPECT_EQ(segments[6].getBrightness(), 0);
}
