#define NEO_GRB 0
#define NEO_KHZ800 0

class Adafruit_NeoPixel
{
public:
    Adafruit_NeoPixel() = default;
    Adafruit_NeoPixel(int i, int a, int j) {};
    int ledArray;
    void setPixelColor(int i, int Color) {};
    int Color(int red, int green, int blue) {return 0;};
    void setBrightness(int color) {};
    void show() {};
    int getBrightness() {return 0;};
};