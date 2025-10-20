const int relayPin = 1; //定义继电器引脚号

void setup()
{
  pinMode(relayPin, OUTPUT); //配置继电器引脚号的模式为输出模式
  digitalWrite(relayPin, HIGH); //设置初始电平为高电平
}

void loop()
{
  digitalWrite(relayPin, HIGH); //设置电平为高电平
  delay(2000); //强延时两秒
  digitalWrite(relayPin, LOW); //设置电平为低电平
  delay(2000); //强延时两秒
}