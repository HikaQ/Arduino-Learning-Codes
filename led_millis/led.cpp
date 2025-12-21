#include "led.h"

unsigned long temp_blue = 0;     /* 用于记录时间点 */
unsigned long temp_green = 0;

void led_init(void)
{
  blue_led_init();
  green_led_init();
}

void blue_led_init(void) 
{
  pinMode(BLUE_LED_PIN, OUTPUT); 
  digitalWrite(BLUE_LED_PIN, HIGH);
}

void green_led_init(void) 
{
  pinMode(GREEN_LED_PIN, OUTPUT); 
  digitalWrite(GREEN_LED_PIN, HIGH);
}

void led_function(void)
{
  BLUE_LED(1);
  GREEN_LED(1);
  delay(1000);                      
  BLUE_LED(0);
  GREEN_LED(0);
  delay(1000);   
}

void millis_blue_green_function(void)
{
    if ((millis() - temp_blue) >= 2000)   /* 说明1秒已经到了 */
    {
        temp_blue = millis();          /* 更新时间点 */
        /* 执行周期为1秒的操作 */
        BLUE_LED_TOGGLE();
    }

    if ((millis() - temp_green) >= 1000)
    {
        temp_green = millis();
        GREEN_LED_TOGGLE();
    }
}