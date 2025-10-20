#ifndef __BUZZER_H
#define __BUZZER_H

#include "Arduino.h"

#define BUZZER_PIN 1
#define BUZZER_TOGGLE() digitalWrite(BUZZER_PIN, !digitalRead(BUZZER_PIN))

void millis_buzzer(void);

#endif