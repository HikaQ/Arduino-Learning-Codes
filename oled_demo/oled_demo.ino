#include <Wire.h>        // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy: #include "SSD1306.h"

//实例化
SSD1306Wire display(0x3C, 39, 38, GEOMETRY_128_64, I2C_TWO, 800000);

void setup()
{
  display.init(); // 初始化OLED
  display.flipScreenVertically();

  display.clear(); // 清屏
  display.setPixelColor(10, 10, WHITE);

  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, "helloworld");

  display.setFont(ArialMT_Plain_24);
  display.drawString(0, 16, "hello");

  display.display();

  display.drawLine(0, 50, 50, 50);
  display.display();
}

void loop() {

}