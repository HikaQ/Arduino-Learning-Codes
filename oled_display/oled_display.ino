#include "SSD1306Wire.h"        // legacy: #include "SSD1306.h"
SSD1306Wire display(0x3C, 39, 38); //地址 SDA SCL

void setup()
{
  Serial.begin(115200);    /* 串口初始化 */
  display.init(); //初始化OLED
  display.flipScreenVertically();
  display.clear();//清屏
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, "oled display");
  display.display();
}

void loop()
{
  Serial.println("Waitting for Serial Data \n"); /* 打印等待输入数据 */
  while (Serial.available() > 0)                /* 检测串口是否有接收到数据 */
  {
    String serial_data;                         /* 定义String数据类型的变量 */
    int c = Serial.read();                      /* 读取输入进来的串口数据 */
    while (c >= 0)
    {
      serial_data += (char)c;                   /* 把数据拼凑进serial_data */
      c = Serial.read();
    }
    display.setColor(BLACK);
    display.fillRect(0, 17, 128, 48); //区域清除
    display.setColor(WHITE);
    display.drawStringMaxWidth(0, 17, 128, serial_data);  //具有自动换行功能
    Serial.print("Received Serial Data: ");    /* 打印出数据的提示信息 */
    Serial.println(serial_data);               /* 打印出接收到的数据 */
  }
  display.display();
  delay(1000);            /* 检测周期1秒 */
}