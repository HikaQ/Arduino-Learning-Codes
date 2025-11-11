const int ledPin = 43;  // led 引脚
const int buzzerPin = 1;  // 蜂鸣器引脚
int len = 0; // 读取的数据长度
String serial_data; // 存放的数据字符串

void serial_callback(void) // 串口回调函数
{
  if (Serial.available() > 0)
  {
    len = Serial.available(); // 接收缓存区的长度
    for (int i = 0; i < len; i++) /* 数据接收 */
    {
      serial_data += (char)Serial.read();
    }
    // Serial.println(serial_data);
    /* 数据解析 */
    if (serial_data.equals("LED_ON")) // 判断接收的数据是否是LED_ON
    {
      digitalWrite(ledPin, LOW); // 灯亮
    }
    else if (serial_data.equals("LED_OFF")) // 判断接收的数据是否是LED_OFF
    {
      digitalWrite(ledPin, HIGH); // 灯灭
    }
    else if (serial_data.equals("BEEP_ON")) // 判断接收的数据是否是BEEP_ON
    {
      digitalWrite(buzzerPin, LOW); // 蜂鸣器响
    }
    else if (serial_data.equals("BEEP_OFF")) // 判断接收的数据是否是BEEP_OFF
    {
      digitalWrite(buzzerPin, HIGH);
    }
    serial_data.clear();
  }
}


void setup() {
  Serial.begin(115200);
  Serial.onReceive(serial_callback);
  pinMode(ledPin, HIGH);
  digitalWrite(ledPin, HIGH);

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
