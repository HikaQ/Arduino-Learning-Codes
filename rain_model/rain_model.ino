#include "rain_function.h"

bool monitoringEnabled = false;   // 检测功能开关状态
bool lastButtonState = HIGH;      // 上一次按钮状态
bool currentButtonState;          // 当前按钮状态
int buttonPressCount = 0;         // 按钮按下次数计数器

void setup() { 
  init_function(); // 初始化系统
}

void loop() {
  button_function(); // 处理按钮按下事件

  // 如果检测功能开启，则进行雨滴检测
  if (monitoringEnabled) {
    rain_function(); // 检测雨水
  }

  delay(10); // 短暂延时，防止过于频繁的循环
}
