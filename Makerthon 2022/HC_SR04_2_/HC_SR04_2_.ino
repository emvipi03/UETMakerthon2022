//#include <NewPing.h>
//
//#define trigPin1 A0
//#define echoPin1 A1
//#define trigPin2 A2
//#define echoPin2 A3
//
//long duration, distance, FIRSTSensor, SECONDSensor, THIRDSensor;
//
//void SonarSensor(int trigPin, int echoPin)
//{
//  NewPing sonar (trigPin, echoPin,20);
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  duration = pulseIn(echoPin, HIGH);
//  distance = sonar.ping_cm();
//}
//void setup() {
//  // put your setup code here, to run once:
//  pinMode(trigPin1, OUTPUT);
//  pinMode(echoPin1, INPUT);
//  pinMode(trigPin2, OUTPUT);
//  pinMode(echoPin2, INPUT);
//  pinMode(7, OUTPUT);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  SonarSensor(trigPin1, echoPin1);
//  FIRSTSensor = distance;
//  SonarSensor(trigPin2, echoPin2);
//  SECONDSensor = distance;
//
//  Serial.print("S1:"); Serial.println(FIRSTSensor); delayMicroseconds(10);
//  Serial.print("S2:"); Serial.println(SECONDSensor); delayMicroseconds(10);
//}


#include <NewPing.h>
NewPing sonar1(A0,A1,600);
NewPing sonar2(A2,A3,600);
NewPing sonar3(A4,A5,600);
void setup() {
  Serial.begin(9600);
  delay(50);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);//pin Nut 9 là buzzer
}
void loop() {
  int d1 = sonar1.ping_cm();
  int d2 = sonar2.ping_cm();
  int d3 = sonar3.ping_cm();
  Serial.print("S1 = ");
  Serial.println(sonar1.ping_cm());
  Serial.print("S2= ");
  Serial.println(sonar2.ping_cm());
  Serial.print("S3= ");
  Serial.println(sonar3.ping_cm());
  delay(200);

  if(d1 <10 & d1 > 0 || d2 < 10 & d2> 0 || d3 < 10 & d3 > 0) {
    digitalWrite(7, HIGH);
    
    /*buzzer*/
    tone(9, 1000);      // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(9);          // Stop sound...
    delay(1000);        // ...for 1sec
  } else digitalWrite(7, LOW);
}
