#include <LiquidCrystal_I2C.h>

#include <Wire.h>
#include <BH1750.h>

BH1750 Sensor;

void setup() {
  Serial.begin(9600);
  Sensor.begin();
  Serial.println("BH1750 Test begin");
}

void loop() {
  float lux = Sensor.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  delay(1000); 
}