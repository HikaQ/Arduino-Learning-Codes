#ifndef RAIN_FUNCTION_H
#define RAIN_FUNCTION_H

#include <Arduino.h>

// 引脚定义
extern const int rainSensorPin;
extern const int buzzerPin;
extern const int buttonPin;

// 全局变量声明
extern bool monitoringEnabled;
extern bool lastButtonState;
extern bool currentButtonState;
extern int buttonPressCount;

// 函数声明
void init_function();
void button_function();
void rain_function();

#endif