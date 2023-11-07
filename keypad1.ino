#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int menu = 1;

bool up = LOW;
bool down = LOW;
bool select = LOW;
bool left = LOW;
bool right = LOW;

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);  
  lcd.print("Test On");
  delay(500);
  lcd.clear();
}

void loop() {
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
}

void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1:
      lcd.clear();
      lcd.print(">1.Mode");
      lcd.setCursor(0,1);
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

void action1() {
  lcd.clear();
  menu = 1;
  while (!left) {
    
    lcd.setCursor(0, 1);
    lcd.print("Mode: 1");
    getKeyinput();
    
    if(up){
      menu++;
      updateMenu();
    }
    if(down){
      menu--;
      updateMenu();
    }
    switch(menu){
      
      case 1:
        lcd.clear();
        lcd.print("Choose Mode");
        lcd.setCursor(0,1);
        lcd.print("Mode: 1");
        break;
      case 2:
        lcd.clear();
        lcd.print("Choose Mode");
        lcd.setCursor(0,1);
        lcd.print("Mode: 2");
        break;
      case 3:
        lcd.clear();
        lcd.print("Choose Mode");
        lcd.setCursor(0,1);
        lcd.print("Mode: 3");
        break;
      case 4:
        lcd.clear();
        lcd.print("Choose Mode");
        lcd.setCursor(0,1);
        lcd.print("Mode: 4");
        break;
    }
  }
}

void action2() {
  lcd.clear();
  while (!select) {
    menu = 1;
    lcd.setCursor(0, 1);
    lcd.print("Mode: 1");
    getKeyinput();
    if(left){
      menu--;
      updateMenu();
    }
    if(right){
      menu++;
      updateMenu();
    }
    if(up){
      menu = 2;
      updateMenu();
    }
    if(down){
      menu = 1;
      updateMenu();
    }
  
  }
}

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
  } else if (key < 200)  // Up Key
  {

    up = HIGH;
    Serial.println("UP");
  } else if (key < 400)  // Down Key
  {
    down = HIGH;
    Serial.println("DOWN");
  } else if (key < 600)  //Left Key
  {
    left = HIGH;
    Serial.println("LEFT");
  } else if (key < 800)  //Result

  {
    select = HIGH;
    Serial.print("Select");
  }
}
