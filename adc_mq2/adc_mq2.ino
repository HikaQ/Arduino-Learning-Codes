// 注意：烟雾报警要连5Vin 引脚，千万不能连3V3 如果ESP发烫，马上拔电
const int MQ2_PIN = 8;  // MQ2传感器连接的引脚
const int BUZZER_PIN = 14; // 蜂鸣器连接的引脚
uint16_t adc_val = 0; // 放数字值
uint32_t adc_vol = 0; // 放模拟值 电压值
bool buzzerState = false; // 蜂鸣器状态

void setup()
{
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT); // 设置蜂鸣器引脚为输出模式
  digitalWrite(BUZZER_PIN, HIGH); // 初始关闭蜂鸣器

  Serial.println("MQ2传感器监测系统启动");
  Serial.println("电压超过3000mV时蜂鸣器报警");
}

void loop()
{
  adc_val = analogRead(MQ2_PIN);
  adc_vol = analogReadMilliVolts(MQ2_PIN);
  Serial.print("ADC值:");
  Serial.print(adc_val);
  Serial.print(" | 电压:");
  Serial.print(adc_vol);
  Serial.println("mV");
  // 检测电压是否超过3000mV
  if(adc_vol > 3000)
  {
    if(!buzzerState) {
      Serial.println("警告：电压超过3000mV！蜂鸣器报警！");
      buzzerState = true;
    }
    digitalWrite(BUZZER_PIN, LOW); // 打开蜂鸣器
  }
  else
  {
    if(buzzerState) {
      Serial.println("电压恢复正常，关闭蜂鸣器");
      buzzerState = false;
    }
    digitalWrite(BUZZER_PIN, HIGH); // 关闭蜂鸣器
  }
  delay(1000);
}
