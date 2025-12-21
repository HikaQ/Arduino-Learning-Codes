#include "SSD1306Wire.h"
SSD1306Wire display(0x3c, 39, 38); // 地址0x3c, SDA=39, SCL=38

void drawGraphicsDemo() {
  // 设置字体
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, "Graphics Demo");
  
  // 画多个点
  for(int i = 0; i < 10; i++) {
    display.setPixel(10 + i*2, 20 + i);
  }
  
  // 画多条线
  display.drawLine(0, 30, 50, 30);    // 水平线
  display.drawLine(60, 30, 60, 50);   // 垂直线
  display.drawLine(70, 30, 120, 50);  // 斜线
  
  // 画多个矩形
  display.drawRect(0, 55, 25, 8);     // 矩形框
  display.fillRect(30, 55, 25, 8);    // 填充矩形
  
  // 画多个圆
  display.drawCircle(80, 56, 7);      // 圆形框
  display.fillCircle(100, 56, 7);     // 填充圆
}

void drawMoreShapes() {
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "More Shapes:");
  
  // 绘制三角形
  display.drawLine(10, 20, 30, 20);  // 底边
  display.drawLine(10, 20, 20, 10);  // 左边
  display.drawLine(20, 10, 30, 20);  // 右边
  
  // 绘制网格
  for(int i = 0; i <= 8; i++) {
    display.drawLine(40 + i*10, 15, 40 + i*10, 55);  // 垂直线
    display.drawLine(40, 15 + i*5, 120, 15 + i*5);   // 水平线
  }
  
  // 绘制圆弧线
  for(int i = 0; i < 180; i += 10) {
    int x = 20 + cos(i * 3.14 / 180) * 15;
    int y = 40 + sin(i * 3.14 / 180) * 15;
    display.setPixel(x, y);
  }
}

void setup() {
  // 初始化显示屏
  display.init();
}

void loop() {
  // 可以在这里添加动画或交互功能
  delay(3000);
  display.clear();
  // 绘制图形演示
  drawGraphicsDemo();
  display.display();

  delay(3000);
  display.clear();
  // 绘制图形演示
  drawMoreShapes();
  display.display();
}