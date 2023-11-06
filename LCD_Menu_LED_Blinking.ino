//This is project done by Teach Me Something

#include <LiquidCrystal.h>


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

boolean upbutton = LOW;
boolean downbutton = LOW;
boolean selectbutton = LOW;
boolean backbutton = LOW;
int blue=A1;
int green =A2;
int yellow=A3;
int red =A4;
int menu = 1;
int x=0;
int ledState = LOW;  
unsigned long previousMillis = 0;       
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  lcd.begin(16, 2);
   Serial.begin(9600);
  lcd.setCursor(2,0);
  lcd.print("Hello World");
  delay(500);
  lcd.clear();
  updateMenu();
}

void loop() {
  getKeyinput();

    if (backbutton){
    menu=1;
       while (backbutton)
      {
      Serial.println("Back Press");
      getKeyinput();
       }
       updateMenu();
  }
  if (downbutton){
    menu++;
    updateMenu();
    delay(100);
    while (downbutton)
    {
      Serial.println("Down Press");
      getKeyinput();
       }
  }
  if (upbutton){
    menu--;
    updateMenu();
    delay(100);
    while(upbutton)
    {
     
      Serial.println("UP Press");
      getKeyinput();
      
    }
  }
  if (selectbutton){
    executeAction();
    updateMenu();
    delay(100);
    while (selectbutton)
    {
     
      Serial.println("Select Press");
      getKeyinput();
      
    }
  }
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">1.Mode");
      lcd.setCursor(0, 1);
      lcd.print(" 2.Setting");
      break;
    case 2:
      lcd.clear();
      lcd.print(" 1.Mode");
      lcd.setCursor(0, 1);
      lcd.print(">2.Setting");
      break;
    case 3:
      lcd.clear();
      lcd.print(">3.LED Fading");
      lcd.setCursor(0, 1);
      lcd.print(" 4.LED Chasing");
      break;
    case 4:
      lcd.clear();
      lcd.print(" 3.LED Fading");
      lcd.setCursor(0, 1);
      lcd.print(">4.LED Chasing");
      break;
    case 5:
      menu = 4;
      break;
  }
}

void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;
  }
}

void action1() {
 
  lcd.clear();
  while (!(backbutton))
    {
   getKeyinput();
  if (upbutton)
  x=0;
  if (downbutton)
  x=1;
  if(x==0)
  {
  lcd.setCursor(0,0);
  lcd.print(">a) Blinking ON");
  lcd.setCursor(0,1);
  lcd.print(" b) Blinking OFF");
    if (millis() - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis =millis();


    // set the LED with the ledState of the variable:
   
   }
  }
     if(x==1)
  {
   ledState = LOW;
  lcd.setCursor(0,0);
  lcd.print(" a) Blinking ON");
  lcd.setCursor(0,1);
  lcd.print(">b) Blinking OFF");
   }
  digitalWrite(blue, ledState);
   digitalWrite(green, ledState);
   digitalWrite(yellow, ledState);
   digitalWrite(red, ledState);
   Serial.println(ledState);
  }
    while (backbutton)
    getKeyinput ();
     digitalWrite(blue,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
    
    Serial.println("LED Exit");
    x=0;
}
void action2() {
  lcd.clear();
   while (!(backbutton))
    {
   getKeyinput();
  if (upbutton)
  x=0;
  if (downbutton)
  x=1;
  if(x==0)
  {
    ledState = HIGH;
  lcd.setCursor(0,0);
  lcd.print(">a) LED ON");
  lcd.setCursor(0,1);
  lcd.print(" b) LED OFF");
  
   }
     if(x==1)
  {
    ledState = LOW;
  lcd.setCursor(0,0);
  lcd.print(" a) LED ON");
  lcd.setCursor(0,1);
  lcd.print(">b) LED OFF");

  }
   digitalWrite(blue, ledState);
   digitalWrite(green, ledState);
   digitalWrite(yellow, ledState);
   digitalWrite(red, ledState);
   Serial.println(ledState);
  
  }
  
  while (backbutton)
    getKeyinput ();
      digitalWrite(blue,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
    Serial.println("LED Exit");
    x=0;
}
void action3() {
  digitalWrite(yellow,HIGH);
  lcd.clear();
  while (!(backbutton))
    {
   getKeyinput();
  if (upbutton)
  x=0;
  if (downbutton)
  x=1;
  if(x==0)
  {
  lcd.setCursor(0,0);
  lcd.print(">a) Fading ON");
  lcd.setCursor(0,1);
  lcd.print(" b) Fading OFF");
   for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    getKeyinput ();
    if(backbutton || downbutton)
   { fadeValue =255;
    x=1;
   }
   analogWrite(blue, fadeValue);
   analogWrite(green, fadeValue);
   analogWrite(yellow, fadeValue);
   analogWrite(red, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
    Serial.println(fadeValue);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    getKeyinput ();
    if(backbutton || downbutton)
   { fadeValue =0;
    x=1;
   }
     analogWrite(blue, fadeValue);
   analogWrite(green, fadeValue);
   analogWrite(yellow, fadeValue);
   analogWrite(red, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
     Serial.println(fadeValue);
  }
   
   }
     if(x==1)
  {
  lcd.setCursor(0,0);
  lcd.print(" a) Fading ON");
  lcd.setCursor(0,1);
  lcd.print(">b) Fading OFF");
  digitalWrite(blue,LOW);
  Serial.println("Fading OFF");
  }
  }
    while (backbutton)
    getKeyinput ();
  digitalWrite(blue,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
    Serial.println("LED Exit");
    x=0;
}

void action4() {
   previousMillis =millis();
  lcd.clear();
  while (!(backbutton))
    {
   getKeyinput();
  if (upbutton)
  x=0;
  if (downbutton)
  x=1;
  if(x==0)
  {
  lcd.setCursor(0,0);
  lcd.print(">a) Chasing ON");
  lcd.setCursor(0,1);
  lcd.print(" b) Chasing OFF");
  if (millis() - previousMillis < 150)
  {
    digitalWrite(blue,HIGH);
    Serial.println("LED 1");
  }
  if ((millis() - previousMillis >= 150) && (millis() - previousMillis <= 300))
  {
    digitalWrite(green,HIGH);
    digitalWrite(blue,LOW);
     Serial.println("LED 2");
  }
   if ((millis() - previousMillis >= 300) && (millis() - previousMillis <= 450))
  {
    digitalWrite(yellow,HIGH);
    digitalWrite(green,LOW);
     Serial.println("LED 3");
  }
    if ((millis() - previousMillis >= 450) && (millis() - previousMillis <= 600))
  {
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
     Serial.println("LED 4");
  }
      if (millis() - previousMillis > 600) 
  {
    digitalWrite(blue,LOW);
    digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    previousMillis =millis();
  }
 
  }
     if(x==1)
  {
  lcd.setCursor(0,0);
  lcd.print(" a) Chasing ON");
  lcd.setCursor(0,1);
  lcd.print(">b) Chasing OFF");
  digitalWrite(blue,LOW);
    digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
    digitalWrite(red,LOW);
  Serial.println("LED OFF");
  }
  }
    while (backbutton)
    getKeyinput ();
  digitalWrite(blue,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
    Serial.println("LED Exit");
    x=0;
}



void getKeyinput() {
  int key = analogRead(A0);
  if (key > 1000) 
  {
    upbutton=LOW;
     downbutton=LOW;
     selectbutton =LOW;
     backbutton=LOW;
  }
 // Serial.println(key);
 
 if (key < 50) // Right Key
 {

 }
 else if (key < 200) // Up Key
 {
  
 upbutton=HIGH;
 Serial.println("UP");
 }
 else if (key < 400) // Down Key
  {
  downbutton=HIGH;
  Serial.println("DOWN");
  }
 else if (key < 600) //Left Key
 {
backbutton=HIGH;
 }
 else if (key < 800) //Result
  
{
selectbutton=HIGH;
Serial.print("Select");
}

 
}
