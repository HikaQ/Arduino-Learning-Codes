#ifndef __LED_H
#define __LED_H

#include "Arduino.h"

#define BLUE_LED_PIN   44
#define GREEN_LED_PIN   43

#define BLUE_LED(x) digitalWrite(BLUE_LED_PIN, x)
#define BLUE_LED_TOGGLE()  digitalWrite(BLUE_LED_PIN, !digitalRead(BLUE_LED_PIN))

#define GREEN_LED(x) digitalWrite(GREEN_LED_PIN, x)
#define GREEN_LED_TOGGLE()  digitalWrite(GREEN_LED_PIN, !digitalRead(GREEN_LED_PIN))

void led_init(void);
void blue_led_init(void); 
void green_led_init(void); 

void led_function(void);
void millis_blue_green_function(void);

#endif
