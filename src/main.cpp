// #include <Arduino.h>

// // put function declarations here:
// int myFunction(int, int);

// void setup() {
//   // put your setup code here, to run once:
//   int result = myFunction(2, 3);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }


#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 2
#define TFT_CS 15
#define TFT_RST 4
#define TFT_MOSI 18
#define TFT_SCK 5
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCK, TFT_RST, -1);

void setup() {
  tft.begin();

  tft.setCursor(26, 120);
  tft.setTextColor(ILI9341_RED);
  tft.setTextSize(3);
  tft.println("Hello, TFT!");

  tft.setCursor(20, 160);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(2);
  tft.println("I can has colors?");
}

void loop() { }