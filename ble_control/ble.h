#ifndef BLE_H
#define BLE_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>

// ======== 蓝牙配置参数 ========
#define BLE_NAME "Super_Servo"          // 蓝牙设备名称
#define SERVICE_UUID "ba4a51a7-fa7c-46a4-9f6c-3d7a6dca4649" // 服务UUID
#define CHAR_UUID "5f22b8d9-201f-41dc-8d44-249674a099bb"    // 特征UUID

// ======== 函数声明 ========
void ble_init();          // 初始化蓝牙
void ble_send(String message); // 发送数据到手机


#endif
