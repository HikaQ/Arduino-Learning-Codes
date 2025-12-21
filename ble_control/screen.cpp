#include "screen.h"
SSD1306Wire display(OLED_ADDRESS, SDA_PIN, SCL_PIN);  // 全局OLED对象
static const int centerX = SCREEN_WIDTH / 2;         // 圆心X坐标
static const int centerY = 32;                        // 圆心Y坐标
static const int radius = 18;                         // 圆盘半径
static const int pointerLength = 15;                  // 指针长度

void screen_init() {
    display.init();  // 初始化OLED显示屏
    display.flipScreenVertically();  // 如果屏幕上下颠倒，可以注释这行
    delay(1000);  // 显示欢迎信息1秒
    Serial.println("OLED屏幕初始化完成");
}

void screen_update(int servo_angle) {
    display.clear();  // 清屏
    screen_draw_servo_dial(servo_angle); // 绘制舵机表盘
    screen_draw_pointer(servo_angle);   // 绘制指针
    screen_draw_info(servo_angle);      // 绘制角度信息
    display.display();  // 更新显示
}

// 显示当前角度
void screen_draw_info(int angle) {
    delay(1);
}

void screen_draw_servo_dial(int angle) {
    display.drawCircle(centerX, centerY, radius);  // 绘制外圆
    // 绘制刻度(15度一个刻度)
    for (int i = 0; i <= 180; i += 15) {
        float rad = (i - 90) * PI / 180.0;  // 将角度转换为弧度
        // 计算刻度线起点和终点
        int x1 = centerX + (radius - 5) * cos(rad);
        int y1 = centerY + (radius - 5) * sin(rad);
        int x2 = centerX + radius * cos(rad);
        int y2 = centerY + radius * sin(rad);
        display.drawLine(x1, y1, x2, y2);  // 绘制刻度线
    }
}

void screen_draw_pointer(int angle) {
    float screen_angle = (90 - angle) * PI / 180.0;
    int endX = centerX + pointerLength * cos(screen_angle);  // 计算指针终点
    int endY = centerY + pointerLength * sin(screen_angle);
    display.drawLine(centerX, centerY, endX, endY);  // 绘制指针（从圆心到终点）
    display.fillCircle(endX, endY, 2);  // 绘制指针末端小圆点
}