#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>

#define LED_PIN 43  

// 定义UUID（可以自己生成，确保唯一性）
#define SERVICE_UUID        "38eeb46f-5518-4550-886e-ba90d759ae8c"
#define CHARACTERISTIC_UUID "953166f8-46c2-4250-9e0d-d30a0fbb5160"

BLECharacteristic* pCharacteristic;  // 全局变量

// 特征值回调：当手机发送数据时会触发
class MyCallbacks: public BLECharacteristicCallbacks 
{
    void onWrite(BLECharacteristic* pCharacteristic) 
    {  
        std::string value = pCharacteristic->getValue();// 获取手机发送的数据

        if (value.length() > 0) 
        {
            Serial.print("收到消息：");
            Serial.println(value.c_str());
            
            // 控制LED
            if (value == "LED_ON") 
            {
                digitalWrite(LED_PIN, HIGH);  // 打开LED
                Serial.println("LED已打开");
                pCharacteristic->setValue("LED状态:已打开");
            } 
            else if (value == "LED_OFF") 
            {
                digitalWrite(LED_PIN, LOW);   // 关闭LED
                Serial.println("LED已关闭");
                pCharacteristic->setValue("LED状态:已关闭");
            } 
            else 
            {
                pCharacteristic->setValue("ESP32 Reserved: " + value);  // 回复消息
            }
        }
    }
};

void setup() 
{
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);  // 把43号引脚设为输出模式（控制LED必须）
  digitalWrite(LED_PIN, LOW); // 初始关闭LED
  Serial.println("LED引脚初始化完成");

  BLEDevice::init("hyl_ESP32");  // 1. 初始化BLE设备

  BLEServer* pServer = BLEDevice::createServer();  // 2. 创建服务器

  BLEService* pService = pServer->createService(SERVICE_UUID);  // 3. 创建服务

  // 4. 创建特征值（可读、可写）
  pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID,BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_WRITE);

  pCharacteristic->setCallbacks(new MyCallbacks());  // 5. 设置回调函数

  pCharacteristic->setValue("Hello,I am ESP32");  // 6. 设置初始值

  pService->start();  // 7. 启动服务

  BLEDevice::startAdvertising();  // 8. 开始广播

  Serial.println("BLE设备已启动,等待连接...");
  Serial.println("设备名称: hylESP32");
}

void loop() 
{
  // 主循环不需要做任何事情，BLE会自动在后台运行
  delay(1000);
}