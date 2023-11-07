void action1() {
  lcd.clear();
  lcd.print("Mode: 1");
  int x = 1;
  bool buttonPressed = false;

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

      if (select) {
        if (x == 1) {
          lcd.clear();
          lcd.print("Huydeptrai");
        } else if (x == 2) {
          lcd.clear();
          lcd.print("Dinh Ngu");
        } else if (x == 3) {
          lcd.clear();
          lcd.print("code lo");
        } else if (x == 4) {
          lcd.clear();
          lcd.print("haha");
        }
      }
    } else if (down && x > 1) {
      x--;
      lcd.clear();
      lcd.print("Mode: ");
      lcd.print(x);
      delay(100);
    } else {
      buttonPressed = false;
    }

    delay(100);
  }
}
