void callback(void)
{
  Serial.println("GPIO 4 Interrupted")
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  pinMode(18, OUTPUT);
  pinMode(4, INPUT);
  attachInterrupt(4, callBack, RISING);
}

int cnt = 0;

void loop() {
  Serial.printf("cnt: %d\n", cnt++);
  digitalWrite(18, cnt % 4);
  delay(1000);
}