/**************************************
Author: Zenju Daisuke (Matsumoto Lab.)
Purpose: Servo Control by Serial
***************************************/

#include <Servo.h>

Servo servo;
int deg = 0;

void setup() {
  // setup Servo
  servo.attach(3);
  servo.write(deg);
  
  // setup Serial
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  // move Servo
  servo.write(deg);
}
