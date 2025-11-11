uint16_t adc_val = 0;
uint32_t adc_vol = 0;

void setup()
{
  Serial.begin(115200);
  // analogSetAttenuation(ADC_11db);
}

void loop()
{
  // 读取8号引脚的 数字值
  adc_val = analogRead(8);
  Serial.print("数字值 adc_val:");
  Serial.print(adc_val); /* 模拟信号的AD值 */

  // 读取8号引脚的 电压值 模拟值
  adc_vol = analogReadMilliVolts(8);
  Serial.print("模拟值 电压值 adc_vol:");
  Serial.println(adc_vol); /* 模拟信号的电压值 */
  delay(1000);
}
