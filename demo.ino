#include <LiquidCrystal.h>
#include <BH1750.h>
#include <Wire.h>

BH1750 sensor;
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int menu = 1;
int x = 1;

bool up = LOW;
bool down = LOW;
bool select = LOW;
bool left = LOW;
bool right = LOW;

void setup() {
  Wire.begin();
  sensor.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Test On");
  delay(500);
  lcd.clear();
  lcd.print(">1.Mode");
  lcd.setCursor(0,1);
  lcd.print(" 2.Setting");
  pinMode(11, OUTPUT);
}

void loop() {
  float lux = sensor.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lx");
  getKeyinput();
  if (left) {
    menu = 1;
    while (left) {
      getKeyinput();
    }
    updateMenu();
  }
  if (down) {
    menu++;
    updateMenu();
    delay(100);
  }
  if (up) {
    menu--;
    updateMenu();
    delay(100);
  }
  if (select) {
    executeAction();
    updateMenu();
    delay(100);
  }
  Serial.print(x);
  delay(100);
}
// Menu 1
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
      menu = 2;
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
  }
}
// Khi chon Mode //
void action1() {
  lcd.clear();
  lcd.print("Mode: 1");
  bool buttonPressed = false;
  int selectedMode = 0;

  while (!left) {
    if (!buttonPressed) {
      getKeyinput();
    }

    if (up && x < 4) {
      x++;
      lcd.clear();
      lcd.print("Mode: ");
      lcd.print(x);
      delay(100);
      
    } 
    else if (down && x > 1) {
      x--;
      lcd.clear();
      lcd.print("Mode: ");
      lcd.print(x);
      delay(100);
    } 
    else if (select) {
      selectedMode = x;
      lcd.clear();
      
      if(selectedMode == 1 )
      {
        lcd.clear();
        executeMode1();
      }
      if(selectedMode == 2){
        lcd.clear();
        executeMode2();
      }
      if(selectedMode == 3){
        lcd.clear();
        executeMode3();
      }
      if(selectedMode == 4){
        lcd.clear();
        executeMode4();
      }
    }
     else {
      buttonPressed = false;
    }
    delay(100);
  }
}

// excute cua Mode

void executeMode1() {
  lcd.print("Light ON");
  analogWrite(11, 255);
  // Execute actions specific to Mode 1 here
}

void executeMode2() {
  lcd.print("Light OFF");
  analogWrite(11,0);
  // Execute actions specific to Mode 2 here
}

void executeMode3() {
  lcd.print("Mode: 3");
  lcd.setCursor(0, 1);
  lcd.print("Selected");
  // Execute actions specific to Mode 3 here
}

void executeMode4() {
  lcd.print("Mode: 4");
  lcd.setCursor(0, 1);
  lcd.print("Selected");
  // Execute actions specific to Mode 4 here
}

// action cua Setting (chua lam) //
void action2() {
  lcd.clear();
  lcd.print("Mode: 1");
  bool buttonPressed = false;
  int selectedMode = 0;

  while (!left) {
    if (!buttonPressed) {
      getKeyinput();
    }

    if (up && x < 4) {
      x++;
      lcd.clear();
      lcd.print("Mode: ");
      lcd.print(x);
      delay(100);
      
    } 
    else if (down && x > 1) {
      x--;
      lcd.clear();
      lcd.print("Mode: ");
      lcd.print(x);
      delay(100);
    } 
    else if (select) {
      selectedMode = x;
    }
  }
}

// Lay du lieu tu phim keypad //
void getKeyinput() {
  int key = analogRead(A0);
  if (key > 1000) {
    up = LOW;
    down = LOW;
    select = LOW;
    left = LOW;
    right = LOW;
  }
  if (key < 50)  // Right Key
  {
    right = HIGH;
    Serial.println("RIGHT");
  } 
  else if (key < 200)  // Up Key
  {
    up = HIGH;
    Serial.println("UP");
  } 
  else if (key < 400)  // Down Key
  {
    down = HIGH;
    Serial.println("DOWN");
  } 
  else if (key < 600)  // Left Key
  {
    left = HIGH;
    Serial.println("LEFT");
  } 
  else if (key < 800)  // Select
  {
    select = HIGH;
    Serial.println("Select");
  }
}
