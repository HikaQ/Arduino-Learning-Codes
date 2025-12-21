#include <Wire.h>

#define OLED_ADDR 0x3C

void sendcommand(uint8_t cmd)
{
  Wire.beginTransmission(OLED_ADDR);
  Wire.write(0x00); //发送控制命令
  Wire.write(cmd);
  Wire.endTransmission();
}

void senddata(uint8_t data)
{
  Wire.beginTransmission(OLED_ADDR);
  Wire.write(0x40); //发送的是数据
  Wire.write(data);
  Wire.endTransmission();
}

void oled_clear()
{
  uint8_t ret = 0;
  for (uint8_t page_num = 0; page_num < 8; page_num++)
  {
    sendcommand(0xB0 + page_num); //发送页地址
    sendcommand(0x00);          //发送列地址低位
    sendcommand(0x10);          //发送列地址高位
    for (uint8_t i = 0; i < 128; i++)
    {
      senddata(0x00);
    }
  }
}

void draw_point(uint8_t x, uint8_t y)
{
  uint8_t page_num = y / 8;
  uint8_t y_page = y % 8;
  uint8_t temp = 1 << y_page;
  uint8_t x_high = (x & 0xF0) >> 4;
  uint8_t x_low = x & 0x0F;
  sendcommand(0xB0 + page_num); //发送页地址
  sendcommand(0x00 | x_low);    //发送列地址低位
  sendcommand(0x10 | x_high);   //发送列地址高位
  senddata(temp);
}

void setup()
{
  Serial.begin(115200);
  Wire.begin(39, 38);
  //OLED屏初始化序列
  sendcommand(0xAE);
  sendcommand(0xD5);
  sendcommand(80);
  sendcommand(0xA8);
  sendcommand(0x3F);
  sendcommand(0xD3);
  sendcommand(0x00);
  sendcommand(0x40);
  sendcommand(0x8D);
  sendcommand(0x14);
  sendcommand(0x20);
  sendcommand(0x02);
  sendcommand(0xA1);
  sendcommand(0xC8);
  sendcommand(0xDA);
  sendcommand(0x12);
  sendcommand(0x81);
  sendcommand(0xEF);
  sendcommand(0xD9);
  sendcommand(0xF1);
  sendcommand(0xDB);
  sendcommand(0x30);
  sendcommand(0xA4);
  sendcommand(0xA6);
  sendcommand(0xAF);
  oled_clear();
  draw_point(0, 0);
  draw_point(1, 1);
  draw_point(10, 10);
}

void loop()
{

}