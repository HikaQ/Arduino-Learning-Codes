#include "ble.h"
extern void servo_set_angle(int angle); // 声明外部函数（在servo.cpp中定义）
static BLEServer* ble_server = NULL; // 静态变量（只在本文件中可见）
static BLEService* ble_service = NULL;
static BLECharacteristic* ble_char = NULL;
static bool ble_connected = false;

// --- 蓝牙回调 ---
class ServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        ble_connected = true;
        Serial.println("蓝牙已连接");
        ble_send("舵机控制器已连接");
    }

    void onDisconnect(BLEServer* pServer) {
        ble_connected = false;
        Serial.println("蓝牙已断开");

        BLEDevice::startAdvertising(); // 重新开始广播
        Serial.println("等待连接...");
    }
};

// 数据接收回调
class DataCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic* pCharacteristic) {
        std::string value = pCharacteristic->getValue();

        if (value.length() > 0) {
            String data = String(value.c_str());
            data.trim(); // 去除空格
            Serial.println("收到指令：" + data);
            int angle = data.toInt(); // 解析角度值
            servo_set_angle(angle);// 控制舵机转动

            String reply = "舵机已转到 " + String(angle) + " 度"; // 回复确认消息
            ble_send(reply);
        }
    }
};

// ========== 蓝牙函数实现 ==========
void ble_init() {
    BLEDevice::init(BLE_NAME); // 初始化蓝牙设备
    ble_server = BLEDevice::createServer(); // 创建BLE服务器
    ble_server->setCallbacks(new ServerCallbacks());
    ble_service = ble_server->createService(SERVICE_UUID); // 创建BLE服务

    // 创建特征值
    ble_char = ble_service->createCharacteristic(
        CHAR_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE |
        BLECharacteristic::PROPERTY_NOTIFY
    );

    ble_char->setCallbacks(new DataCallbacks()); // 设置回调函数
    ble_char->setValue("ESP32舵机控制器"); // 设置初始值
    ble_service->start(); // 启动服务

    BLEAdvertising* advertising = BLEDevice::getAdvertising(); // 开始广播
    advertising->addServiceUUID(SERVICE_UUID);
    advertising->setScanResponse(true);
    BLEDevice::startAdvertising();

    Serial.print("蓝牙设备: ");
    Serial.println(BLE_NAME);
    Serial.println("等待手机连接...");
}

void ble_send(String message) {
    if (ble_connected && ble_char) {
        ble_char->setValue(message.c_str());
        ble_char->notify();
    }
}