const int rainSensorPin = 4; //雨滴传感器D0引脚连接到数字引脚4
const int buzzerPin = 14; //蜂鸣器连接到数字引脚14

void setup()
{
  pinMode(rainSensorPin, INPUT); //设置雨滴传感器引脚为输入模式
  pinMode(buzzerPin, OUTPUT); //设置蜂鸣器引脚为输出模式
  digitalWrite(buzzerPin, HIGH); //初始化蜂鸣器为关闭状态
}

void loop()
{
  // 读取雨滴传感器状态
  int rainState = digitalRead(rainSensorPin);

  if (rainState == LOW)
  {
    digitalWrite(buzzerPin, LOW);
  }
  else
  {
    digitalWrite(buzzerPin, HIGH);
  }
}

// 蜂鸣器响 同时ESP32绿灯亮 绿灯是43号引脚
// 蜂鸣器不响 同时ESP32绿灯不亮 绿灯是43号引脚