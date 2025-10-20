#include "buzzer.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  millis_buzzer();
}
