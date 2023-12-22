#include <gtest/gtest.h>
#include "../TwoDigitSevenSegment.h"

struct defaultDoubleDigit : TwoDigitSevenSegment
{
    defaultDoubleDigit() : TwoDigitSevenSegment(
        4, 5
    )
    {
    }
};

TEST(TwoDigitSevenSegmentTest, TestSetNumber)
{
    defaultDoubleDigit doubleDigit = defaultDoubleDigit();
    doubleDigit.setNumber(0);
    EXPECT_EQ(doubleDigit.getNumber(), 0);
    doubleDigit.setNumber(99);
    EXPECT_EQ(doubleDigit.getNumber(), 99);
}

TEST(TwoDigitSevenSegmentTest, TestTurnOff)
{
    defaultDoubleDigit doubleDigit = defaultDoubleDigit();
    doubleDigit.turnOn();
    doubleDigit.turnOff();
    SingleDigitSevenSegment* digits = doubleDigit.getDigits();
    for (int i=0; i<2; i++)
        for (int j=0; j<7; j++)
            EXPECT_FALSE(digits[i].getSegments()[j].getState());
}

TEST(TwoDigitSevenSegmentTest, TestTurnOn)
{
    defaultDoubleDigit doubleDigit = defaultDoubleDigit();
    doubleDigit.turnOff();
    doubleDigit.turnOn();
    SingleDigitSevenSegment* digits = doubleDigit.getDigits();
    for (int i=0; i<2; i++)
        for (int j=0; j<7; j++)
            EXPECT_TRUE(digits[i].getSegments()[j].getState());
}

TEST(TwoDigitSevenSegmentTest, TestSetLedSettings)
{
    defaultDoubleDigit doubleDigit = defaultDoubleDigit();

    doubleDigit.setLedSettings(255, 255, 255, 255);
    rgbColors maxColors = rgbColors(255,255,255);
    SingleDigitSevenSegment* digits = doubleDigit.getDigits();
    for (int i=0; i<2; i++)
        for (int j=0; j<7; j++)
        {
            EXPECT_EQ(digits[i].getSegments()[j].getColors(), maxColors);
            EXPECT_EQ(digits[i].getSegments()[j].getBrightness(), 255);
        }

    doubleDigit.setLedSettings(0, 0, 0, 0);
    rgbColors minColors = rgbColors(0,0,0);
    digits = doubleDigit.getDigits();
    for (int i=0; i<2; i++)
        for (int j=0; j<7; j++)
        {
            EXPECT_EQ(digits[i].getSegments()[j].getColors(), minColors);
            EXPECT_EQ(digits[i].getSegments()[j].getBrightness(), 0);
        }
}
