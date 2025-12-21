#include "w25q64.h"

// 读取数据
void readData(uint32_t addr, uint8_t *data, uint16_t len) {
  digitalWrite(15, LOW);
  mySPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  mySPI.transfer(0x03); // 读取指令 0x03
  mySPI.transfer((addr >> 16) & 0xFF);
  mySPI.transfer((addr >> 8) & 0xFF);
  mySPI.transfer(addr & 0xFF);
  for (uint16_t i = 0; i < len; i++) {
    data[i] = mySPI.transfer(0x00);
  }
  mySPI.endTransaction();
  digitalWrite(15, HIGH);
}

// 测试字符串读取
void testStringRead() {
  Serial.println("\n=== 字符串读取测试 ===");
  char* TEST_STRING = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  uint16_t strLen = strlen(TEST_STRING);
  
  // 读取字符串
  uint8_t readBuffer[64]; // 足够大的缓冲区
  readData(0x1000, readBuffer, strLen);
  readBuffer[strLen] = '\0'; // 添加字符串结束符
  
  Serial.print("读取到的字符串: ");
  Serial.println((char*)readBuffer);
}