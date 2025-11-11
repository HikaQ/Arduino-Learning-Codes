hw_timer_t *timer0 = NULL;
uint8_t count_index = 0;  /* 代表倒计时的时间 */
bool count_flag = false;
const int buttonPin = 0;  // 按钮连接到数字引脚0
const int buzzerPin = 4;  // 蜂鸣器连接到数字引脚4
const int ledPin = 43;  // LED连接到数字引脚4

void timer0_callback(void)
{
  if (count_index < 5)
  {
    count_index++;
  }
  digitalWrite(ledPin, !digitalRead(ledPin));
}

void setup() {
  // LED灯初始化
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  // 按钮初始化
  pinMode(buttonPin, INPUT_PULLUP);
  // 蜂鸣器初始化
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, HIGH);

  /* 初始化定时器 */
  timer0 = timerBegin(0, 80, true);
  /* 注册中断回调函数 */
  timerAttachInterrupt(timer0, timer0_callback, true);
  /* 设置定时时间和触发方式 */
  timerAlarmWrite(timer0, 1000000, true);
  /* 启动定时器 */
  timerAlarmEnable(timer0);
  /* 关闭定时器 */
  timerAlarmDisable(timer0);
}

void loop() {
  if (digitalRead(buttonPin) == LOW)
  {
    delay(50); // 50ms 延时消抖
    if (digitalRead(buttonPin) == LOW)
    {
      count_flag = true; // 计时功能开始
    }
    // 等待按钮释放
    while (digitalRead(buttonPin) == LOW) {
      delay(10);
    }
  }

  if (count_flag)
  {
    digitalWrite(buzzerPin, LOW); // 蜂鸣器开始短叫一声
    delay(100);
    digitalWrite(buzzerPin, HIGH); // 蜂鸣器结束
    timerWrite(timer0, 0);  // 定时器计数归零 写0进去
    timerAlarmEnable(timer0); // 定时器开启计时
    count_flag = false;
    count_index = 0; // 计算值要清零
  }

  if (count_index == 5)
  {
    timerAlarmDisable(timer0); // 结束定时 关闭定时器
    digitalWrite(buzzerPin, LOW);
    delay(500); // 叫500ms
    digitalWrite(buzzerPin, HIGH); // 蜂鸣器开关闭
    count_index = 0; // 计数值要清零
  }
}

