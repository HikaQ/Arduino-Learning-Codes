#include "rain_function.h"

// 下雨提示器（带开关控制）
const int rainSensorPin = 4;  // 雨滴传感器D0引脚连接到数字引脚4
const int buzzerPin = 14;     // 蜂鸣器连接到数字引脚14
const int buttonPin = 0;      // 按钮连接到数字引脚0

void init_function(){
  pinMode(rainSensorPin, INPUT);  // 设置雨滴传感器引脚为输入模式
  pinMode(buzzerPin, OUTPUT);     // 设置蜂鸣器引脚为输出模式
  pinMode(buttonPin, INPUT_PULLUP); // 设置按钮引脚为输入模式，启用内部上拉电阻
  digitalWrite(buzzerPin, HIGH);  // 初始化蜂鸣器为关闭状态

  Serial.begin(9600); // 初始化串口，用于调试

  Serial.println("下雨提示器已启动");
  Serial.println("按下按钮开启/关闭检测功能");
  Serial.print("按钮按下次数：");
  Serial.println(buttonPressCount);
}

void button_function(){
  // 读取按钮状态（使用内部上拉电阻，按下时为LOW，未按下时为HIGH）
  currentButtonState = digitalRead(buttonPin);

  // 检测按钮按下（下降沿检测）
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    delay(50);
    currentButtonState = digitalRead(buttonPin); // 再次确认按钮状态

    if(currentButtonState == LOW) {
      monitoringEnabled = !monitoringEnabled; // 切换检测功能状态
    
      // 串口输出状态
      if (monitoringEnabled) {
        Serial.println("检测功能已开启");
      } else {
        Serial.println("检测功能已关闭");
        digitalWrite (buzzerPin, HIGH); // 关闭蜂鸣器
      }
      // 等待按钮释放
      while(digitalRead(buttonPin) == LOW) {
        delay(10);
      }
    }
  }

  lastButtonState = currentButtonState; // 更新上一次按钮状态

  // 如果检测功能开启，则进行雨滴检测
  if (monitoringEnabled) {
    // 读取雨滴传感器状态
  }
}

void rain_function(){
  int rainState = digitalRead(rainSensorPin);

    // 判断是否有雨
    if (rainState == LOW) {
      digitalWrite(buzzerPin, LOW); // 有雨时，蜂鸣器鸣叫
      Serial.println("希克君检测到雨水！");
    } else {
      digitalWrite(buzzerPin, HIGH);
    }
}