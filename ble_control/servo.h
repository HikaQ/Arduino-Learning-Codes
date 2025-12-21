#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>

// ---------- 舵机配置参数 ----------
#define SERVO_PIN 14        // 舵机信号线连接的GPIO引脚
#define PWM_CHANNEL 3       // PWM通道号（0-15）
#define SERVO_FREQ 50       // PWM频率（Hz）- SG90需要50Hz
#define PWM_RESOLUTION 10   // PWM分辨率（位）- 10位=0-1023
#define MIN_ANGLE 0         // 最小角度
#define MAX_ANGLE 180       // 最大角度

// ---------- 函数声明 ----------
void servo_init();          // 初始化舵机
void servo_set_angle(int angle); // 设置舵机角度（0-180度）
int servo_get_angle();      // 获取当前角度

#endif