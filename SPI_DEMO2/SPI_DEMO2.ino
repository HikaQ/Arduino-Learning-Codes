// #include "w25q64.h"
#include <SPI.h>
SPIClass mySPI(HSPI); // 创建 SPI 对象（使用 HSPI）

void setup() {
  Serial.begin(115200); //串口
  pinMode(15, OUTPUT); // 设置CS 引脚模式
  digitalWrite(15, HIGH); // 默认不选中 拉高时候不选中

  mySPI.begin(14, 12, 13, 15); // 使用自定义引脚初始化 SPI CS_PIN: 15    SCK_PIN: 14  MISO_PIN:
  readChipID(); // 读取芯片ID验证连接
  // 分别测试写入和读取
  testStringWrite();
  testStringRead();
}

void loop() {
// 这里不要写代码
}

// 读取芯片ID
void readChipID() {
  digitalWrite(15, LOW); // 选中从机 拉低CS引脚
  mySPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0)); // 配置SPI参数（1MHz, SPI_
  mySPI.transfer(0x9F); // 读取JEDEC ID指令 // 发送指令读取 JEDEC ID 0x9F
  uint8_t manufacturerID = mySPI.transfer(0x00); // 接收完整的 JEDEC ID 0xEF
  mySPI.endTransaction(); // 结束事务

  digitalWrite(15, HIGH); // 释放从机 拉高CS引脚

  Serial.print("制造商 ID: 0x"); // 打印完整结果
  Serial.println(manufacturerID, HEX);
}