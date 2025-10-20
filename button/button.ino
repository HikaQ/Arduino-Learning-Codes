const int buttonPin = 0;
const int buzzerPin = 1;

int buttonState = 0;

void setup() 
{
  Serial.begin(9600); // 通讯配置函数
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

int32_t key_count = 0;

void loop() 
{
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH)
  {
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
    digitalWrite(buzzerPin, LOW);

    key_count ++;
    Serial.println(key_count); // 通讯功能函数
  }



}
