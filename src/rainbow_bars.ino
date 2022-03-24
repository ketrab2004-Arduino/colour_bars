#include <stdint.h>
#include <SPI.h>
#include <Wire.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>

#include <Colouring.h>

#define TFT_CS 10
#define TFT_DC 9
#define TFT_BL 5
#define SD_CS 4

#define WIDTH 320
#define HEIGHT 240
#define BRIGHTNESS 127

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_FT6206 ts = Adafruit_FT6206();

void setup() {
    Serial.begin(115200);
    tft.begin();
    ts.begin();

    pinMode(TFT_BL, OUTPUT);
    analogWrite(TFT_BL, BRIGHTNESS);

    tft.setRotation(1);

    // tft.fillScreen( colourFromRGB(255, 255, 255) );
    // delay(1000);

    // tft.fillScreen( colourFromRGB(0, 255, 255) );
    // delay(1000);

    // tft.fillScreen( colourFromRGB(255, 0, 255) );
    // delay(1000);

    // tft.fillScreen( colourFromRGB(255, 165, 0) );
    // tft.println("orange");
    // delay(1000);

    // tft.setCursor(10, 10);
    // tft.println(colourFromRGB(255, 165, 0));
    // tft.println(colourFromRGB(255, 165, 0), HEX);
}

unsigned int hue = 0;
int height = 0;
void loop() {
    auto c = colourFromHSV(hue, 1, 1);
    //tft.fillScreen( c );
    tft.fillRect(0, height, WIDTH, 1, c);

    // tft.color565();

    tft.setCursor(WIDTH>>2, HEIGHT>>2);
    tft.println(hue);

    hue++;
    if (hue >= 360) {
        hue = 0;
    }

    height++;
    if (height >= HEIGHT) {
        height = 0;
    }
}
