// 按键中断服务程序，当按键中断触发时自动调用
void key_int_isr(void)
{
  digitalWrite(43, !digitalRead(43));
}

void setup() {
  pinMode(43, OUTPUT);
  digitalWrite(43, HIGH);
  pinMode(0, INPUT_PULLUP);

  attachInterrupt(0, key_int_isr, FALLING);
}

void loop() {
  delay(1000000);
}