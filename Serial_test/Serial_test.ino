unsigned long time0 = 0;  /* 存放当前时间 */
unsigned long temp = 0;   /* 用于记录时间点 */
unsigned long t = 1000;   /* 时间间隔 */

int len;  // 存放接受数据的长度
unsigned char rec_data[50];   // 存放接受的数据

void setup() {
  // 设定串口波特率
  Serial.begin(115200);
}

void loop() {
  time0 = millis();       /* 获取程序启动以来的时间 */

  if ((time0 - temp) >= t)/* 说明1秒已经到了 */
  {
    temp = time0;         /* 更新时间点 */

    /* 执行周期为1秒的操作 */
    Serial.printf("waitting for serial data\r\n");
    // Serial.println("waitting for serial data");
  }
}
