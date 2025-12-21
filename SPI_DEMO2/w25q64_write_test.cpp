#include "w25q64.h"

// 写入数据
void writeData(uint32_t addr, const uint8_t *data, uint16_t len) {
  writeEnable();
  digitalWrite(15, LOW);
  mySPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  mySPI.transfer(0x02); // 页编程指令
  mySPI.transfer((addr >> 16) & 0xFF);
  mySPI.transfer((addr >> 8) & 0xFF);
  mySPI.transfer(addr & 0xFF);
  for (uint16_t i = 0; i < len; i++) {
    mySPI.transfer(data[i]);
  }
  mySPI.endTransaction();
  digitalWrite(15, HIGH);
  waitBusy();
}

// 测试字符串写入
void testStringWrite() {
  Serial.println("\n=== 字符串写入测试 ===");
  char* TEST_STRING = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  uint16_t strLen = strlen(TEST_STRING);
  
  Serial.print("测试字符串: ");
  Serial.println(TEST_STRING);
  
  eraseSector(0x1000); // 1. 先擦除0x1000地址对应的扇区
  writeData(0x1000, (const uint8_t*)TEST_STRING, strLen); // 2. 写入字符串到0x1000地址
}

// 等待Flash操作完成
void waitBusy() {
  while (true) {
    digitalWrite(15, LOW);
    mySPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
    mySPI.transfer(0x05); // 读取状态 0x05
    uint8_t status = mySPI.transfer(0x00);
    mySPI.endTransaction();
    digitalWrite(15, HIGH);
    if (!(status & 0x01)) break;
    delay(1);
  }
}

// 写使能
void writeEnable() {
  digitalWrite(15, LOW);
  mySPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  mySPI.transfer(0x06); // 写使能 0x06 指令
  mySPI.endTransaction();
  digitalWrite(15, HIGH);
}

// 擦除扇区（4KB）
void eraseSector(uint32_t addr) {
  writeEnable();
  digitalWrite(15, LOW);
  mySPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  mySPI.transfer(0x20);
  mySPI.transfer((addr >> 16) & 0xFF);
  mySPI.transfer((addr >> 8) & 0xFF);
  mySPI.transfer(addr & 0xFF);
  mySPI.endTransaction();
  digitalWrite(15, HIGH);
  waitBusy();
}