#include <LiquidCrystal.h>
LiquidCrystal lcd(11,10, 7, 6, 5, 4);
//               (RS, E,D4,D5,D6,D7) 
int loa = 9;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("UPDATING...");
  delay(500);
  pinMode(loa, OUTPUT);
  
}
int a = 0;
void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  noTone(loa);
  if (a == 0) {
    tone(loa,3000,1000);
    lcd.home();
    lcd.print("LEFT");
   
  } else
  if (a == 1) {
    tone(loa,3000,1000);
    lcd.setCursor(11,0);
    lcd.print("RIGHT");
  } else
  if (a == 2) {
    tone(loa,3000,1000);
    lcd.setCursor(6,0);
    lcd.print("FRONT");
  } else
  if (a == 3) {
    tone(loa,3000,1000);
    lcd.setCursor(6,1);
    lcd.print("BEHIND");
    a = -1;
  }
  delay(500);
  a++;
}
