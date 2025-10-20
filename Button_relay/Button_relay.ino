const int buttonPin = 0;
const int relayPin = 1; //定义继电器引脚号

int buttonState = 0;

void setup()
{
  pinMode(relayPin, OUTPUT); //配置继电器引脚号的模式为输出模式
  pinMode(buttonPin, INPUT_PULLUP); //设置初始电平为高电平
}

void loop()
{
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    digitalWrite(relayPin, LOW);
  }
  else
  {
    digitalWrite(relayPin, HIGH);
  }
}