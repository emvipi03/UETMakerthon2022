#include <LiquidCrystal.h>

LiquidCrystal lcd(9,8,7,6,5,4);
const int triger=3; //chan triger cua cam bien HCSR04
const int echo=2; //chan echo cua cam bien HCSR04

void setup(){
  Serial.begin(9600);
  pinMode(triger,OUTPUT); //triger phat tin hieu
  pinMode(echo,INPUT); //echo nhan tin hieu
  lcd.begin(16,2);
}

void loop(){
  float duration; //bien do time 
  float distance; //bien luu khoang cach
  digitalWrite(triger,0); //tat chan triger
  delayMicroseconds(2);
  digitalWrite(triger,1); //phat xung triger
  delayMicroseconds(10);

  duration= pulseIn(echo,1,3000); //do rong xung HIGH cua chan echo sau 3000ms
  distance= (duration *0.034/2);
  lcd.setCursor(0,0);
  lcd.print("distance");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm");
  delay(1000);
  
}
