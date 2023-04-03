void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 10; i++) {
    digitalWrite(2,HIGH);
    delay(200);
    digitalWrite(2,LOW);
    delay(200);
  }
}
