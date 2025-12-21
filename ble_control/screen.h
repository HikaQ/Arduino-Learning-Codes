#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>
#include "SSD1306Wire.h"

// ========== 屏幕配置 ==========
#define OLED_ADDRESS 0x3C    // OLED I2C地址（通常是0x3C或0x3D）
#define SDA_PIN 39           // ESP32默认SDA引脚
#define SCL_PIN 38           // ESP32默认SCL引脚
#define SCREEN_WIDTH 128     // 屏幕宽度
#define SCREEN_HEIGHT 64     // 屏幕高度

// ========== 函数声明 ==========
void screen_init();               // 初始化屏幕
void screen_update(int servo_angle);  // 更新屏幕显示
void screen_draw_servo_dial(int angle); // 绘制舵机表盘
void screen_draw_pointer(int angle);   // 绘制指针
void screen_draw_info(int angle);      // 绘制角度信息

#endif