void setup() {
  // 设定串口波特率
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()) {
    delay(100); // 等待数据传输完毕
    int n = Serial.available();
    Serial.print("接收到 ");
    Serial.print(n);
    Serial.print("字节数据：");
    delay(100);
    for(int i = 0; i < n; ++i) {
      Serial.print((char)Serial.read());
    }
    Serial.println();
  }
}
