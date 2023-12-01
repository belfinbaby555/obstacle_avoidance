//code Created by Belfin Baby

#include <HCSR04.h>

byte triggerPin = A2;
byte echoPin = A3;

int MOTORspeed=200;
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);

  HCSR04.begin(A2, A3);
}
void loop() {
  double* distance=HCSR04.measureDistanceCm();
  Serial.println(distance[0]);

  if(distance[0]<=20){
    forward();
    delay(500);
    right();
    delay(600);
    }
else{
  backward();
  }

  

}
void forward(){
  analogWrite(3,MOTORspeed);
  digitalWrite(2,HIGH);
  digitalWrite(7,LOW);
  analogWrite(6,MOTORspeed);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  }
  void backward(){
  analogWrite(3,MOTORspeed);
  digitalWrite(2,LOW);
  digitalWrite(7,HIGH);
  analogWrite(6,MOTORspeed);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  }
  void right(){
  analogWrite(3,250);
  digitalWrite(2,HIGH);
  digitalWrite(7,LOW);
  analogWrite(6,250);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  }
void left(){
  analogWrite(3,250);
  digitalWrite(2,LOW);
  digitalWrite(7,HIGH);
  analogWrite(6,250);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  }
  void sto(){
  analogWrite(3,0);
  digitalWrite(2,LOW);
  digitalWrite(7,LOW);
  analogWrite(6,0);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  }
