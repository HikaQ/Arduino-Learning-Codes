// ESP32蓝牙控制SG90舵机
// 主程序
#include "servo.h"
#include "ble.h"
#include "screen.h"

void setup() {
  // 初始化串口
  Serial.begin(115200);
  delay(100); // 等待串口稳定

  Serial.println("\n=== ESP32蓝牙舵机控制器 ===");
  Serial.println("系统初始化中...");

  // 初始化舵机
  servo_init();

  // // 初始化蓝牙
  ble_init();

  // // 初始化OLED屏幕
  screen_init();

  Serial.println("=== 系统就绪 ===");
  Serial.println("使用手机蓝牙连接设备，发送0-180的数字控制舵机");
}

void loop() {
  // 主循环可以空着，蓝牙会在后台自动运行
  delay(100); // 短暂延时，避免CPU占用过高

  int current_angle = servo_get_angle();
  screen_update(current_angle);
}