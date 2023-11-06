#include <LiquidCrystal.h>

//LCD pin to Arduino
const int pin_RS = 8;
const int pin_EN = 9;
const int pin_d4 = 4;
const int pin_d5 = 5;
const int pin_d6 = 6;
const int pin_d7 = 7;
const int pin_BL = 10;

LiquidCrystal lcd( pin_RS, pin_EN, pin_d4, pin_d5, pin_d6, pin_d7);

#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5

int lcd_key = 0;
int adc_key_in = 0;


int curMode = 0;
int maxMode = 5; //tong so mode

void displayMode(int mode){
  lcd.setCursor(0, 1);
  lcd.print("Mode: " + String(mode+1));
}

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);  //can dong lcd print
  lcd.print("Select Mode:");
  displayMode(curMode);
}



void loop() {
  lcd_key = read_LCD_buttons();
  lcd.setCursor(10, 1);

    if(lcd_key == btnLEFT && curMode > 0){
        Serial.println(adc_key_in);
        curMode = curMode - 1;
        displayMode(curMode);
      }

    if(lcd_key == btnRIGHT && curMode < maxMode - 1){
        Serial.println(adc_key_in);
        curMode = curMode + 1;
        displayMode(curMode);
      }
    /*
    case btnUP: {
        Serial.println(adc_key_in);
        lcd.print("    UP");
        break;
      }
    case btnDOWN: {
        Serial.println(adc_key_in);
        lcd.print("  DOWN");
        break;
      }
      */
/*    case btnSELECT: {
        if(curMode == 1)
        
        if(curMode == 2)
        break;
      }
  */
}

int read_LCD_buttons() {
  adc_key_in = analogRead(0); //A0
  
  if (adc_key_in < 60) 
    return btnRIGHT;
  
  if (adc_key_in < 200) 
    return btnUP;

  if (adc_key_in < 400) 
    return btnDOWN;
  
  else if (adc_key_in < 600) 
    return btnLEFT;
  
  else if (adc_key_in < 800) 
    return btnSELECT;
  
  return btnNONE;
  
}
//problem: bấm một nút thì giá trị giữ nguyên nên sẽ tăng liên tục