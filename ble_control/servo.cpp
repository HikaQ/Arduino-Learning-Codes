#include "servo.h"

static int current_angle = 90; // 当前角度

void servo_init() {
  ledcSetup(PWM_CHANNEL, SERVO_FREQ, PWM_RESOLUTION);
  ledcAttachPin(SERVO_PIN, PWM_CHANNEL);
  // 设置初始PWM
  int pwm = (2.5 + (current_angle * 10.0 / 180.0)) / 100.0 * 1023;
  ledcWrite(PWM_CHANNEL, pwm);
  Serial.println("舵机初始化完成");
}

void servo_set_angle(int angle) {
  // 限制角度范围
  if (angle < MIN_ANGLE) angle = MIN_ANGLE;
  if (angle > MAX_ANGLE) angle = MAX_ANGLE;

  // 平滑转动到目标角度
  while (current_angle != angle) {
    // 移动1度
    if (current_angle < angle) current_angle++;
    else current_angle--;

    // 设置PWM
    int pwm = (2.5 + (current_angle * 10.0 / 180.0)) / 100.0 * 1023;
    ledcWrite(PWM_CHANNEL, pwm);

    // 控制速度（每度20ms）
    delay(20);
  }

  Serial.print("角度: "); Serial.println(angle);
}

int servo_get_angle() {
  return current_angle;
}