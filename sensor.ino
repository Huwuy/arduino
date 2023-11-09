#include <Wire.h>
#include <BH1750.h>

BH1750 sensor;

int i = 112;
int x = 100;

void setup() {
  Wire.begin();
  sensor.begin();
  Serial.begin(9600);
  Serial.println("BH1750 Test begin");
  pinMode(11, OUTPUT);
}

void loop() {
  float lux = sensor.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  
  if (lux < x) {
    i++;
  } 
  else if(lux > x){
    i--; // Decrease brightness
  }
  analogWrite(11,i);
  if (lux >= x - 3 && lux <= x + 3)
  {
    analogWrite(11,i);
    delay(900000);
  }
  delay(100);
}